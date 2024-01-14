#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main (void) {
	// Declared variables
	int pin=2903, option, enteredPin, count=0, count1=5, amount=0,continueProgram=1;
	float balance=5000;
	// Declared variables
	time_t now;
	time(&now);
	printf("%s", ctime(&now));
	printf("\n================ATM================");
	while (pin != enteredPin){
		printf("\nEnter pin to proceed\n");
		scanf("%d",&enteredPin);
	if (enteredPin !=pin) {
		printf("invalid pin");
	}
	count++;
	if (count==5 && pin!= enteredPin){
		exit (0);
	}
	}
	while(continueProgram!=0){
   printf("\n Select Transaction");
   printf("\n 1. Withdrawal");
   printf("\n 2. Deposit");
   printf("\n 3. check balance");
   scanf("%d",&option);
   switch(option) {
   	case 1: 
   	while (amount<=0){
   		printf("\nEnter the amount :");
   		scanf("%d", &amount);
   		if (amount<=0){
   			printf("invalid amount\n");
   		}
   		if (balance<amount){
   			printf("insufficient funds");
   			amount=0;
   }
   else {
   	balance-=amount;
   	printf("you have withdrawn $%d and your current balance is $%.2f",amount, balance);
   	}
   }
   case 2: 
   printf("enter the amount: ");
   scanf("%d", &amount);
   balance+=amount;
   printf("you have deposited $%d. your new balance is $%.2f", amount, balance);
   amount=0;
   break;
   
   case 3:
   printf("Your current balance is $%.2f", balance);
   break;
   
   default:
   puts("invalid option ");
}
printf("Do you which to perform another transaction? press 1[yes], 0[No]");
scanf("%d",&continueProgram);
system("cls");
}

	return 0;
}
