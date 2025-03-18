#ifndef APC_H
#define APC_H

#include<string.h>
#include<stdlib.h>
#include<stdio.h>

#define SUCCESS 0
#define FAILURE -1

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int validation(int argc,char *argv[]);

/*store the operands into the list */
void digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *operand1,char *operand2);

/*Insertion last Operaton into the list*/
int insert_last(Dlist **head,Dlist **tail,int data);

/*Insertion first Operaton into the list*/
int insert_first(Dlist **headR,Dlist **tailR,int data);

/*Print the list*/
void print_list(Dlist *headR);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[]);


/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Division */
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);

#endif
