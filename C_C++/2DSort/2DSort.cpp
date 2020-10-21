#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

// function to sort the array
void sort(char array[5][5]){
	char temp[25];
	// store the 22D array into a temporary 1D array
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			temp[i * 5 + j] = array[i][j];
		}
	}
	// Sort the 1D array
	for (int i = 0; i < 25; i++){
		for (int j = 0; j <= i; j++){
			if (temp[i] < temp[j]){
				char x = temp[i];
				temp[i] = temp[j];
				temp[j] = x;
			}
		}
	}
	// Store the sorted 1D array back into the 2D array
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			array[i][j] = temp[i * 5 + j];
		}
	}
}

// main function starts
int main(){
	// Declare a 5x5 array
	char arr[5][5];
	srand(time(0));
	// fill the 2D array with random capital alphabets
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			arr[i][j] = rand() % 26 + 'A';
		}
	}
	// display the original random array
	cout << endl << "The original array is:" << endl;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	// call the sort function to sort the array
	sort(arr);
	// display the sorted array
	cout << endl << "The sorted array is:" << endl;
	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

