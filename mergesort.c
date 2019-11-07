#include<stdio.h>
#include<stdlib.h>
void merge(int a[],int lb,int mid,int ub)
{
	int i=0;
	int j=mid+1;
	int k=0;
	int temp[50];
	while(i<=mid&&j<=ub)
	{
		if(a[i]>a[j])
			temp[k++]=a[j++];
		else if(a[j]>a[i])
			temp[k++]=a[i++];
		else
		{
			temp[k++]=a[i++];
			temp[k++]=a[j++];
		}
	}
	while(i<=mid)
		temp[k++]=a[i++];
	while(j<=ub)
		temp[k++]=a[i++];
	for(i=lb,k=0;i<=ub;i++,k++)
		a[i]=temp[k];
}
void mergesort(int ar[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergesort(ar,lb,mid);
		mergesort(ar,mid+1,ub);
		merge(ar,lb,mid,ub);
	}
}
void main()
{
	int ar[50];
	printf("Enter the no. of elements : ");
	int n;
	scanf("%d",&n);
	printf("Enter the elements : ");
	for(int i=0;i<n;i++)
		scanf("%d",&ar[i]);
	mergesort(ar,0,n-1);
	printf("\n");
	for(int i=0;i<n;i++)
		printf("%d",ar[i]);
}
	
