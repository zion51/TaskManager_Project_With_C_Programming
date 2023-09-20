# TaskManager_Project_With_C_Programming
To Understand the sourceCode Follow the steps given bellow:


1. We start by including important header documents ('stdio.h', 'stdlib.h', and 'string.h') to empower input/yield, memory designation, and string tasks.

2. We characterize a construction named 'Errand' to address a solitary undertaking. It incorporates data about task need, portrayal, and a pointer to the following errand (connected list structure).

3. We characterize one more construction named 'PriorityQueue' to address our undertaking administrator. It incorporates pointers to the front of the errand line and to a set of experiences list for putting away erased undertakings.

4. The 'initializePriorityQueue' capability introduces a vacant need line. Both the front and history pointers are set to 'Invalid' at first.

5. The 'enqueue' capability adds an undertaking to the need line. It makes another errand hub and supplements it into the line in light of its need, keeping the control.

6. The 'executeHighestPriorityTask' capability eliminates and executes the most elevated need task from the line. It likewise stores the executed assignment in the set of experiences list for potential fix.

7. The 'displayTasks' capability prints the undertakings in the ongoing line to the control center.

8. The 'deleteTask' capability eliminates an undertaking from the line in light of its depiction. It likewise stores the erased task in the set of experiences list for potential fix.

9. The 'undoLastTask' capability permits you to fix the last erased task by moving it from the set of experiences list back to the front of the line.

10. In the 'fundamental' capability, we make a case of the 'PriorityQueue' to deal with our errands. We start a circle that shows a menu of choices for cooperating with errands.

11. The menu choices are shown with clear depictions, and the client is incited to enter their decision.

12. Contingent upon the client's decision, the program performs different activities:
   - 1: Add another errand with need and portrayal.
   - 2: Execute the most noteworthy need task.
   - 3: Show all assignments in the line.
   - 4: Erase an undertaking in view of its depiction.
   - 5: Fix the last erased task.
   - 6: Stop the program.

13. The program handles client input and plays out the relating activities. Assuming the info is invalid, it prompts the client to attempt once more.

14. The circle go on until the client decides to stop the program.

15. At long last, the program returns 0 to demonstrate fruitful execution.

This code furnishes an essential intelligent errand supervisor with choices to add, execute, show, erase, fix, and quit undertakings. It utilizes a need line information structure and a set of experiences rundown to oversee undertakings and fix tasks.
