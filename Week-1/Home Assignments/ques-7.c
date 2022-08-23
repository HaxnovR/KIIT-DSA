/*WAP to find out the kth smallest and kth largest element stored in a dynamic
array of n integers, where k<n.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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

void main() {
    srand(time(NULL));
    int range, k;
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
    printf("\nEnter number to check for smallest/largest (k) :");
    scanf("%d", &k);
    if(k>range){
        printf("k shouldn't be greater than n!!!");return;
    }
    BubbleSort(arr, range);
    printf("\nSorted Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    printf("\n%d Smallest element: %d",k, arr[k-1]);
    printf("\n%d Largest element: %d",k, arr[range-k]);
    free(arr);
    return;
}