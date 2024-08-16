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
    FILE *myFile = fopen("input.txt", "r");
    

    int n;
    printf("Enter the number of elements to read from the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        if (fscanf(myFile, "%d", &arr[i]) != 1) {
            fclose(myFile);
            
            return EXIT_FAILURE;
        }
    }
    
    fclose(myFile);

    int arr_quick[n];
    for (int i = 0; i < n; i++) {
        arr_quick[i] = arr[i];
    }

    quickSort(arr_quick, 0, n - 1);

    printf("Sorted array using quickSort: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr_quick[i]);
    }
    printf("\n");

    FILE *fp = fopen("output.txt", "w+");
    if (fp == NULL) {
       
        return EXIT_FAILURE;
    }

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", arr_quick[i]);
    }

    fclose(fp);

    return EXIT_SUCCESS;
}

