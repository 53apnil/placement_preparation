#include<stdio.h>
#include<malloc.h>

struct readyQue 
{
	int (*ptr)[4];
	int pno;
	struct readyQue *next;
};
typedef struct readyQue node;
int timer=0;int flag=1;
node *start=NULL,*end=NULL;
int stat=0;
int swt=0;
void bubble_sort()
{
	node * temp;
	temp=start;
	int no;
	int sflag;
	node *temp1=NULL;
	do
	{
		temp=start;
		sflag=0;
		while(temp->next!=temp1)
		{
	
			if(*(*((temp->ptr)+temp->pno)+2) < *(*((temp->next->ptr)+temp->next->pno)+2))
			{
			
				no=temp->pno;
				temp->pno=temp->next->pno;
				temp->next->pno=no;
				sflag=1;
			}
			temp=temp->next;
		}
		temp1=temp;
	
	}
	while(sflag);
	
}
void enQueue(int array[][4],int i)
{
	node * newnode;
	newnode=(node *)malloc(sizeof(node));
	newnode->next=NULL;
	newnode->ptr=array;
	newnode->pno=i;
	if(start==NULL)
	{
		start=newnode;
		end=newnode;

	}
	else
	{
		end->next=newnode;
		end=newnode;

	}

}
void getProcess(int parr[][4],int n,int time)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(parr[i][1]==time)
		{
			enQueue(parr,i);
		}
	}
}
void ljf(int parr[][4],int n)
{
	timer=0;
	int count=0;
	while(count<n)
	{
		getProcess(parr,n,timer);
		if(start!=NULL && flag==1)
		{bubble_sort();flag=0;}
		if(start!=NULL)
		{
			if(*(*((start->ptr)+start->pno)+3)==0) 
			{
				printf("%d\t",timer);	
				stat=stat+timer-*(*(start->ptr+start->pno)+1); 
				swt=swt+timer-*(*(start->ptr+start->pno)+1)-*(*(start->ptr+start->pno)+2);  
				start=start->next;
				flag=1;
				count++;
			}
			else
			{*(*((start->ptr)+start->pno)+3)-=1;timer+=1;}
			
		}
		else
		{
			timer+=1;
		}
		
	}
		printf("\nAverage TAT =%f",(float)stat/n);
		printf("\nAverage WT=%f",(float)swt/n);

}
void main()
{
	int n;
	int i;
	printf("Enter count of all process\n");
	scanf("%d",&n);
	int process[n][4];
	printf("Enter pno Arrival time burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&process[i][0],&process[i][1],&process[i][2]);
		process[i][3]=process[i][2];
	}
	ljf(process,n);
}
