#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
struct node* root=NULL;
struct node *ptr,*parent,*succ;
int d,l,flag=0;
void insert()
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	
	printf("Enter the element to be inserted : ");
	scanf("%d",&d);
	newnode->data=d;
	newnode->left=NULL;
	newnode->right=NULL;
	if(root==NULL)
		root=newnode;
	else
	{
		ptr=root;		
		while(ptr!=NULL&&flag==0)
		{
			if(d>(ptr->data))
			{
				parent=ptr;
				ptr=ptr->right;
			}
			else if(d<(ptr->data))
			{
				parent=ptr;
				ptr=ptr->left;
			}
			else
			 flag=1;
		}
		if(flag==1)
			printf("Element already exits !");
		else
		{
			if(d>parent->data)
				parent->right=newnode;
			else
				parent->left=newnode;
		}
	}
}
void delete(int f)
{
	int cas;
	if(root==NULL)
		printf("Tree is empty !");
	else
	{
		ptr=root;
		flag=0;
		while((ptr!=NULL)&&(flag==0))
		{
			if(d>(ptr->data))
			{
				parent=ptr;
				ptr=ptr->right;
			}
			else if(d<(ptr->data))
			{
				parent=ptr;
				ptr=ptr->left;
			}
			else
				flag=1;
		}
		if(flag==0)
			printf("Element not present in the tree !");
		else
		{
			if(ptr->left==NULL&&ptr->right==NULL)
				cas=1;
			else if(ptr->left!=NULL && ptr->left!=NULL)
				cas=3;
			else
				cas=2;
			if(cas==1)
			{
				if(parent->left==ptr)
					parent->left=NULL;
				else
					parent->right=NULL;
				if(ptr==root)
					root=NULL;
				free(ptr);
			}
			else if(cas==2)
			{	
				if(parent->left==ptr)
				{
					if(ptr->left!=NULL)
						parent->left=ptr->left;
					else
						parent->left=ptr->right;
				}
				else
				{
					if(ptr->left!=NULL)
						parent->right=ptr->left;
					else
						parent->right=ptr->right;
				}
				free(ptr);
			}
			else
			{
				succ=ptr->right;
				while(succ->left!=NULL)
				{
					succ=succ->left;
					l=succ->data;
					delete(succ->data);
					ptr->data=l;
				}
			}
		}
	}
}	
void preorder(struct node* p)
{
	if(p!=NULL)
	{
		printf("%d,",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}
void inorder(struct node* p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d,",p->data);
		inorder(p->right);
	}
}
void postorder(struct node* p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d,",p->data);
	}
}	
void search()
{
	printf("Enter the element to be searched : ");
	scanf("%d",&d);
	ptr=root;
	flag=0;
	while(ptr!=NULL&&flag==0)
	{
		if(d>ptr->data)
			ptr=ptr->right;
		else if(d<ptr->data)
			ptr=ptr->left;
		else
			flag=1;
	}
	if(flag==1)
		printf("Element found ");
	else
		printf("Element not found ");
}						
void main()
{
	printf("1. Insert\n2. Delete\n3. Traverse\n4. Search\n5. Exit\n");
	int ch;
	do
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			break;
			case 2:
			{
				int f;
				printf("Enter the element to be deleted : ");
				scanf("%d",&f);
				delete(f);
				break;
			}
			case 3:printf("Preorder : ");
				preorder(root);
				printf("\nInorder : ");
				inorder(root);
				printf("\nPostorder : ");
				postorder(root);
				break;
			case 4:search();
				break;
			case 5:exit(1);
			default:printf("\nWrong choice\n");
		}
	}while(1);
}
	
