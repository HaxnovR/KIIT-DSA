#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}node;
node *head, *ref;

void create(int n){
    int num;
    head = (node *)malloc(sizeof(node));
    printf("Enter data for node 1:");
    scanf("%d",&num);
    head->data = num;
    head->prev = NULL;
    head->next = NULL;
    ref = head;
    for (int i = 2; i <= n; i++){
        node *temp = (node *)malloc(sizeof(node));
        printf("Enter data for node %d:", i);
        scanf("%d",&num);
        temp->data = num;
        temp->prev = ref;
        temp->next = NULL;

        ref->next = temp;
        ref = temp;
    }
}

void display(){
    node *temp = head;
    while(temp != NULL){
        printf(" %d |", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void sort(){
    node *temp = head;
    while(temp != NULL){
        node *next = temp->next;
        while (next != NULL){
            if(temp->data>next->data){
                int x = temp->data;
                temp->data = next->data;
                next->data = x;
            }
            next = next->next;
        }
        temp = temp->next;
    }
}


void delete(int pos){
    node *temp = head;
    int count = 1;
    while(temp != NULL){
        node *next = temp->next;
        node *prev = temp->prev;
        if(count == pos){
            next->prev = prev;
            prev->next = next;
            break;
        }
        temp = temp->next;
        count++;
    }
}

void delete_duplicates(){
    node *temp = head;
    node *next = temp->next;
    int count = 1;
    while(temp != NULL){
        if(temp->data==next->data){
            printf("%d == %d | %d\n",temp->data,next->data,count);
            delete(count);
        }
        count++;
        temp = temp->next;
        next = next->next;
    }
}

int main(){
    printf("Enter the number of elements to store:");
    int n;
    scanf("%d", &n);

    create(n);
    display();
    sort();
    display();
    delete_duplicates();
    display();
    printf("end");

    return 0;
}