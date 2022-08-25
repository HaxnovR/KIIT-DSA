// Create Linked List
// Display list
// Traverse
// Smallest and Largest

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

// void createList(node **list, int n){
//     node *temp = *list;
//     if(temp == NULL){
//         temp = malloc(sizeof(node));
//         temp->data = n;
//         temp->next = NULL;
//         *list = temp;
//     }
//     else{
//         while(temp->next != NULL){
//             temp = temp->next;
//         }
//         temp->next = malloc(sizeof(node));
//         temp = temp->next;
//         temp->data = n;
//         temp->next = NULL;
//     }
// }

void displayList(node *p){
    while(p != NULL){
        printf("%d->", p->data);
        if(p->next == NULL){
            printf("%d", p->data);
            break;
        }
    }
}

int main(){
    int range, choice;
    printf("Enter the number of Nodes: ");
    scanf("%d", &range);
    struct node *prev, *head=NULL, *p;
    for(int i = 1; i <= range; i++){
        p=(struct node*)malloc(sizeof(struct node));
        p->data = abs(rand() % 99);
        p->next = NULL;
        if(head == NULL){
            head = p;
        }  
        else{
            prev->next=p;
        }
       prev=p;
    }
    
    displayList(head);
    
    return 0;
}