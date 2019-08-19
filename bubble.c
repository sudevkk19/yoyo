#include<stdio.h>
void main()
{
	int a[10];
	int i,n;
	printf("Enter no. of terms : ");
	scanf("%d",&n);
	printf("\nEnter the terms :\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int temp;
	for(i=0;i<n-1;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}	
