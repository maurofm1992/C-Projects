//Mauricio Da Graca, 02/11/2015
//This is the first assignment of the semester and 
// is a game that consist in guessing a letter you can play as much as six times.



#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXGUESSES 5

//function prototypes with a comment for each one describing what the function does.
//Copy and paste from assignment
//this function provides instructions to the user on how to play the game
void GameRules();
//this function runs one game. It for checks either 5 incorrect guesses or correct guess.
//It returns a 0 if the game is over and the player did not guess the letter, otherwise it
//returns 1.
int PlayOneGame(char solution);
//this function prompts the player to make a guess and returns that guess
//this function is called from inside the PlayOneGame( ) function described above
char GetGuess();
//this function takes two arguments, the guess from the player
//and the solution letter from the file.
//It lets the user know if the guess comes alphabetically before or after the answer
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match
//this function is called from inside the PlayOneGame( ) function described above
int CompareSolutionToGuess(char guess, char solution);


int main()
{
	//declare additional variables
	//declare FILE pointer
	FILE *Ptr;
	char solution;
	int numGames = 0, i = 0, win = 1;

	//display instructions
	//function call to gamerules
	GameRules();
	//connect to the file HINT: use fopen
	Ptr= fopen("letters.txt", "r");

	//get number of games to play
	printf("How many games do you want to play?\n");
	printf("PLease enter a number 1 trough 6 > ");
	scanf("%d", &numGames);
	

	//this for loop will allow the player to play more than one game
	//without recompiling
	for (i = 0; i < numGames; i++)
	{
		printf("\nLets play Game %d", i+1); 
		printf("\n****************************");
		//get a letter from file - use fscanf
		fscanf(Ptr, " %c", &solution);
		//Play one game (Call PlayOneGame function)
		//function call to play one game
		win = PlayOneGame(solution);
		

		//tell the player if they have won or lost
		if (win == 0)
		{
			printf("\nSorry you lost, The answer is %c\n\n\n", solution);
		}
		else
		{
			printf("Congratulations, You Won!!\n\n\n");
		}
	
	
		
	}

	//close file 
	fclose(Ptr);
	return 0;

}


//Function definitions
void GameRules()
{
	printf("Welcome to Guess The Leter game\n");
	printf("First, you will enter the number of games you want to play (1-6 games)\n");
	printf("Then you have 5 chances for each game to guess each letter.\n");
	printf("Let's begin\n\n");
	printf("--------------------------------------------------------------------------------");
	return 0;
}
char GetGuess()
{
	char guess = 0;
	//User enters the guess
	printf("\n\nEnter your guess>");
	scanf(" %c", &guess);
	//returns the guess from the user
	return guess;
}
//copy and paste prototypes and comments from assignment. Then remove the ; from each
//this function takes two arguments, the guess from the player
//and the solution letter from the file.
//It lets the user know if the guess comes alphabetically before or after the answer
//The function returns 1 if the guess matches the solution and returns a 0 if they do not match
//this function is called from inside the PlayOneGame( ) function described above
int CompareSolutionToGuess(char guess, char solution)
{
	if ((guess) == (solution))
	{	
		return 1;
	}
	
	else if ((guess) < (solution))
	{
		printf("The letter: %c comes before the answer", guess);
		return 0;
	
	}
	else
	{
		printf("The letter: %c comes after the answer", guess);
		return 0;
	}
 
}

int PlayOneGame(char solution )
{
	int numGuesses = 0;
	int winOrLose = 0;//SHOULD BE INITIALZED TO 0
	char guess = 0; 


	//As long as the user  has not used up the maximum number
	//of guesses and has not guessed correctly 
	//the game will continue using this while loop
	while (numGuesses < MAXGUESSES && winOrLose == 0)
	{
		//function call to GetGuess
		guess = GetGuess();

		//function call to CompareSolutionToGuess
		winOrLose = CompareSolutionToGuess(guess, solution);

		//update counter for number of guesses used
		numGuesses = numGuesses + 1;
	}
	return winOrLose;


}