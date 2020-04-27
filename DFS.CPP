#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#define max_size 10
int pop(int *top,int stack[]);        //pop an element from stack
void push(int *top,int stack[],int element);  //push an element into stack
int isEmpty(int top);                       //check to see if stack is empty
void main()
	{
	int stack[max_size],isVisited[max_size]={0};
	int matrix_adj[max_size][max_size];       //stack,matrix,top amd isvisited for deploying stack & dfs
	int top=-1,i,j,start_node,has_adj;        //top=-1 means stack is empty
	char *input;
	clrscr();
	for(i=0;i <= (max_size-1);i++)             //reads matrix adjacent
		{
		gets(input);
		matrix_adj[i][0]=atoi(strtok(input," "));
		for(j=1;j <= (max_size-1);j++)
			{
			matrix_adj[i][j]=atoi(strtok(NULL," "));
			}
		}
	scanf("%d",&start_node);         //read start node
	printf("%d -",start_node);
	push(&top,stack,start_node);
	isVisited[start_node]=1;
	while(isEmpty(top))                 //check the condition of termination
		{
		has_adj=0;                      //checks to see if node have any adjacents
		for(i=0;i <= (max_size-1);i++)
			{
			if((matrix_adj[stack[top]][i]==1) && (isVisited[i]==0))
				{
				isVisited[i]=1;
				has_adj=1;
				push(&top,stack,i);
				printf("%d -",stack[top]);  //print the visited node
				break;
				}
			}
		if(has_adj == 0)
			{
			pop(&top,stack);     //pop if have no adj
			}
	  }
	  for(i=0;i <= (max_size-1);i++)
		{
		if(isVisited[i]==0)
			printf("\nThe graph is not connected. \n");
			break;
		}
	  getch();
	}
//********************************************************
void push(int *top,int stack[],int element)       //deploying stack
	{                                             //push an element
	if((*top) >= max_size)
		{
		printf("Stack is full \n");
		return;
		}
	stack[++(*top)]=element;
	}
//********************************************************
int pop(int *top,int stack[])            //pop an element
	{
	if((*top) == -1)
		{
		printf("Stack is empty,Can not pop. \n");
		return -1;
		}
	else
		{
		return stack[(*top)--];
		}
	}
//*********************************************************
int isEmpty(int top)                   //check the stack if empty returns 0
	{
	if(top == -1)
		return 0;
	else
		return 1;
	}
//***********************************************************
