#include "apc.h"

int main(int argc,char *argv[])
{
	/* Declare the pointers */
      
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL,*tailR=NULL;

	//Validation
	if(validation(argc,argv)==FAILURE)
	{
		printf("ERROR: Inputs are Not Support\n");
		return 0;
	}
	printf("INFO: Validation SUccessfully\n");
	
	char operator=argv[2][0];
	char *str1=argv[1];
	char *str2=argv[3];


		switch (operator)
		{
			case '+':
                                
				/* call the function to perform the addition operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]);
                if(addition(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
				{
					printf("ADDITION Operation is FAILED\n");
					return 0;
				}
				printf("ADDITION Operation is SUCCESS\n");
				printf("Addition is: ");
				print_list(headR);
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				//digit_to_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]);
				if(subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR,argv)==FAILURE)
				{
					printf("SUBTRACTION Operation is FAILED\n");
					return 0;
				}
				printf("SUBTRACTION Operation is SUCCESS\n");
				printf("Subtraction is: ");
				print_list(headR);
				break;
			case 'x':	
				/* call the function to perform the multiplication operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]);
				if(multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
				{
					printf("MULTIPLICATION Operation is FAILED\n");
					return 0;
				}
				printf("MULTIPLICATION Operation is SUCCESS\n");
				printf("Multiplication is: ");
				print_list(headR);
				break;
			case '/':	
				/* call the function to perform the division operation */
				digit_to_list(&head1,&tail1,&head2,&tail2,argv[1],argv[3]);
				if(division(&head1,&tail1,&head2,&tail2,&headR,&tailR)==FAILURE)
				{
					printf("DIVISION Operation is FAILED\n");
					return 0;
				}
				printf("DIVISION Operation is SUCCESS\n");
				printf("DIVISION is: ");
				print_list(headR);
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}
	return 0;
}
