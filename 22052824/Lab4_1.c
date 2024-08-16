#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int partitionIndex = partition(arr, low, high);
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
  

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

  
    int* arr_quick = (int*)malloc(n * sizeof(int));
    if (arr_quick == NULL) {
        printf("Memory allocation failed\n");
        free(arr);
        free(arr_qsort);
        return 1;
    }
    for (int i = 0; i < n; i++) {
        arr_quick[i] = arr[i];
    }

    quickSort(arr_quick, 0, n - 1);

    printf("Sorted array using quickSort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr_quick[i]);
    }
    printf("\n");

  
    free(arr);
    free(arr_qsort);
    free(arr_quick);

    return 0;
}

