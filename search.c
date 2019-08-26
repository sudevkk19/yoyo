#include<stdio.h>
void linears(int a[],int n,int b)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]==b)
		{
			printf(" Element found at positon %d",(i+1));
			return;		
		}
	}
	printf("\nElement not found\n ");
}
void sorter(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}			
void binaryl(int a[],int n,int b)
{
	int l,u,m;
	l=0;
	u=n;
	while(l<=u)
	{
		m=(l+u)/2;
		if(b==a[m])
		{
			printf(" Element found at position %d",(m+1));
			break;
		}
		else if(b<a[m])
			u=m-1;
		else if(b>a[m])
			l=m+1;
		
		else
		{
			printf(" Element not found ");
			break;
		}				
	}
}
void binaryr(int a[],int l,int u,int b)
{
	int m;	
	if(l>u) 
		printf(" Element not found ");
	else
	{
		m=(l+u)/2;
		if(b==a[m])
			printf(" Element found at position %d",(m+1));
		else if(b>a[m])
		{
			l=m+1;
			binaryr(a,l,u,b);
		}
		else if(b<a[m])
		{
			u=m-1;			
		        binaryr(a,l,u,b);
		}
			
	}
}		
void main()
{
	int n;
	printf(" Enter the number of elements in the array : ");
	scanf("%d",&n);
 	int a[100];
	printf(" Ener the elements :\n ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int b;
	printf(" Enter the number to be searched : ");
	scanf("%d",&b);
 	char ch;
	do
	{
		printf(" Enter l for linear or b for binary : ");
		scanf("%c",&ch);
	}while(ch!='l'&&ch!='b');

	if(ch=='l')
		linears(a,n,b);
	else
	{
		do
		{
			printf(" Enter l for loop and r for recursive method : ");
			scanf("%c",&ch);
		}while(ch!='l'&&ch!='r');
		if(ch=='l')
		{
			sorter(a,n);
			binaryl(a,n,b);
		}
		else
		{	
			sorter(a,n);
			binaryr(a,0,n,b);
		}
	}
} 
