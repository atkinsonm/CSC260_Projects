// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 6
// Description: Driver for Assignment 6. Tests use cases of the Matrix class.
// Filename: Driver.cpp
// Last modified on: 4/29/2013

#include <iostream>
#include <fstream>
#include <string>
#include "Matrix.h"

using namespace std;

void fromKeyboard();
void fromFile();
void sampleFunctions(Matrix&, Matrix&);

int main()
{
	int input;
	
	do
	{
		cout << "Please enter whether you would like to read in matrices from the keyboard (0) or from a file (1): ";
		cin >> input;	
	}
	while (input != 0 && input != 1);

	if (input == 0)
	{
		fromKeyboard();
	}
	else
	{
		fromFile();
	}
	
	return 0;
}

void fromKeyboard() //Reads in 2 matrices from the keyboard
{
	int x, y;
	
	cout << endl <<"Please specify the number of rows in the first matrix: ";
	cin >> x;
	cout << endl << "Please specify the number of columns in the first matrix: ";
	cin >> y;
	
	Matrix m1(x,y);
	
	cout << endl << "Please type the elements for the matrix, a row at a time. These can all be on one line: ";
	cin >> m1;
	
	cout << endl <<"Please specify the number of rows in the second matrix: ";
	cin >> x;
	cout << endl << "Please specify the number of columns in the second matrix: ";
	cin >> y;
	
	Matrix m2(x,y);
	
	cout << endl << "Please type the elements for the matrix, a row at a time. These can all be on one line: ";
	cin >> m2;
	
	sampleFunctions(m1, m2);
}

void fromFile() //Reads in 2 matrices from user-specified files
{
	ifstream fin1, fin2;
	int x, y;
	string input;
	
	cout << endl << "Please enter the name of the first file you would like to read a matrix in from: ";
	cin >> input;
	fin1.open(input.c_str());
	
	while (fin1.good() != true)
	{
		cout << endl << "There was an error reading in the file. Please check that the file exists in the current directory and enter the name again: ";
		getline(cin, input);
		fin1.open(input.c_str());
	}
	
	fin1 >> x >> y;
	Matrix m1(x, y);
	fin1 >> m1;
	
	cout << endl << "Please enter the name of the second file: ";
	cin >> input;
	fin2.open(input.c_str());

	while (fin2.good() != true)
	{
		cout << endl << "There was an error reading in the file. Please check that the file exists in the current directory and enter the name again: ";
		getline(cin, input);
		fin2.open(input.c_str());
	}
	
	fin2 >> x >> y;
	Matrix m2(x, y);
	fin2 >> m2;
	
	sampleFunctions(m1, m2);
}

//Performs examples of the basic overloaded functions of the Matrix class
void sampleFunctions(Matrix& m1, Matrix& m2)
{
	cout << endl << "You entered for matrix 1: " << endl << m1 << endl << endl << "And for matrix 2: " << endl << m2 << endl;
	cout << endl << "Here is an example of addition between the two matrices you input: ";
	Matrix m3 = (m1 + m2);
	
	Complex c(3, 5);
	
	cout << endl << "Here is an example of matrix 1 plus the complex number " << c << ": ";
	m3 = (m1 + c);
	
	cout << endl << "Here is an example of multiplication between the two matrices you input: ";
	Matrix m4 = (m1 * m2);
	
	cout << endl << "Here is an example of multiplication between matrix 2 and the complex number " << c << ": ";
	Matrix m5 = (m2 * c);
}