#include<stdio.h>
#include<stdlib.h>
int visited[10];
int vv[10];
int a[10][10];
int n;
void dfs(int i)
{
	printf("%d, ",vv[i]);
	visited[i]=1;
	for(int j=1;j<n;j++)
		if(a[i][j]==1&&visited[j]==0)
			dfs(j);
}
void bfs(int i)
{
	if(visited[i]==0)
	{
		printf("%d, ",vv[i]);
		visited[i]=1;
	}
	for(int j=0;j<n;j++)
		if(a[i][j]==1&&visited[j]==0)
		{
			printf("%d, ",vv[j]);
			visited[j]=1;
		}
	for(int j=i+1;j<n;j++)
		bfs(j);
}
void main()
{	
	for(int i=0;i<10;i++)
		visited[i]=0;
	printf("Enter the number of vertices : ");
	scanf("%d",&n);
	printf("Enter the value of the vertices : ");
	for(int i=0;i<n;i++)
		scanf("%d",&vv[i]);
	printf("Enter the links : ");
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	printf(" Depth first search :");
	dfs(0);
	for(int i=0;i<10;i++)
		visited[i]=0;
	printf(" Breadth first search :");
	bfs(0);
	
}
	
