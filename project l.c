#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for a task
struct Task {
    int priority;
    char description[100];
    struct Task* next;
};

// Structure for a priority queue
struct PriorityQueue {
    struct Task* front;
    struct Task* history; // To store deleted tasks for undo
};

// Function to initialize an empty priority queue
void initializePriorityQueue(struct PriorityQueue* queue) {
    queue->front = NULL;
    queue->history = NULL;
}

// Function to add a task to the priority queue
void enqueue(struct PriorityQueue* queue, int priority, const char* description) {
    struct Task* newTask = (struct Task*)malloc(sizeof(struct Task));
    if (newTask) {
        newTask->priority = priority;
        strcpy(newTask->description, description);
        newTask->next = NULL;

        if (queue->front == NULL || priority < queue->front->priority) {
            newTask->next = queue->front;
            queue->front = newTask;
        } else {
            struct Task* current = queue->front;
            while (current->next != NULL && priority >= current->next->priority) {
                current = current->next;
            }
            newTask->next = current->next;
            current->next = newTask;
        }
    }
}

// Function to execute the highest priority task
void executeHighestPriorityTask(struct PriorityQueue* queue) {
    if (queue->front == NULL) {
        printf("No tasks to execute.\n");
    } else {
        struct Task* taskToExecute = queue->front;
        printf("Executing task: Priority %d - %s\n", taskToExecute->priority, taskToExecute->description);

        // Move the executed task to the history for potential undo
        struct Task* historyTask = (struct Task*)malloc(sizeof(struct Task));
        if (historyTask) {
            historyTask->priority = taskToExecute->priority;
            strcpy(historyTask->description, taskToExecute->description);
            historyTask->next = queue->history;
            queue->history = historyTask;
        }

        queue->front = taskToExecute->next;
        free(taskToExecute);
    }
}

// Function to display the tasks in the priority queue
void displayTasks(struct PriorityQueue* queue) {
    struct Task* current = queue->front;
    printf("Tasks in the queue:\n");
    while (current != NULL) {
        printf("Priority %d - %s\n", current->priority, current->description);
        current = current->next;
    }
}

// Function to delete a task based on its description
void deleteTask(struct PriorityQueue* queue, const char* description) {
    struct Task* current = queue->front;
    struct Task* prev = NULL;

    while (current != NULL) {
        if (strcmp(current->description, description) == 0) {
            if (prev == NULL) {
                // Task to delete is at the front of the queue
                queue->front = current->next;
            } else {
                prev->next = current->next;
            }

            // Move the deleted task to the history for potential undo
            struct Task* historyTask = (struct Task*)malloc(sizeof(struct Task));
            if (historyTask) {
                historyTask->priority = current->priority;
                strcpy(historyTask->description, current->description);
                historyTask->next = queue->history;
                queue->history = historyTask;
            }

            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }

    printf("Task not found: %s\n", description);
}

// Function to undo the last task
void undoLastTask(struct PriorityQueue* queue) {
    if (queue->history == NULL) {
        printf("No tasks to undo.\n");
        return;
    }

    struct Task* lastTask = queue->history;
    queue->history = lastTask->next;

    // Reinsert the undone task into the front of the queue
    lastTask->next = queue->front;
    queue->front = lastTask;

    printf("Last task undone.\n");
}

int main() {
    struct PriorityQueue taskQueue;
    initializePriorityQueue(&taskQueue);

    while (1) {


        printf(".............................................\n");
        printf("...............ENTRY YOUR TASK...............\n");
        printf(".............................................\n");
        printf(".              1. Add Task                  .\n");
        printf(".     2. Execute Highest Priority Task      .\n");
        printf(".           3. Display Tasks                .\n");
        printf(".            4. Delete Task                 .\n");
        printf(".           5. Undo Last Task               .\n");
        printf(".                6. Quit                    .\n");
        printf(".............................................\n");
        printf(".............................................\n");
        printf(". Enter your choice: ");


        int choice;
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1: {
                int priority;
                char description[100];
                printf("Enter task priority: ");
                scanf("%d", &priority);
                getchar(); // Consume newline
                printf("Enter task description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove trailing newline
                enqueue(&taskQueue, priority, description);
                break;
            }

            case 2:
                executeHighestPriorityTask(&taskQueue);
                break;

            case 3:
                displayTasks(&taskQueue);
                break;

            case 4: {
                char description[100];
                printf("Enter the description of the task to delete: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove trailing newline
                deleteTask(&taskQueue, description);
                break;
            }

            case 5:
                undoLastTask(&taskQueue);
                break;

            case 6:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;

        }



    }

    return 0;
}
