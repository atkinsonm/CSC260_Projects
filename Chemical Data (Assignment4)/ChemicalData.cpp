// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 4
// Description: Reads in a list of Chemicals from a file and allows the user to manipulate and output the list.
// Filename: ChemicalData.cpp
// Last modified on: 3/25/2013

#include "ChemicalData.h"
#include <iostream>
#include <fstream>

ChemicalData::ChemicalData()
{
	index = 0;
}

void ChemicalData::addChemical(Chemical c)
{
	if (index<=2000)
	{
		ChemArray[index] = c;
		index++;
		cout << endl << "Chemical successfully added to list!";
	}
	else
		cout << "Array is at capacity. Please remove duplicates to try to free up space.";
}

void ChemicalData::updateChem(string id)
{
	int temp1 = ChemicalData::search(id);
	int temp2;
	string input;
	if (temp1 != -1)
	{
		cout << endl << "Enter the attribute you would like to change." << endl << "1. Name" << endl << "2. CAS Number" << endl << "3. Clean Air Regulated"
		<< endl << "4. Classification" << endl << "5. Metal? (YES/NO)" << endl << "6. Metal Type" << endl << "7. Carcinogen? (YES/NO)" << endl << 
		"8. Form" << endl << "9. Units" << endl << "10. Risk  ";
		cin >> temp2;
		
		switch (temp2)
		{
			case 2:
			{
				cout << endl << "Enter a new CAS number for the chemical: ";
				cin >> input;
				ChemArray[temp1].setID(input);
				break;
			}
			case 3:
			{
				cout << endl << "Enter whether this chemical is regulated by the Clean Air Act (YES/NO): ";
				cin >> input;
				if (input == "YES")
					ChemArray[temp1].setIsCleanAirAct(true);
				else
					ChemArray[temp1].setIsCleanAirAct(false);
				break;
			}
			case 4:
			{
				cout << endl << "Enter the classification of the chemical: ";
				cin >> input;
				if (input == "PBT")
					ChemArray[temp1].setIsPBT(true);
				else
					ChemArray[temp1].setIsPBT(false);
				break;
			}
			case 5:
			{
				cout << endl << "Enter whether this chemical is a metal (YES/NO): ";
				cin >> input;
				if (input == "YES")
					ChemArray[temp1].setIsMetal(true);
				else
					ChemArray[temp1].setIsMetal(false);
				break;
			}
			case 6:
			{
				cout << endl << "Enter the type of metal ";
				cin >> temp2;
				ChemArray[temp1].setMetalType(temp2);
				break;
			}
			case 7:
			{
				cout << endl << "Enter whether the chemical is a carcinogen (YES/NO): ";
				cin >> input;
				if (input == "YES")
					ChemArray[temp1].setIsCarcinogen(true);
				else
					ChemArray[temp1].setIsCarcinogen(false);
				break;
			}
			case 8:
			{
				cout << endl << "Enter the form the chemical is in: ";
				cin >> input;
				ChemArray[temp1].setFormType(input.at(0));
				break;
			}
			case 9:
			{
				cout << endl << "Enter the units the chemical is measured in: ";
				cin >> input;
				ChemArray[temp1].setUnits(input);
				break;
			}
			case 10:
			{
				cout << endl << "Enter the risk level of the chemical: ";
				cin >> input;
				ChemArray[temp1].setRisk(input);
				break;
			}
			default:
			{
				cout << endl << "Enter the new name for the chemical: ";
				cin >> input;
				ChemArray[temp1].setName(input);
			}
		}
		cout << endl << "Successfully updated chemical!";
	}
	else
		cout << endl << "Sorry, that chemical found not be found. Please check that you have entered the correct CAS number.";
}

void ChemicalData::sort(string attribute)
{
	int length = 2000;
	int i;
	Chemical key;
	for(int j=1;j<length;j++)
	{
		key=ChemArray[j];
		i=j-1;
		while(ChemArray[i].getID()>key.getID() && i>=0)
		{
			ChemArray[i+1]=ChemArray[i];
			i--;
		}
		ChemArray[i+1]=key;
	}
	cout << endl << "The array has been sorted!";
}

void ChemicalData::removeDups()
{
	sort("id");
	Chemical c;
	for (int i = 0; i < 2000; i++)
	{
		if (ChemArray[i].getID() == ChemArray[i+1].getID())
		{
			ChemArray[i+1] = c;
		}
	}
}

int ChemicalData::search(string id)
{
	bool found = false;
	int result = -1, i = 0;
	
	while (!found && i <= 2000)
	{
		if(ChemArray[i].getID() == id)
		{
			result = i;
			found = true;
		}
		i++;
	}
	return result;
}

string ChemicalData::printArray()
{
	string result;
	for (int i = 0; i <= 2000; i++)
		result += ChemArray[i].toString() += '\n';
	return result;
}




