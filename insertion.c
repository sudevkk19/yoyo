#include<stdio.h>
void main()
{
	int a[10],n,i,k;
	printf("Enter the no. of terms : ");
	scanf("%d",&n);
	printf("\nEnter the terms :\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int temp1,count;
	for(i=1;i<n;i++)
	{
		count=0;
		if(a[i]<a[i-1])
		{
			count=1;
			for(int j=i-2;j>=0;j--)
			{
				if(a[i]<a[j])
					count++;
			}
			temp1=a[i];
			for(k=i;k>(i-count);k--)
				a[k]=a[k-1];
			a[k]=temp1;
		}
	}
	printf("\nSorted array : ");
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}		
