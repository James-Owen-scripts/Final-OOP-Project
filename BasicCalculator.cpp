/*
* Final Project
* Author: James Owen
* Student ID number: T00704318
* File name: BasicCalculator.cpp
* Requirements:
*   Basic and scientific calculator application
*/


#include "BasicCalculator.h"

// constructor
BasicCalculator::BasicCalculator(double in) : Calculator(in) {}

// destructor
BasicCalculator::~BasicCalculator() {}

// addition
BasicCalculator operator + (BasicCalculator &opp1, BasicCalculator &opp2) {
    BasicCalculator temp;
    double in = opp1.getInput() + opp2.getInput();
    temp.setInput(in);

    return temp;
}

// subtraction
BasicCalculator operator - (BasicCalculator &opp1, BasicCalculator &opp2) {
    BasicCalculator temp;
    double in = opp1.getInput() - opp2.getInput();
    temp.setInput(in);

    return temp;
}

// multiplication
BasicCalculator operator * (BasicCalculator &opp1, BasicCalculator &opp2) {
    BasicCalculator temp;
    double in = opp1.getInput() * opp2.getInput();
    temp.setInput(in);

    return temp;
}

// division
BasicCalculator operator / (BasicCalculator &opp1, BasicCalculator &opp2) {
    BasicCalculator temp;
    double in = 0;
    if (opp2.getInput() == 0) {
        throw std::runtime_error("Divide by zero exception");
    }
    in = opp1.getInput() / opp2.getInput();
    temp.setInput(in);

    return temp;
}

// square
BasicCalculator BasicCalculator::square(BasicCalculator &opp) const {
    BasicCalculator temp;
    double in = opp.getInput() * opp.getInput();
    temp.setInput(in);

    return temp;
}

// square root
BasicCalculator BasicCalculator::squareRoot(BasicCalculator &opp) const {
    BasicCalculator temp;
    double in = std::sqrt(opp.getInput());

    temp.setInput(in);

    return temp;
}

void BasicCalculator::display() {
    std::cout << "Basic Calculator output: " << getInput() << std::endl;
}