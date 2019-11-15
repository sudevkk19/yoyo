#include<stdio.h>

void merge(int a[],int lb, int mid,int ub)
{
 int i,j,k,temp[18];
 i=lb;
 j=mid+1;
 k=0;
 while((i<=mid)&&(j<=ub))
 { 
  if(a[i]<a[j])
  {
   temp[k]=a[i];
   k++;
   i++;
  }
  else if(a[j]<a[i])
  {
   temp[k]=a[j];
   k++;
   j++;
  }
  else
  {
   temp[k]=a[i];
   temp[k]=a[j];
   k++;
   i++;
   j++;
   }
 
}
while(i<=mid)
{ 
  temp[k]=a[i];
  i++;
  k++;
}
while(j<=ub)
{
  temp[k]=a[j];
  j++;
  k++; 
}
for(i=lb,k=0;i<=ub;i++,k++)
 a[i]=temp[k];
}
void split(int a[],int lb,int ub)
{
int mid;
if(lb<ub)
{
 mid=(lb+ub)/2;
 split(a,lb,mid);
 split(a,(mid+1),ub);
}
merge(a,lb,mid,ub);
}

int main()
{
int n,i,a[18];
printf("Enter no of elements in the array: ");
scanf("%d",&n);
printf("Enter %d elements\t",n);
for(i=0;i<n;i++)
 scanf("%d",&a[i]);
 printf("Array is:\t");
 for(i=0;i<n;i++)
  printf("%d\t",a[i]);
 printf("sorted array is:\t"); 
split(a,0,(n-1));
for(i=0;i<n;i++)
 printf("%d\t",a[i]);
 }
 
