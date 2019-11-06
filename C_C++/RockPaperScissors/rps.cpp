
//ROCK, PAPER, SCISSORS game program
//Program Description:  Two players are each allowed to input their choice of either rock, paper, or scissors.
//This program then determines the winner based on their choices.  The players can play as many games as they
//want, and the program will keep a running score on how many wins each player has had and how many ties there
//were.

#include <iostream>
#include <cctype>
using namespace std;

//Function prototype declarations:
void Welcome();//Prints the program's title
void Input(char& player1Choice, char& player2Choice);//Inputs each player's choice of either rock, paper, or scissors and checks that the input is correct
void CheckOutcome(char player1Choice, char player2Choice, unsigned char& outcome);//Checks to see which player won, or if the game ended in a tie
void TallyScores(unsigned char outcome, unsigned long& player1Wins, unsigned long& player2Wins, unsigned long& ties);//Keeps track of the total amount of games each player has won, and how many ties there were.  Displays these results after each game. 

int main(){
	
	//The following is a list of all the variables used in this program:
	char player1Choice;//Holds player 1's choice (R for Rock, P for Paper, and S for Scissors)
	char player2Choice;//Holds player 2's choice (R for Rock, P for Paper, and S for Scissors)
	unsigned char outcome;//Holds a number representing the outcome of the game (0 for tie, 1 for player 1 victory, 2 for player 2 victory)
	unsigned long player1Wins = 0;//Stores player 1's total number of victories so far
	unsigned long player2Wins = 0;//Stores player 2's total number of victories so far
	unsigned long ties = 0;//Stores the total number of ties so far
	char playAgain;//If the users wish to play again, they enter Y or y.  Any other entry terminates the program.
	
	Welcome();
	
	do{//Main program loop
		
		//These functions run the game and then tally and print the scores:
		Input(player1Choice, player2Choice);
		CheckOutcome(player1Choice, player2Choice, outcome);
		TallyScores(outcome, player1Wins, player2Wins, ties);
		
		//Ask if the player wants to continue the program or quit:
		cout << "Play again? Y/y continues, other quits: ";
		cin >> playAgain;
		cin.ignore(999, '\n');//This line is necessary to ignore any characters input after the initial character.
							  //Otherwise the loop will procede through every character entered before accepting new input.
		
	} while(playAgain == 'y' || playAgain == 'Y');

	
	return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Prints the program's title
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Welcome(){
	cout << "Welcome to Rock, Paper, Scissors!\n\n";
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Inputs each player's choice of either rock, paper, or scissors and checks that the input is correct
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Input(char& player1Choice, char& player2Choice){
	
	do{
		cout << "Player 1: Please enter either (R)ock, (P)aper, or (S)cissors: ";
		cin >> player1Choice;
		cin.ignore(999, '\n');
		player1Choice = toupper(player1Choice);
	} while(player1Choice != 'R' && player1Choice != 'P' && player1Choice != 'S');
	
	do{
		cout << "Player 2: Please enter either (R)ock, (P)aper, or (S)cissors: ";
		cin >> player2Choice;
		cin.ignore(999, '\n');
		player2Choice = toupper(player2Choice);
	} while(player2Choice != 'R' && player2Choice != 'P' && player2Choice != 'S');
	
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Checks to see which player won, or if the game ended in a tie
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void CheckOutcome(char player1Choice, char player2Choice, unsigned char& outcome){
	
	if(player1Choice == player2Choice){//Check for a tie first.
		cout << "\nIt's a tie!\n\n";
		outcome = 0;
		return;
	}
	else if(player1Choice == 'R'){//Determine who wins if Player 1 picks Rock.
		if(player2Choice == 'P'){
			cout << "\nPlayer 2 wins!\n\n";
			outcome = 2;
			return;
		}
		else{
			cout << "\nPlayer 1 wins!\n\n";
			outcome = 1;
			return;
		}
	}
	else if(player1Choice == 'P'){//Determine who wins if Player 1 picks Paper.
		if(player2Choice == 'S'){
			cout << "\nPlayer 2 wins!\n\n";
			outcome = 2;
			return;
		}
		else{
			cout << "\nPlayer 1 wins!\n\n";
			outcome = 1;
			return;
		}
	}
	else if(player1Choice == 'S'){//Determine who wins if Player 1 picks Scissors.
		if(player2Choice == 'R'){
			cout << "\nPlayer 2 wins!\n\n";
			outcome = 2;
			return;
		}
		else{
			cout << "\nPlayer 1 wins!\n\n";
			outcome = 1;
			return;
		}
	}	
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Keeps track of the total amount of games each player has won, and how many ties there were.  Displays these results after each game. 
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void TallyScores(unsigned char outcome, unsigned long& player1Wins, unsigned long& player2Wins, unsigned long& ties){
	
	//Add the current outcome to the total:
	if(outcome == 1)
		player1Wins++;
	else if(outcome == 2)
		player2Wins++;
	else if(outcome == 0)
		ties++;
	
	//Print the results to the screen:
	cout << "Scores after this play:" << endl;
	cout << "Player 1: " << player1Wins << endl;
	cout << "Player 2: " << player2Wins << endl;
	cout << "Ties: " << ties << endl;
	cout << endl;
	
}

