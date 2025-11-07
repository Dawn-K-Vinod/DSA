// Merge sort (divide & conquer) (recursive)

#include <stdio.h>

void merge (int start, int mid, int end, int arr[]) {
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int left[n1], right[n2];
    for (int i= 0 ; i < n1; i++) { left[i] = arr[start + i]; }
    for (int j = 0 ; j < n2; j++) { right[j] = arr[mid + 1 + j]; }

    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
        else 
            arr[k++] = right[j++];
    }
    while (i < n1) arr[k++] = left[i++];
    while (j < n2) arr[k++] = right[j++];
}

void merge_sort(int start,int end, int arr[]) {
    if (start >= end) return;
    int mid = (int) (start+end)/2;
    merge_sort(start, mid, arr);
    merge_sort(mid+1, end, arr);
    merge(start, mid, end, arr);
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

    merge_sort(0, n-1, arr); // merge sort
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    } printf("\n");
    
    return 0;
}
