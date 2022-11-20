#include<stdio.h>
#include<time.h>

typedef struct list{
	int data;
	struct list *next;
}list;

// void swap(int *xp, int *yp){
// 	int temp = *xp;
// 	*xp = *yp;
// 	*yp = temp;
// }
void selectionSort2080(list *L, int n){
    list *min2080 = L;
    for (int i = 0; i < n; i++){
        list *temp = min2080->next;
        while (temp != NULL){
            if(temp->data < min2080->data){
                min2080->data = temp->data;
            }
            temp = temp->next;
        }
        min2080 = min2080->next;
    }
    return L;
}

void selectionSort2080(int arr[], int n){
	int i, j, min;

	for (i = 0; i < n-1; i++)
	{
		min = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min])
			min = j;

		if(min != i)
			swap(&arr[min], &arr[i]);
	}
}

void printArray(int arr[], int size){
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(){
	srand(time(NULL));
    int a[100];
    for (int i = 0; i < 100; i++){
        a[i] = rand() % 100 - 1;
    }
    printf("Array before sorting:\n");
    printArray(a, 100);
    printf("\nArray after sorting:\n");
    selectionSort2080(a, 100);
    printArray(a, 100);
    
    return 0;
}
