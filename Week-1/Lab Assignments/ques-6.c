// Given a dynamic array, WAP to print the next greater element (NGE) for
// every element. The next greater element for an element x is the first
// greater element  on  the  right  side  of  x  in  array.  Elements  for
//  which  no  greater element exist, consider next greater element as -1.

#include<stdio.h>
#include<stdlib.h>

void nextGreatest(int *arr, int n){
    int temp, greatest;
    printf("\nElement | NGE");
    for(int i = 0; i < n - 1; i++){
        greatest = -1;
        for(int j = i; j < n - 1; j++){          
            if(arr[j] > arr[i]){               
                greatest = arr[j];
                break;
            }
        }
        printf("\n%d        %d", arr[i], greatest);
    }
}

int main() {
    srand(time(NULL));
    int* arr;
    int range;
    printf("Enter the range of array:");
    scanf("%d", &range);
    arr = (int *)malloc(range*sizeof(int));
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 100 - 1;
    }
    printf("Original Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    nextGreatest(arr, range);

    free(arr);
    return 0;
}