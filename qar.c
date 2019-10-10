#include<stdio.h>
#include<stdlib.h>
#define max 5
int ar[max];
int front=-1,rear=-1;
void enqueue()
{
	if(rear==(max-1))
		printf("Queue is Full ! ");
	else
	{
		int n;
		printf("Enter the element : ");
		scanf("%d",&n);
		if(rear==-1)
		{
			front=0;
			rear=0;
			ar[rear]=n;
		}
		else
			ar[++rear]=n;
	}
}
void dequeue()
{
	if(front==-1)
		printf("Queue is empty !");
	else
	{
		printf(" The dequeued element is : %d",ar[front]);
		if((front+1)>rear)
			front=rear=-1;
		else
			front++;
	}
	printf("\n");
}
void display()
{
	if(rear==-1)
		printf("Queue is empty ! \n");
	else
	{
		for(int i=front;i<=rear;i++)
			printf("%d, ",ar[i]);
	}
}	
void main()
{
	int n;
	printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit");
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:enqueue();
					break;
			case 2:dequeue();
					break;
			case 3:display();
					break;
			case 4:exit(1);
			default:printf("Wrong choice ! \n");
		}
	}while(1);
}
	
