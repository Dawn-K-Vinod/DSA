# Strict Algorithm for basicMemoryAllocator_&_garbageCollector.c

## 1. Definitions
- Define a structure `memory` representing a memory block (fields: size, startAddr, isFree, prev, next).
- Define an integer variable `MAX_SIZE` to store the total size of memory.

## 2. Supporting Functions
- **createBlock(size, addr, isFree):**
    - Allocate memory for a new `memory` structure using `malloc`.
    - Initialize all fields.
    - Set `prev` and `next` to `NULL`.
    - Return pointer to new structure.

- **displayAll(temp):**
    - Traverse list from `temp`.
    - For each block, print whether block is Free or Allocated along with address range and size.
    - At the end, print `NULL`.

- **display_freeOrAllocatedBlocks(temp, isFree):**
    - Traverse list from `temp`.
    - For each block, if block's `isFree` matches input, print its details.
    - At the end, print `NULL`.

## 3. Allocation Algorithm
- **allocateProcess(head, size, choice):**  
    - Set pointers `temp=head`, `selected=NULL`.
    - If `choice==1` (First Fit):
        - Scan the list.
        - Select first free block where `block.size >= size`.
    - If `choice==2` (Best Fit):
        - Find free block with minimal size >= process size.
    - If `choice==3` (Worst Fit):
        - Find free block with maximal size >= process size.
    - If no suitable block:
        - Print message and return current head.
    - Otherwise:
        - Create a new allocated block of given size at block's startAddr.
        - Link new block before selected block.
        - Reduce `selected` block's size by allocation amount, increment its startAddr.
        - If selected block's size becomes zero:
            - Remove it from the list and deallocate memory using `free`.
        - If selected block was head, update head.
    - Print allocation success message.
    - Display all blocks.
    - Return possibly updated head.

## 4. Garbage Collector Algorithm
- **garbageCollector(temp):**
    - Traverse list from `temp`.
    - Whenever two contiguous blocks are both free:
        - Merge second block into first block (`size += next.size`).
        - Remove second block, update pointers, free memory.
    - Continue until no more merges available.

## 5. Free Process Algorithm
- **freeProcess(head, addr):**
    - Traverse list from `head` until a block with startAddr == addr is found.
    - If not found, print error and return.
    - If block already free, print message and return.
    - Otherwise:
        - Set block's `isFree=1`.
        - Run garbageCollector to merge adjacent free blocks.
        - Display all blocks.

## 6. Main Program Logic
- Prompt user for number of memory blocks `n`.
- For `i` from 0 to `n-1`:
    - Prompt for block size.
    - Create block with specified size, starting at correct address.
    - Link blocks into doubly linked list.
- After setup, display all blocks.
- Set `MAX_SIZE` to total memory size.

- **Enter main loop:**
    - Show menu:
        - 1: Allocate a process
        - 2: Free/deallocate a process
        - 3: Exit
    - Process user input accordingly:
        - **If 1:**  
            - Prompt for process size; validate.
            - Prompt for allocation method (FirstFit/BestFit/WorstFit); validate.
            - Call `allocateProcess` and update head.
        - **If 2:**  
            - Display all allocated blocks.
            - Prompt for address to free.
            - Call `freeProcess`.
        - **If 3:**  
            - Print and exit.
        - **Default:**  
            - Print error and re-prompt.

- End program when user chooses exit.
