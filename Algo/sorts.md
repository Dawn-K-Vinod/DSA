## Strict Algorithm for `sorts_combined.c`

1. **Initialize counting variables:**
    - Set `swap_count` and `comparison_count` to 0.

2. **Define a swap function:**
    - Given two integer pointers, swap their values and increment `swap_count`.

3. **Define Bubble Sort function:**
    - For each element (from 0 to n-2):
        - Initialize a flag to 0.
        - For each adjacent pair up to n-1-i:
            - Increment `comparison_count`.
            - If the left element is greater than the right element:
                - Swap them.
                - Set flag to 1.
        - If flag is 0 (no swaps), break.

4. **Define Insertion Sort function:**
    - For each element from index 1 to n-1:
        - Initialize j = i.
        - While j > 0:
            - Increment `comparison_count`.
            - If previous element is greater than current:
                - Swap them.
                - Decrement j.
            - Else, break.

5. **Define Merge function:**
    - Compute sizes of left and right subarrays.
    - Copy corresponding elements into temporary arrays.
    - Compare and merge elements:
        - While both subarrays have elements:
            - Increment `comparison_count`; if right is chosen instead of left, increment by 2.
            - Place lesser element into original array.
            - Increment `swap_count`.
        - Copy remaining elements from left and right into original array, incrementing `swap_count` for each.

6. **Define Merge Sort function:**
    - If start index >= end index, return.
    - Compute mid index.
    - Recursively call merge sort for left and right subarrays.
    - Merge two sorted subarrays.

7. **Define Quick Sort function:**
    - If start index >= end index, return.
    - Choose pivot as middle element.
    - Initialize pointers for scanning (i), lower limit, upper limit.
    - For each element:
        - If less than pivot:
            - Increment `comparison_count`, swap, advance pointers.
        - If greater than pivot:
            - Increment `comparison_count` by 2, swap, move upper limit.
        - If equal to pivot:
            - Advance pointer.
    - Recursively sort subarrays before lower limit and after upper limit.

8. **Define a function to display step counts and reset counters.**

9. **Main Program:**
    - Prompt user for array size.
    - Initialize array and temporary copy.
    - Read array elements from user.
    - For each sorting algorithm:
        - Restore original array from temp.
        - Sort using the algorithm.
        - Print steps taken (comparisons and swaps/moves).
    - Print the sorted array.

10. **End Program.**
