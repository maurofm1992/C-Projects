//Mauricio Da Graca 3/18/2015 
//New Bank Assignment 2
//This assigment consist in simulating the work of an ATM

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<ctype.h>
#define CREDIT 3000

// Displays the list of options available
//prompts for the user’s selection and sets the value of the selection
void RunChoices(int*choice);
//Asks the user which type of account they would like to access and sets the
//value of the selection
void SelectAccount(char*account);
//Prompts the user for the amount of deposit and updates the selected account
void AddMoney(double *acctMoney);
//Prompts the user for the amount of the withdrawal, determines if there are
//sufficient funds and updates the selected account if funds are dispensed
void RemoveMoney(double *acctMoney, char account);
//Displays the user’s current account balance for the selected account
void DisplayBalance(double balance, char account);
//Asks the user if they want another transaction
void MakeTransaction(char *again);

//Main function.
int main()

{
	int choice;
	char account;
	double acctMoney;
	double cbal = 800.00;
	double sbal = 1500.00;
	double rbal = -1100;
	char again = 'y';

	//Print greeting for the user
	printf("Hi, welcome to NEWBANK here is the account information:\n");
	printf("\nThere is $%.2f in the Checking\n", cbal);
	printf("	 $%.2f in the Savings\n", sbal);
	printf("	 $%.2f in Credit\n", rbal);

	while (again != 'y' && again != 'n')
	{
		printf("\nSorry %c is not an option.\n", again);
		printf("Please select a valid option: ");
		scanf("%d", &again);
	}


	// Displays the list of options available
	//prompts for the user’s selection and sets the value of the selection
	while (again == 'y')
	{ 
		RunChoices(&choice);
		printf("\nThe Transaction is > %d\n", choice);



		//call tne function Select the account
		SelectAccount(&account);
		printf("\nThe Account you selected is %c\n", account);

		//when they are making a deposit
		if (choice == 1)
		{
			if (account == 'c')
			{
				AddMoney(&cbal);
			}
			else if (account == 's')
			{
				AddMoney(&sbal);
			}
			else if (account == 'r')
			{
				AddMoney(&rbal);
			}
			else
				printf("Do not Know");

		}
		//when they are taking money out
		else if (choice == 2)
		{
			if (account == 'c')
			{
				RemoveMoney(&cbal, account);
			}
			else if (account == 's')
			{
				RemoveMoney(&sbal, account);
			}
			else if (account == 'r')
			{
				RemoveMoney(&rbal, account);
			}
			else
			{
				printf("Can't be done, Sorry");
			}
		}

		else if (choice == 3)
		{
			if (account == 'c')
			{
				DisplayBalance(cbal, account);
			}
			else if (account == 's')
			{
				DisplayBalance(sbal, account);
			}
			else if (account == 'r')
			{
				DisplayBalance(rbal, account);
			}
			else
			{
				printf("There has been no selection for an accout balance, Sorry.");
			}
		}
		else
		{
			printf("Do not know");
			MakeTransaction(&again);
		}
		MakeTransaction(&again);
	}
	//Asks the user if they want another transaction
	
	
}

void RunChoices(int *choice)
{
	int num;
	//Display a the accounts that are available
	printf("--------------------------------------------------------------------------------\n");
	printf("Please select the transaction you want to do today\n\n");
	printf("(1) for Deposit\n");
	printf("(2) for Withdraw\n");
	printf("(3) for Account Balance   ");
	//Get the selection from the user.
	scanf("%d", &num);
	
	//Loop that does not let you go further until the user enters a correct option.
	while (num != 1 && num != 2 && num != 3)
	{
		printf("\nSorry %d is not a valid option.\n", num);
		printf("-----------------------------------------------------------------------------\n\n");
		printf("Please select a valid option");
		scanf("%d", &num);
	}
	*choice = num;	
}

void MakeTransaction(char *again)
{
	//decalre any variables needed.
	char option;
	printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
	printf("\nWould you like to do another transaction?");
	printf("	\n\n(n) for NO.");
	printf("	\n(y) for YES.");
	scanf(" %c", &option);
	*again = option;
	if (option == 'y')
	{

	}
	else
	{
		printf("Thank you for banking at NEWBANK, have a nice day!!!\n\n");
	}
	
}

void SelectAccount(char *account)

{
	char letter;
	//Display a the accounts that are available
	printf("--------------------------------------------------------------------------------\n");
	printf("Please select the account.\n\n");
	printf("(c) Checking Account\n");
	printf("(s) Savings Account\n");
	printf("(r) Credit Account    ");
	//Get the account from the user
	scanf(" %c", &letter);
	//Loop that  will not let the user go further until they enter a correct account.
	while (letter != 'c' && letter != 's' && letter != 'r')
    {
		printf("Sorry %c is not an account in the system.\n", letter);
		printf("Please select a valid account: ");
		scanf("%c", &letter);
	}
	*account = letter;

}

//Prompts the user for the amount of deposit and updates the selected account
void AddMoney(double *acctMoney)
{
	//declare any variables needed.
	double amount, total;
	printf("********************************************************************************\n");
	//ask the user for an amount and get it
	printf("Enter the amount you want to deposit > ");
	scanf("%lf", &amount);
	printf("\n***The amount you entered is = $%.2f***", amount);

	//Math 
	total = *acctMoney + amount;
	*acctMoney = total;
	//gives the new balance to the user after the transaction
	printf("\n\nThe New balance in the Account is $%.2f\n", *acctMoney);
}

//Prompts the user for the amount of the withdrawal, determines if there are
//sufficient funds and updates the selected account if funds are dispensed
void RemoveMoney(double *acctMoney, char account)

//compare the desired amount to be withdrawn

//with how much is actually available in the account

{
	//Declare the variables
	double amount;
	double total;
	printf("********************************************************************************\n");
	printf("Enter the amount you want to withdraw: ");
	scanf("%lf", &amount);
	printf("***The amount you entered is $%.2f\n", amount);
	printf("\n-------------------------------------------------------------------------------\n");
	//there are two options
	if (account == 'c' || account == 's')
	{
		//not enough money to make the withdrawl
		while (amount >= *acctMoney)
		{
			printf("Sorry, you do not have enough funds.\n");
			printf("Please enter a new amount: ");
			scanf("%lf", &amount);
			printf("\n-------------------------------------------------------------------------------\n");

		}
		//Math
		total = *acctMoney - amount;
		*acctMoney = total;
		printf("The new balance in the Account is $%.2f.\n", total);
	}

	else if (account == 'r')
	{
		//Make sure the user does not go below the -3000
		if (amount - *acctMoney <= CREDIT)
		{
			total = *acctMoney - amount;
			*acctMoney = total;
			printf("\n\nThe balance of the Account is = $%.2f\n", *acctMoney);
			printf("\n-------------------------------------------------------------------------------\n");
		}
		else
		{
			//does not let the credit go below 0.
			while (amount - *acctMoney >= CREDIT)
			{
				printf("You exceeded the credit limit\n");
				printf("Sorry, please enter a different amount. ");
				scanf("%lf", &amount);	
				printf("\n-------------------------------------------------------------------------------\n");
			}
			//Math
			total = *acctMoney - amount;
			*acctMoney = total;
			printf("The new balance in the Account is $%.2f.\n", total);
		}
	}
}

//Displays the user’s current account balance for the selected account
void DisplayBalance(double balance, char account)
{
	if (account == 'c' || account == 's' || account == 'r')
	{
		printf("********************************************************************************\n\n");
		printf("The balance of your Account is = %.2f\n", balance);
	}
}