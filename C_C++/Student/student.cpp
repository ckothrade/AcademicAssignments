
//Student Class & Student Class Test Program
//Program Description: The Student class stores a student's name, number of courses he/she is enrolled in, and the names of those courses.
//(The maximum amount of courses a student can be enrolled in is determined by the constant MAX_CLASSES)
//The Student class also provides functions to allow the user to input this data, output the data to the screen, and to reset the data.
//The main function allows the user to test the Student class's input, output, and reset functions as many times as they like.

#include <iostream>
#include <string>
using namespace std;


//Function prototypes:
bool ContinueProgram();//Prompts the user, asking them if they wish to continue the program.  Returns true if yes, false if no.

//Class delcarations:
class Student {
public:
    //CONSTRUCTORS:
    Student(){numClasses = 0;}
    //OTHER FUNCTIONS:
    void input();//Allows the user to enter values for name, numClasses, and classList.
    //(There are no setters for this class.  You must use input() if you wish to change the object's data.)
    void output();//Prints name, numClasses, and classList to the screen.
    void reset();//Resets numClasses to 0 and clears classList. name remains unchanged.
    //GETTERS:
    string getName(){return name;}
    int getNumClasses(){return numClasses;}
    string getClass(int classNumber){return classList[classNumber];}
private:
    static const int MAX_CLASSES = 7;//This is the maximum number of courses a student can be enrolled in.
    string name;//The student's name.
    int numClasses;//The number of courses the student is currently enrolled in.
    string classList[MAX_CLASSES];//A list containing the names of the courses the student is enrolled in.
    //They may be enrolled in fewer than the maximum number of classes as defined
    //by the constant MAX_CLASSES, but they cannot be enrolled in more classes
    //than the limit set by MAX_CLASSES.
};


int main(){
    
    Student student1;
    
    do{
        student1.input();
        student1.output();
        student1.reset();
    } while(ContinueProgram());
    
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------//
//ContinueProgram: Prompts the user, asking them if they wish to continue the program.  Returns true if yes, false if no.//
//-----------------------------------------------------------------------------------------------------------------------//
bool ContinueProgram(){
    
    char userChoice;//Holds the choice, y or n, input by the user.
    
    //Get and validate the user's choice
    do{
        cout << endl;
        cout << "Would you like to enter the data again? (y/n): ";
        cin.sync();
        cin  >> userChoice;
        userChoice = tolower(userChoice);
        cin.ignore();
        system("cls");
    } while(userChoice != 'y' && userChoice != 'n');
    
    //Return the user's choice, either to continue the program or end it:
    if(userChoice == 'y'){
        cout << endl;
        cout << "Restarting program..." << endl << endl;
        system("pause");
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

//###########################//
//# Student Class Functions #//
//###########################//

//---------------------------------------------------------------------------//
//input: Allows the user to enter values for name, numClasses, and classList.//
//---------------------------------------------------------------------------//
void Student::input(){
    
    //Input the student's name:
    cout << endl;
    cout << "Please input the student's name: ";
    getline(cin, name);
    
    //Input the number of classes the student will be enrolled in:
    cout << endl;
    cout << "Next, input the number of classes this student will be enrolled in," << endl;
    cout << "up to a maximum of " << MAX_CLASSES << ": ";
    //Input validation loop:
    while(true){
        
        cin >> numClasses;//Get input...
        
        //...Then check it:
        if(cin.fail()){
            cout << "That's not a number. Please enter a number between 1 and " << MAX_CLASSES << ": ";
            cin.clear();
            cin.sync();
            continue;
        }
        else if(numClasses > MAX_CLASSES){
            cout << "Number is too large. Please enter a number between 1 and " << MAX_CLASSES << ": ";
            continue;
        }
        else if(numClasses < 1){
            cout << "Number is too small. Please enter a number between 1 and " << MAX_CLASSES << ": ";
            continue;
        }
        else
            break;
        
    }
    cin.sync();//Flush the input buffer. This is necessary because I used cin in the loop above instead of getline(),
    //which means the newline character gets left in the stream and gets input as the first class name
    //in the loop below.
    
    //Input the names of the classes the student is enrolled in:
    cout << endl;
    cin.ignore();
    cout << "Please input the names of these " << numClasses << " classes:" << endl;;
    for(int i = 0; i < numClasses; i++){
        cout << "Class #" << i+1 << ": ";
        getline(cin, classList[i]);
    }
    
    system("cls");//After input has been taken, clear the screen.
}

//-------------------------------------------------------------//
//output: Prints name, numClasses, and classList to the screen.//
//-------------------------------------------------------------//
void Student::output(){
    
    cout << endl;
    cout << name << " is enrolled in the following courses:" << endl;
    for(int i = 0; i < numClasses; i++){
        cout << classList[i] << endl;
    }
    
    cout << endl;
    system("pause");//Allow the user to view the data before continuing.
    system("cls");//After user has finished viewing the data, clear the screen.
}

//---------------------------------------------------------------------------//
//reset: Resets numClasses to 0 and clears classList. name remains unchanged.//
//---------------------------------------------------------------------------//
void Student::reset(){
    
    numClasses = 0;//Reset numClasses to 0...
    
    for(int i = 0; i < MAX_CLASSES; i++){//...And fill classList with null characters.
        classList[i] = "\0";
    }
    
}
