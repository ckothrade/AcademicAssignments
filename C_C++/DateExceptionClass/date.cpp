
//Program Description: The purpose of this program is to practice using c++'s exception handling features.  To this end, a Date class has been written.  The Date class is
//constructed such that it will throw the appropriate exception when an invalid date is passed to it.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> //for exit
using namespace std;

//EXCEPTION CLASSES:
class InvalidDay{};
class InvalidMonth{};
class InvalidYear{};

//Class delcarations:
//######################//
//#     Date Class     #//
//######################//
//Description: Stores a valid A.D. date, and has various functions for printing this date, nicely formatted.
//Any attempt to input an invalid date into this function will result in an exception of either InvalidDay,
//InvalidMonth, or InvalidYear being thrown, depending on the erroneous data that was input.
class Date{
	public:
		//CONSTRUCTORS:
			Date()
				:day(1), month(1), year(1970)
				{/*Intentionally left empty*/}
			Date(int theYear) throw (InvalidYear)
				:day(1), month(1), year(theYear)
				{validateDate();}
			Date(int theMonth, int theYear) throw (InvalidMonth, InvalidYear)
				:day(1), month(theMonth), year(theYear)
				{validateDate();}
			Date(int theDay, int theMonth, int theYear) throw (InvalidDay, InvalidMonth, InvalidYear)
				:day(theDay), month(theMonth), year(theYear)
				{validateDate();}
		//OTHER FUNCTIONS:
			void printDate1() const;//Prints the date in the format MM/DD/YY (e.g. 12/25/13)
			void printDate2() const;//Prints the date in the format Month DD, YYYY (e.g. December 25, 2013)
			void printDate3() const;//Prints the date in the format DD Month YYYY (e.g. 25 December  2013)
		//GETTERS:
			int getDay() const {return day;}
			int getMonth() const {return month;}
			int getYear() const {return year;}
		//SETTERS:
			void setDay(int newDay) throw (InvalidDay);
			void setMonth(int newMonth) throw (InvalidMonth);
			void setYear(int newYear) throw (InvalidYear);
	private:
		int day;
		int month;
		int year;
		void validateDate() const throw (InvalidDay, InvalidMonth, InvalidYear);//Validates the date, and throws the appropriate exception if some part of it is invalid.
		void printMonthName() const;//Prints the name of the month.
};

//Function prototypes:
void testDateSetMethods();//Tests the set methods in the Date Class.
void testDateConstructor();//Tests the Date Class's 3-arg constructor.
void testDatePrintMethods(Date testDate);//Tests all the Date Class's print methods.

//-----------------------------//
//--------MAIN FUNCTION--------//
//-----------------------------//
int main(){
	
	//TESTING DATE CLASS:
	try{
		testDateSetMethods();
		testDateConstructor();
	}
	catch(...){
		cout << "Ending Program..." << endl;
	}
	
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------//
//testDateSetMethods(): Tests the get methods in the Date Class.
//------------------------------------------------------------------------------------------------------------------------//
void testDateSetMethods(){
	
	//Variables used for holding user input.
	int testDay;
	int testMonth;
	int testYear;
	
	//The Date object used for testing:
	Date testDate;
	
	//Print a header:
	cout << "TESTING THE DATE CLASS'S SET METHODS:" << endl;
	
	//Test Date Class's set methods:
	try{
		cout << "Enter the year: ";
		cin >> testYear;
		testDate.setYear(testYear);
		cout << "Enter the month: ";
		cin >> testMonth;
		testDate.setMonth(testMonth);
		cout << "Enter the day: ";
		cin >> testDay;
		testDate.setDay(testDay);
	}
	catch(InvalidYear){
		cout << "Invalid Year!" << endl;
		throw;//Re-throws the exception this catch block caught.
	}
	catch(InvalidMonth){
		cout << "Invalid Month!" << endl;
		throw;//Re-throws the exception this catch block caught.
	}
	catch(InvalidDay){
		cout << "Invalid Day!" << endl;
		throw;//Re-throws the exception this catch block caught.
	}
	
	//If the date entry was successful, print the date in all formats:
	testDatePrintMethods(testDate);
	
	cout << endl << endl;
}

//------------------------------------------------------------------------------------------------------------------------//
//testDateConstructor(): Tests the Date Class's 3-arg constructor.
//------------------------------------------------------------------------------------------------------------------------//
void testDateConstructor(){
	
	//Variables used for holding user input.
	int testDay;
	int testMonth;
	int testYear;
	
	//Print a header:
	cout << "TESTING THE DATE CLASS'S 3-ARG CONSTRUCTOR:" << endl;
	
	//Prompt the user for data to be used to construct an object of Date class:
	cout << "Enter the year: ";
	cin >> testYear;
	cout << "Enter the month: ";
	cin >> testMonth;
	cout << "Enter the day: ";
	cin >> testDay;
	
	//Test Date Class's 3-arg constructor and catch any exceptions thrown:
	try{
		Date testDate(testDay, testMonth, testYear);
		
		//If the date entry was successful, print the date in all formats:
		testDatePrintMethods(testDate);
	}
	catch(InvalidYear){
		cout << "Invalid Year!" << endl;
		throw;//Re-throws the exception this catch block caught.
	}
	catch(InvalidMonth){
		cout << "Invalid Month!" << endl;
		throw;//Re-throws the exception this catch block caught.
	}
	catch(InvalidDay){
		cout << "Invalid Day!" << endl;
		throw;//Re-throws the exception this catch block caught.
	}
	
	
	
	cout << endl << endl;
}

//------------------------------------------------------------------------------------------------------------------------//
//testDatePrintMethods(): Tests all the Date Class's print methods.                                                       //
//------------------------------------------------------------------------------------------------------------------------//
void testDatePrintMethods(Date testDate){
	cout << endl;
	cout << "Congratulations, you entered a valid date!" << endl;
	cout << "The date you entered was: " << endl;
	testDate.printDate1();
	cout << endl;
	testDate.printDate2();
	cout << endl;
	testDate.printDate3();
	cout << endl;
}

//################################//
//#     Date Class Functions     #//
//################################//

//------------------------------------------------------------------------------------------------------------------------//
//Date::printDate1(): Prints the date in the format MM/DD/YY (e.g. 12/25/13)                                              //
//------------------------------------------------------------------------------------------------------------------------//
void Date::printDate1() const {
	cout << setfill('0');
	cout << setw(2) << month << "/"; 
	cout << setw(2) << day << "/";
	cout << setw(2) << year%100;
}

//------------------------------------------------------------------------------------------------------------------------//
//Date::printDate2(): Prints the date in the format Month DD, YYYY (e.g. December 25, 2013)                               //
//------------------------------------------------------------------------------------------------------------------------//
void Date::printDate2() const {
	printMonthName();
	cout << setfill('0');
	cout << " " << day << ", " << setw(4) << year;
}

//------------------------------------------------------------------------------------------------------------------------//
//Date::printDate3(): Prints the date in the format DD Month YYYY (e.g. 25 December  2013)                                //
//------------------------------------------------------------------------------------------------------------------------//
void Date::printDate3() const {
	cout << setfill('0');	
	cout << day << " ";
	printMonthName();
	cout << " " << setw(4) << year;
}

//---------------//
//----SETTERS----//
//---------------//
void Date::setDay(int newDay) throw (InvalidDay){
	day = newDay;
	validateDate();
}

void Date::setMonth(int newMonth) throw (InvalidMonth){
	month = newMonth;
	validateDate();
}

void Date::setYear(int newYear) throw (InvalidYear){
	year = newYear;
	validateDate();
}

//------------------------------------------------------------------------------------------------------------------------//
//Date::validateDate(): Validates the date, and throws the appropriate exception if some part of it is invalid.           //
//------------------------------------------------------------------------------------------------------------------------//
void Date::validateDate() const throw (InvalidDay, InvalidMonth, InvalidYear){
	
	bool isLeapYear;//Set to true if the year is a leap year.
	
	//First check to see if the year is valid; the smallest year possible (in A.D.) is 1.
	if(year < 1)
		throw InvalidYear();
	
	//Now, check to see if the month is valid.
	else if(month < 1 || month > 12)
		throw InvalidMonth();
	
	//All these months that have 31 days...
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if(day < 1 || day > 31)//...So check to see if the day is within the range 1-31.
			throw InvalidDay();
	}
	
	//All these months that have 30 days...
	else if(month == 4 || month == 6 || month == 9 || month == 11){
		if(day < 1 || day > 30)//...So check to see if the day is within the range 1-30.
			throw InvalidDay();
	}
	
	
	//---START OF CHECK FEBRUARY---//
	//Finally, if the month is February, check to see if it is a leap year then check the appropriate day range:
	else if(month == 2){
		
		//Check if the year is a leap year:
		if(year%4 == 0){//Leap years are any year that can be evenly divided by 4...
			isLeapYear = true;
			if(year%100 == 0){//...Unless the year can be evenly divided by 100...
				isLeapYear = false;
				if(year%400 == 0)//...except if the year can also be evenly divided by 400.
					isLeapYear = true;
			}
		}else{
			isLeapYear = false;//If the year fails the first test and can't even be evenly divided by 4, then it's not a leap year.
		}
		
		
		//And then validate the day accordingly:
		if(isLeapYear){
			if(day < 1 || day > 29)//Check to see if the day is within the range 1-29.
				throw InvalidDay();
		}
		else{
			if(day < 1 || day > 28)//Check to see if the day is within the range 1-28.
				throw InvalidDay();
		}
		
	}
	//---END OF CHECK FEBRUARY---//
	
	
	//If the code has reached this point, then all is well and the date is valid.  Every possibility has been checked.
}

//------------------------------------------------------------------------------------------------------------------------//
//Date::printMonthName(): Prints the name of the month.                                                                   //
//------------------------------------------------------------------------------------------------------------------------//
void Date::printMonthName() const {

	switch(month){
		case 1:
			cout << "January";
			break;
		case 2:
			cout << "February";
			break;
		case 3:
			cout << "March";
			break;
		case 4:
			cout << "April";
			break;
		case 5:
			cout << "May";
			break;
		case 6:
			cout << "June";
			break;
		case 7:
			cout << "July";
			break;
		case 8:
			cout << "August";
			break;
		case 9:
			cout << "September";
			break;
		case 10:
			cout << "October";
			break;
		case 11:
			cout << "November";
			break;
		case 12:
			cout << "December";
			break;
	}
}
