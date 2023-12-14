/*
* Final Project
* Author: James Owen
* Student ID number: T00704318
* File name: ScientificCalculator.h
* Requirements:
*   Basic and scientific calculator application
*/


#ifndef FINAL_SCIENTIFICCALCULATOR_H
#define FINAL_SCIENTIFICCALCULATOR_H
#include "BasicCalculator.h"
#include <cmath>
#include <iostream>


class ScientificCalculator : public BasicCalculator {
public:
    // constructor
    ScientificCalculator(double = 0);
    // destructor
    ~ScientificCalculator();

    // sin
    ScientificCalculator sin (ScientificCalculator &) const;
    // cos
    ScientificCalculator cos (ScientificCalculator &) const;
    // tan
    ScientificCalculator tan (ScientificCalculator &) const;
    // absolute
    ScientificCalculator abs (ScientificCalculator &) const;
    // power or
    ScientificCalculator powerOf(ScientificCalculator &, ScientificCalculator &) const;

    // display
    void virtual display() override;
};


#endif //FINAL_SCIENTIFICCALCULATOR_H
