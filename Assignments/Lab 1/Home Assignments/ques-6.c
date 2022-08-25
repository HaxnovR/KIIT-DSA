/*WAP to sort rows of a dynamic matrix having m rows and n columns in
ascending and columns in descending order.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortArray(int **arr, int s){
    int temp;
    for (int k = 0; k < s; k++){
        for(int i = 0; i < s - 1; i++){       
            for(int j = 0; j < s - i - 1; j++){          
                if(arr[k][j] > arr[k][j + 1]){               
                    temp = arr[k][j];
                    arr[k][j] = arr[k][j + 1];
                    arr[k][j + 1] = temp;
                }
            }
        }
    }
    for (int k = 0; k < s; k++){
        for(int i = 0; i < s - 1; i++){       
            for(int j = 0; j < s - i - 1; j++){          
                if(arr[j][k] > arr[j+1][k]){               
                    temp = arr[j][k];
                    arr[j][k] = arr[j+1][k];
                    arr[j+1][k] = temp;
                }
            }
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