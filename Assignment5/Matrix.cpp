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

const int defRows = 3;
const int defCols = 4;

//Default Matrix constructor
Matrix::Matrix()
{
	rows = defRows;
	columns = defCols;
}

//Matrix constructor given rows and columns
Matrix::Matrix(int r, int c)
{
	rows = r;
	columns = c;
}

//Matrix input
istream& operator>> (istream& strm, Matrix& rhs)
{
	double num;
	for (int i = 0; i < rhs.rows; i++)
	{
		for (int j = 0; j < rhs.columns; j++)
		{
			strm >> num; //Istream into double
			Complex c(num, 0); //Double converted to Complex
			rhs.matrix[i][j] = c; //Complex saved in Matrix
		}
	}
	return strm;
}

//Matrix plus Matrix
Matrix Matrix::operator+ (Matrix& rhs)
{
	Matrix result(rhs.rows, rhs.columns);
	if ((rows == rhs.rows) && (columns == rhs.columns))
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < columns; j++)
				result.matrix[i][j] = matrix[i][j] + rhs.matrix[i][j];
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
	Matrix result(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			result.matrix[i][j] = Complex(matrix[i][j].real + rhs.real, matrix[i][j].imag + rhs.imag);
	}
	cout << endl <<endl << *this << "\n\n\t\t + \n\n\t\t" << rhs << "\n\n\t\t = \n\n" << result;
	return result;
}

Matrix& Matrix::operator= (const Matrix& rhs)
{
	rows = rhs.rows;
	columns = rhs.columns;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			matrix[i][j] = rhs.matrix[i][j];
	}
	return *this;
}

Matrix& Matrix::operator= (Complex& rhs)
{
	rows = 1;
	columns = 1;
	matrix[0][0] = rhs;
	return *this;
}

Matrix Matrix::operator* (Matrix& rhs)
{
	Matrix result(rows, rhs.columns);
	Complex c(0,0);
	if (columns == rhs.rows)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < rhs.columns; j++)
			{
				for (int k = 0; k < rows; k++)
				{
					for (int l = 0; l < columns; l++)
						c = c + Complex((matrix[k][l].real*rhs.matrix[l][k].real), (matrix[k][l].imag*rhs.matrix[l][k].imag));
				}
				result.matrix[i][j] = c;
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
	Matrix result(rows, columns);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			Complex c(matrix[i][j].real * rhs.real, matrix[i][j].imag * rhs.imag);
			result.matrix[i][j] = c;
		}
	}
	cout << endl <<endl << *this << "\n\n\t\t * \n\n\t\t" << rhs << "\n\n\t\t = \n\n" << result;
	return result;
}

//Matrix output
ostream& operator<< (ostream& strm, const Matrix& rhs)
{
	for (int i = 0; i < rhs.rows; i++)
	{
		for (int j = 0; j < rhs.columns; j++)
		{
			strm << " " << rhs.matrix[i][j];
		}
		strm << endl;
	}
	return strm;
}