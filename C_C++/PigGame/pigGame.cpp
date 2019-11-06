
//Pig game program
//Program Description: This program allows a human player to play a game of "Pig" against the computer.
//In "Pig," the two players take turns rolling a die.  After each roll, the total of all their rolls
//that turn are tallied up, and the player is then given the option to either roll again or hold.
//If the player chooses  to hold, all their points accumulated so far that turn are added to their
//point total.  If the player rolls a 1 at any point, all points accumulated during that turn are
//lost and their turn ends.  The first player to reach 100 or more total points is the winner.

#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;

//Declare Constants:
const int DICE_LOWER_LIMIT = 1;//Smallest number that can be rolled by the dice
const int DICE_UPPER_LIMIT = 6;//Largest number that can be rolled by the dice

//Function Prototypes:
void Welcome();//Prints a welcome message
int humanTurn(int humanTotalScore);//Handles the execution of the human player's turn; returns the human player's turn total to be added to their game total
int computerTurn(int computerTotalScore);//Handles the execution of the computer player's turn; returns the computer player's turn total to be added to their game total
void displayCurrentScores(int humanTotalScore, int computerTotalScore);//Prints the current total scores to the screen.
int rollDice();//Returns a random number from 1 to 6


int main(){
	
	//Declare variables:
	int humanTotalScore = 0;
	int computerTotalScore = 0;
	
	//Seed the random number generator:
	srand(time(NULL));
	
	//Display the welcome message:
	Welcome();
	
	//MAIN GAME LOOP: Loop until a victor emerges:
	while(true){
		humanTotalScore += humanTurn(humanTotalScore);
		if(humanTotalScore >= 100)//Break out of the loop if the human player has won...
			break;
		displayCurrentScores(humanTotalScore, computerTotalScore);//...Otherwise display the scores.
		computerTotalScore += computerTurn(computerTotalScore);
		if(computerTotalScore >= 100)//Break out of the loop if the computer player has won...
			break;
		displayCurrentScores(humanTotalScore, computerTotalScore);//...Otherwise display the scores.
	}
	
	//Display an appropriate victory message depending on who won:
	system("cls");
	cout << "\n\n";
	if(humanTotalScore >= 100)
		cout << "YOU WIN!!!" << endl;
	else
		cout << "Too bad, you lose. Keep trying!" << endl;
	
	//Display the final scores:
	cout << "The final scores:" << endl;
	cout << "HUMAN PLAYER: " << humanTotalScore << endl;
	cout << "COMPUTER PLAYER: " << computerTotalScore << "\n\n" << endl;
	
	
	return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Prints a welcome message
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Welcome(){
	cout << "---------------" << endl;
	cout << "Welcome to Pig!" << endl;
	cout << "---------------\n" << endl;
	cout << "Can you beat the computer?" << endl;
	cout << "Take turns rolling a die - the first player to reach 100 or more points wins!\n" << endl;
	system("pause");
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Handles the execution of the human player's turn; returns the human player's turn total to be added to their game total
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int humanTurn(int humanTotalScore){
	
	//Declare variables:
	int humanTurnScore = 0;//Holds the score the player has accumulated so far this turn
	int valueOfLastRoll = 0;//Holds the last value that was rolled by the die
	char playerChoice;//Holds an R if the player wishes to roll again, and an H if they want to hold.
	
	while(true){//Loops until the human player rolls a 1 or chooses to hold
		system("cls");//Clears the console, so that only the most recent turn is displayed
		cout << "\n\nIt is your turn!" << endl;//Remind the player that it is currently their turn.
		cout << "----------------" << endl;
		valueOfLastRoll = rollDice();//Roll the die
		
		if(valueOfLastRoll == 1){//If it's a 1, skip the human player's turn and return a 0 for the turn score
			cout << "You rolled a 1, so your turn gets skipped! Better luck next time!\n\n" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		else{//Otherwise, add the roll value to the turn score, and give the player the option of either rolling again or holding
			humanTurnScore += valueOfLastRoll;
			if(humanTurnScore + humanTotalScore >= 100){//If the human player's roll takes the total score over 100, the human player wins, so automatically hold...
				cout << "With that last roll, you're now over 100 points!" << endl;
				system("pause");
				return humanTurnScore;
			}
			else{//...Otherwise, if the human player's roll does not take the total score over 100, continue the turn as normal
				cout << "You rolled a " << valueOfLastRoll << "!\nThat makes your total score for this turn " << humanTurnScore << "." << endl;//Display the roll and the new total turn score
				cout << "If you choose to hold now, your overall score will be " << humanTurnScore + humanTotalScore << "." << endl;//Display what the total score will be if they choose to hold at this point
				do{//Loop until the player makes a selection by entering either a lowercase or uppercase R or H 
					cout << "Enter R to roll again, or H to hold: ";
					cin.sync();
					cin >> playerChoice;
					playerChoice = toupper(playerChoice);
				} while(playerChoice != 'R' && playerChoice != 'H');
				if(playerChoice == 'H')//If the player chooses to hold, return the turn score thus far.
					return humanTurnScore;
			}
		}
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Handles the execution of the computer player's turn; returns the computer player's turn total to be added to their game total
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int computerTurn(int computerTotalScore){
	//Declare variables:
	int computerTurnScore = 0;//Holds the score the player has accumulated so far this turn
	int valueOfLastRoll = 0;//Holds the last value that was rolled by the die
	
	while(true){//Loops until the computer player either rolls a 1 or reaches a turn score of 20
		system("cls");//Clears the console, so that only the most recent turn is displayed
		cout << "\n\nIt is the computer's turn!" << endl;//Remind the human player that it is currently the computer player's turn.
		cout << "----------------" << endl;
		valueOfLastRoll = rollDice();//Roll the die
		
		if(valueOfLastRoll == 1){//If it's a 1, skip the computer player's turn and return a 0 for the turn score
			cout << "The computer rolled a 1, so its turn gets skipped! Take that, computer!!\n\n" << endl;
			system("pause");
			system("cls");
			return 0;
		}
		else{//Otherwise, add the roll value to the turn score, and check to see if the turn score has gone over 20 yet
			computerTurnScore += valueOfLastRoll;
			if(computerTurnScore + computerTotalScore >= 100){//If the computer player's roll takes the total score over 100, the computer player wins, so automatically hold...
				cout << "Uh oh! With that last roll, the computer now has over 100 points!" << endl;
				system("pause");
				return computerTurnScore;
			}
			else{//...Otherwise, if the computer player's roll does not take its total score over 100, continue the turn as normal
				cout << "The computer rolled a " << valueOfLastRoll << "!\nThat makes its total score for this turn " << computerTurnScore << "." << endl;//Display the roll and the new total turn score
				cout << "If the computer were to hold now, its overall score would be " << computerTurnScore + computerTotalScore << "." << endl;//Display what the total score will be if they choose to hold at this point
				if(computerTurnScore >= 20){//If the computer player's score is 20 or higher, display a message saying the computer is holding and return its turn score thus far.
					cout << "**The computer chooses to hold**\nIts score is now " << computerTurnScore + computerTotalScore << ".\n\n" << endl;
					system("pause");
					return computerTurnScore;
				}
				else{//Otherwise, the computer will roll again.
					cout << "**The computer chooses to roll again**\n\n" << endl;
					system("pause");
				}
			}
		}
	}
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Prints the current total scores to the screen.
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void displayCurrentScores(int humanTotalScore, int computerTotalScore){
	system("cls");
	cout << "The current total scores:" << endl;
	cout << "HUMAN PLAYER: " << humanTotalScore << endl;
	cout << "COMPUTER PLAYER: " << computerTotalScore << "\n\n" << endl;
	system("pause");
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Returns a random number from 1 to 6
//------------------------------------------------------------------------------------------------------------------------------------------------------------
int rollDice(){
	return ((rand()%(DICE_UPPER_LIMIT-DICE_LOWER_LIMIT+1))+DICE_LOWER_LIMIT);
}

