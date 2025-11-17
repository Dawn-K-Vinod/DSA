**Strict Algorithm for Binary Search Program (binarySearch.c)**

1. **Start**
2. Print "Enter the number of items in the sorted array: "
3. Read integer `n`
4. Declare array `sortedArray` of size `n`
5. For `i` from 0 to `n-1`:
    a. Print "Enter item-(i+1):"
    b. Read integer and assign to `sortedArray[i]`
6. Loop forever:
    a. Print "--Menu--"
    b. Print "1. Search"
    c. Print "2. Exit"
    d. Print "Enter your choice: "
    e. Read integer `choice`
    f. If `choice` equals 1:
        i. Print "Enter the key to search: "
        ii. Read integer `key`
        iii. Call function `binarySearch(sortedArray, 0, n-1, key)` and store result in `keyIndex`
        iv. If `keyIndex` is not -1:
            - Print "The key {key} is found at position {keyIndex}"
        v. Else:
            - Print "The key {key} is not found."
    g. Else if `choice` equals 2:
        i. Print "Exiting the program...."
        ii. Stop program
    h. Else:
        i. Print "Invalid Entry! Try Again."
        
**Binary Search Function (`binarySearch(arr, start, end, key)`):**
1. If `start > end`, return -1
2. Set `mid = start + (end - start) / 2`
3. If `key < arr[mid]`, recursively call `binarySearch(arr, start, mid - 1, key)` and return result
4. Else if `key > arr[mid]`, recursively call `binarySearch(arr, mid + 1, end, key)` and return result
5. Else, return `mid`
6. **End Function**

**End Algorithm**
