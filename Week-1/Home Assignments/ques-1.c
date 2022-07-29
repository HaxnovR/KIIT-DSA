/* Given an unsorted dynamic array arr and two numbers x and y, find the
minimum distance between x and y in arr. The array might also contain
duplicates. You may assume that both x and y are different and present in
arr.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int minDistance(int *arr, int n, int x, int y){
    int min;
    for(int i = 0; i < n ; i++){       
        for(int j = i+1; j < n ; j++){
            int temp;
            if(arr[i] == x && arr[j] == y || arr[j] == x && arr[i] == y){
                if(i>j)temp = i-j;
                else temp = j-i;
                if(min>temp){
                    min = temp;
                }
            }
        }
    }
    return min;
}

int main() {
    srand(time(NULL)); 
    int range, x, y;
    int* arr;
    printf("Enter the range of array:");
    scanf("%d", &range);
    arr = (int*)malloc(range*sizeof(int));
    for (int i = 0; i < range; i++){
        arr[i] = rand() % 10 - 1;
    }
    printf("Original Array: \n");
    for (int i = 0; i < range; i++){
        printf("%d  ",arr[i]);
    }
    printf("\nEnter X:");
    scanf("%d", &x);
    printf("Enter Y:");
    scanf("%d", &y);
    minDistance(arr, range, x, y);
    printf("The minimum distance between %d and %d is %d",x,y,minDistance(arr, range, x, y));
    free(arr);
    return 0;
}