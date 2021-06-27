#include<stdio.h>
#include<stdlib.h>
struct node{
			int info;
			struct node *prev,*next;
			};
typedef struct node node1;

void initlist(node1 **list)
{
	*list=NULL;
	
}
void enterlist(node1 **list,int x)
{
	node1 *p,*back,*q;
	p=(node1*)(malloc(sizeof(node1)));
	p->info=x;
	if (*list==NULL)
	{
		p->next=NULL;
		p->prev=NULL;
		*list=p;
	}
	else
	{
		q=*list;
		if (x<q->info)
		{
			while(q->prev!=NULL && x<q->info)
			q=q->prev;
			if (x<q->info)	
			{
				p->prev=NULL;
				p->next=q;
				q->prev=p;				
			}
			else
			{
				p->prev=q;
				p->next=q->next;
				q->next=p;
				p->next->prev=p;
			}
		*list=p;
		}
		else
		{
			while(q->next!=NULL && x>q->info)
			q=q->next;
			if (x>q->info)	
			{
				p->next=NULL;
				p->prev=q;
				q->next=p;				
			}
			else
			{
				p->next=q;
				p->prev=q->prev;
				q->prev=p;
				p->prev->next=p;
			}	
		*list=p;		
		}	
	}
}
void deletelist(node1 **list,int x)
{
	node1 *p;
	p=*list;
	if (x<p->info)
	{
		while(p->prev!=NULL && x<p->info)
		p=p->prev;
	}
	else
	{
		while(p->next!=NULL && x>p->info)
		p=p->next;
	}	
	if (x==p->info)
	{
		if (p->prev==NULL && p->next==NULL)
		{
			*list=NULL;
			free(p);
		}
		else
		{
			if (p->prev!=NULL)
			{
				p->prev->next=p->next;
				*list=p->prev;
			}
			if (p->next!=NULL)
			{
				p->next->prev=p->prev;
				*list=p->next;
			}	
			free(p);
			
		}
	}
	else
	printf("value not present in the list\n");
}
int searchlist(node1 **list,int x)
{
	node1 *p;
	p=*list;
    if(x<p->info)
    {
		while(p!=NULL && x<p->info)
		p=p->prev;
	}
	else
	{
		while(p!=NULL && x>p->info)
		p=p->next;
	}
	if (p->info==x)
	{
		*list=p;
		return 1;
	}
	else
	return 0;
}
void traverselist(node1 *list)
{
	node1 *p;
	p=list;
	while(list!=NULL && list->prev!=NULL)
	list=list->prev;
	while(list!=NULL)
	{
		if(list!=p)
		printf("%d--> ",list->info);
		else
		printf("[%d]--> ",list->info);
		list=list->next;
	}
	printf("\n");
}
int emptylist(node1 *list)
{
	if (list==NULL)
	return 1;
	else 
    return 0;
}
int main()
{
	node1 *list;
	int choice,v,i;
	initlist(&list);
	do{
		printf("1. Enter a value in list\n");
		printf("2. Delete a value from list\n");
		printf("3. Search in list\n");
		printf("4. Traverse the list\n");
		printf("5. EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Give value to enter: ");
				scanf("%d",&v);
				enterlist(&list,v);
				break;
		case 2:
				printf("Give value to delete: ");
				scanf("%d",&v);
				if (emptylist(list)==0)
				deletelist(&list,v);
				else
				printf("list empty, cannot delete\n");
				break;
		case 3:
				printf("Give value to search: ");
				scanf("%d",&v);
				if (searchlist(&list,v)==1)
				printf("Value found in list\n");
				else
				printf("value not found in list\n");
				break;
		case 4:
				printf("The List is (List pointer position is as in [ ]):\n");
				traverselist(list);
				printf("\n");
				break;
		case 5:
				printf("Thank you, BYE\n");
				break;
		default:
				printf("invalid choice, enter again\n");
		}
	} while(choice!=5);	
}
