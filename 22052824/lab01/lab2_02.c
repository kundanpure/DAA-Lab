#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b) {
    while(a != b){
    if(a>b){
    return gcd(a-b,b);
    }
    else {
    return gcd(a,b-a);
    }
    }
    return a;
}


void processArray(int n, int *numberArray, FILE *fp) {
    for (int i = 0; i < n; i=i+2) {
            int result = gcd(numberArray[i], numberArray[i+1]);
            fprintf(fp, "GCD of %d and %d is %d\n", numberArray[i], numberArray[i+1], result);
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
    fp = fopen("output.txt", "w+");
  

    processArray(n, numberArray, fp);

    fclose(fp);

    return 0;
}
