/*
* Final Project
* Author: James Owen
* Student ID number: T00704318
* File name: Calculator.cpp
* Requirements:
*   Basic and scientific calculator application
*/

#include "Calculator.h"

// initialize input in constructor
Calculator::Calculator(const double in) : input(in) {}

// destructor
Calculator::~Calculator() {}


// setInput function
void Calculator::setInput(const double in) {
    input = in;
}

// getInput function
double Calculator::getInput() const {
    return input;
}

