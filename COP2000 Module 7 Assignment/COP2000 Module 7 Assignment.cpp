/*
Landon Scott
COP2000
4-18-24
Purpose: Create a command prompt sign-in for users to check their account information by entering their account sign-in details. If the user
is an admin, let them see the whole server's account details.
*/

// Include Functions
#include <iostream>
#include <iomanip>
#include <fstream>
 
// No typing std:: without importing the whole library
using std::cout;
using std::string;

// Function Prototypes
bool readFile(string theAccounts[5][7]);
void showAll(string theAccounts[5][7]);
void sortInput(string theAccounts[5][7]);
bool validateUser(string theAccounts[5][7], string username, string password, int &saveRow);

// remember to use setw and cin.fail----------------------------------------------------------
int main() {

    // rows then columns
    string accounts[5][7];
    string username;
    string password;

    // If file couldn't be read, exit program
    if(!readFile(accounts)) {
        cout << "There was an error reading the file, exiting program...";
        // exit with a error
        exit(1);
    }
    
    sortInput(accounts);

    do {
        // Prompt the user
        cout << "Enter the following information or 0 to Exit..." << std::endl;

        // Get username from user
        cout << "Please Enter Your User Name > ";
        std::cin >> username;
        if(username == "0") {
            exit(0);
        }

        // Get password from user
        cout << "Please Enter Your Password > ";
        std::cin >> password;
        if(password == "0") {
            exit(0);
        }

        // Validate the user's username and password
        int row;
        if(!validateUser(accounts, username, password, row)) {
            cout << "\nUsername and Password do not match... Please try again...\n\n" << std::endl;
            continue;
        }
        
        // Check if user is admin or general user, and display accordingly
        if(accounts[row][5] == "U") {
            cout << "\n";
            for(int iterator = 0; iterator < 7; ++iterator) {
                cout << std::setw(17) << accounts[row][iterator];
            }
            cout << "\n" << std::endl;
        } else {
            showAll(accounts);
        }
        
    } while(true);
    

    return 0;
}

// Returns true if no issues 
bool readFile(string theAccounts[5][7]) {
    
    std::ifstream inputFile;
    inputFile.open("AccountData.txt");

    // unhappy condition
    if(inputFile.fail()) {
        inputFile.close();
        return false;
    }

    // Insert all values from file into theAccounts 2D array
    for(int rows = 0; rows < 5; ++rows) {
        for(int columns = 0; columns < 7; ++columns) {
            inputFile >> theAccounts[rows][columns];
        }
        
    }

    inputFile.close();

    return true;
}

// Check if user submitted username and password match with any of the values
bool validateUser(string theAccounts[5][7], string username, string password, int &saveRow) {
    bool usernameGood, passwordGood;
    
    // Cycle through the rows
    for(int row = 0; row < 5; ++row){
        // if the username matches
        if(username == theAccounts[row][0]) {
            usernameGood = true;
            // if the password also matches
            if(password == theAccounts[row][3]) {
                passwordGood = true;
                saveRow = row;

                return true;
            }
        }
    }
    // Didn't fully match / didnt match at all
    return false;
}

// Runs through all the values of theAccounts and prints them in a table
void showAll(string theAccounts[5][7]) {
    cout << "\n";
    for(int rows = 0; rows < 5; ++rows) {
        for(int columns = 0; columns < 7; ++columns) {
            cout << std::setw(17) << theAccounts[rows][columns];
        }
        cout << "\n" << std::endl;
    }
}

// Isn't this a useless function? Data doesn't need to be sorted...
// Sorts data from file by last name and reasigns it to theAccounts
void sortInput(string theAccounts[5][7]) {
    
    // Create and assign the variable
    string tempData[5][7]; 
    for(int row = 0; row < 5; ++row) {
        for(int column = 0; column < 7; ++column) {
            tempData[row][column] = theAccounts[row][column];
        }
    }

    // Selection sort (this is... interestingly made... O(N^4) :/ )
    char alphabeticalOrder[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    // move up the starting position
    for(int startingPosition = 0; startingPosition < 5; ++startingPosition) {
        bool positionsSwitched = false;
        // set the current letter
        for(int currentLetter = 0; currentLetter < 26; ++currentLetter) {
            // go through the rows
            for(int row = startingPosition; row < 5; ++row) {
                // if current row == the current letter of the alphabet
                if(theAccounts[row][2].at(0) == alphabeticalOrder[currentLetter] && !positionsSwitched) { 
                    positionsSwitched = true;

                    // temp copy of line being replaced at beginning
                    string tempCopy[7];
                    for(int iterator = 0; iterator < 7; ++iterator) {
                        // make the copy of the beginning             
                        tempCopy[iterator] = theAccounts[startingPosition][iterator];

                        // replace beginning                       
                        theAccounts[startingPosition][iterator] = theAccounts[row][iterator];
                        
                        // replace mid                        
                        theAccounts[row][iterator] = tempCopy[iterator];                        
                    }
                }
            }
        }
        positionsSwitched = false;
    }
}