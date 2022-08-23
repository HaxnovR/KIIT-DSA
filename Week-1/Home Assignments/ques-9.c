/*You are given an array of 0s and 1s in random order. Segregate 0s on left
side and 1s on right side of the array. Traverse array only once.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void sortOnesZeros(int *arr, int n){
    int count = 0;;
    for (int i = 0; i < n ; i++){
        if(arr[i] == 0)count++;
    }
    for (int i = 0; i < n; i++){
        if(i<count)arr[i] = 0;
        else arr[i] = 1;
    }
}

void main() {
    srand(time(NULL));
    int range;
    int* arr;
    printf("Enter the range of array:");
    scanf("%d", &range);
    arr = (int*)malloc(range*sizeof(int));
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 2;
    }
    printf("Original Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    sortOnesZeros(arr, range);
    printf("\nSorted Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    free(arr);
    return;
}