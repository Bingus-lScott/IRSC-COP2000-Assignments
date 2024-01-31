/*
Landon Scott 
1 - 9 - 2024
COP 2000

The purpose of the program is to display the area of a pre-defined / hardcoded square.
*/ 

#include <iostream>
using namespace std;

int main() {
	// This section displays the title block
	cout << "********************************" << endl;
	cout << "***        Landon Scott      ***" << endl;
	cout << "********************************" << endl;
	cout << "***         My Square        ***" << endl;
	cout << "********************************" << endl;

	// This section calculates the area of the square and stores it in var area
	int length = 20;
	int area = length * length;

	// Displays the area to the screen
	cout << "The area of the square is " << area << " cm" << endl;

	return 0;
}