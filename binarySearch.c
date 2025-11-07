#include <stdio.h>

int binarySearch(int arr[], int start, int end, int key) {
    if (start>end) return -1;
    int mid = (int) (start + (end - start) / 2);

    if (key < arr[mid]) return binarySearch(arr, start, mid-1, key);
    else if (key > arr[mid]) return binarySearch(arr, mid+1, end, key);
    else return mid;
}

int main() {
    int n, key;
    printf("Enter the number of items in the sorted array: ");
    scanf("%d", &n);

    int sortedArray[n];
    for (int i = 0; i<n; i++) {
        printf("Enter item-%d:", i+1);
        scanf("%d", &sortedArray[i]);
    }

    while (1) {
        printf("\n--Menu--\n");
        printf("1. Search\n");
        printf("2. Exit\n");

        int choice;
        printf("Enter you choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int keyIndex = binarySearch(sortedArray, 0, n-1, key);
                if (keyIndex!=-1) printf("The key %d is found at position %d\n", key, keyIndex); 
                else printf("The key %d is not found.\n", key);
                break;
            case 2:
                printf("Exiting the program....\n"); return 0;
            default:
                printf("Invalid Entry! Try Again.\n");
        }
    }
    return 0;
}