#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR,char *argv[])
{
	/* Definition goes here */
	int ret=0,flag=0;
	char *opr1=argv[1],*opr2=argv[3];
	if(strlen(opr1) > strlen(opr2))
	{
		digit_to_list(head1,tail1,head2,tail2,argv[1],argv[3]);
	}
	else if(strlen(opr1) < strlen(opr2))
	{
		digit_to_list(head2,tail2,head1,tail1,argv[1],argv[3]);	
		flag=1;
	}
	else
	{
		int i=0;
		while(opr1[i])
		{
			if(opr1[i] == opr2[i])
			{
				i++;
			}
			else if(opr1[i] < opr2[i])
			{
				digit_to_list(head2,tail2,head1,tail1,argv[1],argv[3]);	
				flag=1;
				break;
			}
			else
			{
			    digit_to_list(head1,tail1,head2,tail2,argv[1],argv[3]);
				break;
			}
		}
		if(opr1[i]=='\0')
		{
			if(insert_first(headR,tailR,0) == FAILURE)
			{
				return FAILURE;
			}
			return SUCCESS;
		}
	}
	// print_list(*head1);
	// print_list(*head2);
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	while(temp1 != NULL || temp2 != NULL)
	{
		if(temp1 == NULL)
		{
			ret=temp2->data;
			temp2=temp2->prev;
		}
		else if(temp2 == NULL)
		{
			ret=temp1->data;
			temp1=temp1->prev;
		}
		else 
		{
			if(temp1->data > temp2->data) 
			{
				ret=temp1->data - temp2->data;
				temp1=temp1->prev;
				temp2=temp2->prev;
			}
			else if(temp1->data < temp2->data)
			{
				int move=0;
				while(temp1->prev != NULL)
				{
					if(temp1->prev->data != 0)
					{
						temp1->prev->data -= -1;
						temp1->data  += 10;
						break;
					}
					else
					{
						temp1=temp1->prev;
						move++;
					}
				}
				while(move != 0)
				{
					temp1->data=temp1->data-1;
					temp1=temp1->next;
					temp1->data=temp1->data + 10;
					move--;
				}
				ret=temp1->data - temp2->data;
				temp1=temp1->prev;
				temp2=temp2->prev;
			}
			else
			{
				ret=0;
				temp1=temp1->prev;
				temp2=temp2->prev;
			}
		}
		if(insert_first(headR,tailR,ret) == FAILURE)
		{
			return FAILURE;
		}
	}
	if(flag==1)
	{
		(*headR)->data *= -1;
	}
	return SUCCESS;
}