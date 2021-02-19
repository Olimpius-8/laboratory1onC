#include <stdio.h>
#include <stdlib.h>

typedef struct Line{
    int size;
    double* array;
}Line;

typedef struct Matrix{
    int size;
    Line *matrix;
}Matrix;

void enterMatrix(Matrix *rm, Line *lengths){
    double *p;
    int i, j, n,m, value, maxsize;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    rm->size = n;
    rm->matrix = (Line*)calloc(n,sizeof(Line));
    lengths->array = (double*)calloc(n,sizeof(double));
    //col = (int*)malloc(n * sizeof(int)); // массив кол-ва элеменов в строках массива a
    // Ввод элементов массива
    for (i = 0; i<rm->size; i++)
    {
        printf("Введите количество столбцов строки %d: ", i+1);
        scanf("%d", &n);
        rm->matrix[i].size = n;
        rm->matrix[i].array = (double*)calloc(m,sizeof(int));
        for (j = 0; j<n; j++) {
            printf("matrix[%d][%d]= ", i+1, j+1);
            scanf("%d", &value);
            maxsize = 0;
            rm->matrix[i].array[j] = value;
            while (value>0) {
                maxsize++;
                value/=10;
            }
            lengths->array[i] += maxsize;
        }
        lengths->array[i]/=m;
    }
}

void maximusLengthNumberMatrix(Matrix *source, Matrix *results, Line *lengtharray){
    int i,j,k,length,value;
    results->matrix = (Line*)calloc(source->size,sizeof(Line));
    for (i = 0; i < source->size; i++) {
        results->matrix[i].array = (double*)malloc(source->matrix[i].size*sizeof(double));
        //printf("length [%d] = %d", i, lengtharray[i]);
        for (k = j = 0; j < source->matrix[i].size; j++) {
            value = source->matrix[i].array[j];
            length = 0;
            while (value > 0) {
                length++;
                value/=10;
            }
            if (length > lengtharray->array[j]) {
                results->matrix[i].array[k++] = source->matrix[i].array[j];
            }
        }
        results->matrix[i].array = realloc(results->matrix[i].array,sizeof(double));
        results->matrix[i].size = k;
    }
}

void printDoubleMatrix(Matrix *printed){
    int i,j;
    //printf("%d lines\n", lines);
    for (i = 0; i < printed->size; i++) {
        //printf("%d sourcecolumns of line %d\n", sourcecolumns[i], i);
        for (j = 0; j < printed->matrix[i].size; j++)
            printf("%5.2f  \t", printed->matrix[i].array[j]);
        printf("\n");
    }
}

void eraseMatrices(Matrix *source, Matrix *results, Line *lengtharray){
    int i;
    for (i = 0; i < source->size; i++) {
        free(source->matrix[i].array);
        free(results->matrix[i].array);
    }
    free(source->matrix);
    free(results->matrix);
    free(lengtharray->array);
    source->size = 0;
    results->size = 0;
    lengtharray->size=0;
    source->matrix=NULL;
    results->matrix=NULL;
    lengtharray->array =NULL;
}

void main(){

    Matrix *source = {0, NULL};
    Matrix *result = {0,NULL};
    Line *lengtharray = {0, NULL};  //матрица с длинами чисел в строке

    enterMatrix(source, lengtharray);
    printf("Source Matrix\n");
    printDoubleMatrix(source);
    maximusLengthNumberMatrix(source, result,lengtharray);
    printf("Result matrix\n");
    printDoubleMatrix(result);
    eraseMatrices(source, result, lengtharray);
}
