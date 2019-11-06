
//Program Description: This program takes a .cpp file(testFile.cpp) and writes its contents to a .html file(testFile.html), 
//properly converting the .cpp file's contents so that it will display properly when viewed in a web browser.

#include <iostream>
#include <iomanip>
#include <fstream>//File I/O
#include <string>
#include <cstdlib> //for exit
using namespace std;

//Function prototypes:
void convert(ifstream& fileIn, ofstream& fileOut);//Takes a .cpp file that fileIn is connected to and re-writes it to a .html file that fileOut is connected to
												  //such that the contents of the .cpp file, now written to an .html file, will display properly in a web browser.

//-----------------------------//
//--------MAIN FUNCTION--------//
//-----------------------------//
int main(){
	
	//Open the input file:
	ifstream fileIn("testFile.cpp");
	//Test for input file open success:
	if(fileIn.fail()){
		cout << endl << "Input file open failed." << endl;
		exit(1);
	}
		
	//Open the output file:
	ofstream fileOut("testFile.html");
	//Test for output file open success:
	if(fileOut.fail()){
		cout << endl << "Output file open failed." << endl;
		exit(1);
	}
	
	convert(fileIn, fileOut);
	
	//Close the files:
	fileIn.close();
	fileOut.close();
	
	return 0;
}

//------------------------------------------------------------------------------------------------------------------------------//
//convert(): Takes a .cpp file that fileIn is connected to and re-writes it to a .html file that fileOut is connected to        //
//           such that the contents of the .cpp file, now written to an .html file, will display properly in a web browser.     //
//------------------------------------------------------------------------------------------------------------------------------//
void convert(ifstream& fileIn, ofstream& fileOut){
	
	char c;//This will hold characters from the input file, to be written to the output file
	
	//Insert the <PRE> tag in order to perserve the whitespace and formatting of the original .cpp file when its contents are viewed using the new .html file:
	fileOut << "<PRE>" << endl;
	
	fileIn.get(c);//Attempt to get the first character.
	while(!fileIn.eof()){//Keep looping until the end-of-file is reached.
	
		//Check to see if the character input is either a < or a >, and replace with the HTML equivalent accordingly.
		if(c == '<')
			fileOut << "&lt;";
		else if(c == '>')
			fileOut << "&gt;";
		else
			fileOut << c;//If it is not either < or >, simply write the character input to the output file.
		
		fileIn.get(c);//Get the next character.
	}
	
	//Insert </PRE> in order to signify the end of the previously-inserted <PRE> tag:
	fileOut << "</PRE>" << endl;
}
