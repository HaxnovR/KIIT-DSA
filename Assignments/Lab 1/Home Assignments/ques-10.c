/*WAP to swap all the elements in the 1st column with all the corresponding
elements in the last column, and 2nd column with the second last column
and 3rd with 3rd last etc. of a 2-D dynamic array. Display the matrix.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortArray(int **arr, int s){
    int temp;
    for (int i = 0; i < s; i++){
        for (int j = 0; j < s/2; j++){
            temp = arr[i][j];
            arr[i][j] = arr[i][s-j-1];
            arr[i][s-j-1] = temp;
        }  
    }
}

int main(){
    srand(time(NULL));
    int size, **arr;
    printf("Enter the size of square matrix: ");
    scanf("%d", &size);
    arr = (int **)malloc(size*sizeof(int));
    for (int i = 0; i < size; i++){
        arr[i] = (int *)malloc(size*sizeof(int));
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            arr[i][j] = rand() % 10 - 1;
        }
    }
    
    printf("\nGenerated 2-D Array:\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }
    sortArray(arr, size);
    printf("\nSorted Array:\n");
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%d  ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}