// WAP to sort adynamic array of n numbers.

#include<stdio.h>
#include<stdlib.h>

void BubbleSort(int *arr, int n){
    int temp;
    for(int i = 0; i < n - 1; i++){       
        for(int j = 0; j < n - i - 1; j++){          
            if(arr[j] > arr[j + 1]){               
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
    printf("Enter the range of array:");
    scanf("%d", &range);
    int arr[range];
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 100 - 1;
    }
    printf("\nOriginal Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    BubbleSort(arr, range);
    printf("\nSorted Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}