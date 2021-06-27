#include<stdio.h>
#include<stdlib.h>
struct node{
			int rno;
			int age;
			int mar;
			struct node *nr,*na,*nm;
			};
typedef struct node node1;

void initlist(node1 **list)
{
	*list=NULL;
	
}
void enterlist(node1 **lr,node1 **la,node1 **lm,int vr,int va,int vm)
{
	node1 *p,*back,*q;
	p=(node1*)(malloc(sizeof(node1)));
	p->rno=vr;
	p->age=va;
	p->mar=vm;
	if (*lr==NULL)
	{
		*lr=p;
		*la=p;
		*lm=p;
		p->nr=NULL;
		p->na=NULL;
		p->nm=NULL;
	}
	else
	{
		// linked list related to rollno
		q=*lr;
		back=*lr;
		while(q!=NULL && vr>q->rno)
		{
			back=q;
			q=q->nr;
		}
		if (back==q)
		{
			p->nr=q;
			*lr=p;
		}
		else
		{
			back->nr=p;
			p->nr=q;
		}
		// linked list related to age
		q=*la;
		back=*la;
		while(q!=NULL && va>q->age)
		{
			back=q;
			q=q->na;
		}
		if (back==q)
		{
			p->na=q;
			*la=p;
		}
		else
		{
			back->na=p;
			p->na=q;
		}
		// linked list related to marks
		q=*lm;
		back=*lm;
		while(q!=NULL && vm>q->mar)
		{
			back=q;
			q=q->nm;
		}
		if (back==q)
		{
			p->nm=q;
			*lm=p;
		}
		else
		{
			back->nm=p;
			p->nm=q;
		}
	}
}
void traverselistr(node1 *lr)
{
	while(lr!=NULL)
	{
		printf("%d   %d   %d\n",lr->rno,lr->age,lr->mar);
		lr=lr->nr;
	}
	printf("\n");
}
void traverselista(node1 *la)
{
	while(la!=NULL)
	{
		printf("%d   %d   %d\n",la->rno,la->age,la->mar);
		la=la->na;
	}
	printf("\n");
}
void traverselistm(node1 *lm)
{
	while(lm!=NULL)
	{
		printf("%d   %d   %d\n",lm->rno,lm->age,lm->mar);
		lm=lm->nm;
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
	node1 *lr,*la,*lm;
	int choice,vr,va,vm;
	initlist(&lr);
	initlist(&la);
	initlist(&lm);
	do{
		printf("1. Enter a record in list\n");
		printf("2. Traverse the list in order of rollno\n");
		printf("3. Traverse the list in order of age\n");
		printf("4. Traverse the list in oreder of marks\n");
		printf("5. EXIT\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
				printf("Give rollno, age, marks to enter: ");
				scanf("%d%d%d",&vr,&va,&vm);
				enterlist(&lr,&la,&lm,vr,va,vm);
				break;
		case 2:
				printf("The List in order of rollno-->\n");
				printf(" ROLL NO.    AGE     MARKS\n");
				printf("----------------------------\n");
				traverselistr(lr);
				printf("\n");
				break;
		case 3:
				printf("The List in order of age-->\n");
				printf(" ROLL NO.    AGE     MARKS\n");
				printf("----------------------------\n");
				traverselista(la);
				printf("\n");
				break;
		case 4:
				printf("The List in order of marks-->\n");
				printf(" ROLL NO.    AGE     MARKS\n");
				printf("----------------------------\n");
				traverselistm(lm);
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
