// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 4
// Description: Reads in a list of Chemicals from a file and allows the user to manipulate and output the list.
// Filename: ChemicalData.h
// Last modified on: 3/25/2013

#include "Chemical.h"
#include <iostream>
#include <fstream>

class ChemicalData
{
	private:
		Chemical ChemArray[2000];
		int index;
		
	public:
		ChemicalData();
	
		void addChemical(Chemical);
		
		/*Parameters: Chemical
    
		Pre-condition: Stand-alone Chemical
		Post-condition: Chemical added to array*/
		
		void updateChem(string);
		
		/*Parameters: string of chemical ID
    
		Pre-condition: Chemical in array
		Post-condition: Chemical data manipulated*/
		
		void sort(string);
		
		/*Parameters: Sorting criteria (string)
    
		Pre-condition: Unsorted array
		Post-condition: Sorts array of chemicals*/

		void removeDups();
		
		/*Parameters: none
    
		Pre-condition: Array of Chemicals
		Post-condition: Array without duplicate Chemicals*/
		
		int search(string);
		
		/*Parameters: Chemical CAS number (string)
    
		Pre-condition: Searching to see if Chemical already exists
		Post-condition: Index if chemical found, -1 otherwise*/
		
		string printArray();
};