#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
};
struct node* head=NULL;
void push()
{
	struct node* newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(newnode==NULL)
		printf("No space ! ");
	else
	{
		printf("Enter the data to be inserted : ");
		int d;
		scanf("%d",&d);
		newnode->data=d;
		newnode->next=NULL;
		if(head==NULL)
			head=newnode;
		else
		{
			newnode->next=head;
			head=newnode;
		}
	}
}
void pop()
{
	if(head==NULL)
		printf("Stack is empty ");
	else
	{
		struct node* temp;
		temp=head;
		head=head->next;
		printf("The popped element is %d",temp->data);
		free(temp);
	}
}
void display()
{
	if(head==NULL)
		printf("Stack is empty");
	else
	{
		struct node* temp;
		temp=head;
		while(temp->next!=NULL)
		{
			printf("%d->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}	
void main()
{
	printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
	int ch;
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:push();
				break;
			case 2:pop();
				break;	
			case 3:display();
				break;
			case 4:exit(1);
			default: printf(" Wrong number inputted ");
		}
	}while(1);
}
