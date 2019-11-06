
//Rational Numbers Class & Rational Numbers Class Test Program
//Program Description: Implements the Rational class (See description of rational class below for details).
//The main function allows the user to test the rational class: users enter in various fractions they wish
//to test, and the program performs various operations on the fractions and then outputs the results for the
//user to see.


#include <iostream>
#include <stdlib.h>
#include <cstdlib> //for exit
using namespace std;

//Class delcarations:
//##################//
//# Rational Class #//
//##################//
//Description: Objects of this class represent rational numbers; that is, fractions of the form (integer)/(integer).
//Every funcion in this class, including constructors, ensures that the denominator will never become zero.
//This class automatically normalizes any rational input into it; it will always ensure that the fraction is reduced
//fully and that the negative sign will only show up in front of the numerator.
//Operator overloads for a wide variety of operators are provided; see the class body below.  
//Various constructors are included to allow you to initialize objects of class rational in a variety of ways; again, see the class declaration below.  

class Rational {
	public:
		//CONSTRUCTORS:
		Rational()//Default constructor sets the rational number to 0/1 = 0
			:numerator(0), denominator(1)
			{/*Intentionally left empty*/}
		Rational(int wholeNumber)//One integer parameter sets the rational number to a whole number: wholeNumber/1 = wholeNumber
			:numerator(wholeNumber), denominator(1)
			{/*Intentionally left empty*/}
		Rational(int fractionNumerator, int fractionDenominator);//Two integer parameters sets the numerator and denominator directly.
																 //Reports an error and ends the program if 0 is entered as the denominator.
		//OVERLOADED OPERATORS:
		friend ostream& operator <<(ostream& outputStream, const Rational& rationalNumber);
		friend istream& operator >>(istream& inputStream, Rational& rationalNumber);
		bool operator ==(Rational otherRational);
		bool operator <(Rational otherRational);
		bool operator >(Rational otherRational);
		bool operator <=(Rational otherRational);
		bool operator >=(Rational otherRational);
		Rational operator +(Rational otherRational);
		Rational operator -(Rational otherRational);
		Rational operator *(Rational otherRational);
		Rational operator /(Rational otherRational);
		//GETTERS:
		int getNumerator(){return numerator;}
		int getDenominator(){return denominator;}
		//SETTERS:
		void setNumerator(int newNumerator){numerator = newNumerator; normalize();}
		void setDenominator(int newDenominator);
	private:
		int numerator;
		int denominator;
		void normalize();//Normalizes the rational number such that the denominator is positive, the numerator's sign reflects the 
		                 //sign of the whole rational number, and the numerator and the denominator are as small as possible. 
};

//Function prototypes:
bool ContinueProgram();//ContinueProgram: Prompts the user, asking them if they wish to continue the program.  Returns true if yes, false if no.

//-----------------------------//
//--------MAIN FUNCTION--------//
//-----------------------------//
int main(){
	
	//Test the constructors:
	Rational test1(50,-5);
	Rational test2(5);
	Rational test3;
	
	
	//Main program loop - used to test objects of Rational class:
	do{
		
		//Test output operator <<:
		cout << "TEST OUTPUT OPERATOR <<" << endl;
		cout << "Rational number test1: " << test1 << endl;
		cout << "Rational number test2: " << test2 << endl;
		cout << "Rational number test3: " << test3 << endl;
		cout << endl;
		system("pause");
		system("cls");
		
		//Test input operator >>:
		cout << "TEST INPUT OPERATOR >>" << endl;
		cout << "---Please input two rational numbers for testing---" << endl;
		cout << "Rational test1: ";
		cin >> test1;
		cout << "Rational test2: ";
		cin >> test2;
		cout << endl;

		//Display the new values for test1 and test2 to show that the input was successful:
		cout << "VALIDATE THAT INPUT WAS SUCCESSFUL AND FRACTIONS HAVE BEEN PROPERLY NORMALIZED" << endl;
		cout << "Rational number test1: " << test1 << endl;
		cout << "Rational number test2: " << test2 << endl;
		cout << endl;
		system("pause");
		system("cls");
		
		//Test the comparison operators:
		cout << "TESTING COMPARISON OPERATORS" << endl;
		if(test1 == test2)
			cout << test1 << " = " << test2 << endl;
		if(test1 < test2)
			cout << test1 << " < " << test2 << endl;
		if(test1 > test2)
			cout << test1 << " > " << test2 << endl;
		if(test1 <= test2)
			cout << test1 << " <= " << test2 << endl;
		if(test1 >= test2)
			cout << test1 << " >= " << test2 << endl;
		cout << endl;
		system("pause");
		system("cls");
		
		//Test the arithmetic operators:
		cout << "TESTING ARITHMETIC OPERATORS" << endl;
		cout << test1 << " + " << test2 << " = " << test1+test2 << endl;
		cout << test1 << " - " << test2 << " = " << test1-test2 << endl;
		cout << test1 << " * " << test2 << " = " << test1*test2 << endl;
		cout << test1 << " / " << test2 << " = " << test1/test2 << endl;
		cout << endl;
		system("pause");
		system("cls");
		

		
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


//############################//
//# Rational Class Functions #//
//############################//

//----------------//
//CONSTRUCTORS:   //
//----------------//
Rational::Rational(int fractionNumerator, int fractionDenominator)//Two integer parameters sets the numerator and denominator directly.
	:numerator(fractionNumerator)								  //Reports an error and ends the program if 0 is entered as the denominator.
{
	if(fractionDenominator == 0){
		cout << endl << "ERROR: 0 in the denominator of a rational number." << endl;
		cout << "Ending program..." << endl;
		exit(1);
	}
	else{
		denominator = fractionDenominator;
	}
	normalize();
}

//-----------------------------------------------------------------------------------------------------------------------//
//normalize: Normalizes the rational number such that the denominator is positive, the numerator's sign reflects the     //
//sign of the whole rational number, and the numerator and the denominator are as small as possible.                     //
//-----------------------------------------------------------------------------------------------------------------------//
void Rational::normalize(){
	
	//Check up front to see if the numerator is zero; if it is, set the denominator to 1 and end the function...
	if(numerator == 0){
		denominator = 1;
		return;
	}
	//...Otherwise, continue on with the regular normalization proceedure:
	
	//Make the denominator positive while keeping an approprate sign for the numerator:
	if(denominator < 0){
		numerator *= (-1);
		denominator *= (-1);
	}
	
	//Reduce the fraction so that both numerator and denominator are as small as possible:
	
	int i;//This will hold the greatest common factor between the numerator an the denominator.
	      //How do we find the greatest common factor? Well...
	
	//...First, we determine whether the numerator or denominator has the smallest absolute value,
	//and then assign this value to i:
	if(denominator >= abs(numerator))//(We already know the denominator is positive, so we don't have to get its absolute value.)
		i = abs(numerator);//The numerator could be negative, so use its absolute value.
	else
		i = denominator;

	//Now see if i divides evenly into both numerator and denominator;
	//if it does, then divide both numerator and denominator by i, which is the greatest common factor.
	//If i doesn't evenly divide both numerator an denominator, then subtract one from i and check again
	//with the new value of i.  Keep doing this until the GCF is found:
	while(i > 0){
		if(numerator%i == 0 && denominator%i == 0){
			numerator /= i;
			denominator /= i;
			return;
		}else i--;
	}
}

//-----------------------------------------------------------------------//
//  << OPERATOR OVERLOAD:                                                //
//Allows the use of the << operator to output objects of class Rational. //
//-----------------------------------------------------------------------//
ostream& operator <<(ostream& outputStream, const Rational& rationalNumber){
	outputStream << rationalNumber.numerator;
	outputStream << "/";
	outputStream << rationalNumber.denominator;
	
	return outputStream;
}

//-----------------------------------------------------------------------//
//  >> OPERATOR OVERLOAD:                                                //
//Allows the use of the >> operator to input objects of class Rational.  //
//This function prompts the user and fully validates their input.        //
//                                                                       //
//Note: One quirk of this function is that any characters entered after  //
//the first integer entered for the denominator will be ignored;         //
//e.g. entering 500/236.52 will be interpreted as 500/236,               //
//and entering 2/5Ggs will be interpreted as 2/5.                        // 
//-----------------------------------------------------------------------//
istream& operator >>(istream& inputStream, Rational& rationalNumber){
	
	cout << endl;
	
	//Input validation loop:
	while(true){
		//Prompt the user first:
		cout << "Enter a rational number: ";
		
		//Next, try to input the numerator...
		inputStream >> rationalNumber.numerator;
		//...Then check the input for validity:
		if(inputStream.fail()){
			cout << "Improper entry; try again." << endl;
			inputStream.clear();
			inputStream.sync();
			continue;//If the input isn't valid, clear and flush the input stream and try again.
		}
		
		//If all is well, try to input the division sign '/':
		if(inputStream.get() != '/'){
			cout << "Improper entry; try again." << endl;
			inputStream.clear();
			inputStream.sync();
			continue;//If the input isn't valid, clear and flush the input stream and try again.
		}
		
		//Finally, try to input the denominator...
		inputStream >> rationalNumber.denominator;
		//...Then check the input for validity:
		if(inputStream.fail()){
			cout << "Improper entry; try again." << endl;
			inputStream.clear();
			inputStream.sync();
			continue;//If the input isn't valid, clear and flush the input stream and try again.
		}else if(rationalNumber.denominator == 0){
			cout << "Denominator can't be zero; try again." << endl;
			inputStream.sync();
			continue;//If the input isn't valid, clear and flush the input stream and try again.
		}
		
		break;//If all is well, break out of the loop.
	}
	
	rationalNumber.normalize();
	
	inputStream.sync();//Flush the input buffer in order to rid the input stream of any pesky newline characters.
	return inputStream;
}

//-----------------------------------------------------------------------//
//  == OPERATOR OVERLOAD:                                                //
//Allows the use of the == operator to check if two objects of class     //
//Rational are equal.                                                    //
//-----------------------------------------------------------------------//
bool Rational::operator ==(Rational otherRational){
	
	if(numerator*otherRational.denominator == otherRational.numerator*denominator)//  Given two rational numbers a/b and c/d;
		return true;															  //  a/b = c/d if a*d = c*b
	else
		return false;
	
}

//-----------------------------------------------------------------------//
//  < OPERATOR OVERLOAD:                                                 //
//Allows the use of the < operator to check if one object of class       //
//Rational is less than another object of class Rational.                //
//-----------------------------------------------------------------------//
bool Rational::operator <(Rational otherRational){
	
	//The case where both rational numbers are positive and nonzero:
	if(numerator*denominator > 0 && otherRational.numerator*otherRational.denominator > 0){//If this is true, both rational numbers are positive and nonzero.
		if(numerator*otherRational.denominator < otherRational.numerator*denominator)//  Given two positive and nonzero rational numbers a/b and c/d;
			return true;															 //  a/b < c/d if a*d < c*b
		else
			return false;
	}
	
	//The case where both rational numbers are negative and nonzero:
	if(numerator*denominator < 0 && otherRational.numerator*otherRational.denominator < 0){//If this is true, both rational numbers are negative and nonzero.
		if((-1)*numerator*otherRational.denominator > (-1)*otherRational.numerator*denominator)//  Given two negative and nonzero rational numbers a/b and c/d;
			return true;																	   //  a/b < c/d if -a/b > -c/d;
		else																				   //  therefore a/b < c/d if (-1)*a*d > (-1)*c*b
			return false;
	}
	
	//The case where one rational number is positive and the other negative OR both are zero:
	if(numerator*denominator < otherRational.numerator*otherRational.denominator)//Since we have already covered the cases where both rational numbers have the same sign,
		return true;                                                             //we know the fractions must either have different signs or be zero;
	else                                                                         //thus if this evaluates to true then we know that a/b is negative and c/d (otherRational)
		return false;                                                            //is positive.  If a/b is positive and c/d is negative, or both are zero, it will evaluate to
	                                                                             //false, which is what we want.
}

//-----------------------------------------------------------------------//
//  > OPERATOR OVERLOAD:                                                 //
//Allows the use of the > operator to check if one object of class       //
//Rational is greater than another object of class Rational.                //
//-----------------------------------------------------------------------//
bool Rational::operator >(Rational otherRational){
	
	//The case where both rational numbers are positive and nonzero:
	if(numerator*denominator > 0 && otherRational.numerator*otherRational.denominator > 0){//If this is true, both rational numbers are positive and nonzero.
		if(numerator*otherRational.denominator > otherRational.numerator*denominator)//  Given two positive and nonzero rational numbers a/b and c/d;
			return true;															 //  a/b > c/d if a*d > c*b
		else
			return false;
	}
	
	//The case where both rational numbers are negative and nonzero:
	if(numerator*denominator < 0 && otherRational.numerator*otherRational.denominator < 0){//If this is true, both rational numbers are negative and nonzero.
		if((-1)*numerator*otherRational.denominator < (-1)*otherRational.numerator*denominator)//  Given two negative and nonzero rational numbers a/b and c/d;
			return true;																	   //  a/b > c/d if -a/b < -c/d;
		else																				   //  therefore a/b > c/d if (-1)*a*d < (-1)*c*b
			return false;
	}
	
	//The case where one rational number is positive and the other negative OR both are zero:
	if(numerator*denominator > otherRational.numerator*otherRational.denominator)//Since we have already covered the cases where both rational numbers have the same sign,
		return true;                                                             //we know the fractions must either have different signs or be zero;
	else                                                                         //thus if this evaluates to true then we know that a/b is positive and c/d (otherRational)
		return false;                                                            //is negative.  If a/b is negative and c/d is positive, or both are zero, it will evaluate to
	                                                                             //false, which is what we want.
}

//-----------------------------------------------------------------------//
//  <= OPERATOR OVERLOAD:                                                //
//Allows the use of the <= operator to check if one object of class      //
//Rational is less than or equal to another object of class Rational.    //
//-----------------------------------------------------------------------//
bool Rational::operator <=(Rational otherRational){
	
	//The case where both rational numbers are positive and nonzero:
	if(numerator*denominator > 0 && otherRational.numerator*otherRational.denominator > 0){//If this is true, both rational numbers are positive and nonzero.
		if(numerator*otherRational.denominator <= otherRational.numerator*denominator)//  Given two positive and nonzero rational numbers a/b and c/d;
			return true;															  //  a/b <= c/d if a*d <= c*b
		else
			return false;
	}
	
	//The case where both rational numbers are negative and nonzero:
	if(numerator*denominator < 0 && otherRational.numerator*otherRational.denominator < 0){//If this is true, both rational numbers are negative and nonzero.
		if((-1)*numerator*otherRational.denominator >= (-1)*otherRational.numerator*denominator)//  Given two negative and nonzero rational numbers a/b and c/d;
			return true;																	    //  a/b <= c/d if -a/b >= -c/d;
		else																				    //  therefore a/b <= c/d if (-1)*a*d >= (-1)*c*b
			return false;
	}
	
	//The case where one rational number is positive and the other negative OR both are zero:
	if(numerator*denominator <= otherRational.numerator*otherRational.denominator)//Since we have already covered the cases where both rational numbers have the same sign,
		return true;                                                              //we know the fractions must either have different signs or be zero;
	else                                                                          //thus if this evaluates to true then we know that a/b is negative and c/d (otherRational)
		return false;                                                             //is positive, or both are zero.  If a/b is positive and c/d is negative, it will evaluate to
	                                                                              //false, which is what we want.
}

//-----------------------------------------------------------------------//
//  >= OPERATOR OVERLOAD:                                                //
//Allows the use of the >= operator to check if one object of class      //
//Rational is greater than or equal to another object of class Rational. //
//-----------------------------------------------------------------------//
bool Rational::operator >=(Rational otherRational){
	
	//The case where both rational numbers are positive and nonzero:
	if(numerator*denominator > 0 && otherRational.numerator*otherRational.denominator > 0){//If this is true, both rational numbers are positive and nonzero.
		if(numerator*otherRational.denominator >= otherRational.numerator*denominator)//  Given two positive and nonzero rational numbers a/b and c/d;
			return true;															  //  a/b >= c/d if a*d >= c*b
		else
			return false;
	}
	
	//The case where both rational numbers are negative and nonzero:
	if(numerator*denominator < 0 && otherRational.numerator*otherRational.denominator < 0){//If this is true, both rational numbers are negative and nonzero.
		if((-1)*numerator*otherRational.denominator <= (-1)*otherRational.numerator*denominator)//  Given two negative and nonzero rational numbers a/b and c/d;
			return true;																	    //  a/b >= c/d if -a/b <= -c/d;
		else																				    //  therefore a/b >= c/d if (-1)*a*d <= (-1)*c*b
			return false;
	}
	
	//The case where one rational number is positive and the other negative OR both are zero:
	if(numerator*denominator >= otherRational.numerator*otherRational.denominator)//Since we have already covered the cases where both rational numbers have the same sign,
		return true;                                                              //we know the fractions must either have different signs or be zero;
	else                                                                          //thus if this evaluates to true then we know that a/b is positive and c/d (otherRational)
		return false;                                                             //is negative, or both are zero.  If a/b is negative and c/d is positive, it will evaluate to
	                                                                              //false, which is what we want.
}

//-----------------------------------------------------------------------//
//  + OPERATOR OVERLOAD:                                                 //
//Allows the use of the + operator to add one object of class            //
//Rational to another object of class Rational.                          //
//-----------------------------------------------------------------------//
Rational Rational::operator +(Rational otherRational){
	
	//If both fractions have the same denominator b such that a/b and c/b; simply return (a + c)/b:
	if(denominator == otherRational.denominator)
		return Rational(numerator + otherRational.numerator, denominator);
	//Otherwise if they have different denominators b and d such that a/b and c/d; return (a*d + c*b)/(b*d)
	else
		return Rational(numerator*otherRational.denominator + otherRational.numerator*denominator, denominator*otherRational.denominator);
	
}

//-----------------------------------------------------------------------//
//  - OPERATOR OVERLOAD:                                                 //
//Allows the use of the - operator to subtract one object of class       //
//Rational from another object of class Rational.                        //
//-----------------------------------------------------------------------//
Rational Rational::operator -(Rational otherRational){
	
	//If both fractions have the same denominator b such that a/b and c/b; simply return (a - c)/b:
	if(denominator == otherRational.denominator)
		return Rational(numerator - otherRational.numerator, denominator);
	//Otherwise if they have different denominators b and d such that a/b and c/d; return (a*d - c*b)/(b*d)
	else
		return Rational(numerator*otherRational.denominator - otherRational.numerator*denominator, denominator*otherRational.denominator);
	
}

//-----------------------------------------------------------------------//
//  * OPERATOR OVERLOAD:                                                 //
//Allows the use of the * operator to multiply one object of class       //
//Rational with another object of class Rational.                        //
//-----------------------------------------------------------------------//
Rational Rational::operator *(Rational otherRational){
	//(a/b) * (c/d) = (a*c)/(b*d):
	return Rational(numerator*otherRational.numerator, denominator*otherRational.denominator);
}

//-----------------------------------------------------------------------//
//  / OPERATOR OVERLOAD:                                                 //
//Allows the use of the / operator to divide one object of class         //
//Rational by another object of class Rational.                          //
//-----------------------------------------------------------------------//
Rational Rational::operator /(Rational otherRational){
	//(a/b) / (c/d) = (a/b) * (d/c) = (a*d)/(b*c):
	return Rational(numerator*otherRational.denominator, denominator*otherRational.numerator);
}

//----------------//
//SETTERS:        //
//----------------//
void Rational::setDenominator(int newDenominator){
	if(newDenominator == 0){
		cout << endl << "ERROR: 0 in the denominator of a rational number." << endl;
		cout << "Ending program..." << endl;
		exit(1);
	}
	else{
		denominator = newDenominator;
	}
	
	normalize();
}

