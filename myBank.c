#include "myBank.h"
#include <stdio.h>
#define Length 50
#define Range 901

// 2D array that represent pool of Bank accounts;
double Accounts[2][Length] = {0};
// pointer to the last account used
int myindex = 0;
// counter for the bank accounts
int num_of_accounts = 0;

void open_account(double amount){
	// check if there is empty bank account
	while(myindex < Length && Accounts[1][myindex] == 1){
		myindex = myindex + 1;
	}
	// no empty bank account
	if(num_of_accounts == Length){
		printf("Sorry, there isn't an empty bank account\n");
	}
	else{
		Accounts[0][myindex] = amount;
		Accounts[1][myindex] = 1;
		num_of_accounts++;
		printf("Your account number is: %d\n",myindex + Range);
	}
}
// print balance
void balance(int account_number){
	printf("The balance is: %.2lF\n",Accounts[0][account_number - Range]);

}
// deposit to the given account
void deposit(int account_number, double amount){
	Accounts[0][account_number - Range] += amount;
	printf("The balance is: %.2lF\n",Accounts[0][account_number - Range]);
}
// withdrawal money from given account
void withdrawal(int account_number, double amount){
	if(Accounts[0][account_number - Range] - amount < 0){
		printf("There isn't enough money in the account\n");
	}
	else{
		Accounts[0][account_number - Range]-= amount;
		printf("The balance is: %.2lF\n",Accounts[0][account_number - Range]);
			}
}
// close given account
void close_account(int account_number){
	Accounts[0][account_number - Range] = 0;
	Accounts[1][account_number - Range] = 0;
	myindex = account_number - Range;
	num_of_accounts--;
	printf("Account number %d is closed\n", account_number);
}
// add interest to all accounts
void interest_add(double interest_rate){
	if(num_of_accounts != 0){
		for(int i = 0; i < Length; i++){
			if(Accounts[1][i] != 0){
				Accounts[0][i] += Accounts[0][i] * (interest_rate) / 100;
			}
		}
		printf("Interest has been added to all accounts\n");
	}
	else{
		printf("There is no open bank accounts!.\n");
	}
}


// print all the bank accounts number and balance
void print_accounts(){
	if(num_of_accounts != 0){
		int counter = 0;
		for(int i = 0; i < Length; i++){
			if(Accounts[1][i] != 0){
				counter++;
				printf("%d) Account number %d has balance of %.2lF\n", counter, i + Range, Accounts[0][i]);
			}
		}
	}
	else{
		printf("There is no open bank accounts!.\n");
	}
}
//Close all bank accounts
void exit_prog(){
	if(num_of_accounts != 0){
		for(int i = 0; i < Length; i++){
			if(Accounts[1][i] != 0){
				Accounts[0][i] = 0;
				Accounts[1][i] = 0;
				num_of_accounts--;
			}
		}
		myindex = 0;

	}
	printf("The bank is closed\n");
}

// check if the account number is valid;
int isAccount(){
	int account_number;
	printf("account_number?: ");
	if(scanf("%d",&account_number) == 1){
		if(account_number < Range || account_number > 950){
			printf("This account number is not exist\n");
			return 0;
		}
		else if(Accounts[1][account_number - Range] == 0){
			printf("This account is closed\n");
			return 0;
		}
		return account_number;
	}
	else{
		printf("Invalid account number, Please try again.\n");
		return 0;
	}
}
// check the amount input/if valid
double Amount(){
	double amount;
	printf("amount?: ");
	if(scanf("%lF", &amount) == 1){
		if(amount < 0){
			printf("The amount must be positive\n");
			return 0;
		}
		return amount;
	}
	else{
		printf("Invalid amount, Please try again.\n");
		return 0;
	}
}

// check interest input/if valid
double Interest_rate(){
	double interest_rate;
	printf("Interest rate?: ");
	if(scanf("%lF",&interest_rate) == 1){
		if(interest_rate < 0){
			printf("Interest rate can't be lower then zero\n");
			return 0;
		}
		return interest_rate;
	}
	else{
		printf("Invalid interest rate, Please try again.\n");
		return 0;
	}
}




