// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 4
// Description: Reads in a list of Chemicals from a file and allows the user to manipulate and output the list.
// Filename: Chemical.h
// Last modified on: 3/25/2013

#include <string>
#include <iostream>

class Chemical
{
	private:
		string name;
		string id;
		string units;
		string risk;
		bool isCleanAirAct, isPBT, isMetal, isCarcinogen;
		int metalType;
		char formType;
		
	public:
		Chemical();
		
		/*Parameters: none*/		
	
		Chemical(string, string, bool, bool, bool, int, bool, char, string, string); // Constructor
	
		/*Parameters: 
		string name
		string id
		boolean isCleanAirAct
		boolean isPBT
		boolean isMetal
		int metalType
		boolean isCarcinogen
		char formType
		string units
		string risk
    
		Pre-condition: List of attributes of a chemical 
		Post-condition: Instantiated Chemical object*/
		
		string toString(); //String representation
		
		void setName(string);
		void setID(string);
		void setUnits(string);
		void setRisk(string);
		void setIsCleanAirAct(bool);
		void setIsPBT(bool);
		void setIsMetal(bool);
		void setIsCarcinogen(bool);
		void setMetalType(int);
		void setFormType(char);
		string getID();
};