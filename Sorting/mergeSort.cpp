#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;

void merge(int a[], int beg, int mid, int end){
    int x = mid - beg + 1;
    int y = end - mid;
    int l[x], r[y];

    for (int i = 0; i < x; i++){
        l[i] = a[beg+i];
    }
    for (int i = 0; i < y; i++){
        l[i] = a[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = beg;

    while (i < x && j < y){    
        if(l[i] <= r[j]){    
            a[k] = l[i];    
            i++;    
        }    
        else{    
            a[k] = r[j];    
            j++;    
        }    
        k++;    
    }    
    while (i < x) {
        a[k] = l[i];
        i++;
        k++;
    }

    while (j < y) {
        a[k] = r[j];
        j++;
        k++;
    }

}

void mergeSort(int a[], int beg, int end){
    if(beg < end){
        int mid = (beg + end)/2;
        mergeSort(a, beg, mid);
        mergeSort(a, mid+1, end);
        merge(a, beg, mid, end);
    }
}

void printArray(int a[]){
    for (int i = 0; i < 100; i++){
        cout << a[i] << " ";
    }
}

int main(){
    srand(time(NULL));
    int a[100];
    for (int i = 0; i < 100; i++){
        a[i] = rand() % 100 - 1;
    }
    printf("Array before sorting:\n");
    printArray(a);
    printf("\nArray after sorting:\n");
    mergeSort(a, 0, 99);
    printArray(a);
    
    return 0;
}