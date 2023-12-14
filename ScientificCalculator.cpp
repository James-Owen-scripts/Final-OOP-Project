/*
* Final Project
* Author: James Owen
* Student ID number: T00704318
* File name: ScientificCalculator.cpp
* Requirements:
*   Basic and scientific calculator application
*/

#include "ScientificCalculator.h"

// constructor
ScientificCalculator::ScientificCalculator(double in) : BasicCalculator(in) {}

// destructor
ScientificCalculator::~ScientificCalculator() {}

// sine
ScientificCalculator ScientificCalculator::sin(ScientificCalculator &opp) const {
    ScientificCalculator temp;
    double radianAngle = opp.getInput() * M_PI / 180;
    temp.setInput(std::sin(radianAngle));

    return temp;
}

// cosine
ScientificCalculator ScientificCalculator::cos(ScientificCalculator &opp) const {
    ScientificCalculator temp;
    double radianAngle = opp.getInput() * M_PI / 180;
    temp.setInput(std::cos(radianAngle));

    return temp;
}

// tangent
ScientificCalculator ScientificCalculator::tan(ScientificCalculator &opp) const {
    ScientificCalculator temp;
    double radianAngle = opp.getInput() * M_PI / 180;
    temp.setInput(std::tan(radianAngle));

    return temp;
}

// absolute
ScientificCalculator ScientificCalculator::abs(ScientificCalculator &opp) const {
    ScientificCalculator temp;
    double absVal = std::abs(opp.getInput());
    temp.setInput(absVal);

    return temp;
}

// power of
ScientificCalculator ScientificCalculator::powerOf(ScientificCalculator &opp1, ScientificCalculator &opp2) const {
    ScientificCalculator temp;
    double in = std::pow(opp1.getInput(), opp2.getInput());

    temp.setInput(in);
    return temp;
}

// display
void ScientificCalculator::display() {
    std::cout << "Scientific Calculator Output: " << getInput() << std::endl;
}
