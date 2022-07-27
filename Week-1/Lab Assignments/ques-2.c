// WAP to reverse the contents of a dynamic array of n elements.

#include<stdio.h>
#include<stdlib.h>

void ReverseArray(int *arr, int n){
    int temp;
    for (int i = 0; i < n/2; i++){
        temp = arr[i];
        arr[i] = arr[n-i-1];
        arr[n-i-1] = temp;
    } 
}

int main() {
    srand(time(NULL));
    int range;
    printf("Enter the range of array:");
    scanf("%d", &range);
    int arr[range];
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 100 - 1;
    }
    printf("Original Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    ReverseArray(arr, range);
    printf("\nReversed Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}