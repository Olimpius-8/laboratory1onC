#include <stdio.h>
#include <stdlib.h>

int ** enterMatrix(int *sizelines, int *sizecol){
    int **matrix,*col;
    int i, j, n, m;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    matrix = (int**)malloc(n * sizeof(int*));
    col = (int*)malloc(n * sizeof(int)); // массив кол-ва элеменов в строках массива a
    // Ввод элементов массива
    for (i = 0; i<n; i++)
    {
        printf("Введите количество столбцов строки %d: ", i+1);
        scanf("%d", &m);
        col[i] = m;
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j<m; j++) {
            printf("matrix[%d][%d]= ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }
    *sizelines = n;
    sizecol = col;
    return matrix;
}

void printDoubleMatrix(int **matrix, int sizelines, int *sizecolumns){
    int i,j;
    printf("%d lines\n", sizelines);
    for (i = 0; i < sizelines; i++) {
        printf("%d columns of line %d\n", *(sizecolumns+i), i);
        if (i!=0) {
            for (j = 0; j < *(sizecolumns+i); j++)
                printf("%d  \t", *(*(matrix + i*sizecolumns[i-1])+j));
        }
        else{
            for (j = 0; j < *(sizecolumns+i); j++)
                printf("%d  \t", *(*(matrix + i*sizecolumns[i-1])+j));
        }
        printf("\n");
    }
}

void eraseMatrices(int **matrix, /*int *averagematrix, */ int *sizecolumns){
    int i;
    for (i = 0; i < sizecolumns[i]; i++)
        free(matrix[i]);
    //free(averagematrix);
    free(sizecolumns);
    free(matrix);
}

void main(){
    int **sourcematrix;
    //int *averagematrix;
    int sizelines=0;
    int *sizecolumns;
    sourcematrix = enterMatrix(&sizelines, sizecolumns);
    printf("%d lines\n", sizelines);
    printf("%d ", **sourcematrix);
    //printDoubleMatrix(**sourcematrix, sizelines, *sizecolumns);
    /*eraseMatrices(sourcematrix, /*averagematrix*///, sizecolumns);
}
