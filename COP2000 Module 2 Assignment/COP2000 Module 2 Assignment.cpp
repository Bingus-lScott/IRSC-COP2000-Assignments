/*
Landon Scott
1/30/2024
COP2000

The purpose of the program is to calcualte the monetary gains for each type of seating and the entire total for a theatre. 
*/

// Library used for input output stream to the console
#include <iostream>
// Library used for setting the precision of the input output stream in this program
#include <iomanip>
// So I dont have to write std:: every time I want to use cout or cin
using namespace std;

// Main function that gets executed at beginning of the program
int main(){
	// The static price of the balcony seating
	const double balconyPrice = 50;
	// The static price of the grand tier seating
	const double gtPrice = 175.25;
	// The static price of the loge seating
	const double logePrice = 125;
	// The static price of the mezzanine seating
	const double mezzPrice = 100;
	// The static price of the orchastra seating
	const double orchPrice = 230.5;

	// The number of tickets purchased for balcony seating. gets value from user input
	int balconySeatsPurchased;
	// The number of tickets purchased for grand tier seating. gets value from user input
	int gtSeatsPurchased;
	// The number of tickets purchased for loge seating. gets value from user input
	int logeSeatsPurchased;
	// The number of tickets purchased for mezzanine seating. gets value from user input
	int mezzSeatsPurchased;
	// The number of tickets purchased for orchastra seating. gets value from user input
	int orchSeatsPurchased;

	// The total profits of the balcony seating, obtained by balconySeatsPurchased*balconyPrice
	double balconyTotal;
	// The total profits of the grand tier seating, obtained by gtSeatsPurchased*gtPrice
	double gtTotal;
	// The total profits of the loge seating, obtained by logeSeatsPurchased*logePrice
	double logeTotal;
	// The total profits of the mezzanine seating, obtained by mezzSeatsPurchased*mezzPrice
	double mezzTotal;
	// The total profits of the orchestra seating, obtained by orchSeatsPurchased*orchPrice
	double orchTotal;
	// The total profits of all seatings combined, obtained by multiplying all of the other totals
	double grandTotal;

	// A little string so that I don't have to ctrl+v something 50 times
	string spiel = "Please input the total number of seats purchased for: ";
	// output the spiel to console
	cout << spiel 
		// output the following text to console
		 << "Balcony Seating > ";
	// get user input and store it in variable
	cin >> balconySeatsPurchased;
	// update total variable using collected data
	balconyTotal = balconySeatsPurchased * balconyPrice;

	// output the spiel to console
	cout << spiel
		// output the following text to console
		<< "Grand Tier Seating > ";
	// get user input and store it in variable
	cin >> gtSeatsPurchased;
	// update total variable using collected data
	gtTotal = gtSeatsPurchased * gtPrice;

	// output the spiel to console
	cout << spiel
		// output the following text to console
		<< "Loge Seating > ";
	// get user input and store it in variable
	cin >> logeSeatsPurchased;
	// update total variable using collected data
	logeTotal = logeSeatsPurchased * logePrice;

	// output the spiel to console
	cout << spiel
		// output the following text to console
		<< "Mezzanine Seating > ";
	// get user input and store it in variable
	cin >> mezzSeatsPurchased;
	// update total variable using collected data
	mezzTotal = mezzSeatsPurchased * mezzPrice;

	// output the spiel to console
	cout << spiel
		// output the following text to console
		<< "Orchestra Seating > ";
	// get user input and store it in variable
	cin >> orchSeatsPurchased;
	// update total variable using collected data
	orchTotal = orchSeatsPurchased * orchPrice;

	// update total variable using collected data
	grandTotal = balconyTotal + gtTotal + logeTotal + mezzTotal + orchTotal;


	// Output title text to console, skipping a line
	cout << "\nTheadore Theatre Ticket Sales"
		// end the line
		 << endl
		// output the (very manual) line break to console
		 << "-----------------------------"
		// end the line
		 << endl;

	// set the precision to 2 digits
	cout << setprecision(2)
		// make it only apply to decimals
		<< fixed
		// output the following text to console as well as a tab
		<< "Balcony:\t$"
		// output the total value on the same line
		<< balconyTotal
		// end the line
		<< endl;

	// set the precision to 2 digits
	cout << setprecision(2)
		// make it only apply to decimals
		<< fixed
		// output the following text to console as well as a tab
		<< "Grand Tier:\t$"
		// output the total value on the same line
		<< gtTotal
		// end the line
		<< endl;

	// set the precision to 2 digits
	cout << setprecision(2)
		// make it only apply to decimals
		<< fixed
		// output the following text to console as well as 2 tabs
		<< "Loge:\t\t$"
		// output the total value on the same line
		<< logeTotal
		// end the line
		<< endl;

	// set the precision to 2 digits
	cout << setprecision(2)
		// make it only apply to decimals
		<< fixed
		// output the following text to console as well as a tab
		<< "Mezzanine:\t$"
		// output the total value on the same line
		<< mezzTotal
		// end the line
		<< endl;

	// set the precision to 2 digits
	cout << setprecision(2)
		// make it only apply to decimals
		<< fixed
		// output the following text to console as well as a tab
		<< "Orchestra:\t$"
		// output the total value on the same line
		<< orchTotal
		// end the line
		<< endl;

	// set the precision to 2 digits
	cout << setprecision(2)
		// make it only apply to decimals
		<< fixed
		// output the following text to console as well as a tab
		<< "Total Sales:\t$"
		// output the total value on the same line
		<< grandTotal
		// end the line
		<< endl;

	// end the program with return code 0 because it a habbit :)
	return 0;
}