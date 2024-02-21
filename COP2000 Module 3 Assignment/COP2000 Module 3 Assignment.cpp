#include <iostream>
using namespace std;

 int main(){

   // Title Block
  cout << "Architect Area Calculator:\n"
       << "***********************\n"
       << "1. Rectangle\n"
       << "2. Triangle\n"
       << "3. Circle\n"
       << "4. Quit\n" 
       << endl;

   // Display the text for choosing the operation
  cout << "Please enter a menu item (1-4) > ";

   // Get the operation
  int operation;
  cin >> operation;

   // The cin number variables, declared once
   double num1;
   double num2;
   
  // Swtich statement for all the diffrent operations
  switch(operation){
    // Rectangle Case
    case 1:
      cout << "\nRectangle"
           << "\nPlease enter the length > ";
      cin >> num1;

      cout << "Please enter the width > ";
      cin >> num2;

      cout << "\n Area = "
           << num1 * num2
           << " sq/ft"
           << endl;
    break;

    // Triangle Case
    case 2:
      cout << "\nTriangle"
           << "\nPlease enter the base > ";
      cin >> num1;

      cout << "Please enter the height > ";
      cin >> num2;

      cout << "\n Area = "
           << (num1 * num2)/2
           << " sq/ft"
           << endl;
    break;

    // Circle Case
    case 3:
      cout << "\nCircle"
           << "\nPlease enter the radius > ";
      cin >> num1;

      cout << "\n Area = "
           << 3.14 * (num1 * num1)
           << " sq/ft"
           << endl;
    break;

    // Quit Case
    case 4:
      cout << "\nThank you for using Architect Area Calculator..."
           << endl;
      // Quit the program
      return 0;
    break;

    default:
      cout << "ERROR: Invalid Operation Selected";
      // Quit the program with an error
      return 1;
    break;
  }

  return 0;
}