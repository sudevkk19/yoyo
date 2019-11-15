#include<stdio.h>
int a[18];
void swap(int l, int r)
{
  int temp;
  temp=a[l];
  a[l]=a[r];
  a[r]=temp;
}

void heapify(int i, int n)
{
  int largest,lc,rc;
  largest=i;
  lc=2*i+1;
  rc=2*i+2;
  if((a[lc]>a[largest])&&lc<n)
   largest=lc;
  if((a[rc]>a[largest])&&rc<n)
   largest=rc;
  if(i!=largest)
  {
  swap(i,largest);
  /* int temp;
   temp=a[i];
   a[i]=a[largest];
   a[largest]=temp;*/  
 heapify(largest,n);
  }
 }     
 
void heapsort(int n)
{
 int i;
 for(i=n/2-1;i>=0;i--)
  heapify(i,n);
 for(i=n-1;i>=0;i--)
 {
  swap(0,i);
    /* int temp;
   temp=a[0];
   a[0]=a[i];
   a[i]=temp; */
  heapify(0,i);
  }
 }  
 
int main()
{
  int n,i;
printf("Enter no of elements in the array: ");
scanf("%d",&n);
printf("Enter %d elements\t",n);
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("Array is:\t");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]);
 printf("\nsorted array is:\t"); 
 heapsort(n);
for(i=0;i<n;i++)
 printf("%d\t",a[i]);
}
 
  
