#include <stdio.h>
int swap_count=0;
int comparison_count=0;

void swap(int *a, int *b) {
    swap_count++;
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int n, int arr[]) {
    for (int i=0; i < n-1; i++) {
        int flag = 0;
        for (int j=0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
            comparison_count++;
        }        
        if (!flag) break;
    }
}

void insertionSort(int n, int arr[]) {
    int j;
    for (int i = 1; i < n; i++) {
        j = i;
        while (j>0) {
            comparison_count++;
            if (arr[j-1] > arr[j]) {
                swap(&arr[j-1], &arr[j]);
                j--;
            } else break;
        }
    }
}

void merge (int start, int mid, int end, int arr[]) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];
    for (int i= 0 ; i < n1; i++) { left[i] = arr[start + i]; }
    for (int j = 0 ; j < n2; j++) { right[j] = arr[mid + 1 + j]; }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            comparison_count++;
            arr[k++] = left[i++];
        } 
        else {
            comparison_count+=2;
            arr[k++] = right[j++];
        }
        swap_count++;
    }
    while (i < n1) {arr[k++] = left[i++]; swap_count++;}
    while (j < n2) {arr[k++] = right[j++]; swap_count++;}
}
void merge_sort(int start,int end, int arr[]) {
    if (start >= end) return;
    int mid = (int) (start+end)/2;
    merge_sort(start, mid, arr);
    merge_sort(mid+1, end, arr);
    merge(start, mid, end, arr);
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
            comparison_count++;
            swap(&arr[lowerLimit], &arr[i]);
            i++; lowerLimit++;
        }
        else if (arr[i] > pivot) {
            comparison_count+=2;
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

void displaySteps() {
    printf("Comparisons: %d\n", comparison_count);
    printf("Swaps/moves: %d\n", swap_count);    
    comparison_count = swap_count = 0;
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of array to sort: ");
    scanf("%d",&n);

    int arr[n], temp[n];
    printf("Enter the items: \n");
    for (int i = 0; i < n; i++) {
        printf("Item-%d: ", i+1);
        scanf("%d",&arr[i]);
        temp[i] = arr[i];
    } printf("\n");

    bubbleSort(n, arr);
    printf("Bubble sort:\n");
    displaySteps();

    for (int i = 0; i < n; i++) arr[i] = temp[i];
    insertionSort(n, arr);
    printf("Insertion sort:\n");
    displaySteps();

    for (int i = 0; i < n; i++) arr[i] = temp[i];
    merge_sort(0, n-1, arr);
    printf("Merge sort:\n");
    displaySteps();

    for (int i = 0; i < n; i++) arr[i] = temp[i];
    quickSort(0, n-1, arr);
    printf("Quick sort:\n");
    displaySteps();    

    printf("Array after sorting: \n"); // display once
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
    
    return 0;
}
