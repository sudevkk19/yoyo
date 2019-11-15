#include<stdio.h>
#include<stdlib.h>

int a[20],n;
void swap(int l, int r)
{
  int temp;
  temp=a[l];
  a[l]=a[r];
  a[r]=temp;
}

int partition(int lb,int ub)
{
  int pivot,left,right;
  pivot=a[lb];
  left=lb;
  right=ub;
  while(left<right)
  {
   while((a[left]<=pivot)&&(left<right))
    left++;
   while((a[right]>pivot)&&(left<right))
    right--;
   if(left<right)
    swap(left,right);
      }
   right--;   
   swap(lb,right);
   return right;
}

void quicksort(int lb,int ub)
{
int p;
 if(lb<ub)
 {
  p=partition(lb,ub);
 
 quicksort(lb,(p-1));
 
 quicksort((p+1),ub); 
 }
}


int main()
{
 int i;
 printf("Enter no of elements: ");
 scanf("%d",&n);
 printf("enter %d elements: \t",n);
 for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  printf("Array is:\t");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]); 
 quicksort(0,(n-1)); 
 printf("\n");
 printf("Sorted Array is:\t");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]);
} 
 
