#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 10


struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

// Function prototypes
void readDataFromFile(struct person **people, int *n);
void minHeapify(struct person *heap, int heapSize, int i);
void maxHeapify(struct person *heap, int heapSize, int i);
void buildMinHeap(struct person *heap, int heapSize);
void buildMaxHeap(struct person *heap, int heapSize);
void insertMinHeap(struct person **heap, int *heapSize, struct person newPerson);
void deleteOldestPerson(struct person *heap, int *heapSize);
void displayWeightOfYoungest(struct person *heap, int heapSize);
void swap(struct person *a, struct person *b);
void printHeap(struct person *heap, int heapSize);

int main() {
    struct person *heap = NULL;
    struct person *maxHeap = NULL;
    int heapSize = 0;
    int maxHeapSize = 0;
    int option, n = 0;

    while (1) {
        printf("MAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on the age\n");
        printf("3. Create a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                readDataFromFile(&heap, &n);
                heapSize = n;
                break;
            case 2:
                buildMinHeap(heap, heapSize);
                break;
            case 3:
                buildMaxHeap(heap, heapSize);
                break;
            case 4:
                displayWeightOfYoungest(heap, heapSize);
                break;
            case 5:
                // Implement insertion logic here
                break;
            case 6:
                deleteOldestPerson(heap, &heapSize);
                break;
            case 7:
                free(heap);
                exit(0);
        }
    }
}

void readDataFromFile(struct person **people, int *n) {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    int size = INITIAL_SIZE;
    *people = (struct person *)malloc(size * sizeof(struct person));
    if (!*people) {
        printf("Memory allocation failed.\n");
        fclose(file);
        return;
    }

    int i = 0;
    while (fscanf(file, "%d %ms %d %d %d", &(*people)[i].id, &(*people)[i].name, &(*people)[i].age, &(*people)[i].height, &(*people)[i].weight) != EOF) {
        i++;
        if (i >= size) {
            size *= 2;
            *people = (struct person *)realloc(*people, size * sizeof(struct person));
            if (!*people) {
                printf("Memory allocation failed.\n");
                fclose(file);
                return;
            }
        }
    }

    *n = i;
    fclose(file);
}

void minHeapify(struct person *heap, int heapSize, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].age < heap[smallest].age) {
        smallest = left;
    }
    if (right < heapSize && heap[right].age < heap[smallest].age) {
        smallest = right;
    }
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, heapSize, smallest);
    }
}

void maxHeapify(struct person *heap, int heapSize, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].weight > heap[largest].weight) {
        largest = left;
    }
    if (right < heapSize && heap[right].weight > heap[largest].weight) {
        largest = right;
    }
    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, heapSize, largest);
    }
}

void buildMinHeap(struct person *heap, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        minHeapify(heap, heapSize, i);
    }
}

void buildMaxHeap(struct person *heap, int heapSize) {
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        maxHeapify(heap, heapSize, i);
    }
}

void insertMinHeap(struct person **heap, int *heapSize, struct person newPerson) {
    *heapSize += 1;
    *heap = (struct person *)realloc(*heap, *heapSize * sizeof(struct person));
    if (!*heap) {
        printf("Memory allocation failed.\n");
        return;
    }
    (*heap)[*heapSize - 1] = newPerson;

    int i = *heapSize - 1;
    while (i != 0 && (*heap)[(i - 1) / 2].age > (*heap)[i].age) {
        swap(&(*heap)[i], &(*heap)[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteOldestPerson(struct person *heap, int *heapSize) {
    if (*heapSize <= 0) return;
    heap[0] = heap[*heapSize - 1];
    *heapSize -= 1;
    heap = (struct person *)realloc(heap, *heapSize * sizeof(struct person));
    if (!heap) {
        printf("Memory allocation failed.\n");
        return;
    }
    minHeapify(heap, *heapSize, 0);
}

void displayWeightOfYoungest(struct person *heap, int heapSize) {
    if (heapSize == 0) {
        printf("Heap is empty.\n");
        return;
    }
    struct person youngest = heap[0];
    for (int i = 1; i < heapSize; i++) {
        if (heap[i].age < youngest.age) {
            youngest = heap[i];
        }
    }
    printf("Weight of youngest student: %.2f kg\n", youngest.weight * 0.453592);
}

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void printHeap(struct person *heap, int heapSize) {
    for (int i = 0; i < heapSize; i++) {
        printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n", heap[i].id, heap[i].name, heap[i].age, heap[i].height, heap[i].weight);
    }
}

