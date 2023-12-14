/*
* Final Project
* Author: James Owen
* Student ID number: T00704318
* File name: main.cpp
* Requirements:
*   Basic and scientific calculator application
*/

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Calculator.h"
#include "ScientificCalculator.h"
#include "BasicCalculator.h"

using namespace std;

// constants
#define BASIC "Basic"
#define SCIENTIFIC "Scientific"

// calculator functions
void basicCalc();
void scientificCalc();

// get user input
void inputVals(string = "", string = "");

// parse output
void parser(string = "", string = "");

// basic calculator functions
void addition(double = 0.0, double = 0.0, string = "");
void subtraction(double = 0.0, double = 0.0, string = "");
void multiplication(double = 0.0, double = 0.0, string = "");
void division(double = 0.0, double = 0.0, string = "");
void square(double = 0.0, string = "");
void squareRoot(double = 0.0, string = "");

// scientific calculator functions
void cosine(double = 0.0);
void sine(double = 0.0);
void tangent(double = 0.0);
void absolute(double = 0.0);
void power(double = 0.0, double = 0.0);


// main function just starts by calling basic calculator
int main() {
    basicCalc();
}

// basic calculator function
void basicCalc() {
    string userIn = "";

    // prompt user to enter input
    cout << "\nWelcome to the Basic Calculator here are your options: ";
    cout << "\nAddition ((a/A) or (num1 + num2))";
    cout << "\nSubtraction ((s/S o)r (num1 - num2))";
    cout << "\nMultiplication ((m/M) or (num1 * num2))";
    cout << "\nDivision ((d/D) or (num1 / num2))";
    cout << "\nSquare ((sq/SQ) or (num^))";
    cout << "\nSquare Root ((sr/SR) or (num r))";
    cout << "\nScientific Calculator (sc/SC)";
    cout << "\nExit (e/E)";
    cout << "\n\nPlease enter here:" << endl;

    // input from user
    getline(cin, userIn);

    // if user selected one of the prompted calculations
    if (userIn == "a" || userIn == "A" || userIn == "s" || userIn == "S" || userIn == "m" || userIn == "M" ||
            userIn == "d" || userIn == "D" || userIn == "sq" || userIn == "SQ" || userIn == "sr" || userIn == "SR") {

        inputVals(userIn, BASIC);
    }

    // Change to scientific calculator
    else if (userIn == "sc" || userIn == "SC") {
        scientificCalc();
    }

    // see if user has incorrect input or tried to exit or entered a keystroke input
    else {
        parser(userIn, BASIC);
    }
}

// scientific calculator function
void scientificCalc() {
    string userIn = "";

    // prompt user to enter input
    cout << "\nWelcome to the Scientific Calculator here are your options: ";
    cout << "\nAddition ((a/A) or (num1 + num2))";
    cout << "\nSubtraction ((s/S o)r (num1 - num2))";
    cout << "\nMultiplication ((m/M) or (num1 * num2))";
    cout << "\nDivision ((d/D) or (num1 / num2))";
    cout << "\nSquare ((sq/SQ) or (num^))";
    cout << "\nSquare Root ((sr/SR) or (num r))";
    cout << "\nSine ((sin/SIN) or (angle i))";
    cout << "\nCosine ((cos/COS) or (angle c)";
    cout << "\nTangent ((tan/TAN or (angle t)";
    cout << "\nAbsolute Value ((abs/ABS) or (num |)";
    cout << "\nPower of ((p/P) or (num p num))";
    cout << "\nBasic Calculator (bc/BC)";
    cout << "\nExit (e/E)";
    cout << "\n\nPlease enter here:" << endl;

    // input
    getline(cin, userIn);

    // if user selected one of the prompted calculations
    if (userIn == "a" || userIn == "A" || userIn == "s" || userIn == "S" || userIn == "m" || userIn == "M" ||
        userIn == "d" || userIn == "D" || userIn == "sq" || userIn == "SQ" || userIn == "sr" || userIn == "SR" ||
        userIn == "sin" || userIn == "SIN" || userIn == "cos" || userIn == "COS" || userIn == "tan" || userIn == "TAN" ||
        userIn == "abs" || userIn == "ABS" || userIn == "p" || userIn == "P") {
        inputVals(userIn, SCIENTIFIC);
    }

    // Change to basic calculator
    else if (userIn == "bc" || userIn == "BC") {
        basicCalc();
    }

    // see if user has incorrect input or tried to exit or entered a keystroke input
    else {
        parser(userIn, SCIENTIFIC);
    }
}

// method for prompted user input
void inputVals(string userIn, string typeCalculator) {
    string inVal;
    double val1, val2;

    cout << "\nPlease enter your first value: "; // prompt user for first input
    getline(cin, inVal); // first value added to string

    // try block to parse to double
    try {
        val1 = stod(inVal);
    }

    // catch block for if user entered a non-numeric argument
    catch (const invalid_argument& e) {
        cerr << "Invalid argument" << endl;

        // if else to return to calculator if incorrect input
        if (typeCalculator == BASIC) {
            basicCalc();
        }
        else {
            scientificCalc();
        }
    }

    // catch block if user entered a argument that is out of range
    catch (const out_of_range& e) {
        cerr << "Value out of range" << endl;

        // if else to return to calculator if incorrect input
        if (typeCalculator == BASIC) {
            basicCalc();
        }
        else {
            scientificCalc();
        }
    }

    // if statement to see if equation only requires one input
    if (userIn != "sq" && userIn != "SQ" && userIn != "sr" && userIn != "SR" && userIn != "sin" && userIn != "SIN" &&
    userIn != "cos" && userIn != "COS" && userIn != "tan" && userIn != "TAN" && userIn != "abs" && userIn != "ABS") {

        cout << "\nPlease enter your second value: "; // prompt user to enter second value
        getline(cin, inVal); // second value added to string

        // try block to parse to double
        try {
            val2 = stod(inVal);
        }

        // catch block for if user entered a non-numeric argument
        catch (const invalid_argument& e) {
            cerr << "Invalid argument" << endl;

            // if else to return to calculator if incorrect input
            if (typeCalculator == BASIC) {
                basicCalc();
            }
            else {
                scientificCalc();
            }
        }

        // catch block if user entered a argument that is out of range
        catch (const out_of_range& e) {
            cerr << "Value out of range" << endl;

            // if else to return to calculator if incorrect input
            if (typeCalculator == BASIC) {
                basicCalc();
            }
            else {
                scientificCalc();
            }
        }
    }

    // if statement to find the calculation the user wanted and take them to the function to execute
    if (userIn == "a" || userIn == "A"){
        addition(val1, val2, typeCalculator);
    }
    else if (userIn == "s" || userIn == "S") {
        subtraction(val1, val2, typeCalculator);
    }
    else if (userIn == "m" || userIn == "M") {
        multiplication(val1, val2, typeCalculator);
    }
    else if (userIn == "d" || userIn == "D") {
        division(val1, val2, typeCalculator);
    }
    else if (userIn == "sq" || userIn == "SQ") {
        square(val1, typeCalculator);
    }
    else if (userIn == "sr" || userIn == "SR") {
        squareRoot(val1, typeCalculator);
    }
    else if (userIn == "sin" || userIn == "SIN") {
        sine(val1);
    }
    else if (userIn == "cos" || userIn == "COS") {
        cosine(val1);
    }
    else if (userIn == "tan" || userIn == "TAN") {
        tangent(val1);
    }
    else if (userIn == "abs" || userIn == "ABS") {
        absolute(val1);
    }
    else if (userIn == "p" || userIn == "P") {
        power(val1, val2);
    }

    // clear cin
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // if else to return to the calculator menu for user to do another action
    if (typeCalculator == BASIC) {
        basicCalc();
    }
    else {
        scientificCalc();
    }
}

// parser function parses user input or exits the program or finds the user has entered an incorrct value
void parser(string userIn, string type) {

    // iterate: to change if user wanted to exit the program
    // decCount: to make sure entered numeric values only have 1 decimal
    // negCount: to make sure there is only one negative in number
    bool iterate = true, decCount = true, negCount = true;

    string val1 = ""; // val1: holds users first numeric argument
    char opp = '\0'; // opp: is the calculation type the user would like to execute
    string val2 = ""; // val2 is the users second numeric argument

    // for loop iterates through the input of the user
    for (int i = 0; i < userIn.length(); i++) {

        // if statement to ignore white spaces
        if (userIn[i] == ' ') {
            continue;
        }

        // check if user wants to exit, change iterate to false and break the loop
        else if (userIn == "e" || userIn == "E") {
            iterate = false;
            cout << "Thanks for using the " << type << " Calculator!" << endl;
            exit(0);
            break;
        }

        // first number parse
        else if ((isdigit(userIn[i]) || (userIn[i] == '.' && decCount) || (userIn[i] == '-' && negCount)) &&
                opp == '\0' && val2.empty()) {

            // if statement to make sure - wasn't entered in the middle of the number
            if (val1 != "" && userIn[i] == '-') {
                break;
            }
            val1 += userIn[i]; // concatenate val1

            if (userIn[i] == '.') decCount = false; // set decCount to false once it has been used
            if (userIn[i] == '-') negCount = false; // set negCount to false once it has been used
        }

        // get user input
        else if (!val1.empty() && (userIn[i] == '+' || userIn[i] == '-' || userIn[i] == '/'  || userIn[i] == '*'
                                   || userIn[i] == '^' || userIn[i] == 'r' || userIn[i] == 'i' || userIn[i] == 'c' ||
                                   userIn[i] == 't' || userIn[i] == '|' || userIn[i] == 'p') && opp == '\0' && val2.empty()) {

            opp = userIn[i]; // make opp equal to the operation the user wanted
            decCount = true; // reset decCount to true for second argument
            negCount = true; // reset negCount to true for second argument
        }
        else if (!val1.empty() && opp != '\0' && (isdigit(userIn[i]) || (userIn[i] == '.' && decCount) ||
                (userIn[i] == '-' && negCount))) {

            // if statement to make sure - wasn't entered in the middle of the number
            if (val2 != "" && userIn[i] == '-') {
                break;
            }

            val2 += userIn[i]; // concatenate val2

            if (userIn[i] == '.') decCount = false; // set decCount to false once it has been used
            if (userIn[i] == '-') negCount = false; // set negCount to false once it has been used
        }

        // break else
        else {
            break;
        }
    }
    double numVal1, numVal2; // numbers that val1 and val2 will be parsed to

    // check if val1 and val2 are empty else
    if (!val1.empty() && !val2.empty()) {
        // try parse val1
        try {
            numVal1 = stod(val1);
            // try parse val2
            try {
                numVal2 = stod(val2);
            }
            // catch block if user entered a argument that is non-numeric
            catch (const invalid_argument& e) {
                cerr << "Invalid argument" << endl;
            }
            // catch block if user entered a argument that is out of range
            catch (const out_of_range& e) {
                cerr << "Value out of range" << endl;
            }
        }
        // catch block if user entered a argument that is non-numeric
        catch (const invalid_argument& e) {
            cerr << "Invalid argument" << endl;
        }
        // catch block if user entered a argument that is out of range
        catch (const out_of_range& e) {
            cerr << "Value out of range" << endl;
        }
    }
    // parse single value equations
    else if (!val1.empty()) {
        // try parse val1
        try {
            numVal1 = stod(val1);
        }
        // catch block if user entered a argument that is non-numeric
        catch (const invalid_argument& e) {
            cerr << "Invalid argument" << endl;
        }
        // catch block if user entered a argument that is out of range
        catch (const out_of_range& e) {
            cerr << "Value out of range" << endl;
        }
    }

    // check for type of calculation if opp != '\0'
    if (opp != '\0') {
        // switch statement to find what calculation the user wanted and sends them there
        switch (opp) {
            case '+':
                addition(numVal1, numVal2, type);
                break;

            case '-':
                subtraction(numVal1, numVal2, type);
                break;

            case '*':
                multiplication(numVal1, numVal2, type);
                break;

            case '/':
                division(numVal1, numVal2, type);
                break;

            case '^':
                square(numVal1, type);
                break;

            case 'r':
                squareRoot(numVal1, type);
                break;

            case 'i':
                sine(numVal1);
                break;

            case 'c':
                cosine(numVal1);
                break;

            case 't':
                tangent(numVal1);
                break;

            case '|':
                absolute(numVal1);
                break;

            case 'p':
                power(numVal1, numVal2);
                break;
        }
    }
    // user wants to exit the program
    else if (userIn == "e" || userIn == "E") {
        iterate = false;
    }
    // incorrect user input
    else {
        cout << "Incorrect Input Please try again." << endl;
    }

    // send user back to the calculator they came from
    if (iterate) {
        if (type == BASIC) {
            basicCalc();
        }
        else {
            scientificCalc();
        }
    }
}

//      basic calculator functions

// function for addition
void addition(double val1, double val2, string type) {
    BasicCalculator *adds[3]; // basic calculator array

    // if else to check which calculator the user is using
    if (type == BASIC) {
        adds[0] = new BasicCalculator(val1); // initiate val1 to position 0
        adds[1] = new BasicCalculator(val2); // initiate val2 to position 1
        adds[2] = new BasicCalculator(); // result to position 2
    }
    else {
        adds[0] = new ScientificCalculator(val1); // initiate val1 to position 0
        adds[1] = new ScientificCalculator(val2); // initiate val2 to position 1
        adds[2] = new ScientificCalculator(); // result to position 2
    }

    *adds[2] = *adds[0] + *adds[1]; // add together using operator overloading

    adds[2]->display(); // point to display function

    // for loop to delete all object instances from memory
    for (int i = 0; i < 3; i++) {
        delete adds[i];
    }
}

// function for subtraction
void subtraction(double val1, double val2, string type) {
    BasicCalculator *subs[3]; // basic calculator array

    // if else to check which calculator the user is using
    if (type == BASIC) {
        subs[0] = new BasicCalculator(val1); // initiate val1 to position 0
        subs[1] = new BasicCalculator(val2); // initiate val2 to position 1
        subs[2] = new BasicCalculator(); // result to position 2
    }
    else {
        subs[0] = new ScientificCalculator(val1); // initiate val1 to position 0
        subs[1] = new ScientificCalculator(val2); // initiate val2 to position 1
        subs[2] = new ScientificCalculator(); // result to position 2
    }

    *subs[2] = *subs[0] - *subs[1]; // subtract using operator overloading

    subs[2]->display(); // point to display function

    // for loop to delete all object instances from memory
    for (int i = 0; i < 3; i++) {
        delete subs[i];
    }
}

// function for multiplication
void multiplication(double val1, double val2, string type) {
    BasicCalculator *mul[3]; // basic calculator array

    // if else to check which calculator the user is using
    if (type == BASIC) {
        mul[0] = new BasicCalculator(val1); // initiate val1 to position 0
        mul[1] = new BasicCalculator(val2); // initiate val2 to position 1
        mul[2] = new BasicCalculator(); // result to position 2
    }
    else {
        mul[0] = new ScientificCalculator(val1); // initiate val1 to position 0
        mul[1] = new ScientificCalculator(val2); // initiate val2 to position 1
        mul[2] = new ScientificCalculator(); // result to position 2
    }

    *mul[2] = *mul[0] * *mul[1]; // multiplication using operator overloading

    mul[2]->display(); // point to display function

    // for loop to delete all object instances from memory
    for (int i = 0; i < 3; i++) {
        delete mul[i];
    }
}

// function for division
void division(double val1, double val2, string type) {
    BasicCalculator *div[3]; // basic calculator array

    // if else to check which calculator the user is using
    if (type == BASIC) {
        div[0] = new BasicCalculator(val1); // initiate val1 to position 0
        div[1] = new BasicCalculator(val2); // initiate val2 to position 1
        div[2] = new BasicCalculator(); // result to position 2
    }
    else {
        div[0] = new ScientificCalculator(val1); // initiate val1 to position 0
        div[1] = new ScientificCalculator(val2); // initiate val2 to position 1
        div[2] = new ScientificCalculator(); // result to position 2
    }

    // divide by zero exception
    try {
        *div[2] = *div[0] / *div[1]; // division using operator overloading
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
    }

    div[2]->display(); // point to display function

    // for loop to delete all object instances from memory
    for (int i = 0; i < 3; i++) {
        delete div[i];
    }
}

// function for square
void square(double val, string type) {
    BasicCalculator *squared; // basic calculator pointer

    // if else to check which calculator the user is using
    if (type == BASIC) {
        squared = new BasicCalculator(val);
    }
    else {
        squared = new ScientificCalculator(val);
    }

    *squared = squared->square(*squared); // point to squared function and re-initiate squared to return value

    squared->display(); // point to display function

    delete squared; // delete object instance of squared from memory
}

// function to find the square root
void squareRoot(double val, string type) {
    BasicCalculator *squareRooted; // basic calculator pointer

    // if else to check which calculator the user is using
    if (type == BASIC) {
        squareRooted = new BasicCalculator(val);
    }
    else {
        squareRooted = new ScientificCalculator(val);
    }

    *squareRooted = squareRooted->squareRoot(*squareRooted); // point to square root function and re-initialize to return value

    squareRooted->display(); // point to display function

    delete squareRooted; // delete object instance of squareRooted from memory
}


//       scientific calculator functions

// function to find sin value
void sine(double val) {
    ScientificCalculator *sinVal = new ScientificCalculator(val); // initialize sinVal with val

    *sinVal = sinVal->sin(*sinVal); // point to sin function to return the object containing result

    sinVal->display(); // display output

    delete sinVal; // delete sinVal from memory
}

// function to find cos val
void cosine(double val) {
    ScientificCalculator *cosVal = new ScientificCalculator(val); // initialize cosVal with val

    *cosVal = cosVal->cos(*cosVal); // point to cos function to return the object containing result

    cosVal->display(); // display output

    delete cosVal; // delete cosVal from memory
}

// function to find tan val
void tangent(double val) {
    ScientificCalculator *tanVal = new ScientificCalculator(val); // initialize tanVal with val

    *tanVal = tanVal->tan(*tanVal); // point to tan function to return the object containing result

    tanVal->display(); // display output

    delete tanVal; // delete tanVal from memory
}

// function to find a numbers absolute value
void absolute(double val) {
    ScientificCalculator *absVal = new ScientificCalculator(val); // initialize absVal with val

    *absVal = absVal->abs(*absVal); // point to abs function to return the object containing result

    absVal->display(); // display output

    delete absVal; // delete absVal from memory
}

// function to find the result of a number to the power of another number
void power(double val1, double val2) {
    ScientificCalculator *powVals[2] = { new ScientificCalculator(val1), new ScientificCalculator(val2)}; // initialize the two array items to contain val1, and val2 in object

    *powVals[0] = powVals[0]->powerOf(*powVals[0], *powVals[1]); // have position 0 to contain result point to powerOf function to calculate

    powVals[0]->display(); // display output

    // for loop to delete array items from memory
    for (int i = 0; i < 2; i++) {
        delete powVals[i];
    }
}