#include<stdio.h>
#include<stdlib.h>
char post[50];
char stack[10];
int stk=-1,pst=-1;
void intopost(char in[])
{
	int z;
	for(int i=0;in[i]!='\0';i++)
	{
		if(in[i]==' ')
			continue;
		else if(in[i]=='+'||in[i]=='-'||in[i]=='*'||in[i]=='/'||in[i]=='('||in[i]=='^'||in[i]==')')
		{
			if(in[i]=='+'||in[i]=='-')
			{
				if((in[i]=='+')&&(stack[stk]=='*'||stack[stk]=='/'||stack[stk]=='^'||stack[stk]=='-'))
				{
					for(z=stk;stack[z]!='('&&z>-1;z--)
						post[++pst]=stack[z];
					stk=z;
					stack[++stk]=in[i];
				}
				else if((in[i]=='-')&&(stack[stk]=='*'||stack[stk]=='/'||stack[stk]=='^'||stack[stk]=='+'))
				{	
					for(z=stk;stack[z]!='('&&z>-1;z--)
						post[++pst]=stack[z];
					stk=z;
					stack[++stk]=in[i];
				}
				else
				{
					stack[++stk]=in[i];
				}
			}
			else if(in[i]=='*'||in[i]=='/')
			{
				if((in[i]=='*')&&(stack[stk]=='^'||stack[stk]=='/'))
				{
					for(z=stk;(stack[z]=='*'||stack[z]=='/'||stack[z]=='^')&&z>-1;z--)
						post[++pst]=stack[z];
					stk=z;
					stack[++stk]=in[i];
				}
				else if((in[i]=='/')&&(stack[stk]=='^'||stack[stk]=='*'))
				{
					for(z=stk;(stack[z]=='*'||stack[z]=='/'||stack[z]=='^')&&z>-1;z--)
						post[++pst]=stack[z];
					stk=z;
					stack[++stk]=in[i];
				}
				else if(in[i]=='^')
				{
					for(z=stk;stack[z]=='^'&&z>-1;z--)
						post[++pst]=stack[z];
					stk=z;
					stack[++stk]=in[i];
				}					
				else
				{
					stack[++stk]=in[i];
				}
			}
			else if(in[i]==')')
			{
				for(z=stk;stack[z]!='('&&z>-1;z--)
					post[++pst]=stack[z];
				stk=z-1;
			}
			else
			{
				stack[++stk]=in[i];
			}			
		}
		else
		{
			post[++pst]=in[i];
		}
	}
	for(int h=stk;stack[h]!='('&&h!=-1;h--)
		post[++pst]=stack[h];
		
}	
void main()
{
	char in[50],ch,ch1;
	int i,m=0,count=0;
	printf(" Enter the infix expression : ");
	scanf("%s",in);	
	/*ch=in[0];
	in[0]='(';
	for(i=1;in[i]!='\0';i++)
	{
		ch1=in[i];
		in[i]=ch;
		ch=ch1;
	}
	in[i++]=')';
	in[i]='\0';
	for(i=0;in[i]!='\0';i++)
		printf("%c",in[i]);*/	
	intopost(in);
	for(i=0;i<=pst;i++)
		printf("%c ",post[i]);
}


