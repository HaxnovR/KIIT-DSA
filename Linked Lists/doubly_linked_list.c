#include <stdio.h>
#include <stdlib.h>


struct node {
	int info;
	struct node *prev, *next;
};
struct node* start = NULL;
struct node* ennode = NULL;


void traverse_forward(){
	
	if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	
	struct node* temp;
	temp = start;
	while (temp != NULL) {
		//printf("Data = %d\n", temp->info);
        printf("%d ", temp->info);
		temp = temp->next;
	}
}
void traverse_backward(){
	
	if (start == NULL) {
		printf("\nList is empty\n");
		return;
	}
	
	struct node* temp;
	temp = ennode;
	while (temp != NULL) {
        printf("%d ", temp->info);
		temp = temp->prev;
	}
}


void insertAtFront(){
	int data;
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->prev = NULL;

	
	temp->next = start;
	start = temp;
}


void insertAtEnd(){
	int data;
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	temp->info = data;
	temp->next = NULL;
	trav = start;

	
	if (start == NULL) {

		start = temp;
	}

	
	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}


void insertAtPosition(){
	int data, pos, i = 1;
	struct node *temp, *newnode;
	newnode = malloc(sizeof(struct node));
	newnode->next = NULL;
	newnode->prev = NULL;

	
	printf("\nEnter position : ");
	scanf("%d", &pos);
	

	
	if (start == NULL) {
		start = newnode;
		newnode->prev = NULL;
		newnode->next = NULL;
	}

	
	else if (pos == 1) {
	    insertAtFront();
	}

	
	else {
	printf("\nEnter number to be inserted: ");
	scanf("%d", &data);
	newnode->info = data;
	temp = start;
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		newnode->prev = temp;
		temp->next = newnode;
		temp->next->prev = newnode;
	}
}

void deleteFirst(){
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
}


void deleteEnd()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	temp = start;
	while (temp->next != NULL)
		temp = temp->next;
	if (start->next == NULL)
		start = NULL;
	else {
		temp->prev->next = NULL;
		free(temp);
	}
}


void deletePosition(){
	int pos, i = 1;
	struct node *temp, *position;
	temp = start;

	
	if (start == NULL)
		printf("\nList is empty\n");

	
	else {
		
		printf("\nEnter position : ");
		scanf("%d", &pos);

		
		if (pos == 1) {
			deleteFirst(); 
			if (start != NULL) {
				start->prev = NULL;
			}
			free(position);
			return;
		}

		
		while (i < pos - 1) {
			temp = temp->next;
			i++;
		}
		
		position = temp->next;
		if (position->next != NULL)
			position->next->prev = temp;
		temp->next = position->next;

		
		free(position);
	}
}
void DlListcreation(int n)
{
    int i, num;
    struct node *fnNode;
 
    if(n >= 1)
    {
        start = (struct node*)malloc(sizeof(struct node));
 
        if(start != NULL)
        {
            printf(" Input data for node 1 : "); 
            scanf("%d", &num);
 
            start->info = num;
            start->prev = NULL;
            start->next = NULL;
            ennode = start;

            for(i=2; i<=n; i++)
            {
                fnNode = (struct node *)malloc(sizeof(struct node));
                if(fnNode != NULL)
                {
                    printf(" Input data for node %d : ", i);
                    scanf("%d", &num);
                    fnNode->info = num;
                    fnNode->prev = ennode;    
                    fnNode->next = NULL;
 
                    ennode->next = fnNode;   
                    ennode = fnNode;            
                }
                else
                {
                    printf(" Memory can not be allocated.");
                    break;
                }
            }
        }
        else
        {
            printf(" Memory can not be allocated.");
        }
    }
}


int main(void){
    int n; 
    printf("\nEnter total nodes: ");
    scanf("%d",&n);
    DlListcreation(n);
	int choice;
	while (1) {

		printf("\n\t1.To see list\n");
        printf("\t2.To see list backwards\n");
		printf("\t3.For insertion at starting\n");
		printf("\t4.For insertion at end\n");
		printf("\t5.For insertion at any position\n");
		printf("\t6.For deletion of first element\n");
		printf("\t7.For deletion of last element\n");
		printf("\t8.For deletion of element at any position\n");
		printf("\t9.To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse_forward();
			break;
        case 2:
			traverse_backward();
			break;
		case 3:
			insertAtFront();
			break;
		case 4:
			insertAtEnd();
			break;
		case 5:
			insertAtPosition();
			break;
		case 6:
			deleteFirst();
			break;
		case 7:
			deleteEnd();
			break;
		case 8:
			deletePosition();
			break;

		case 9:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
}
