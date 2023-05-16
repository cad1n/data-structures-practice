#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIN 2
#define COL 2

int simpleVectorMatrix() {

    int *mat;
    int i;

    mat = (int *) malloc(LIN * COL * sizeof(int));
    if (mat == NULL) {
        printf("Insufficient memory...\n");
        exit(1);
    }
    for (i = 0; i < LIN * COL; i++) {
        mat[i] = i;
    }

    //access the first row and the second column element
    // function-> k = i*n + j -> i* LIN*COL + j
    // example -> int idx = 0 * LIN*COL + 1

    printf("%d", mat[1]);
    return 0;
}

int multipleVectorMatrix() {
    int **mat, i;

    mat = (int **) malloc(LIN * sizeof(int));
    for (i = 0; i < LIN; i++) {
        mat[i] = (int *) malloc(COL * sizeof(int));
    }

    mat[0][0] = 10;
    mat[0][1] = 20;

    printf("%d\n", mat[0][0]);
    printf("%d\n", mat[0][1]);

    for (i = 0; i < LIN; i++) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}

int charChain(char c) {
    if (c < '0' || c > '9') {
        return 1;
    }
    return 0;
}

int charTest() {
    char name[] = "Steve Jobs";
    int length = strlen(name);
    int i = 0;

    while (name[i] != '\0') {
        printf("%c", name[i]);
        i++;
    }
    printf("\n");
    printf("Char array size: %d", length);
    return 0;
}

typedef struct person{
    int age;
    float weight;
}tperson;

typedef float real;

int dynamicMemoryAccess(){
    tperson *p;

    p = (struct person*) malloc(sizeof (struct person));
    p->age = 25;
    p->weight =76.44;

    printf("Age: %d ", p->age);
    printf("\n");
    printf("Weight: %.2f ", p->weight);

    return 0;
}

int main() {


    //A simple vector matrix
    simpleVectorMatrix();
    printf("\n\n");
    printf("--------------------------------------");
    printf("\n");

    //A multiple vector matrix, involving an array of pointers
    multipleVectorMatrix();
    printf("\n\n");
    printf("--------------------------------------");
    printf("\n");

    //A chain of characters
    printf("%d\n", charChain('8'));
    printf("\n\n");
    printf("--------------------------------------");
    printf("\n");

    //Printing an array of characters, validating and printing only before the end of the array
    charTest();
    printf("\n\n");
    printf("--------------------------------------");
    printf("\n");

    //Dynamically accessing a pointer's memory address and printing its content
    dynamicMemoryAccess();
    printf("\n\n");
    printf("--------------------------------------");
    printf("\n");


    return 0;
}
