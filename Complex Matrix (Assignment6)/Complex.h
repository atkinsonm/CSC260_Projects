// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 6
// Description: 
// Filename: Complex.h
// Last modified on: 4/29/2013

#ifndef COMPLEX_H
#define	COMPLEX_H

#include <iostream>

using namespace std; 

class Complex 
{
	friend class Matrix;
	public:
		Complex();
		Complex(double, double);
		
		const Complex operator+(const Complex&) const;
		const Complex operator+(double) const;
    
		friend ostream& operator<<(ostream&, const Complex&);
		friend istream& operator>>(istream&, Complex&);
		friend const Complex operator+(double, Complex&);
		
		Complex operator-();
		
	private:
		double real, imag;
};
#endif	/* COMPLEX_H */

