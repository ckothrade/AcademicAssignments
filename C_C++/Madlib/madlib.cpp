
//MADLIB game program
//Program Description: This program allows the user to "fill in the blanks" on a madlib story.
//The user is first prompted for all the inputs needed (e.g. the name of a food, the name of 
//an animal, etc.), without seeing the story they will be inserted into.  Once all the inputs
//have been gathered, the program then automatically inserts them into the appropriate blanks
//in the story and prints the results for the user to read.

#include <iostream>
using namespace std;

void Welcome();//Prints a welcome message
void Input(string& instructorName, string& yourName, 
		   string& food, string& adjective, 
		   string& color, string& animal, double& number);//Inputs strings entered by the user for use in the madlib
void PrintMadlib(string instructorName, string yourName, 
		  	     string food, string adjective, 
			     string color, string animal, double number);//Prints the madlib with the user-entered strings inserted into the appropriate slots.

int main(){
	
	//These strings and double hold all the words that will be substituted into the madlib.
	string instructorName;
	string yourName;
	string food;
	string adjective;
	string color;
	string animal;
	double number = 0.0;
	
	Welcome();
	Input(instructorName, yourName, food, adjective, color, animal, number);
	PrintMadlib(instructorName, yourName, food, adjective, color, animal, number);

	
	return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Prints a welcome message
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Welcome(){
	cout << "Welcome to Madlib!\n\n";
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Inputs strings entered by the user for use in the madlib
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void Input(string& instructorName, string& yourName, 
		    string& food, string& adjective, 
		   string& color, string& animal, double& number){
	
	cout << "Enter the name of your Instructor: ";
	getline(cin, instructorName);
	cout << "Enter your name: ";
	getline(cin, yourName);
	cout << "Enter the name of a food: ";
	getline(cin, food);
	cout << "Enter an adjective: ";
	getline(cin, adjective);
	cout << "Enter the name of a color: ";
	getline(cin, color);
	cout << "Enter the name of a type of animal: ";
	getline(cin, animal);
	
	cout << "Enter a number between 100 and 120: ";
	//Check to see if the user entered a value between 100 and 120:
	while(true){
		
		cin >> number;
		
		if(cin.fail()){
			cout << "That's not a number. Please enter a number between 100 and 120: ";
			cin.clear();
			cin.ignore(999, '\n');
			continue;
		}
		else if(number > 120.0){
			cout << "Number is too large. Please enter a number between 100 and 120: ";
			continue;
		}
		else if(number < 100.0){
			cout << "Number is too small. Please enter a number between 100 and 120: ";
			continue;
		}
		else
			break;
			
	}
	
	
	
}


//------------------------------------------------------------------------------------------------------------------------------------------------------------
//Prints the madlib with the user-entered strings inserted into the appropriate slots
//------------------------------------------------------------------------------------------------------------------------------------------------------------
void PrintMadlib(string instructorName, string yourName, 
		  	     string food, string adjective, 
			     string color, string animal, double number){
	
	cout << "\n\nYour madlib:\n" << endl;
	
	cout << "Dear Professor " << instructorName << ",\n\n";
	cout << "I am sorry that I am unable to turn in my homework at this time." << endl;
	cout << "First, I ate a rotten " << food << ", which made me turn " << color << " and" << endl;
	cout << "extremely ill. I came down with a fever of " << number << "." << endl;
	cout << "Next, my " << adjective << " pet " << animal << " must have smelled the remains" << endl;
	cout << "of the " << food << " on my homework, because he ate it. I am currently" << endl;
	cout << "rewriting my homework and hope you will accept it late." << endl;
	cout << "\nSincerely," << endl;
	cout << yourName;
	
}


