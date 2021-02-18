#include <stdio.h>
#include <stdlib.h>

void enterMatrix(int ***source, int **lengthmatrix, int *sizelines,  int **sizecol){
    int **matrix,*col;
    int i, j, n, m,value, maxsize;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    matrix = (int**)malloc(n * sizeof(int*));
    col = (int*)malloc(n * sizeof(int)); // массив кол-ва элеменов в строках массива a
    // Ввод элементов массива
    lengthmatrix = (int*)malloc(n * sizeof(int));
    for (i = 0; i<n; i++)
    {
        printf("Введите количество столбцов строки %d: ", i+1);
        scanf("%d", &m);
        col[i] = m;
        maxsize = 0;
        lengthmatrix[i]= 0;
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j<m; j++) {
            printf("matrix[%d][%d]= ", i+1, j+1);
            scanf("%d", &value);
            matrix[i][j] = value;
            while (value>0){
                maxsize++;
                value/=10;
            }
            if (maxsize > lengthmatrix[i])
                lengthmatrix[i] = maxsize;
        }
    }
    *sizelines = n;
    *sizecol = col;
    *source = matrix;
}

void insertMaximumLengthNumber(int **source, int *lengthmatrix, int sizelines, int *sizecolumns){

}

void printDoubleMatrix(int **matrix, int sizelines, int *sizecolumns){
    int i,j;
    //printf("%d lines\n", sizelines);
    for (i = 0; i < sizelines; i++) {
        //printf("%d columns of line %d\n", sizecolumns[i], i);
        for (j = 0; j < *(sizecolumns+i); j++)
            printf("%d  \t", matrix[i][j]);
        printf("\n");
    }
}

void eraseMatrices(int **matrix, int *lengthmatrix,  int *sizecolumns){
    int i;
    for (i = 0; i < sizecolumns[i]; i++)
        free(matrix[i]);
    free(lengthmatrix);
    free(sizecolumns);
    free(matrix);
}

void main(){
    int **source;
    int *lengthmatrix;
    int sizelines=0;
    int *sizecolumns;
    enterMatrix(&source, &lengthmatrix, &sizelines,  &sizecolumns);
    printDoubleMatrix(source, sizelines, sizecolumns);

    printf("%d\n", source[0][0]);
    printf("%d", sizecolumns[0]);
    eraseMatrices(source, lengthmatrix, sizecolumns);
    printf("%d\n", source[0][0]);
    printf("%d\n", sizecolumns[0]);
}
