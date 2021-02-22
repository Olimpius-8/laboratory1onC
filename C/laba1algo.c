#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>

typedef struct Line{
    int size;
    double* array;
}Line;

typedef struct Matrix{
    int size;
    Line *matrix;
}Matrix;

int getInt(int *a)
{
    int n;
    do {
        n = scanf("%d", a);
        if (n < 0)
            return 0;
        if (n == 0)
            printf("%s\n", "Error! Repeat input");
    } while (n == 0);
    return 1;
}

int getDouble(double *a){
    int n;
    do {
        n = scanf("%lf", a);
        if (n < 0)
            return 0;
        if (n == 0)
            printf("%s\n", "Error! Repeat input");
    } while (n == 0);
    return 1;
}

void enterMatrix(Matrix *rm, Line *lengths){
    double value;
    char *message = "";
    int i, j, m, maxsize;
    do {
        printf("%s\n", message);
        printf("Enter number of lines: ");
        message = "Incorrect number; repeat, please!";
        getInt(&m);
    } while (m<1);
    rm->size = m;
    rm->matrix = (Line*)calloc(m,sizeof(Line));
    lengths->size = m;
    lengths->array = (double*)calloc(m,sizeof(double));
    //col = (int*)malloc(n * sizeof(int)); // массив кол-ва элеменов в строках массива a
    // Ввод элементов массива
    for (i = 0; i<rm->size; i++)
    {
        //Enter

        message ="";
        do {
            printf("%s\n", message);
            printf("Enter number of items in line %d: --> ", i + 1);
            message = "You are wrong; repeat, please!";
            /*if (getInt(&m) == 0) {
                rm->size = i;
                erase(rm);
            }*/
            getInt(&m);
        } while (m < 1);

        rm->matrix[i].size = m;
        rm->matrix[i].array = (double*)calloc(m,sizeof(double));
        lengths->array[i] = 0.0;
        for (j = 0; j<m; j++) {
            printf("matrix[%d][%d]= ", i+1, j+1);
            /*if (getDouble(p)==0) {
                rm->size = i + 1;
                erase(rm);
            }*/
            getDouble(&value);
            maxsize = 0;
            rm->matrix[i].array[j] = value;
            while (value>1) {
                maxsize++;
                value/=10;
            }
            lengths->array[i] += maxsize;
        }
        lengths->array[i]/=m;

    }
}

void maximusLengthNumberMatrix(Matrix source, Matrix *results, Line lengtharray){
    int i,j,k,length;
    double value;
    results->matrix = (Line*)calloc(source.size,sizeof(Line));
    results->size = source.size;
    for (i = 0; i < source.size; i++) {
        results->matrix[i].array = (double*)malloc(source.matrix[i].size*sizeof(double));
        printf("length [%d] = %5.1lf   \n", i, lengtharray.array[i]);
        for (k = j = 0; j < source.matrix[i].size; j++) {
            value = source.matrix[i].array[j];
            length = 0;
            while (value > 0.5) {
                length++;
                value-=fmod(value,10);
                value/=10;
            }

            if (length > lengtharray.array[j]) {
                results->matrix[i].array[k++] = source.matrix[i].array[j];
            }
        }
        results->matrix[i].array = realloc(results->matrix[i].array,k*sizeof(double));
        results->matrix[i].size = k;
        //printf("%lf  ",results->matrix[i].array[0]);
    }
}

void printDoubleMatrix(Matrix printed){
    int i,j;
    //printf("%d lines\n", lines);
    for (i = 0; i < printed.size; i++) {
        //printf("%d sourcecolumns of line %d\n", sourcecolumns[i], i);
        for (j = 0; j < printed.matrix[i].size; j++)
            printf("%5.1lf  \t", printed.matrix[i].array[j]);
        printf("\n");
    }
}

void erase(Matrix *a){
    int i;
    for (i = 0; i < a->size; ++i) {
        free(a->matrix[i].array);
    }
    free(a->matrix);
    a->size = 0;
    a->matrix = NULL;
}


void eraseMatrices(Matrix *source, Matrix *results, Line *lengtharray){
    erase(source);
    erase(results);
    free(lengtharray->array);
    lengtharray->size=0;
    lengtharray->array =NULL;
}

void main(){

    Matrix source = {0, NULL};
    Matrix result = {0, NULL};
    Line lengtharray = {0, NULL};  //матрица с длинами чисел в строке

    enterMatrix(&source, &lengtharray);
    printf("Source Matrix\n");
    printDoubleMatrix(source);
    maximusLengthNumberMatrix(source, &result, lengtharray);
    printf("Result matrix\n");
    printDoubleMatrix(result);
    eraseMatrices(&source, &result, &lengtharray);
}
