#include<stdio.h>
#include<stdlib.h>
struct node{
			int info;
			struct node *next;
			};
typedef struct node node1;

node1* initlist()
{
	return NULL;
	
}
node1* pushdynamic(node1 *list,int x)
{
	node1 *l;
	l=(node1*)(malloc(sizeof(node1)));
	l->info=x;
	l->next=list;
	return l;
}
node1* popdynamic(node1 *list,int *x)
{
	node1 *p;
	p=list;
	*x=p->info;
	list=p->next;
	free(p);
	return list;
}
int emptystack(node1 *list)
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
	list=initlist();
	do{
		printf("1. Push value in stack\n");
		printf("2. Pop a value from stack\n");
		printf("3. EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Give value to enter: ");
				scanf("%d",&v);
				list=pushdynamic(list,v);
				break;
		case 2:
				if (emptystack(list)==0)
				{
					list=popdynamic(list,&v);
					printf("Popped value=%d\n",v);
				}
				else
				printf("Stack empty, cannot delete\n");
				break;
		case 3:
				printf("Thank you, BYE\n");
				break;
		default:
				printf("invalid choice, enter again\n");
		}
	} while(choice!=3);	
}
