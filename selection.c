#include<stdio.h>
void main()
{
	int a[10];
	int n,i;
	printf("Enter the no. of terms : ");
	scanf("%d",&n);
	printf("Enter the terms:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int pos,temp;
	for(i=0;i<n;i++)
	{
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[pos])
				pos=j;
		}
		temp=a[i];
		a[i]=a[pos];
		a[pos]=temp;
	}
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
