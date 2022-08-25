/*WAP to find the largest number and counts the occurrence of the largest
number in a dynamic array of n integers using a single loop.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void findLargest(int *arr, int n){
    int largest = -1;
    int count = 0;
    for (int i = 0; i < n; i++){
        if(arr[i] == largest){
            count++;
        }
        if(arr[i] > largest){
            count = 1;
            largest = arr[i];
        }
    }
    printf("\nThe Largest Number is %d", largest);
    printf("\nThe count of the Largest number is %d", count);   
}

void main() {
    srand(time(NULL));
    int range;
    int* arr;
    printf("Enter the range of array:");
    scanf("%d", &range);
    arr = (int*)malloc(range*sizeof(int));
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 20 - 1;
    }
    printf("Original Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    findLargest(arr, range);
    free(arr);
    return;
}