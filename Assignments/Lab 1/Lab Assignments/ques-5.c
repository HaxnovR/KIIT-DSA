// Given an unsorted dynamic array of size n, WAP to find and display
// the number of elements between two elements a and b (both inclusive). 
// E.g. Input : arr = [1, 2, 2, 7, 5, 4], a=2 and b=5, Output : 4 and 
// the numbers are: 2, 2, 5, 4.

#include<stdio.h>
#include<stdlib.h>

int getElements(int *arr, int n, int a, int b){
    int num, x, y;
    for(int i = 0; i < n - 1; i++){       
        if(arr[i] == a) x = i;
        if(arr[i] == b) y = i;
    }
    return(y-x+1);
}

int main() {
    srand(time(NULL));
    int range,start,end, elements;
    printf("Enter the range of array:");
    scanf("%d", &range);
    int arr[range];
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 100 - 1;
    }
    printf("Generated Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    printf("\nEnter the starting number:");
    scanf("%d", &start);
    printf("Enter the ending number:");
    scanf("%d", &end);

    elements = getElements(arr, range, start, end);
    printf("The number of elements are = %d", elements);

    return 0;
}