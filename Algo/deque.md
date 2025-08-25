## Algorithm: DE-Queue Operations Using Array

1. **Initialize Deque**
   - Set MAX_SIZE based on user input.
   - Create an array `queue[MAX_SIZE]`.
   - Set FRONT and REAR to -1 (empty state).

2. **Menu Loop**
   - Display a menu for the following operations:
     1. Insert at Front
     2. Insert at Rear
     3. Delete from Front
     4. Delete from Rear
     5. Display Deque
     6. Exit
   - Read user's choice.

3. **Perform Operations Based on Choice**
   - **Insert at Front**
     - If FRONT is at 0, report overflow.
     - If deque is empty, set FRONT and REAR to 0.
     - Else, decrement FRONT.
     - Insert value at FRONT.
   - **Insert at Rear**
     - If REAR is at MAX_SIZE - 1, report overflow.
     - If deque is empty, set FRONT and REAR to 0.
     - Else, increment REAR.
     - Insert value at REAR.
   - **Delete from Front**
     - If deque is empty, report underflow.
     - Remove element at FRONT and increment FRONT.
     - If FRONT > REAR, reset FRONT and REAR to -1.
   - **Delete from Rear**
     - If deque is empty, report underflow.
     - Remove element at REAR and decrement REAR.
     - If FRONT > REAR, reset FRONT and REAR to -1.
   - **Display Deque**
     - If deque is empty, print message.
     - Else, print elements from FRONT to REAR.
   - **Exit**
     - End program.

4. **Repeat Menu Loop Until Exit Selected**
