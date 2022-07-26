#include<stdio.h>
#include<stdlib.h>
int *circularQueue;
int front = -1, back = -1, n;


void enqueue(int number){
	if ((front == 0 && back == n-1) || (front == back+1)) {
		printf("The size of the queue exceeded \n");
		return;
	}
	if (front == -1) {
		front = 0;
		back = 0;
	}
	else {
		if (back == n - 1)
			back = 0;
		else
			back = back + 1;
	}
	circularQueue[back] = number ;
}
void dequeue(){
	if (front == -1) {
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element deleted is : %d ", circularQueue[front]);
	if (front == back) {
		front = -1;
		back = -1;
	}
	else {
		if (front == n - 1)
			front = 0;
		else
			front = front + 1;
	}
}


void Peek(){
	if (front == -1) {
		printf("Queue Underflow\n");
		return ;
	}
	printf("Element peek is : %d ", circularQueue[front]);


}


void display(){
	int f = front, r = back;
	if (front == -1) {
		printf("No number in the queue");
		return;
	}
	printf("Queue Contents :\n");
	if (f <= r) {
		while (f <= r){
			printf("%d\n", circularQueue[f]);
			f++;
		}
	}
	else {
		while (f <= n - 1) {
			printf("%d\n",circularQueue[f]);
			f++;
		}
		f = 0;
		while (f <= r) {
			printf("%d\n",circularQueue[f]);
			f++;
		}
	}
}  


int isEmpty(){
	return (front == -1);
}
int isFull(){
	return ((front == 0 && back == n-1) || (front == back+1));
}


int main(){
	int value,choice;
    printf("Enter size of circular queue: ");  
    scanf("%d",&n);
    circularQueue = (int*)malloc(sizeof(int));


	while(1){
		
		printf("1. Add an item to the queue\n");
		printf("2. Delete an item from the queue\n");
		printf("3. Display the queue\n");
		printf("4. Exit\n");
		printf("Select an option:");
		scanf("%d",&choice);
		switch(choice){
		case 1:
			printf("Enter a number: ");
			scanf("%d",&value);
			enqueue(value);
			
			break;
		case 2:
			dequeue();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		default:
			printf("Wrong option");
		}
		printf("\n\n");
	}


	return 0;
}