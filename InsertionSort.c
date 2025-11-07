// Insertion sort

#include <stdio.h>

void insertionSort(int n, int arr[]) {
    int temp;
    for (int i = 1; i < n; i++) {
        while (arr[i-1] > arr[i] && i>0) {
            temp = arr[i-1];
            arr[i-1] = arr[i];
            arr[i] = temp;
            i--;
        }
    }
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

    insertionSort(n, arr); // insertion sort
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
    
    return 0;
}