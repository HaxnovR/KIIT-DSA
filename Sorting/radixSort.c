#include <stdio.h>  
#define size 100
  
int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max;
}  
  
void countingSort(int a[], int n, int place){  
  int output[n + 1];  
  int count[10] = {0};    
  
  // Calculate count of elements  
  for (int i = 0; i < n; i++)  
    count[(a[i] / place) % 10]++;  
      
  // Calculate cumulative frequency  
  for (int i = 1; i < 10; i++)  
    count[i] += count[i - 1];  
  
  // Place the elements in sorted order  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[(a[i] / place) % 10] - 1] = a[i];  
    count[(a[i] / place) % 10]--;  
  }  
  
  for (int i = 0; i < n; i++)  
    a[i] = output[i];  
}  

void radixsort(int a[], int n) {  
   
  int max = getMax(a, n);  

  for (int place = 1; max / place > 0; place *= 10)  
    countingSort(a, n, place);  
}  

void printArray(int a[]) {  
  for (int i = 0; i < size; ++i) {  
    printf("%d  ", a[i]);  
  }
  printf("\n");  
}  
  
int main() {  
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