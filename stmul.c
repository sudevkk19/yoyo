#include<stdio.h>
#include<stdlib.h>
#define max 20
int a[max];
int top1=-1,top2=max;
void push1()
{
	if((top1+1)==top2)
		printf(" No space ! ");
	else
	{
		int x;
		printf("Enter the element to be pushed : ");
		scanf("%d",&x);
		a[++top1]=x;
	}
}
void push2()
{
	if((top2-1)==top1)
		printf(" No space ! ");
	else
	{
		int x;
		printf("Enter the element to be pushed : ");
		scanf("%d",&x);
		a[--top2]=x;
	}
}
void pop1()
{
	if(top1==-1)
		printf(" Stack 1 is empty ! \n");
	else
		printf("The popped element is %d",a[top1--]);
}
void pop2()
{
	if(top2==max)
		printf("Stack 2 is empty ! \n");
	else
		printf("The popped element is %d",a[top2++]);
}
void display1()
{
	if(top1==-1)
		printf(" Stack 1 is empty ! ");
	else
		for(int i=top1;i>=0;i--)
			printf("%d, ",a[i]);
}
void display2()
{
	if(top2==max)
		printf("Stack 2 is empty ! ");
	else 
		for(int i=top2;i<max;i++)
			printf("%d, ",a[i]);
}	
int main()
{
	int ch;
	do
	{
		printf("\n1. Push into stack 1\n2. Push into stack 2\n3. Pop from stack 1\n4. Pop from stack 2\n5. Display stack 1\n6. Display stack 2\n7. Exit\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case  1: push1();
				break;
			case 2: push2();
				break;
			case 3: pop1();
				break;
			case 4: pop2();
				break;
			case 5: display1();
				break;
			case 6: display2();
				break;
			case 7: exit(1);
			default: printf(" Wrong choice ");
		}
	}while(ch>=1&&ch<=7);
}
