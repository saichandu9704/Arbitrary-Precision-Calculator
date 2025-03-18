#include "apc.h"
#include<stdlib.h>
#include <stdio.h>

int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    // Initialize the result linked list
    *headR = NULL;
    *tailR = NULL;

    // Convert dividend and divisor to numbers
    long long int dividend = 0, divisor = 0;
    Dlist *temp = *head1;

    // Convert dividend from linked list to integer
    while (temp != NULL) 
	{
        dividend = dividend * 10 + temp->data;
        temp = temp->next;
    }

    // Convert divisor from linked list to integer
    temp = *head2;
    while (temp != NULL) 
	{
        divisor = divisor * 10 + temp->data;
        temp = temp->next;
    }

    // Check for division by zero
    if (divisor == 0) 
	{
        printf("ERROR: Division by zero is not allowed.\n");
        return FAILURE;
    }

    // Step 1: Calculate the quotient using subtraction
    long long int quotient = 0;
    while (dividend >= divisor) 
	{
        dividend -= divisor; // Subtract divisor from dividend
        quotient++;          // Increment quotient
    }

    // Step 2: Convert the quotient into a linked list
    if (quotient == 0) 
	{
        // If the quotient is 0, directly add 0 to the result list
        insert_first(headR, tailR, 0);
    } 
	else 
	{
        while (quotient > 0) 
		{
            int digit = quotient % 10;
            insert_first(headR, tailR, digit);
            quotient /= 10;
        }
    }

    // The remainder (left in the dividend) can also be captured if needed
    printf("INFO: Division complete. Quotient linked list created.\n");
    return SUCCESS;
}
