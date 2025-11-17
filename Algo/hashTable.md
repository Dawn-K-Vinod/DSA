# Algorithm for Inserting Integers into a Hash Table with Separate Chaining

**Given:**  
- A hash table of fixed size (10 slots, indexed 0 to 9).  
- A set of integer keys to insert into the table.  
- Hash function: k mod table_size  
- Collision resolution: Separate chaining (linked lists).

---

## Steps

1. **Initialization**
    - Set the hash table size (tableSize) to 10.
    - Create an array `hashTable` of pointers for each slot. Initialize every slot to `NULL`.

2. **Input Number of Keys**
    - Prompt user to enter the number of keys `n`.
    - If `n <= 0`, terminate the program.

3. **Key Insertion (Iterate for each key)**
    - For each key input by the user (repeat `n` times):
        a. Prompt the user to enter the key value.
        b. Compute the hash index as `index = key % tableSize`.
        c. Create a new linked list node (`cell`) to store the key.
        d. If the hash table slot at `index` is empty (`NULL`):
            - Insert the new node directly.
        e. Else (slot is not empty):
            - Traverse the linked list at that slot to its last node.
            - Append the new node at the end.

4. **Display Hash Table**
    - For each slot (from 0 to tableSize-1):
        a. Print the slot index.
        b. Traverse the linked list at each slot, printing values in order.
        c. Print `[NULL]` after the end of the list for that slot.

5. **Print Load Factor**
    - Calculate load factor as `(number of inserted keys) / (table size)`.
    - Print the computed load factor.

---

## Additional Steps Used in Implementation

- **Memory Allocation**
    - Create a new node with dynamic memory allocation (`malloc`).  
    - Ensure node's `value` and `next` fields are initialized correctly.

- **Hash Function**
    - Compute index for each key strictly as: `index = key % tableSize`.

- **Separate Chaining**
    - Handle collisions by storing multiple keys at the same index using a linked list.

---

## Termination

- After displaying the hash table and load factor, the program ends.
