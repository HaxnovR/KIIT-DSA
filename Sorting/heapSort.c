#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int size = 20;
int bt[20];

void create(int i){
    int x,r;
    printf("\n\nEnter element for root: ");
    scanf("%d",&x);
    bt[0]=x;
    for(r=0;r<i;++r){
        printf("\nEnter data for left child:");
        scanf("%d",&x);
        bt[2*r+1]=x;
        printf("\nEnter data for right child:");
        scanf("%d",&x);
        bt[2*r+2]=x;
    }
}

void print(int i){
    int r;
    printf("\nRoot element: %d",bt[r]);
    for(r=1;r<i;r++){
        printf("\nLeft child: %d is %d ",bt[r],bt[2*r+1]);
        printf("\nRight child: %d is %d ",bt[r],bt[2*r+2]);
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int i){
    int l, r, largest;
    l = 2 * i;
    r = 2 * i + 1;
    largest = i;
    if(l <= size && bt[l] > bt[i]) largest = l;
    if(r <= size && bt[r] > bt[i]) largest = r;
    if(largest != i){
        swap (&bt[i], &bt[largest]);
        maxHeapify(largest);
    }
}

void buildMaxHeap(int n){
    for(int i = floor(n/2); i<=1; i--){
        maxHeapify(i);
    }
}

void HeapSort(int n){
    buildMaxHeap(n);
    for(int i = n; i<=2; i--){
        swap(&bt[1], &bt[i]);
        n = n - 1;
        maxHeapify(i);
    }
}

int main(void){
    int h,leaf;
    system("cls");
    printf("Enter the height of the tree:");
    scanf("%d", &h);
    leaf = pow(2,h);
    int i = leaf - 1;
    printf("\nNo. of Leaf Nodes = %d", leaf);
    printf("\nNo. of internal nodes = %d", i);
    create(i);
    print(i);
    // HeapSort(leaf);
    printf("\n\n");
    bt[0] = 111;
    print(i);
}