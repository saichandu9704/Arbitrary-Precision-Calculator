#include "apc.h"

int validation(int argc,char *argv[])
{
	if(argc==4)
	{
		if(strcmp(argv[2],"+")==0 || strcmp(argv[2],"-")==0 || strcmp(argv[2],"x")==0 || strcmp(argv[2],"/")==0 )
		{
			char *operand1=argv[1];
			char *operand2=argv[3];
			int i=0;
			while(operand1[i])
			{
				if(operand1[i]>='0' && operand1[i]<='9')
				{
					i++;
				}
				else
				{
					return FAILURE;
				}
			}
			i=0;
			while(operand2[i])
			{
				if(operand2[i]>='0' && operand2[i]<='9')
				{
					i++;
				}
				else
				{
					return FAILURE;
				}
			}
			return SUCCESS;
		}
		else
		{
			printf("INFO: ./a.out 'operand1' '+,-,x,/' 'operand2'\n");
			return FAILURE;
		}
	}
	else
	{
		printf("INFO: ./a.out 'operand1' 'operator' 'operand2'\n");
		return FAILURE;
	}
}

void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *operand1,char *operand2)
{
	int i=0,data=0;
	while(operand1[i])
	{
		data=operand1[i]-'0';
		if(insert_last(head1,tail1,data)==FAILURE)
		{
			printf("ERROR:Insert Failed\n");
			return;
		}
		i++;
	}
	i=0,data=0;
	while(operand2[i])
	{
		data=operand2[i]-'0';
		if(insert_last(head2,tail2,data)==FAILURE)
		{
			printf("ERROR:Insert Failed\n");
			return;
		}
		i++;
	}
}



int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	int carry=0,result=0;
	while(temp1!=NULL || temp2!=NULL)
	{
		if(temp1==NULL)
		{
			result=(temp2->data)+carry;
			temp2=temp2->prev;
		}
		else if(temp2==NULL)
		{
			result=(temp1->data)+carry;
			temp1=temp1->prev;
		}
		else
		{
			result=(temp1->data)+(temp2->data)+carry;
			temp1=temp1->prev;
			temp2=temp2->prev;
		}
		if(result>9)
		{
			carry=1;
			result=result-10;
		}
		else
		{
			carry=0;
		}
		if(insert_first(headR,tailR,result)==FAILURE)
		{
			printf("ERROR:Insertion first Failed\n");
			return FAILURE;
		}
	}
	if(carry==1)
	{
		if(insert_first(headR,tailR,carry)==FAILURE)
		{
			printf("ERROR:Insertion first Failed\n");
			return FAILURE;
		}
	}
	return SUCCESS;
}


int insert_last(Dlist **head,Dlist **tail,int data)
{
	Dlist *new=malloc(sizeof(Dlist));
	if(new==NULL)
	{
		return FAILURE;
	}
	new->data=data;
	new->prev=NULL;
	new->next=NULL;
	if(*head==NULL || *tail==NULL)
	{
		*head=new;
		*tail=new;
		return SUCCESS;
	}
	new->prev=*tail;
	(*tail)->next=new;
	*tail=new;
	return SUCCESS;
}


int insert_first(Dlist **headR,Dlist **tailR,int data)
{
	Dlist *new=malloc(sizeof(Dlist));
	if(new==NULL)
	{
		return FAILURE;
	}
	new->data=data;
	new->prev=NULL;
	new->next=NULL;
	if(*headR==NULL || *tailR==NULL)
	{
		*headR=new;
		*tailR=new;
		return SUCCESS;
	}	
	new->next=*headR;
	(*headR)->prev=new;
	*headR=new;
	return SUCCESS;
}


void print_list(Dlist *headR)
{
	if(headR==NULL)
	{
		printf("List is Empty\n");
		return;
	}
	while(headR!=NULL)
	{
		printf("%d",headR->data);
		headR=headR->next;
	}
	printf("\n");
}