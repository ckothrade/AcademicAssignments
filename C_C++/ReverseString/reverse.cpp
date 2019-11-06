
//Reverse String
//Program Description: This program contains a function that utilizes pointers to reverse a string that has been input by the user.
//One pointer points to the first element of the string, and the second pointer points to the last character in the string before the
//terminating null.  The function procedes along; incrementing the pointers, swapping the "head" and "tail" elements one by one, until
//the head pointer >= the tail pointer.


#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <cstdlib> //for exit
using namespace std;


//Function prototypes:
bool ContinueProgram();//ContinueProgram: Prompts the user, asking them if they wish to continue the program.  Returns true if yes, false if no.
void input(string &userInput);//Inputs a string from the user.
string reverseString(string theString);//returns a reversed version of the string input as a parameter.

//-----------------------------//
//--------MAIN FUNCTION--------//
//-----------------------------//
int main(){
    
    //Delcare variables:
    string userString;//Holds a string to be reversed, as input by the user.
    
    //Main program loop
    do{
        input(userString);
        cout << endl;
        cout << "You entered:"<< endl << userString << endl;
        cout << "When reveresed, it looks like:" << endl;
        cout << reverseString(userString) << endl << endl;
        
        
    } while(ContinueProgram());
    
    return 0;
}


//------------------------------------------------------------------------------------------------------------------------//
//ContinueProgram: Prompts the user, asking them if they wish to continue the program.  Returns true if yes, false if no. //
//------------------------------------------------------------------------------------------------------------------------//
bool ContinueProgram(){
    
    char userChoice;//Holds the choice, y or n, input by the user.
    
    //Get and validate the user's choice
    do{
        cout << endl;
        cout << "Would you like to run the program again? (y/n): ";
        cin.sync();
        cin  >> userChoice;
        userChoice = tolower(userChoice);
    } while(userChoice != 'y' && userChoice != 'n');
    system("cls");
    
    //Return the user's choice, either to continue the program or end it:
    if(userChoice == 'y'){
        system("cls");
        cin.sync();
        return true;
    }
    else{
        cout << endl;
        cout << "Ending program..." << endl << endl;
        system("pause");
        cin.sync();
        return false;
    }
    
}

//------------------------------------------------------------------------------------------------------------------------//
//input: Inputs a string from the user.                                                                                   //
//------------------------------------------------------------------------------------------------------------------------//
void input(string &userInput){
    
    //Prompt the user to enter a string:
    cout << "Hit enter to start";
    cin.ignore();
    cout << endl;
    cout << "Enter a string: ";
    getline(cin, userInput);
    
}

//------------------------------------------------------------------------------------------------------------------------//
//reverseString: returns a reversed version of the string input as a parameter.                                           //
//------------------------------------------------------------------------------------------------------------------------//
string reverseString(string theString){
    
    //First, convert the string into a char array:
    char *stringAsCharArray = new char[theString.size()];//Create the char array that will hold the contents of theString.
    strcpy(stringAsCharArray, theString.c_str());//As far as I can tell, c_str() sort of "casts" theString as a
    //null-terminated array of characters, and then strcpy() copies this array into
    //stringAsCharArray.
    
    //Next, create the pointers that will initially point to the first and last characters in stringAsCharArray:
    char *head = stringAsCharArray;//Initially points to the first character in stringAsCharArray.
    char *tail = &stringAsCharArray[theString.size()-1];//Initially points to the last character in stringAsCharArray.
    
    //Finally, create the char that will temporarily store a value as part of the swap:
    char temp;
    
    //Loop through, swapping each head and tail value until the memory adress stored in head >= the memory address stored in tail:
    while(head < tail){
        temp = *head;
        *head = *tail;
        *tail = temp;
        head++;
        tail--;
    }
    
    //This constructor takes a null-terminated char array as an argument and creates a string object from it;
    //this effectively converts stringAsCharArray (which was reversed in the loop above) back into string form.
    string reversedString(stringAsCharArray);
    
    //Return the reversed string:
    return reversedString;
}
