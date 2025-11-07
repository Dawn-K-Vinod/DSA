// Quick sort (pivot)

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int start, int end, int arr[]) {
    if (start >= end) return;

    int pivot = arr[(int)(start+end)/2];
    // int pivot = arr[start];
    // int pivot = arr[end];

    int i = start;
    int lowerLimit = start;
    int upperLimit = end;

    while (i <= upperLimit) {
        if (arr[i] < pivot) {
            swap(&arr[lowerLimit], &arr[i]);
            i++; lowerLimit++;
        }
        else if (arr[i] > pivot) {
            swap(&arr[upperLimit], &arr[i]);
            upperLimit--;
        }
        else {
            i++;
        }
    }

    quickSort(start, lowerLimit-1, arr);
    quickSort(upperLimit+1, end, arr);
}


int main() {
    int n;
    printf("Enter the size of array to sort: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the items: \n");
    
    for (int i = 0; i < n; i++) {
        printf("Item-%d: ", i+1);
        scanf("%d",&arr[i]);
    } printf("\n");

    quickSort(0, n-1, arr); // quick sort
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
    
    return 0;
}