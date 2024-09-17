#include "matrix.h"
#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <stdbool.h>

 

#include "matrixlibrary.h"

struct mat {
	int rows;
	int cols;
	union type
	{
	  int i;
	  double d;
	  float f;
	  char c;
	};


};

long valueFromStr(char* rowStr) { //gets the value from prompt 

    if(rowStr != NULL) {

        char* stopstring;

        long l;

        int baseNumber = 10;

        l = strtol(rowStr, &stopstring, baseNumber);

        return l;

    }

    else return 0;

}

 

void parseInputRowValuesVoid(char* inputRowValues) //parses through the row values 

{

    char *token;

    long inputValues[100];

   

    int inputCnt = 0;

    long tmpL;

   

    token = strtok(inputRowValues, ",");

    if(token == NULL){

        printf("Input in empty, nothing to compute!");

    }

    else {

        tmpL = valueFromStr(token);

        inputValues[inputCnt] = tmpL;

        inputCnt = inputCnt + 1;

 

        while(token){

            token = strtok(NULL, ",");

            tmpL = valueFromStr(token);

            inputValues[inputCnt] = tmpL;

            inputCnt = inputCnt + 1;

        }

    }

   

    for(int i = 0; i < inputCnt - 1; i++) {

        printf("%d: ", i);

        printf("%ld\n ", inputValues[i]);

    }

}

 

long parseInputRowValues(char* inputRowValues)

{

 

    printf("Input row values: %s\n", inputRowValues);

   

    char *token;

    long inputValues[100];

   

    int inputCnt = 0;

    long tmpL;

   

    token = strtok(inputRowValues, ",");

    if(token == NULL){

        printf("Input is empty, nothing to compute!");

    }

    else {

        printf("Token: %s\n", token);

        tmpL = valueFromStr(token);

        inputValues[inputCnt] = tmpL;

        inputCnt = inputCnt + 1;

 

        while(token){

            token = strtok(NULL, ",");

            tmpL = valueFromStr(token);

            inputValues[inputCnt] = tmpL;

            inputCnt = inputCnt + 1;

        }

    }

   

    for(int i = 0; i < inputCnt - 1; i++) {

        printf("%d: ", i);

        printf("%ld\n ", inputValues[i]);

    }

   

    return *inputValues;

}

 

char* get_str(FILE* stream)

{

 

    char *s;

    int ix = 0, sz = 1, rf = 0, ch;

 

    if(stream == NULL) {

        s = NULL;

    } else {

        s = (char*)malloc(sizeof(char) * sz);

        if(s != NULL) {

            s[ix] = '\0';

            ch = fgetc(stream);

            while(ch != '\n' && ch != EOF && rf == 0) {

                sz++;

                s = (char*)realloc(s, sizeof(char) * sz);

                if(s != NULL) {

                    s[ix] = ch;

                    ix++;

                    s[ix] = '\0';

                    ch = fgetc(stream);

                } else {

                    rf = 1;

                    free(s);

                    s = NULL;

                }

            }

        }

    }

 

    return s;

}

 

int getNumRowsFromPrompt() { //gets the number of rows from user

    int num_rows;

    printf("\tNumber of rows: ");

    scanf("%d", &num_rows);

    return num_rows;

}

 

int getNumColsFromPrompt() { //gets the number of cols from the user

    int num_cols;

    printf("\tNumber of cols: ");

    scanf("%d", &num_cols);

    return num_cols;

}

 

long getRowValuesFromPrompt(int rowNumber, int size) { //user puts in the row values 

    printf("Enter row %d values: ", rowNumber);

    char *s = get_str(stdin);

 

    printf("Row values: %s\n", s);

    long rowValues = parseInputRowValues(s);

    free(s);

   

    return rowValues;

}

 

long* parseRowValues(char* rowValues, int num_cols) {

    char* ptr;

    long val;

 

    int index = 0;

    // long values[num_cols];

 

    long* values;

    values = (long*)malloc(sizeof(long) *  num_cols);

 

    ptr = strtok(rowValues, ",");

    val = valueFromStr(ptr);

    values[index] = val;

    index = index + 1;

 

    ptr = strtok(NULL, ",");

    while(ptr != NULL) {

        val = valueFromStr(ptr);

        values[index] = val;

        index = index + 1;

        ptr = strtok(NULL, ",");

    }

    return values;

}

 

void makeMatrix(struct mat *matrix) { //

 

    int num_rows = matrix->rows;

    int num_cols = matrix->cols;

 

    long mvalues[num_rows][num_cols];

 

    struct mat *tempMatrix = malloc(sizeof(struct mat));

 

    for(int i = 0; i < num_rows; i++){

 

        printf("Enter row %d values: ", i + 1);

        char inputRowValues[num_cols + 1];

        scanf("%s", inputRowValues);

        printf("Row values: %s\n", inputRowValues);

       
for(int j = 0; j < num_cols; j++){

            long value = rowValues[j];

            mvalues[i][j] = value;

            // printf("Col %d: %ld\n", j, rowValues[j]);

        }

    }
     for(int i = 0; i < num_rows; i++){

        // matrix->data[i] = malloc(num_cols * sizeof(long));

       

        printf("Row %d:", i);

        for(int j = 0; j < num_cols; j++){

            // printf(" %ld", mvalues[i][j]);

            matrix->data[i] = mvalues[i];

            printf(" %p", matrix->data[i]);

        }

        printf("\n");

    }
     printf("\n");

}  void add(){

    int a_num_rows, a_num_cols, b_num_rows, b_num_cols;

    printf("Addition - Matrix A Rows: \n");

    a_num_rows = getNumRowsFromPrompt();

 

    printf("Addition - Matrix A Columns: \n");

    a_num_cols = getNumColsFromPrompt();

 

    printf("Addition - Matrix B Rows: \n");

    b_num_cols = getNumColsFromPrompt();

 

    printf("Addition - Matrix B Columns: \n");

    b_num_rows = getNumRowsFromPrompt();

   

 

   

    // define matrix A struct

    struct mat *matrixA = malloc(sizeof(struct mat));

    matrixA->rows = a_num_rows;

    matrixA->cols = a_num_cols;

    matrixA->data = malloc(a_num_rows * sizeof(void *));

    for (int i = 0; i < a_num_rows; i++) {

        matrixA->data[i] = malloc(a_num_cols * sizeof(void *));

    }

    printf("Addition - Matrix A values: \n");

    makeMatrix(matrixA);

 

    // define matrix B struct

     struct mat *matrixB = malloc(sizeof(struct mat));

    matrixB->rows = b_num_rows;

    matrixB->cols = b_num_cols;

    matrixB->data = malloc(b_num_rows * sizeof(void *));

    for (int i = 0; i < b_num_rows; i++) {

        matrixB->data[i] = malloc(b_num_cols * sizeof(void *));

    }

    printf("Addition - Matrix B values: \n");

    makeMatrix(matrixB);

 

    // int a_size = a_num_rows * a_num_cols;

    // long matrixA[a_size];

 

    // int b_size = b_num_rows * b_num_cols;

    // long matrixB[b_size];

 

    // long matrixResults[a_size];

    // for(int i = 0; i < 2; i++){

    //     // long val = matrixA[i] + matrixB[i];

    //     // matrixResults[i] = val;

    // };

}

 

/*

void substract(){

    int num_rows, num_cols;

    num_rows = getNumRowsFromPrompt();

    num_cols = getNumColsFromPrompt();

   

    int size = num_rows * num_cols;

    long matrixA[size];

    long matrixB[size];

   

    printf("Subtraction - Matrix A values: \n");

    makeMatrix(num_rows, num_cols);

 

    printf("Subtraction - Matrix B values: \n");

    makeMatrix(num_rows, num_cols);

 

    long matrixResults[size];

    for(int i = 0; i < size; i++){

        long val = matrixA[i] - matrixB[i];

        matrixResults[i] = val;

    };

}

*/

/*

void multiply(){

    int num_rows, num_cols;

    num_rows = getNumRowsFromPrompt();

    num_cols = getNumColsFromPrompt();

 

    int size = num_rows * num_cols;

    long matrixA[size];

    long matrixB[size];

   

    printf("Multiply - Matrix A values: \n");

    makeMatrix(num_rows, num_cols);

 

    printf("Multiply - Matrix B values: \n");

    makeMatrix(num_rows, num_cols);

 

    long matrixResults[size];

    for(int i = 0; i < size; i++){

        long val = matrixA[i] - matrixB[i];

        matrixResults[i] = val;

    };

}

*/

int main()

{

   

    int operationSelection;

    bool isOperationSelected = false;

 

    printf("Select matrix operation: \n");

    printf("\t 1.Addition: \n");

    printf("\t 2.Subtraction: \n");

    printf("\t 3.Multiplication: \n");

    printf("\t 99.Exit: \n");

    printf("\n");

   

    while(isOperationSelected == false) {

        scanf("%d", &operationSelection);

        switch(operationSelection){

            case(1): {

                add();

                return 0;

            }

            case(2): {

                break;

            }

            case(3): {

                break;

            }

            case(99): {

                return 0;

                break;

            }

        }

    }

    return 0;

}
