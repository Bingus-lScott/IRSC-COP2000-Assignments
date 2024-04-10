/*
Landon Scott
COP2000
4-9-24

Purpose: Allows the user to input data into the program from a file, which is formatted in one way. Once that data is inputted it allows a user to view the data
through the console. Finally it allows the user to output the inputted data with diffrent formatting to a file.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

// Function Prototypes:
void logo();
void menu();
bool readInventory(string itemNames[], double itemCost[], int itemNoShip[], int canShip[]);
void displayInventory(string itemNames[], double itemCost[], int itemNoShip[], int canShip[]);
void writeFile(string itemNames[], double itemCost[], int itemNoShip[], int canShip[]);

int main(){
    // Initalizying arrays
    string itemNames[10]; 
    double itemCost[10]; 
    int itemNoShip[10];
    int canShip[10];

    // If true, the do while loop doesn't continue next itieration
    bool exit = false;
    // The user's input
    int input;

    do {
        logo();
        menu();
        cin >> input;

        switch(input){
            // Read Inventory
            case 1:
            // Reads the inventory, if it returns true then there was an error reading the file
                if(readInventory(itemNames, itemCost, itemNoShip, canShip)){
                    cout << "\nThere was an error opening inputInventory.txt, Exiting Program...";
                    return 1;
                }
            break;

            // Display Inventory
            case 2:
                displayInventory(itemNames, itemCost, itemNoShip, canShip);
            break;

            // Write to File
            case 3:
                writeFile(itemNames, itemCost, itemNoShip, canShip);
            break;

            // Exit
            case 4:
                exit = true;
            break;

            // default case- if something undefined is entered
            default:
                cout << "You have entered an invalid option. Please try again..." << endl;
                continue;
            break;
        }
    } while (!exit);

    return 0;
}

// Prints the company logo out to console using a series of couts
void logo(){
    cout << "    Indiana Operations" << endl;
    cout << "************  ************" << endl;
    cout << "************  ************" << endl;
    cout << "    ***       ***      ***" << endl;
    cout << "    ***       ***      ***" << endl;
    cout << "    ***       ***      ***" << endl;
    cout << "    ***       ***      ***" << endl;
    cout << "    ***       ***      ***" << endl;
    cout << "    ***       ***      ***" << endl;
    cout << "************  ************" << endl;
    cout << "************  ************" << endl;
    cout << endl;
}

// Prints out the nenu choices with a series of couts
void menu(){
    cout << "1. Read in Inventory" << endl;
    cout << "2. Display Inventory" << endl;
    cout << "3. Write to File" << endl;
    cout << "4. Exit" << endl;
}

// Reads the file inputInventory.txt and sets array values. returns true if there was an error reading it
bool readInventory(string itemNames[], double itemCost[], int itemNoShip[], int canShip[]){
    // create file variable and open file
    ifstream inputFile;
    inputFile.open("inputInventory.txt");

    // check if there was an error opening the file
    if(!inputFile.is_open()){
        // there was an error
        return true;
    }
    cout << "\nFile read successfully..." << endl;

    // Store text in txt file into the arrays
    for(int i = 0; i < 10; ++i){
        // the first 2 words that make up a name, are combined and inserted into itemNames
        string word1, word2;
        
        // Gets each item from the text document and stores it in the variables
        inputFile >> word1 >> word2 >> itemCost[i] >> itemNoShip[i] >> canShip[i];
        itemNames[i] = word1 + " " + word2;
    }

    // closes the file
    inputFile.close();

    // no error
    return false;
}


// Prints the inventory stored in the arrays to the console
void displayInventory(string itemNames[], double itemCost[], int itemNoShip[], int canShip[]){
    // Table labels
    cout << "Item Name              Cost                  No. Stock              Shipping (1-Yes 0-No)" << endl;
    
    // loops through each variable's data and displays it
    for(int i = 0; i < 10; i++){
        cout << itemNames[i] << "               " << itemCost[i] << "                    " << itemNoShip[i] << "                              " << canShip[i] << endl << endl << endl;
    }
}

// Writes the values stored in the arrays to outputInventory.txt
void writeFile(string itemNames[], double itemCost[], int itemNoShip[], int canShip[]){
    // creates an output file variable and creates/opens outputInventory.txt
    ofstream outputFile;
    outputFile.open("outputInventory.txt");

    // loops through the arrays and prints out their values
    for(int i = 0; i < 10; i++){
        outputFile << itemNames[i] << "               " << itemCost[i] << "                    " << itemNoShip[i] << "                              " << canShip[i] << endl << endl;
    }

    // closes the file
    outputFile.close();
}