#include<stdio.h>
#include<stdlib.h>
#define max 20
int a[max];
int top=-1;
void push()
{
	int x;
	if((top+1)==max)
		printf("\nNo space. ");
	else
	{
		int x;
		printf(" Enter the value to be pushed : ");
		scanf("%d",&x);
		a[++top]=x;
	}
}
void pop()
{		
	if(top==-1)
		printf(" Stack is empty ! ");
	else 
		printf(" The popped element is %d",a[top--]);
}
void display()
{
	if(top==-1)
		printf(" Stack is empty ! ");
	else
	{
		for(int i=top;i>=0;i--)
			printf("%d, ",a[i]);
	}
}
int main()
{
	int ch;
	do
	{
		printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(1);	
			default:printf(" Wrong option ");
		}
	}while(ch>=1&&ch<=4);
}
