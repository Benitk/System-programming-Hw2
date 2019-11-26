#include "myBank.h"
#include <stdio.h>
int main(){
	char type;
	double amount;
	double interest_rate;
	int account_number;

	do{
		printf("‫‪Transaction‬‬ ‫‪type?:‬‬ ");
		scanf(" %c", &type);

		switch(type){
			//Open account
			case 'O':
				amount = Amount();
				if(amount){
					open_account(amount);
				}
				break;
			//Print the balance
			case 'B':
				account_number = isAccount();
				if(account_number){
					balance(account_number);
				}
				break;
			//Deposit
			case 'D':
				account_number = isAccount();
				if(account_number){
					amount = Amount();
					if(amount){
						deposit(account_number, amount);
					}
				}
				break;
			//Withdrawal
			case 'W':
				account_number = isAccount();
				if(account_number){
					amount = Amount();
					if(amount){
						withdrawal(account_number, amount);
					}
				}
				break;
			//Close the account
			case 'C':
				account_number = isAccount();
				if(account_number){
					close_account(account_number);
				}
				break;
			//Add interest rate to all accounts
			case 'I':
				interest_rate = Interest_rate();
				if(interest_rate){
					interest_add(interest_rate);
				}
				break;
			//Print accounts
			case 'P':
				print_accounts();
				break;
			//Close all and exit
			case 'E':
				exit_prog();
				break;
			//invalid input
			default:
				printf("\nSorry, invalid input. try one of the following options:\n");
				printf("'O' to open account, 'B' to check balance, 'D' to deposit, 'W' to withdrawal\n");
				printf("'C' to close specific account, 'I' to add interest rate\n");
				printf("'P' to print accounts, 'E' to close all accounts and exit the program\n");
		}
	}while(type != 'E');


	return 0;
}
