#include<iostream>
#include<stdio.h>
#include<time.h>

#define size 100

using namespace std;

void insertionSort(int arr[]){
    for (int i = 0; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArray(int a[]){
    for (int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
}

int main(){
    srand(time(NULL));
    int a[size];
    for (int i = 0; i < size; i++){
        a[i] = rand() % 100 - 1;
    }
    printf("Array before sorting:\n");
    printArray(a);
    printf("\nArray after sorting:\n");
    insertionSort(a);
    printArray(a);
    
    return 0;
}
