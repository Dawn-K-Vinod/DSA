
#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i,j, indexOfSmallest,temp;
    for (i=0; i<n-1; i++) {
        indexOfSmallest = i;
        for (j=i+1; j<n; j++) {
            if (arr[j] < arr[indexOfSmallest]) indexOfSmallest = j;
        }
        temp = arr[i];
        arr[i] = arr[indexOfSmallest];
        arr[indexOfSmallest] = temp;
    }
}

void displayArr(int arr[], int n) {
    for (int i=0; i<n; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {5,4,8,2,7};
    selectionSort(arr, 5);
    displayArr(arr, 5);
    return 0;
}
