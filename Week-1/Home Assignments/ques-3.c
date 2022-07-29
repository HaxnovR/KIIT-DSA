/*WAP to arrange the elements of a dynamic array such that all even numbers
are followed by all odd numbers.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortEvenOdd(int *arr, int n){
    int temp;
    for(int i = 0; i < n - 1; i++){       
        for(int j = 0; j < n - i - 1; j++){          
            if(arr[j] % 2 == 1){               
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int range;
    int* arr;
    printf("Enter the range of array:");
    scanf("%d", &range);
    arr = (int*)malloc(range*sizeof(int));
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 100 - 1;
    }
    printf("Original Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    sortEvenOdd(arr, range);
    printf("\nSorted Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    free(arr);
    return 0;
}