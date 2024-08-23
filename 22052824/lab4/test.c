#include <stdio.h>
#include <stdlib.h>

// Define the structure for a person
struct person {
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};


void readdatafromfile(struct person persons[], int *count) {
    FILE *file = fopen("data.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }

    int i = 0;
    while (fscanf(file, "%d %s %d %d %d", &persons[i].id, persons[i].name, &persons[i].age, &persons[i].height, &persons[i].weight) != EOF) {
        i++;
    }
    *count = i;

    fclose(file);
    printf("Data successfully read from file.\n");
}


void display(struct person persons[], int count) {
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d, Height: %d, Weight: %d\n", 
                persons[i].id, persons[i].name, persons[i].age, 
                persons[i].height, persons[i].weight);
    }
}

int main() {
    struct person persons[100];
    int count = 0;
    int option;

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
                readdatafromfile(persons, &count);
                display(persons, count);
                break;
            case 2:
                // Implement Min-heap based on age
                break;
            case 3:
                // Implement Max-heap based on weight
                break;
            case 4:
                // Display weight of the youngest person
                break;
            case 5:
                // Insert a new person into the Min-heap
                break;
            case 6:
                // Delete the oldest person
                break;
            case 7:
                exit(0);
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}
