/* 
Landon Scott
COP2000
3/6/2024

The purpose of the program is to draw a rectangle with astericks that is the size
that the user defined.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

  // Both are inputted numbers used to define the size of the rectangle
  int num1, num2;

  // The min and max size the program is allowed to draw a rectangle within
  const int minSize = 1;
  const int maxSize = 20;

  // Inputted number to exit the program
  const int EXIT_CODE = 99;

  // Display Title Block
  cout << " Welcome to Rectangle Draw It!!" << endl;
  cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
  // Scale the min and max sizes along with the constant
  cout << " Enter values between " << minSize << " and " << maxSize << "...\n" << endl;
  
  // Do-while loop for rectangle sizing and drawing that will continue until user exits
  do
  {
    // Display the first sizing message
    cout << "Please enter the length of the rectangle <Enter 99 to Exit> > ";
    // Get the first number
    cin >> num1;
    // if the user chose to exit, let them leave
    if(num1 == EXIT_CODE)
      // Probably should just return 0; but I think you want to see me use both break and continue
      break;
    // If the user broke sizing requirements, make them try again
    else if(num1 < minSize || num1 > maxSize){
      cout << "You Have entered an invalid number, please try again." << endl;
      continue;
    }

    // Display the second sizing message
    cout << "Please enter the width of the rectangle <Enter 99 to Exit> > ";
    // Get the second number
    cin >> num2;
    // if the user chose to exit, let them leave
    if(num2 == EXIT_CODE)
      break;
    // If the user broke sizing requirements, make them try again
    else if(num2 < minSize || num2 > maxSize){
      cout << "You Have entered an invalid number, please try again." << endl;
      continue;
    }

    // Drawing code
    // Vertical Axis
    for(int width = 0; width < num2; ++width){
      // Horizontal Axis
      for(int length = 0; length < num1; ++length){
        // Write the current row of astericks
            cout << "*";
      }
      // Go onto next line of astericks
      cout << endl;
    }
  }
  // Condition doesn't really matter as long as it stays true, but if it isn't broke...
  while(num1 != EXIT_CODE && num2 != EXIT_CODE);

  // Exit with code 0 (no errors)
  return 0;
}