#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int data;
    struct node *ptr;
}*front,*rear,*temp,*front1;

int count = 0;

void create(){
    front = rear = NULL;
}
 

void queuesize(){
    printf("\n Queue size : %d", count);
}
 

void enqueue(int data){
    if (rear == NULL)
    {
        rear = (struct node *)malloc(1*sizeof(struct node));
        rear->ptr = NULL;
        rear->data = data;
        front = rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
        rear->ptr = temp;
        temp->data = data;
        temp->ptr = NULL;
 
        rear = temp;
    }
    count++;
}
 

void display(){
    front1 = front;
 
    if ((front1 == NULL) && (rear == NULL))
    {
        printf("Queue is empty");
        return;
    }
    while (front1 != rear)
    {
        printf("%d ", front1->data);
        front1 = front1->ptr;
    }
    if (front1 == rear)
        printf("%d", front1->data);
}
 

void dequeue(){
    front1 = front;
 
    if (front1 == NULL)
    {
        printf("\n Error: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->ptr != NULL)
        {
            front1 = front1->ptr;
            printf("\n dequeueued value : %d", front->data);
            free(front);
            front = front1;
        }
        else
        {
            printf("\n dequeueued value : %d", front->data);
            free(front);
            front = NULL;
            rear = NULL;
        }
        count--;
}
 

int frontelement(){
    if ((front != NULL) && (rear != NULL))
        return(front->data);
    else
        return 0;
}
 

void empty(){
     if ((front == NULL) && (rear == NULL))
        printf("\n Queue empty");
    else
       printf("Queue not empty");
}

void main(){
    int val, choice, e;
 
    
    create();
    while (1)
    {
        printf("\n 1 - enqueueue");
        printf("\n 2 - dequeueue");
        printf("\n 3 - Front element");
        printf("\n 4 - Empty");
        printf("\n 5 - Exit");
        printf("\n 6 - Display");
        printf("\n 7 - Queue size");
        printf("\n Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &val);
            enqueue(val);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            e = frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
    return 0;
}