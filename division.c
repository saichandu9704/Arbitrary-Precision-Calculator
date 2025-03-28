#include "apc.h"


int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR,char *argv[]) 
{
    // Edge Case: If divisor is 0
    Dlist *temp2 = *tail2;
    int flag = 0;
    while (temp2 != NULL) 
	{
        if (temp2->data != 0) 
		{
            flag = 1;
            break;
        }
        temp2 = temp2->prev;
    }
    if (flag == 0) 
	{
        printf("INFO: Division is Not possible\n");
        return FAILURE;
    }

    // Edge Case: If numerator is 0
    flag = 0;
    Dlist *temp1 = *tail1;
    while (temp1 != NULL) 
	{
        if (temp1->data != 0) 
		{
            flag = 1;
            break;
        }
        temp1 = temp1->prev;
    }
    if (flag == 0) 
	{
        *headR=NULL;
        *tailR=NULL;
        if (insert_first(headR, tailR, 0) == FAILURE) 
		{
            printf("ERROR: Insertion first Failed\n");
            return FAILURE;
        }
        return SUCCESS;
    }

    // If dividend == divisor, quotient = 1
    temp1 = *tail1;
    temp2 = *tail2;
    flag = 0;
    while (temp1 != NULL && temp2 != NULL) 
	{
        if (temp1->data != temp2->data) 
		{
            flag = 1;
            break;
        }
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
    if (temp1 == NULL && temp2 == NULL && flag == 0) 
	{
        *headR=NULL;
        *tailR=NULL;
        if (insert_first(headR, tailR, 1) == FAILURE) 
		{
            printf("ERROR: Insertion first Failed\n");
            return FAILURE;
        }
        return SUCCESS;
    }

    // If divisor > dividend, quotient = 0
    temp1 = *tail1;
    temp2 = *tail2;
    while (temp1 != NULL && temp2 != NULL) 
	{
        temp1 = temp1->prev;
        temp2 = temp2->prev;
    }
    if (temp1 == NULL && temp2 != NULL) 
	{
        *headR=NULL;
        *tailR=NULL;
        if (insert_first(headR, tailR, 0) == FAILURE) 
		{
            printf("ERROR: Insertion first Failed\n");
            return FAILURE;
        }
        return SUCCESS;
    }
    if(temp1==NULL && temp2==NULL)
    {
        temp1=*head1;
        temp2=*head2;
        while(temp1->data<=temp2->data)
        {
            if(temp1->data<temp2->data)
            {
                *headR=NULL;
                *tailR=NULL;
                if (insert_first(headR, tailR, 0) == FAILURE) 
                {
                    printf("ERROR: Insertion first Failed\n");
                    return FAILURE;
                }
                return SUCCESS;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }

    // Perform Division using Repeated Subtraction
    int count=0,res1=0,res2=0;
    temp1 = *head1;
    temp2 = *head2;
    while(temp1 != NULL)
    {
        res1=res1*10+(temp1->data);
        temp1=temp1->next;
    }

    while(temp2 != NULL)
    {
        res2=res2*10+(temp2->data);
        temp2=temp2->next;
    }
    
    while (res1 >= res2) 
    {
        if(subtraction(head1, tail1, head2, tail2, headR, tailR, argv)==FAILURE)
        {
            return FAILURE;
        }
        *head1 = *headR;
        *tail1 = *tailR;
        *headR = NULL;
        *tailR = NULL;
        count++;
        res1 =res1-res2;  // Update the numerical value as well
    }
    if (insert_first(headR, tailR, count) == FAILURE) 
    {
        printf("ERROR: Insertion first Failed\n");
        return FAILURE;
    }
    return SUCCESS;
}