/*
* Final Project
* Author: James Owen
* Student ID number: T00704318
* File name: BasicCalculator.h
* Requirements:
*   Basic and scientific calculator application
*/

#ifndef FINAL_BASICCALCULATOR_H
#define FINAL_BASICCALCULATOR_H
#include "Calculator.h"
#include <cmath>
#include <iostream>
#include <stdexcept>


class BasicCalculator : public Calculator {
public:
    // constructor
    BasicCalculator(double = 0);
    // destructor
    ~BasicCalculator();

    // addition operator overload
    friend BasicCalculator operator + (BasicCalculator &, BasicCalculator &);

    // subtraction operator overload
    friend  BasicCalculator operator - (BasicCalculator &, BasicCalculator &);

    // multiplication operator overload
    friend  BasicCalculator operator * (BasicCalculator &, BasicCalculator &);

    // division operator overload
    friend BasicCalculator operator / (BasicCalculator &, BasicCalculator &);

    // square operator overload
    BasicCalculator square(BasicCalculator &) const;

    // square root function
    BasicCalculator squareRoot(BasicCalculator &) const;

    // display
    virtual void display() override;
};


#endif //FINAL_BASICCALCULATOR_H
