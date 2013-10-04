// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 6
// Description: 
// Filename: Complex.cpp
// Last modified on: 4/29/2013

#include "Complex.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Complex::Complex() 
{
    real = 0.0;
    imag = 0.0;
}

Complex::Complex(double r, double i)
{
    real = r; imag = i;
}

istream& operator>>(istream &strm, Complex &a)
{
    strm >> a.real >> a.imag;
}

ostream& operator<<(ostream &strm, const Complex &a)
{
    strm << a.real;
    if(a.imag < 0){
        strm << a.imag << "i";
    }
    else{
        strm << "+" << a.imag << "i";
    }
    return strm;
}

const Complex operator+(double a, Complex &b)
{
    return Complex(b.real+a,b.imag);
}


const Complex Complex::operator+(const Complex &rhs) const
{
    return Complex(real+rhs.real,imag+rhs.imag);
}

const Complex Complex::operator+(double a) const
{
    return Complex(real+a,imag);
}

Complex Complex::operator-()
{
    return Complex(-real, -imag);
}