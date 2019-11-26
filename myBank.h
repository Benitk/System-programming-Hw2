#ifndef __MYBANK_H__
#define __MYBANK_H__

void open_account(double);
void balance(int);
void deposit(int, double);
void withdrawal(int, double);
void close_account(int);
void interest_add(double);
void print_accounts();
void exit_prog();
int isAccount();
double Amount();
double Interest_rate();

#endif /* MYBANK_H_ */
