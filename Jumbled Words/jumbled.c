//Mauricio Da Graca 04/01/2014
//Assignment 3
// User defined functions, character arrays, c style string member functions,
//Write an interactive program that will allow a user to play the game Jumble

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100


// function that displays the instructions on how to play the game. 
void instructions();
// function that plays one entire game
void playGame();
//wipes out the arrays as the new game starts
void clear(char default_array[SIZE]);
// function that creates the partial array ( an array of * , the same size as the word) 
void partialArray(char *solution, char *partial);
// function that returns the letter that the user has guessed.
char getLetter(char jumbled[SIZE], char partial[SIZE]);
// function that sets all of the characters in a word to the same case
char converts(char letter, int longitud);
//A function that locates and places the selected letter where it belongs in the * array.
void placeLetter(char partial[SIZE], char solution[SIZE], char letter);
//ask the user if they want to play again
void another(char *again);
//Compares the guess and the solution to see if the user wins
int right(char guess[SIZE], char jumbled[SIZE], char solution[SIZE], int chances);

int main()
{

	//function call to instructions
	instructions();

	//function call to play a 
	playGame();

}

void instructions()
{
	//Display instructions to the user.
	printf("Welcome to the JUMBLED game\n");
	printf("You will see the word in jumbled form.\n");
	printf("Pick a letter and I will show you where the letter belongs in the word.\n");
	printf("------Next you guess the word------\n");
	printf("You will have three guesses to figure it out!\n");
	printf("Enjoy!!! And GOOD LUCK.\n\n");
}

void playGame()
{
	FILE *cwords;
	int chances = 1;
	char solution[SIZE] = { '\0' };
	char jumbled[SIZE] = { '\0' };
	char again = 'y';
	char partial[SIZE] = { '\0' };
	char guess[SIZE] = { '\0' };
	int win = 0;
	char letter;


	//open file 
	cwords = fopen("getWords.txt", "r");

	{
		while (again != 'n')
		{
			clear(solution);
			clear(jumbled);
			clear(guess);
			clear(partial);
			fscanf(cwords, "%s", &jumbled);
			fscanf(cwords, "%s", &solution);
			partialArray(solution, partial);
			do

			{
				//function call to get the letter from the user
				letter = getLetter(jumbled, partial);
				printf("\n		------------ TRY TO GUESS ------------\n\n");
				//Give the lentgh of the word
				printf("Here is the jumbled word:\n\n		%s\n\n", jumbled);
				printf("Here is what you have so far:\n\n");
				placeLetter(partial, solution, letter);
				//show the partial to the user
				printf("		%s\n\n", partial);

				printf("Guess the word> ");
				scanf("%s", &guess);
				win = right(guess, jumbled, solution, chances);
				chances += 1;
			}

			while (chances <= 3 && win == 0);
			{
				if (win == 1)
				{
					another(&again);
					chances = 1;
				}
				else
				{
					printf("Lets try another time. Good luck next time\n\n");
					printf("--------------------------------------------------------------------------------\n\n");
					chances = 1;
					another(&again);
				}

			}
		}

	}
}

//function definition so the null character does not in
void clear(char default_array[SIZE])
{
	int i = 0;
	for (i = 0; i<SIZE; i++)
	{
		default_array[i] = '\0';
	}
}


void partialArray(char *solution, char *partial)
{
	int counter = 0;
	char current = 'a';
	int i;
	while (current != '\0')
	{
		counter++;
		current = solution[counter];
	}
	for (i = 0; i < counter; i++)
	{
		partial[i] = '*';
	}
}
char getLetter(char jumbled[SIZE], char partial[SIZE])
{
	char guess;
	char letter;
	int length = 0;
	printf("		~~~~~~~~~~~~ PICK A LETTER ~~~~~~~~~~~~~\n\n");
	printf("Here is the jumbled word:\n\n		%s\n", jumbled);
	printf("Here are the letters you have so far:\n\n ");
	printf("		%s\n\n", partial);
	printf("WHAT LETTER WOULD YOU LIKE TO PLACE?");
	scanf(" %c", &guess);
	letter = converts(guess, length);
}
char converts(char letter, int length)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		letter = tolower(letter);
	}
	return letter;
}

void placeLetter(char partial[SIZE], char solution[SIZE], char letter)
{
	int counter = 0;
	char current = 'a';
	while (current != '\0')
	{
		if (letter == solution[counter])
		{
			partial[counter] = letter;
		}
		counter++;
		current = solution[counter];
	}
}
//function that ask the user if they want to play again.

void another(char *again)
{
	printf("Do you want to play another game (y/n)?");
	scanf(" %c", again);
	printf("\n");

	*again = tolower(*again);

	if (*again != 'y' && *again != 'n')
	{
		printf("Invalid selection, please chose (y/n)\n");
	}
}
int right(char guess[SIZE], char jumbled[SIZE], char solution[SIZE], int chances)
{
	if (strcmp(guess, solution) == 0)
	{
		printf("\nYOU GUESSED IT CORRECT!!!!! NICE JOB.\n\n");
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
		return 1;
	}
	else
	{
		printf("\n\n------------You have guessed it wrong\n");
		printf("------------Try again\n\n");
		printf("That was guess %d\n", chances);


		return 0;
	}
}