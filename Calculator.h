/*
* Final Project
* Author: James Owen
* Student ID number: T00704318
* File name: Calculator.h
* Requirements:
*   Basic and scientific calculator application
*/

#ifndef FINAL_CALCULATOR_H
#define FINAL_CALCULATOR_H

// calculator base class
class Calculator {
public:
    // constructor
    Calculator(const double = 0);

    // destructor
    ~Calculator();

    // pure virtual display function
    virtual void display() = 0;

    // getter and setter for input variable
    void setInput(const double = 0);
    double getInput() const;

private:
    // input variable for user input
    double input;

};


#endif //FINAL_CALCULATOR_H
