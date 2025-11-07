// Bubble sort (compare 2 adjacent)

#include <stdio.h>

void bubbleSort(int n, int arr[]) {
    int temp = 0;
    for (int i=0; i < n-1; i++) {
        int flag = 0;
        for (int j=0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if (!flag) break;
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

    bubbleSort(n, arr); // bubble sort
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
    
    return 0;
}