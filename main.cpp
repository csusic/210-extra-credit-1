// COMSC-210 | Extra Credit 1 | Christine Susic

// This is one of my homework assignments for the COMSC-110 class I took at DVC. 

// COMSC-110 | Extra Credit | Christine Susic

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//set precision
const int PREC = 1;
//difficulty range values
const int MIN = 0, MAX_EASY = 10, MAX_MED = 100, MAX_HARD = 1000, MAX_EXTREME = 10000;
//range of 0-2 for addition (0), subtraction (1), or multiplication (2)
const int MIN1 = 0, MAX1 = 2;

int main() {
    //declarations
    cout << fixed << setprecision(PREC);
    srand(time(0));
    int calculations, difficulty, entry, num1, num2, 
    operation, addition, subtraction, multiplication, correctAnswers = 0;
    double percentage;
    
    //input
    //number of math calculations
    cout << "Math tutor 2.0!\n\n";
    cout << "How many math calculations do you want to do? (1-10) ";
    cin >> calculations;
    //input validation
    while (calculations < 1 or calculations > 10 or cin.fail()) {
        if (cin.fail()) {
            cin.clear(); //clears the cin.fail flag
            cin.ignore(1000, '\n'); //clears the buffer of the bad char+endl
        }
        cout << "ERROR. How many math calculations do you want to do? (1-10) ";
        cin >> calculations;
    }
    //difficulty level 
    cout << "What difficulty level do you want? ";
    cout << "Easy (1), medium (2), hard (3), or extreme (4)? ";
    cin >> difficulty;
    //input validation
    while (difficulty < 1 or difficulty > 4 or cin.fail()) {
        if (cin.fail()) {
            cin.clear(); //clears the cin.fail flag
            cin.ignore(1000, '\n'); //clears the buffer of the bad char+endl
        }
        cout << "ERROR. What difficulty level do you want? ";
        cout << "Easy (1), medium (2), hard (3), or extreme (4)? ";
        cin >> difficulty;
    }

    //for loop
    for (int i = 0; i < calculations; i++) {
        
        //difficulty of random numbers
        if (difficulty == 1) {
            num1 = rand() % (MAX_EASY - MIN + 1) + MIN;
            num2 = rand() % (MAX_EASY - MIN + 1) + MIN;
        }
        else if (difficulty == 2) {
            num1 = rand() % (MAX_MED - MIN + 1) + MIN;
            num2 = rand() % (MAX_MED - MIN + 1) + MIN;
        }
        else if (difficulty == 3) {
            num1 = rand() % (MAX_HARD - MIN + 1) + MIN;
            num2 = rand() % (MAX_HARD - MIN + 1) + MIN;
        }
        else {
            num1 = rand() % (MAX_EXTREME - MIN + 1) + MIN;
            num2 = rand() % (MAX_EXTREME - MIN + 1) + MIN;
        }
        
        //calculations
        //random variable for addition, subtraction, or multiplication
        operation = rand() % (MAX1 - MIN1 + 1) + MIN1;
        addition = num1 + num2;
        subtraction = num1 - num2;
        multiplication = num1 * num2;
        
        //output
        cout << "\nWhat is: " << endl;
        //random choice of 0, 1, or 2 for addition, subtraction, or multiplication
        if (operation == 0) {
            cout << num1 << " + " << num2 << " = "; //addition
            cin >> entry;
            if (entry == addition) {
                cout << "Correct!" << endl;
                correctAnswers++;
            }
            else
                cout << "Incorrect, the answer is " << addition << "." << endl;
        }
        else if (operation == 1) {
            cout << num1 << " - " << num2 << " = "; //subtraction
            cin >> entry;
            if (entry == subtraction) {
                cout << "Correct!" << endl;
                correctAnswers++;
            }
            else
                cout << "Incorrect, the answer is " << subtraction << "." << endl;
        }
        else {
            cout << num1 << " * " << num2 << " = "; //multiplication
            cin >> entry;
            if (entry == multiplication) {
                cout << "Correct!" << endl;
                correctAnswers++;
            }
            else
                cout << "Incorrect, the answer is " << multiplication << "." << endl;
        }
    }
    
    cout << "\nCorrect answers: " << correctAnswers << endl;
    percentage = correctAnswers / double(calculations) * 100;
    cout << "Percentage: " << percentage << "%" << endl;

    return 0;
}