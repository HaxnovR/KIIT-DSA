/*WAP to replace every dynamic array element by multiplication of previous
and next of an n element*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void multiplyPrevNext(int *arr, int n){
    int temp;
    for(int i = 1; i < n - 2; i++){       
        arr[i] = arr[i]*arr[i-1]*arr[i+1];
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
    multiplyPrevNext(arr, range);
    printf("\nMultiplied Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    free(arr);
    return 0;
}