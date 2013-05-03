// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 4
// Description: Reads in a list of Chemicals from a file and allows the user to manipulate and output the list.
// Filename: Driver.cpp
// Last modified on: 3/25/2013

#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
#include "ChemicalData.h"

using namespace std;

void menu(ChemicalData&);
void read(ifstream&, ChemicalData&);

int main()
{
	string input;
	int index;
		
	ChemicalData dataArray;

	cout << "\"toxins.csv\" is the default input file. Continue (Y/N)? N to enter own file name (must be in current directory): ";
	getline(cin, input);
	
	if (input == "Y" || input == "y")
		input = "toxins.csv";
	else
	{
		cout << "Enter the name of the file you would like to read from: ";
		getline(cin, input);
	}
	
	ifstream infile;
	infile.open(input.c_str());

	while (infile.good() != true)
	{
		cout << "There was an error reading in the file. Please check that the file exists in the current directory and enter the name again: ";
		getline(cin, input);
		infile.open(input.c_str());
	}
	read(infile, dataArray);	
	menu(dataArray);
	infile.close();
	return 0;
}

void read(ifstream& fileIn, ChemicalData& dataArray)
{
	char name[100];
	char id[100];
	char units[100];
	char risk[100];
	bool isCleanAirAct, isPBT, isMetal, isCarcinogen;
	int metalType;
	char formType;
	char input[100];
	string temp;
	
	while (!fileIn.eof())
	{
		fileIn.getline(name, 100, ',');
		fileIn.getline(id, 100, ',');
		fileIn.getline(input, 100, ',');
		if (input == "YES")
			isCleanAirAct = true;
		else
			isCleanAirAct = false;		
		
		fileIn.getline(input, 100, ',');
		if (input == "PBT")
			isPBT = true;
		else
			isPBT = false;
			
		fileIn.get(input, 100, ',');
		
		if (input == "YES")
			isMetal = true;
		else
			isMetal = false;
		
		fileIn.getline(input, 100, ',');
		metalType = atoi(input);
		
		fileIn.getline(input, 100, ','); 
		
		if (input == "YES")
			isCarcinogen = true;
		else
			isCarcinogen = false;		
		
		fileIn.getline(input, 100, ',');
		temp = input;
		formType = temp.at(0);
		fileIn.getline(units, 100, ',');
		fileIn.getline(risk, 100, '\r');
	
		Chemical c(name, id, isCleanAirAct, isPBT, isMetal, metalType, isCarcinogen, formType, units, risk);
		dataArray.addChemical(c);
	}
	
	cout << endl << "File import complete!" << endl;
}

void menu(ChemicalData& dataArray)
{
	string input;
	short choice;
	do
	{
		cout << endl << "Choose what you would like to do with the data." << endl << "1. Add a new chemical." << endl << "2. Update existing chemical." <<
		endl << "3. Remove duplicate chemicals." << endl << "4. Sort data by specific criteria." << endl << "5. Output data to a file." << endl <<
		"6. End program.  ";
		cin >> choice;
		
		switch (choice)
		{
			case 1:
			{
					char name[100];
					char id[100];
					char units[100];
					char risk[100];
					bool isCleanAirAct, isPBT, isMetal, isCarcinogen;
					int metalType;
					char formType;
					
					cout << "New chemical name and CAS number? (Separate with a space): ";
					cin >> name >> id;
					cout << endl << "Is the chemical covered by the Clean Air Act? (YES/NO) ";
					cin >> input;
					if (input == "YES")
						isCleanAirAct = true;
					else
						isCleanAirAct = false;
					cout << endl << "What classification is the chemical? ";
					cin >> input;
					if (input == "YES")
						isPBT = true;
					else
						isPBT = false;
					cout << endl << "Is the chemical a metal? (YES/NO) ";
					cin >> input;
					if (input == "YES")
					{
						isMetal = true;
						cout << endl << "What type is the metal? ";
						cin >> metalType;
					}
					else
						isMetal = false;
					cout << endl << "Is the chemical a carcinogen? (YES/NO) ";
					cin >> input;
					if (input == "YES")
						isCarcinogen = true;
					else
						isCarcinogen = false;
					cout << endl << "What form type is the chemical? ";
					cin >> formType;
					cout << endl << "What units is the chemical measured in? ";
					cin >> units;
					cout << endl << "What is the risk level of the chemical? ";
					cin >> risk;
					
					Chemical c(name, id, isCleanAirAct, isPBT, isMetal, metalType, isCarcinogen, formType, units, risk);
					cout << "New chemical created! Adding to list...";
					if (dataArray.search(id) == -1)
						dataArray.addChemical(c);
					else
						cout << endl << "Sorry, that chemical already exists in the array. Please only add new chemicals.";
				break;
			}
			case 2:
			{
				string temp;
				cout << endl << "Please enter the CAS number of the chemical you would like to update: ";
				cin >> temp;
				dataArray.updateChem(temp);
				break;
			}
			case 3:
			{
				dataArray.removeDups();
				break;
			}
			case 4:
			{
				string temp;
				cout << endl << "Enter the attribute you would like to sort the array by: ";
				cin >> temp;
				dataArray.sort(temp);
				break;
			}
			case 5:
			{
				cout << endl << "Choose the name of the file you would like to output to (ex. \"output.txt\"): ";
				cin >> input;
				ofstream outFile;
				outFile.open(input.c_str());
				outFile << dataArray.printArray();
				break;
			}
			default:
			{
				choice = 6;
			}
		}
	} while (choice != 6);
}
