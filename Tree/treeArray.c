#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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
    for(r=0;r<i;++r){
        if(i==0){
            printf("\nRoot element: %d",bt[r]);
        }
        printf("\nLeft child: %d is %d ",bt[r],bt[2*r+1]);
        printf("\nRight child: %d is %d ",bt[r],bt[2*r+2]);
    }
}

int main(void){
    int h,leaf;
    printf("Enter the height of the tree:");
    scanf("%d", &h);
    leaf = pow(2,h);
    int i = leaf - 1;
    printf("\nNo. of Leaf Nodes = %d", leaf);
    printf("\nNo. of internal nodes = %d", i);
    create(i);
    print(i);
}