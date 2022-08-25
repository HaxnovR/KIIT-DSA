/*Write a program to replace every element in the dynamic array with the
next greatest element present in the same array.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void nextGreatest(int *arr, int n){
    int temp;
    for(int i = 0; i < n - 1; i++){       
        if(arr[i+1] > arr[i]){               
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
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
    nextGreatest(arr, range);
    printf("\nSorted Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    free(arr);
    return 0;
}