// WAP to search an element in a dynamic array of n numbers.

#include<stdio.h>
#include<stdlib.h>

int getPos(int *arr, int n, int num){
    int pos = -1;
    for (int i = 0; i < n-1; i++){
        if(num == arr[i]){
            pos = i;
            return pos;
        }
    }
}

int main() {
    srand(time(NULL));
    int range, query;
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
    printf("\nEnter the number you want to search for: ");
    scanf("%d", &query);
    int position = getPos(arr, range, query);
    if(position == -1)printf("number NOT found in array!!!");
    else printf("Number found in array at position [%d]", position);
    return 0;
}