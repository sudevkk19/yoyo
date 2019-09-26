#include<stdio.h>
#include<stdlib.h>
struct node
{
	int x;
	struct node* next;
};
struct node* front=NULL,*rear=NULL,*temp,*temp1;
void enqueue()
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
		printf("No space ");
	else
	{
		printf("Enter the data to be inserted : ");
		int d;
		scanf("%d",&d);
		newnode->x=d;
		newnode->next=NULL;
		if(front==NULL)
		{
			front=newnode;
			rear=newnode;
		}
		else
		{
			rear->next=newnode;
			rear=newnode;
		}
	}
}
void dequeue()
{
	if(front==NULL)
		printf("Queue is empty ! ");
	else if(front==rear)
	{
		printf("The element popped is %d",front->x);
		temp=front;
		front=NULL;
		rear=NULL;
		free(temp);
	}
	else
	{
		temp=front;
		front=front->next;
		printf("The element popped is %d",temp->x);
		free(temp);
	}
}
void display()
{
	if(front==NULL)
		printf(" Queue is empty ");
	else
	{
		temp=front;
		while(temp->next!=NULL)	
		{
			printf("%d->",temp->x);
			temp=temp->next;
		}
		printf("%d",temp->x);
	}
}
void main()
{
	printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
	int ch;
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
				break;
			case 2:dequeue();
				break;	
			case 3:display();
				break;
			case 4:exit(1);
			default: printf(" Wrong number inputted ");
		}
	}while(1);
}
