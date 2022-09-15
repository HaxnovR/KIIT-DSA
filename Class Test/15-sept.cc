/*
Q1) Create Linked List to recieve your name and display
Q2) Delete vowels and display
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    char data;
    node *next;
}node;

node *head, *ref;

void create(int n){
    head = (node *)malloc(sizeof(node));
    char ch;
    printf("Enter char 1:");
    getchar();
    scanf("%c", &ch);
    head->data = ch;
    head->next = NULL;
    ref = head;
    for (int i = 2; i <= n; i++){
        node *temp = (node *)malloc(sizeof(node));
        printf("Enter char %d:", i);
        getchar();
        scanf("%c", &ch);
        temp->data = ch;
        temp->next = NULL;
        ref->next = temp;
        ref = temp;
    }
}

void display(){
    node *temp = head;
    while (temp != NULL){
        printf("%c", temp->data);
        temp = temp->next;
    }
}

void delete_vowels(){
    node *temp = head;
    while (temp->next != NULL){
        node *next = temp->next;
        char x = next->data;
        if(x == 'a' || x=='e' || x=='i' || x=='o' || x=='u'){
            temp->next = next->next;
        }
        temp = temp->next;
    }
}

int main(){
    printf("Enter length of your name:");
    int len;
    scanf("%d", &len);
    create(len);
    display();
    printf("\n");
    delete_vowels();
    display();
    return 0;
}