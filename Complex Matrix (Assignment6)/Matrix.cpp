// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 6
// Description: 
// Filename: Matrix.cpp
// Last modified on: 4/29/2013

#include "Matrix.h"
#include "Complex.h"
#include <string>
#include <iostream>

//Default Matrix constructor
Matrix::Matrix()
{
	array = new compPtr[defRows];
	for (int i = 0; i <=defRows; i++)
		array[i] = new Complex[defCols];
	numRows = defRows;
	numCols = defCols;
}

Matrix::Matrix(int r, int c)
{
	numRows = r;
	numCols = c;
	array = new compPtr[numRows];
	for (int i = 0; i <=numRows; i++)
		array[i] = new Complex[c];
}

Matrix::Matrix(const Matrix& rhs)
{
	numRows = rhs.numRows;
	numCols = rhs.numCols;
	array = new compPtr[numRows];
	for (int i = 0; i <=numRows; i++)
	{
		array[i] = new Complex[numCols];
			for (int j = 0; j <= numCols; j++)
				array[i][j] = rhs.array[i][j];
	}
}

//Matrix destructor
Matrix::~Matrix()
{
	for (int i = 0; i <= numRows; i++)
		delete array[i];
	delete []array;
	array = NULL;
}

//Matrix input
istream& operator>> (istream& strm, Matrix& rhs)
{
	double num;
	for (int i = 0; i < rhs.numRows; i++)
	{
		for (int j = 0; j < rhs.numCols; j++)
		{
			strm >> num; //Istream into double
			Complex c(num, 0); //Double converted to Complex
			rhs.array[i][j] = c; //Complex saved in Matrix
		}
	}
	return strm;
}

//Matrix plus Matrix
Matrix Matrix::operator+ (Matrix& rhs)
{
	Matrix result(rhs.numRows, rhs.numCols);
	if ((numRows == rhs.numRows) && (numCols == rhs.numCols))
	{
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < numCols; j++)
				result.array[i][j] = array[i][j] + rhs.array[i][j];
		}
		cout << endl << endl << *this << "\n\n\t\t + \n\n" << rhs << "\n\t\t = \n\n" << result;
		return result;
	}
	else
	{
		cout << endl << "The matrices could not be added because they are not of the same size. Please try again with two same-sized matrices.";
		return rhs;
	}
}

Matrix Matrix::operator+ (Complex& rhs)
{
	Matrix result(numRows, numCols);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			result.array[i][j] = Complex(array[i][j].real + rhs.real, array[i][j].imag + rhs.imag);
	}
	cout << endl <<endl << *this << "\n\n\t\t + \n\n\t\t" << rhs << "\n\n\t\t = \n\n" << result;
	return result;
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
	numRows = rhs.numRows;
	numCols = rhs.numCols;
	
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
			array[i][j] = rhs.array[i][j];
	}
	return *this;
}

Matrix& Matrix::operator= (Complex& rhs)
{
	numRows = 1;
	numCols = 1;
	array[0][0] = rhs;
	return *this;
}

Matrix Matrix::operator* (Matrix& rhs)
{
	Matrix result(numRows, rhs.numCols);
	Complex c(0,0);
	if (numCols == rhs.numRows)
	{
		for (int i = 0; i < numRows; i++)
		{
			for (int j = 0; j < rhs.numCols; j++)
			{
				for (int k = 0; k < numRows; k++)
				{
					for (int l = 0; l < numCols; l++)
						c = c + Complex((array[i][j].real*rhs.array[i][j].real), (array[i][j].imag*rhs.array[l][k].imag));
				}
				result.array[i][j] = c;
				c.real = 0;
				c.imag = 0;
			}
		}
		cout << endl << endl << *this << "\n\n\t\t * \n\n" << rhs << "\n\t\t = \n\n" << result;
		return result;
	}
	else
	{
		cout << endl << "The matrices could not be multiplied because the number of columns in matrix 1 does " <<
		"not equal the number of rows in matrix 2. Please try again with two appropriate matrices.";
		return rhs;
	}

	cout << endl <<endl << *this << "\n\n\t\t + \n\n" << rhs << "\n\n\t\t = \n\n" << result;
	return result;
}

Matrix Matrix::operator* (Complex& rhs)
{
	Matrix result(numRows, numCols);
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			Complex c(array[i][j].real * rhs.real, array[i][j].imag * rhs.imag);
			result.array[i][j] = c;
		}
	}
	cout << endl <<endl << *this << "\n\n\t\t * \n\n\t\t" << rhs << "\n\n\t\t = \n\n" << result;
	return result;
}

//Matrix output
ostream& operator<< (ostream& strm, const Matrix& rhs)
{
	for (int i = 0; i < rhs.numRows; i++)
	{
		for (int j = 0; j < rhs.numCols; j++)
		{
			strm << " " << rhs.array[i][j];
		}
		strm << endl;
	}
	return strm;
}