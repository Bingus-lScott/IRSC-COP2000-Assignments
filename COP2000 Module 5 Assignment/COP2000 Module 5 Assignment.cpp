/*
Landon Scott
COP2000
3-27-2024

The purpose of the program is to enter in a series of baby weights and learn information such as the highest baby weight,
lowest baby weight, and the average baby weight.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype Definitions
void welcome();
void getBabyWeight(double& weight);
void findLowest(double baby1, double baby2, double baby3, double baby4, double baby5);
void findHighest(double baby1, double baby2, double baby3, double baby4, double baby5);
double weightAverage(double baby1, double baby2, double baby3, double baby4, double baby5);

int main(){
    // All the baby weight variables being defined
    double babyWeight1, babyWeight2, babyWeight3, babyWeight4, babyWeight5;
    
    // Create the title block
    welcome();

    // Sadly I can't use a for loop for a lot of this stuff in the scope of this program :(
    // Get the weight for each baby from user input
    getBabyWeight(babyWeight1);
    getBabyWeight(babyWeight2);
    getBabyWeight(babyWeight3);
    getBabyWeight(babyWeight4);
    getBabyWeight(babyWeight5);

    // Find the lowest baby weight and output it to console
    findLowest(babyWeight1, babyWeight2, babyWeight3, babyWeight4, babyWeight5);
    // Find the highest baby weight and output it to console
    findHighest(babyWeight1, babyWeight2, babyWeight3, babyWeight4, babyWeight5);

    // Find the Overall Average Baby Weight and output it to console
    cout << "Overall Baby Weight Average: "
         << fixed
         << setprecision(2)  
         << weightAverage(babyWeight1, babyWeight2, babyWeight3, babyWeight4, babyWeight5);

    return 0;
}

// Create the welcome block when called
void welcome(){
    cout << "******************************************************************" << endl;
    cout << "            BABY WEIGHT PROGRAM" << endl;
    cout << "           Please Enter the Five Baby Weights" << endl;
    cout << "        Please enter a real number Weights (Must be > 0)." << endl;
    cout << endl;
    cout << "        Program Developed by: Landon Scott" << endl;
    cout << "******************************************************************\n" << endl;
}

// Gets the baby weight from user and sets it using a refrence, if the value is invalid it rejects the value and makes user resubmit
void getBabyWeight(double& weight){
    cout << "Please enter the Baby's Weight > ";
    cin >> weight;
    while(weight <= 0){
        cout << "Invalid Weight! Please Enter a Valid Weight > ";
        cin >> weight;  
        cout << endl; 
    }
    cout << endl;
}

// finds the lowest value from all argumuents passed in using a series of if statements and writes the answer to console
void findLowest(double baby1, double baby2, double baby3, double baby4, double baby5){
    double lowestWeight = baby1;
    double lowestNumber = 1;

    if(lowestWeight < baby2){
        lowestWeight = baby2;
        lowestNumber = 2;
    }
    else if(lowestWeight == baby2){
        cout << "We have a TIE!! No Lowest Birth Weight for Today..." << endl;
        return;
    }

    if(lowestWeight < baby3){
        lowestWeight = baby3;
        lowestNumber = 3;
    }
    else if(lowestWeight == baby3){
        cout << "We have a TIE!! No Lowest Birth Weight for Today..." << endl;
        return;
    }

    if(lowestWeight < baby4){
        lowestWeight = baby4;
        lowestNumber = 4;
    }
    else if(lowestWeight == baby4){
        cout << "We have a TIE!! No Lowest Birth Weight for Today..." << endl;
        return;
    }

    if(lowestWeight < baby5){
        lowestWeight = baby5;
        lowestNumber = 5;
    }
    else if(lowestWeight == baby5){
        cout << "We have a TIE!! No Lowest Birth Weight for Today..." << endl;
        return;
    }

    cout << "Baby #" 
         << lowestNumber 
         << " has the lowest birth weight at " 
         << lowestWeight 
         << "." 
         << endl;
}

// finds the highest value from all argumuents passed in using a series of if statements and writes the answer to console
void findHighest(double baby1, double baby2, double baby3, double baby4, double baby5){
    double highestWeight = baby1;
    double highestNumber = 1;

    if(highestWeight > baby2){
        highestWeight = baby2;
        highestNumber = 2;
    }
    else if(highestWeight == baby2){
        cout << "We have a TIE!! No Highest Birth Weight for Today..." << endl;
        return;
    }

    if(highestWeight > baby3){
        highestWeight = baby3;
        highestNumber = 3;
    }
    else if(highestWeight == baby3){
        cout << "We have a TIE!! No Highest Birth Weight for Today..." << endl;
        return;
    }

    if(highestWeight > baby4){
        highestWeight = baby4;
        highestNumber = 4;
    }
    else if(highestWeight == baby4){
        cout << "We have a TIE!! No Highest Birth Weight for Today..." << endl;
        return;
    }

    if(highestWeight > baby5){
        highestWeight = baby5;
        highestNumber = 5;
    }
    else if(highestWeight == baby5){
        cout << "We have a TIE!! No Highest Birth Weight for Today..." << endl;
        return;
    }

    cout << "Baby #" 
         << highestNumber 
         << " has the highest birth weight at " 
         << highestWeight 
         << "." 
         << endl;
}

// returns the mean of all arguments passed in
double weightAverage(double baby1, double baby2, double baby3, double baby4, double baby5){
    return (baby1 + baby2 + baby3 + baby4 + baby5) / 5;
}