
//   This program consists of:
// - Ship Class and its two derived classes, CruiseShip and CargoShip
// - Code for testing the functionality of these three classes

//Program Description: This program contains the Ship class and its two derived classes, CruiseShip and CargoShip.  See the class descriptions below for more details.
//This program's main function is designed to allow the user to test these three classes.


#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib> //for exit
using namespace std;

//Class delcarations:
//##################//
//#   Ship Class   #//
//##################//
//Description: Stores the name of a ship and the year it was built.  Provides a print() function
//that outputs the ship's name and the year it was built.

class Ship {
public:
    //CONSTRUCTORS:
    Ship()
    :name("ERROR: NO NAME STORED"), yearBuilt(-1)// -1 for yearBuilt signifies that no proper yearBuilt has been input yet
    {/*Intentionally left empty*/}
    Ship(string shipName, int yearShipBuilt)
    :name(shipName), yearBuilt(yearShipBuilt)
    {/*Intentionally left empty*/}
    //OTHER FUNCTIONS:
    void print() const;//Prints the ship's name and the year it was built.
    //GETTERS:
    string getName() const {return name;}
    int getYearBuilt() const {return yearBuilt;}
    //SETTERS:
    void setName(string shipName){name = shipName;}
    void setYearBuilt(int yearShipBuilt){yearBuilt = yearShipBuilt;}
private:
    string name;
    int yearBuilt;
};

//####################//
//# CruiseShip Class #//
//####################//
//Description: Derived from Ship class.  Adds an integer datafield for the maximum number of passengers that the
//cruise ship can carry, and overrides the print() function so that it only prints the cruise ship's name and max
//number of passengers.

class CruiseShip: public Ship {
public:
    //CONSTRUCTORS:
    CruiseShip()
    :Ship(), maxPassengers(-1)// -1 for maxPassengers signifies that no proper maxPassengers has been input yet
    {/*Intentionally left empty*/}
    CruiseShip(string shipName, int yearShipBuilt, int shipMaxPassengers)
    :Ship(shipName, yearShipBuilt), maxPassengers(shipMaxPassengers)
    {/*Intentionally left empty*/}
    //OTHER FUNCTIONS:
    void print() const;//Overrides the print() in Ship class; this print() only prints the name of the ship and the maximum number of passengers
    //GETTERS:
    int getMaxPassengers() const {return maxPassengers;}
    //SETTERS:
    void setMaxPassengers(int shipMaxPassengers){maxPassengers = shipMaxPassengers;}
private:
    int maxPassengers;
};

//####################//
//# CargoShip Class #//
//####################//
//Description: Derived from Ship class.  Adds an integer datafield for the cargo capacity in tonnage,
//and overrides the print() function so that it only prints the cargo ship's name and its cargo capacity.

class CargoShip: public Ship {
public:
    //CONSTRUCTORS:
    CargoShip()
    :Ship(), cargoCapacity(-1)// -1 for cargoCapacity signifies that no proper cargoCapacity has been input yet
    {/*Intentionally left empty*/}
    CargoShip(string shipName, int yearShipBuilt, int shipCargoCapacity)
    :Ship(shipName, yearShipBuilt), cargoCapacity(shipCargoCapacity)
    {/*Intentionally left empty*/}
    //OTHER FUNCTIONS:
    void print() const;//Overrides the print() in Ship class; this print() only prints the name of the ship and the cargo capacity
    //GETTERS:
    int getCargoCapacity() const {return cargoCapacity;}
    //SETTERS:
    void setCargoCapacity(int shipCargoCapacity){cargoCapacity = shipCargoCapacity;}
private:
    int cargoCapacity;//in tonnage.
};

//Function prototypes:
bool ContinueProgram();//ContinueProgram: Prompts the user, asking them if they wish to continue the program.  Returns true if yes, false if no.
void inputShip(string &name, int &yearBuilt);//Inputs the data necessary for the creation of a Ship object.
void inputCruiseShip(string &name, int &yearBuilt, int &maxPassengers);//Inputs the data necessary for the creation of a CruiseShip object.
void inputCargoShip(string &name, int &yearBuilt, int &cargoCapacity);//Inputs the data necessary for the creation of a CargoShip object.


//-----------------------------//
//--------MAIN FUNCTION--------//
//-----------------------------//
int main(){
    
    //Delcare variables:
    string name = "---ERROR---";//Holds a ship's name as input by the user. The default value is ---ERROR-- so that the user will know if a name has not been properly input
    int yearBuilt = -1;//Holds the year a ship was built as input by the user.
    int maxPassengers = -1;//Holds the max passengers a cruise ship can hold as input by the user.
    int cargoCapacity = -1;//Holds the cargo capacity of a cargo ship as input by the user.
    
    //Main program loop - used to test objects of Ship, CruiseShip, and CargoShip classes:
    do{
        //Test the default constructor for Ship class and set member variables using mutators:
        cout << endl;
        cout << "Create a ship:";
        Ship ship1;
        inputShip(name, yearBuilt);
        ship1.setName(name);
        ship1.setYearBuilt(yearBuilt);
        
        //Now, test setting member variables using the constructor:
        cout << endl;
        cout << "Create another ship:";
        inputShip(name, yearBuilt);
        Ship ship2(name, yearBuilt);
        
        //Test the default constructor for CruiseShip class and set member variables using mutators:
        cout << endl;
        cout << "Create a cruise ship:";
        CruiseShip cruiseShip1;
        inputCruiseShip(name, yearBuilt, maxPassengers);
        cruiseShip1.setName(name);
        cruiseShip1.setYearBuilt(yearBuilt);
        cruiseShip1.setMaxPassengers(maxPassengers);
        
        //Now, test setting member variables using the constructor:
        cout << endl;
        cout << "Create another cruise ship:";
        inputCruiseShip(name, yearBuilt, maxPassengers);
        CruiseShip cruiseShip2(name, yearBuilt, maxPassengers);
        
        //Test the default constructor for CargoShip class and set member variables using mutators:
        cout << endl;
        cout << "Create a cargo ship:";
        CargoShip cargoShip1;
        inputCargoShip(name, yearBuilt, cargoCapacity);
        cargoShip1.setName(name);
        cargoShip1.setYearBuilt(yearBuilt);
        cargoShip1.setCargoCapacity(cargoCapacity);
        
        //Now, test setting member variables using the constructor:
        cout << endl;
        cout << "Create another cargo ship:";
        inputCargoShip(name, yearBuilt, cargoCapacity);
        CargoShip cargoShip2(name, yearBuilt, cargoCapacity);
        
        
        //Test the print function and display for the user all the ships they have created:
        cout << endl;
        cout << "Here are all the ships you created:" << endl << endl;
        cout << "Generic Ships:";
        ship1.print();
        ship2.print();
        cout << endl;
        cout << "Cruise Ships:";
        cruiseShip1.print();
        cruiseShip2.print();
        cout << endl;
        cout << "Cargo Ships:";
        cargoShip1.print();
        cargoShip2.print();
        
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

//-----------------------------------------------------------------------------------------------------------------------//
//inputShip: Inputs the data necessary for the creation of a Ship object.                                                //
//-----------------------------------------------------------------------------------------------------------------------//
void inputShip(string &name, int &yearBuilt){
    
    
    
    //Prompt the user to enter a value for name:
    cout << endl;
    cout << "Enter the name of the ship: ";
    cin.ignore();
    getline(cin, name);
    
    //Prompt the user to enter a value for yearBuilt:
    cout << "Enter the year the ship was built: ";
    
    //Get input for yearBuilt and loop until its validated:
    while(true){
        
        cin >> yearBuilt;//Get input...
        
        //...Then check it:
        if(cin.fail()){
            cout << "ERROR: That's not a valid input for year built." << endl;
            cout << "Please enter the year the ship was built: ";
            cin.clear();
            cin.sync();
            continue;
        }
        else if(yearBuilt < 1){
            cout << "ERROR: That's not a valid input for year built." << endl;
            cout << "Please enter the year the ship was built: ";
            continue;
        }
        else
            break;
        
    }
    cin.sync();//Flush the input buffer in order to rid the input stream of any pesky newline characters.
}

//-----------------------------------------------------------------------------------------------------------------------//
//inputCruiseShip: Inputs the data necessary for the creation of a CruiseShip object.                                    //
//-----------------------------------------------------------------------------------------------------------------------//
void inputCruiseShip(string &name, int &yearBuilt, int &maxPassengers){
    
    inputShip(name, yearBuilt);//Use inputShip() to get name and yearBuilt first...
    
    //...now get maxPassengers:
    //Prompt the user to enter a value for maxPassengers:
    cout << "Enter the max number of passengers this ship can hold: ";
    
    //Get input for yearBuilt and loop until its validated:
    while(true){
        
        cin >> maxPassengers;//Get input...
        
        //...Then check it:
        if(cin.fail()){
            cout << "ERROR: That's not a valid input for max passengers." << endl;
            cout << "Please enter the max number of passengers this ship can hold: ";
            cin.clear();
            cin.sync();
            continue;
        }
        else if(maxPassengers < 1){
            cout << "ERROR: That's not a valid input for max passengers." << endl;
            cout << "Please enter the max number of passengers this ship can hold: ";
            continue;
        }
        else
            break;
        
    }
    cin.sync();//Flush the input buffer in order to rid the input stream of any pesky newline characters.
    
}

//-----------------------------------------------------------------------------------------------------------------------//
//inputCargoShip: Inputs the data necessary for the creation of a CargoShip object.                                      //
//-----------------------------------------------------------------------------------------------------------------------//
void inputCargoShip(string &name, int &yearBuilt, int &cargoCapacity){
    
    inputShip(name, yearBuilt);//Use inputShip() to get name and yearBuilt first...
    
    //...now get cargoCapacity:
    //Prompt the user to enter a value for cargoCapacity:
    cout << "Enter this ship's cargo capacity: ";
    
    //Get input for yearBuilt and loop until its validated:
    while(true){
        
        cin >> cargoCapacity;//Get input...
        
        //...Then check it:
        if(cin.fail()){
            cout << "ERROR: That's not a valid input for cargo capacity." << endl;
            cout << "Please enter this ship's cargo capacity: ";
            cin.clear();
            cin.sync();
            continue;
        }
        else if(cargoCapacity < 1){
            cout << "ERROR: That's not a valid input for cargo capacity." << endl;
            cout << "Please enter this ship's cargo capacity: ";
            continue;
        }
        else
            break;
        
    }
    cin.sync();//Flush the input buffer in order to rid the input stream of any pesky newline characters.
}


//############################//
//#   Ship Class Functions   #//
//############################//

//--------------------------------------------------------------//
//print: Prints the ship's name and the year it was built.      //
//--------------------------------------------------------------//
void Ship::print() const{
    cout << endl;
    cout << "SHIP NAME: " << name << endl;
    cout << "YEAR BUILT: " << yearBuilt << endl;
}

//##################################//
//#   CruiseShip Class Functions   #//
//##################################//

//---------------------------------------------------------------------------------------------------------------------------------//
//print: Overrides the print() in Ship class; this print() only prints the name of the ship and the maximum number of passengers.  //
//---------------------------------------------------------------------------------------------------------------------------------//
void CruiseShip::print() const{
    cout << endl;
    cout << "SHIP NAME: " << getName() << endl;
    cout << "MAX NUMBER OF PASSENGERS: " << maxPassengers << endl;
}

//##################################//
//#   CargoShip Class Functions   #//
//#################################//

//--------------------------------------------------------------------------------------------------------------------//
//print: Overrides the print() in Ship class; this print() only prints the name of the ship and the cargo capacity    //
//--------------------------------------------------------------------------------------------------------------------//
void CargoShip::print() const{
    cout << endl;
    cout << "SHIP NAME: " << getName() << endl;
    cout << "CARGO CAPACITY: " << cargoCapacity << endl;
}

