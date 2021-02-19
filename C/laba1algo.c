#include <stdio.h>
#include <stdlib.h>

void enterMatrix(int ***source, int **lengths, int *lines,  int **sizecol){
    int **matrix,*col,*lengthmatrix;
    int i, j, n, m,value, maxsize;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    matrix = (int**)malloc(n * sizeof(int*));
    lengthmatrix = (int*)malloc(n * sizeof(int));
    col = (int*)malloc(n * sizeof(int)); // массив кол-ва элеменов в строках массива a
    // Ввод элементов массива

    for (i = 0; i<n; i++)
    {
        printf("Введите количество столбцов строки %d: ", i+1);
        scanf("%d", &m);
        col[i] = m;
        lengthmatrix[i]= 0;
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j<m; j++) {
            printf("matrix[%d][%d]= ", i+1, j+1);
            scanf("%d", &value);
            maxsize = 0;
            matrix[i][j] = value;
            while (value>0) {
                maxsize++;
                value/=10;
            }

            if (maxsize > lengthmatrix[i])
                lengthmatrix[i] = maxsize;
        }
    }
    *lines = n;
    *sizecol = col;
    *source = matrix;
    *lengths = lengthmatrix;
}

void maximusLengthNumberMatrix(int **source,int ***results, int *lengthmatrix, int lines, int *sourcecolumns, int **resultcolumns){
    int i,j,k,length,value;
    int **matrix = (int**)malloc(lines*sizeof(int*));
    int *columns = (int*)malloc(lines*sizeof(int));
    for (i = 0; i < lines; i++) {
        matrix[i] = (int*)malloc(sourcecolumns[i]*sizeof(int));
        //printf("length [%d] = %d", i, lengthmatrix[i]);
        for (k = j = 0; j < sourcecolumns[i]; j++) {
            value = source[i][j];
            length = 0;
            while (value > 0) {
                length++;
                value/=10;
            }
            if (length == lengthmatrix[i]) {
                matrix[i][k++] = source[i][j];
            }
        }
        matrix[i] = (int*)realloc(matrix[i],k);
        columns[i] = k;
    }
    *results = matrix;
    *resultcolumns = columns;
}

void printDoubleMatrix(int **matrix, int lines, int *columns){
    int i,j;
    //printf("%d lines\n", lines);
    for (i = 0; i < lines; i++) {
        //printf("%d sourcecolumns of line %d\n", sourcecolumns[i], i);
        for (j = 0; j < *(columns+i); j++)
            printf("%d  \t", matrix[i][j]);
        printf("\n");
    }
}

void eraseMatrices(int **matrix, int **results, int *lengthmatrix,  int *sourcecolumns, int *resultcolumns){
    int i;
    for (i = 0; i < sourcecolumns[i]; i++) {
        free(matrix[i]);
        free(results[i]);
    }
    free(lengthmatrix);
    free(sourcecolumns);
    free(matrix);
}

void main(){
    int **source;
    int **result;
    int *lengthmatrix;  //матрица с длинами чисел в строке
    int lines;
    int *sourcecolumns; //количество столбцов в каждой строке исходной матрицы
    int *resultcolumns; //количество столбцов в каждой строке результирующей матрицы
    enterMatrix(&source, &lengthmatrix, &lines,  &sourcecolumns);
    printDoubleMatrix(source, lines, sourcecolumns);
    maximusLengthNumberMatrix(source, &result,lengthmatrix,lines,sourcecolumns,&resultcolumns);
    printDoubleMatrix(result, lines, resultcolumns);
    eraseMatrices(source, result, lengthmatrix, sourcecolumns, resultcolumns);
}
