#include <stdio.h>
#include <stdlib.h>

struct Queue {
	int front, rear, size;
	unsigned capacity;
	int* array;
};

struct Queue* createQueue(unsigned capacity)
{
	struct Queue* queue = (struct Queue*)malloc(
		sizeof(struct Queue));
	queue->capacity = capacity;
	queue->front = queue->size = 0;

	queue->rear = capacity - 1;
	queue->array = (int*)malloc(
		queue->capacity * sizeof(int));
	return queue;
}

int isFull(struct Queue* queue){
	return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue){
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item){
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1)
				% queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	printf("%d enqueued to queue\n", item);
}

int dequeue(struct Queue* queue){
	if (isEmpty(queue))
		return 0;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1)
				% queue->capacity;
	queue->size = queue->size - 1;
	return item;
}

int front(struct Queue* queue){
	if (isEmpty(queue))
		return 0;
	return queue->array[queue->front];
}

int rear(struct Queue* queue){
	if (isEmpty(queue))
		return 0;
	return queue->array[queue->rear];
}

void display(struct Queue* queue){
    for (int i = 0; i < queue->size; i++)    {
        printf("%d  ", queue->array[i]);
    }
}

int main(){
    printf("Enter the size of queue:");
    int size,choice,item;
    scanf("%d", &size);
	struct Queue* queue = createQueue(size);
    while (1)    {
        printf("\n\n1. To Queue an item.");
        printf("\n2. To Dequeue an item.");
        printf("\n3. To peek an item.");
        printf("\n4. To display elements.");
        printf("\n5. To check if Full.");
        printf("\n6. To check if Empty.");
        printf("\n7. Exit.");
        printf("\n\nEnter Choice:\n");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("Enter item to queue:");
            scanf("%d", &item);
            enqueue(queue, item);
            break;
        case 2:
            item = dequeue(queue);
            printf("Dequeued item %d", item);
            break;
        case 3:
            printf("First Element = %d", queue->front);
            break;
        case 4:
            display(queue);
            break;
        case 5:
            if(isFull(queue))printf("Queue is Full!");
            else printf("Not Full");
            break;
        case 6:
            if(isEmpty(queue))printf("Queue is Empty!");
            else printf("Not Empty");
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("Invalid Choice. Try Again!");
            break;
        }
    }
    

	return 0;
}
