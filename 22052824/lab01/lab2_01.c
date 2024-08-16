#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n, char *binary, int index) {
    if (n > 0) {
        decimalToBinary(n / 2, binary, index - 1);
        binary[index] = (n % 2) + '0';
    } else if (index >= 0) {
        binary[index] = '0';
        decimalToBinary(n / 2, binary, index - 1);
    }
}

int main() {
    FILE *myFile;
    myFile = fopen("somenumbers.txt", "r");
   

    int n;
    printf("Enter the number of elements to read from the array: ");
    scanf("%d", &n);

    int numberArray[n];
    int i;

    for (i = 0; i < n; i++) {
        fscanf(myFile, "%d", &numberArray[i]);
    }
    
    fclose(myFile);

    FILE *fp;
    fp = fopen("output.txt", "w");
 

   for (int i = 0; i < n; i++) {
        char binary[16] = {0};
        decimalToBinary(numberArray[i], binary, 15);
        fprintf(fp, "%s\n", binary);
    }
    fclose(fp);

    return 0;
}
