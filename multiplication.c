#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	Dlist *headR1=NULL,*tailR1=NULL,*headR2=NULL,*tailR2=NULL;
	int count=0,result=0;
	while(temp2!=NULL)
	{
		int carry=0;
		temp1=*tail1;
		for(int i=0;i<count;i++)
		{
			if(insert_first(&headR2,&tailR2,0)==FAILURE)
			{
				return FAILURE;
			}
		}
		while(temp1!=NULL)
		{
			
			result=temp1->data*temp2->data+carry;
			if(result>9)
			{
				carry=result/10;
				result=result%10;
			}
			else
			{
				carry=0;
			}

			if(count==0)
			{
				if(insert_first(&headR1,&tailR1,result)==FAILURE)
				{
					return FAILURE;
				}
			}
			else
			{
				if(insert_first(&headR2,&tailR2,result)==FAILURE)
				{
					return FAILURE;
				}
			}
			temp1=temp1->prev;
		}

		if((carry>0) && (count==0))
		{
			if(insert_first(&headR1,&tailR1,carry)==FAILURE)
			{
				return FAILURE;
			}
		}
		else if((carry>0) && (count!=0))
		{
			if(insert_first(&headR2,&tailR2,carry)==FAILURE)
			{
				return FAILURE;
			}
		}
		count++;
		if(count==1)
		{
			*headR=headR1;*tailR=tailR1;
		}
		if(count>=2)
		{
			*headR = NULL;
			*tailR = NULL;
			if(addition(&headR1,&tailR1,&headR2,&tailR2,headR,tailR)==FAILURE)
			{
				return FAILURE;
			}
			headR2 = NULL;
			tailR2 = NULL;
			headR1=*headR;tailR1=*tailR;
			if(temp2->prev!=NULL)
			{
				*headR = NULL;
				*tailR = NULL;
			}
		}
		temp2=temp2->prev;
	}
	return SUCCESS;
}
