// Mauricio Da Graca 04/20/15	
// Programming assignment 4
// Create an inventory 
// Intro to Programming in C

#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define SIZE 20


// The struct holds the name of the item, brand, id #, quantity in the store
// the value and average total in the stock.
typedef struct{
	char item[SIZE];
	char brand[SIZE];
	int id;
	int qty;
	double cost;
	double price;
} soccerShoe;

//Function prototypes

// Displays the manu
void Menu();
//Fill up the first five shoes
int fillFive(soccerShoe shoes[]);
//prints the first five shoes
void print(soccerShoe items[], int number);
//Save the items in the file 
void save(soccerShoe items[], int number);
//Display the options and ask the user whats does he wants to do
char decision();
//Adds an item to the catalog.
void add(soccerShoe shoes[], int number);
//Deletes an item in the catalog and the empty space its replace 
//by the las item in the catalog
void delete(soccerShoe new[], int *number);
//Searches through an array to delete an item
int search(soccerShoe find[], int *num);
//Modyfies the price of the item
void modify(soccerShoe change[], int num);


int main()
{
	//Declare all the variables needed
	char lettter;
	int num = 5;
	soccerShoe temp[SIZE];
	char option= ' ';

	//Display the menu.
	Menu ();
	//Fill Five function.
	num = fillFive(temp);
	
	//Display the options and get the option form the user
	option = decision();
	
	while (option != 'q')
	{
		
		if (option == 'p')
		{
			// prints the items already listed on the stock
			print(temp, num);
			option = decision();
			
		
			
		}
		else if (option == 's')
		{
			//saves the items into a txt document.
			save(temp, num);
			option = decision();
			
			
		}
		else if (option == 'a')
		{
			//adds a new item to the inventory.
			add(temp, num);
			option = decision();
			num = num + 1;
			

		}
		else if (option == 'd')
		{
			delete(temp, &num);
			option = decision();
		}		
		else if (option == 'c')
		{
			num = 0;
			option = decision();
		}
		else if (option == 'm')
		{
			modify(temp, &num);
			option = decision();
		}
			
	}
	printf("Good Bye\n");
}

void Menu()
{
	//Greets the user
	printf("WELCOME TO THE STOCK ORGANIZER.\n\n");
	printf("	This program will help you organizing your soccer shoes store.\n");
	printf("	To get started, 5 shoes have already been entered.\n");
}


void print(soccerShoe items[], int number)
{
	int i;
	if (number == 0)
		printf("\n\n------------The catalog is empty-----------");
	for (i = 0; i < number; i++)
	{
		printf("\n\n----------Item Entry# %d----------\n\n", i + 1);
		printf("Name:   %s", items[i].item);
		printf("\nBrand:  %s\n", items[i].brand);
		printf("ID:     %d\n", items[i].id);
		printf("QTY:    %d\n", items[i].qty);
		printf("Cost:   %.2f\n", items[i].cost);
		printf("Price:  %.2f", items[i].price);
		
	}
	
	

}

void save(soccerShoe items[], int number)
{
	int i;
	FILE *doc;

	//open file
	doc = fopen("log.txt", "w");
	
	for (i = 0; i < number; i++)
	{

		//print the items on to a file
		fprintf(doc, "\n\n----------Item Entry# %d----------\n\n", i + 1);
		fprintf(doc, "Name:   %s", items[i].item);
		fprintf(doc, "\nBrand:  %s\n", items[i].brand);
		fprintf(doc, "ID:     %d\n", items[i].id);
		fprintf(doc, "QTY:    %d\n", items[i].qty);
		fprintf(doc, "Cost:   %.2f\n", items[i].cost);
		fprintf(doc, "Price:  %.2f", items[i].price);
	}
	
	fclose(doc);
}

char decision()
{
	//Display the options for the user
	char enter;
	printf("\n\n-------------------------------------------\n");
	printf("Please select an option:\n");
	printf("A - ADD a new entry\n");
	printf("D - DELETE an entry\n");
	printf("P - PRINT entire catalog\n");
	printf("S - SAVE the current catalog\n");
	printf("C - CLEAR the entire catalog\n");
	printf("M - MODIFY the price\n");
	printf("Q - QUIT\n");
	printf("What would you like to do: ");
	scanf(" %c", &enter);

	return enter;
}

void add(soccerShoe shoes[], int number)
{
	//promps and gets the info from the user
	printf("\nPlease enter the name: ");
	scanf("%s", &shoes[number].item);
	printf("Please enter the brand: ");
	scanf("%s", &shoes[number].brand);
	printf("Please enter the I.D# ");
	scanf("%d", &shoes[number].id);
	printf("Please enter the QTY: ");
	scanf("%d", &shoes[number].qty);
	printf("Please enter the cost: ");
	scanf("%lf", &shoes[number].cost);
	printf("Please enter the price: ");
	scanf("%lf", &shoes[number].price);

}

void delete(soccerShoe new[], int *number)
{
	int found = 0;
	found = search(new, number);
	if (found == -1)
	{
		printf("error");
	}
	new[found] = new[*number - 1];
	*number = *number - 1;
}

int search(soccerShoe find[], int *num)
{
	int *target = 0;
	int i;
	
	//Show the ids for the user
	for(i = 0; i < *num; i++)
	{
		printf("%d ,", find[i].id);
	}
	//prompt to get id
	printf("Enter the ID : ");
	scanf("%d", &target);
	
	//Locate  and return index
	for (i = 0; i < target; i++)
	{
		if (target == find[i].id)
			return i;
	}
	return -1;
}

void modify(soccerShoe change[], int num)
{
	int found = 0;
	double newprice;
	found = search(change, num);
	if (found == -1)
	{
		printf("error");
	}
	//shows the user the item that was picked.
	printf("\n\n----------Item Entry# %d----------\n\n",  found + 1);
	printf("Name:   %s", change[found].item);
	printf("\nBrand:  %s\n", change[found].brand);
	printf("ID:     %d\n", change[found].id);
	printf("QTY:    %d\n", change[found].qty);
	printf("Cost:   %.2f\n", change[found].cost);
	printf("Price:  %.2f", change[found].price);
	//ask the user the price that they want to put 
	printf("\n\nPlease enter the updated price:");
	scanf("%lf", &change[found].price);
}



int fillFive(soccerShoe shoes[])
{
	int num;
	
	//Item number 1
	strcpy(shoes[0].item, "Mercurial");
	strcpy(shoes[0].brand, "Nike");
	shoes[0].id = 150;
	shoes[0].qty = 200;
	shoes[0].cost = 60.00;
	shoes[0].price = 79.99;

	//Item number 2
	strcpy(shoes[1].item, "Figo");
	strcpy(shoes[1].brand, "Addidas");
	shoes[1].id = 170;
	shoes[1].qty = 180;
	shoes[1].cost = 80.00;
	shoes[1].price = 94.99;
	
	//Item number 3
	strcpy(shoes[2].item, "CR7 fly");
	strcpy(shoes[2].brand, "Nike");
	shoes[2].id = 400;
	shoes[2].qty = 200;
	shoes[2].cost = 90.00;
	shoes[2].price = 125.99;

	//Item number 4
	strcpy(shoes[3].item, "Zlatan");
	strcpy(shoes[3].brand, "Umbro");
	shoes[3].id = 350;
	shoes[3].qty = 150;
	shoes[3].cost = 45.00;
	shoes[3].price = 57.99;

	//Item number 5
	strcpy(shoes[4].item, "Tiempo");
	strcpy(shoes[4].brand, "Puma");
	shoes[4].id = 470;
	shoes[4].qty = 100;
	shoes[4].cost = 60.00;
	shoes[4].price = 80.00;

	num = 5;
	return num;

}