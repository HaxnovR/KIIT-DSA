#include<stdio.h>
#include<stdlib.h>

typedef struct poly{
    int data;
    struct poly *next;
}poly;

poly CreateList(int n){
    int num; poly *ref;
    poly *head = (poly *)malloc(sizeof(poly));
    printf("Enter data for node x^%d:", n);
    scanf("%d",&num);
    head->data = num;
    head->next = NULL;
    ref = head;
    for (int i = n-1; i >= 0; i--){
        poly *temp = (poly *)malloc(sizeof(poly));
        printf("Enter data for x^%d:", i);
        scanf("%d",&num);
        temp->data = num;
        temp->next = NULL;
        ref->next = temp;
        ref = temp;
    }
    return *head;
}

poly add(poly *a, poly *b, poly *c){
    int num; poly *ref;
    poly *head = (poly *)malloc(sizeof(poly));
    num = a->data + b->data + c->data;
    head->data = num;
    head->next = NULL;
    ref = head;
    a = a->next;
    b = b->next;
    c = c->next;
    while(a != NULL){
        poly *temp = (poly *)malloc(sizeof(poly));
        num = a->data + b->data + c->data ;
        temp->data = num;
        temp->next = NULL;
        ref->next = temp;
        ref = temp;
        a = a->next;
        b = b->next;
        c = c->next;
    }
    return *head;
}

void displayList(poly *head, int n){
    poly *temp = head;
    while(temp != NULL){
        printf("%dx^%d", temp->data, n);
        temp = temp->next;
        if(n!=0)printf(" + ");
        n--;
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter Size of Polynomials:");
    scanf("%d", &n);
    poly x = CreateList(n);
    poly y = CreateList(n);
    poly z = CreateList(n);
    displayList(&x, n);
    displayList(&y, n);
    displayList(&z, n);
    poly final = add(&x, &y, &z);
    displayList(&final, n);
    return 0;
}