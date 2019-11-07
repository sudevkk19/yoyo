#include<stdio.h>
#include<stdlib.h>
int ar[20];
void swap(int i,int j)
{
	int temp=ar[i];
	ar[i]=ar[j];
	ar[j]=temp;
}

int quicks(int lb,int ub)
{
	int pivot=ar[lb];
	int left=lb,right=ub;
	int flag=0;
	while(left<right)
	{
		while((ar[left]<=pivot)&&left<right)
		{
			flag=1;
			left++;
		}
		while((ar[right]>pivot)&&left<right)
		{
			flag=1;
			right--;
		}
		if(left<right)
			swap(left,right);
	} 
	
	swap(lb,right);
	return right;
}
void quicksort(int lb,int ub)
{
	int p;
	if(lb<ub)
	{
		p=quicks(lb,ub);
		quicksort(lb,p-1);
		quicksort(p+1,ub);
	}
}
void main()
{
	printf(" Enter the size of the array : ");
	int n;
	scanf("%d",&n);
	printf(" Enter the elements :\n");
	for(int i=0;i<n;i++)
		scanf("%d",&ar[i]);
	int k,j;
	quicksort(0,n-1);
	printf(" Sorted array : ");
	for(int i=0;i<n;i++)
		printf("%d,",ar[i]);
}
	
	 
		
