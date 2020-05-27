#include<stdio.h>
#include<stdlib.h>

void CreateatEnd(int s,int v);
void DeleteatStart();
void traverse();
void buy();
void sell(int Sha,int Val);
int i=1;

struct node
{
	int share,value,day;
	struct node *next;
};
	typedef struct node NODE;
	NODE *p,*q,*r,*Start=NULL,*End=NULL;

int main()
{
	int ch,sha,val;
	do
	{
		printf("Enter your choice\n");
		printf("1.Buy Shares on day %d\n",i);
		printf("2.Sell Shares on day %d\n",i);
		printf("3.Make next day transactions\n");
		printf("4.EXIT\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				buy();
				traverse();
				break;
			case 2:
				printf("Enter the number of shares to sell\n");
				scanf("%d",&sha);
				printf("Enter the value of Each share to sell with\n");
				scanf("%d",&val);
				sell(sha,val);
				traverse();
				break;
			case 3:
				i++;
				break;
			case 4:
				traverse();
				break;
			default:
				printf("Invalid choice\n");
		}
	}while(ch!=4);
	return 0;
}

void CreateatEnd(int s,int v)
{
	p=(NODE*)malloc(sizeof(NODE));
	p->share=s;
	p->value=v;
	p->day=i;
	if(Start==NULL)
	{
		p->next=NULL;
		Start=p;
		End=p;
	}
	else
	{
		End->next=p;
		p->next=NULL;
		End=p;
        }
}

void DeleteatStart()
{
		p=Start;
		if(Start->next==NULL)
		{
			Start=NULL;
			End=NULL;
		}
		else
			Start=p->next;
		free(p);
}

void traverse()
{
	if(Start==NULL)
		printf("No any Shares are Purchased\n");
	else
	{
		r=Start;
		while(r!=NULL)
		{
			printf("Day:%d\tShares:%d\t,Value:%d\n",r->day,r->share,r->value);
			r=r->next;
		}
	}
}

void buy()
{
	int S,V;
	printf("Enter the number of shares to buy\n");
	scanf("%d",&S);
	printf("Enter the value of Each share\n");
	scanf("%d",&V);
	CreateatEnd(S,V);
}

void sell(int Sha,int Val)
{
	int n=0,Capital=0;
	q=Start;
	while(q!=NULL)
	{
		n=n+q->share;
		q=q->next;
	}
	if(n>=Sha)
	{
		n=Sha;
		r=Start;
		while(n!=0)
		{
			if(n==r->share)
			{
				Capital=Capital+(r->share*(Val-r->value));
				DeleteatStart();
				n=0;
			}
			else if(n>r->share)
			{
				Capital=Capital+(r->share*(Val-r->value));
				n=n-r->share;
				DeleteatStart();
			}
			else
			{
				Capital=Capital+(n*(Val-r->value));
				r->share=r->share-n;
				n=0;
			}
			r=r->next;
		}
		if(Capital>=0)
			printf("Capital Gain has Profit of =%d\n",Capital);
		else
			printf("Capital Gain has Loss of =%d\n",Capital);
	}
	else
		printf("Number of shares are Less\n");
}

