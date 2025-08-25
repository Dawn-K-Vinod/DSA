# Algorithm: Circular Queue Using Array

This algorithm describes a menu-driven program to perform circular queue operations (enqueue, dequeue, display) using an array.

---

## Steps

1. **Start**

2. **Input** the maximum size of the queue (`MAX_SIZE`).

3. **Initialize** queue pointers:
   - `FRONT = -1`
   - `REAR = -1`

4. **Loop until the user chooses to exit:**
   - **Display menu:**
     1. Enqueue
     2. Dequeue
     3. Display
     4. Exit
   - **Input** user's choice.

   - **If choice is 1 (Enqueue):**
     - Check if the queue is full:
       - **If full:** Display "Queue is full. Enqueue operation cannot be done."
       - **Else:**
         - Increment `REAR` (circularly: `(REAR+1) % MAX_SIZE`)
         - **Input** value to enqueue
         - Store value at `cq[REAR]`
         - If `FRONT == -1`, set `FRONT = 0`

   - **If choice is 2 (Dequeue):**
     - Check if the queue is empty:
       - **If empty:** Display "Queue is empty. Dequeue operation cannot be done."
       - **Else:**
         - Display value at `cq[FRONT]`
         - If `FRONT == REAR` (only one element left), reset `FRONT` and `REAR` to `-1`
         - Else, increment `FRONT` (circularly: `(FRONT+1) % MAX_SIZE`)

   - **If choice is 3 (Display):**
     - Check if the queue is empty:
       - **If empty:** Display "Circular Queue is empty."
       - **Else:**
         - Print all elements from `FRONT` to `REAR` (circularly)

   - **If choice is 4 (Exit):**
     - End the loop

   - **Else:** Display "Invalid choice"

5. **End**

---

## Notes

- **Enqueue**: Add item at `REAR`, adjust `REAR` circularly, update `FRONT` if necessary.
- **Dequeue**: Remove item at `FRONT`, adjust `FRONT` circularly, reset both pointers if queue becomes empty.
- **Display**: Iterate from `FRONT` to `REAR` using modulo operation to handle circular nature.
