/*WAP to find out the second smallest and second largest element stored in
a dynamic array.*/

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
    BubbleSort(arr, range);
    printf("\nSorted Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    printf("\n2nd smallest element: %d", arr[1]);
    printf("\n2nd largest element: %d", arr[range-2]);
    free(arr);
    return 0;
}