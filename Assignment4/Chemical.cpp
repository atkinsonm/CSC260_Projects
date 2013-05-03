// Name: Michael Meluso
// Course: CSC 260, Section 01
// Semester: Spring 2013
// Instructor: Dr. Pulimood
// Assignment 4
// Description: Reads in a list of Chemicals from a file and allows the user to manipulate and output the list.
// Filename: Chemical.cpp
// Last modified on: 3/25/2013

#include "Chemical.h"
#include <string>

Chemical :: Chemical(){}

Chemical :: Chemical(string name, string id, bool isCleanAirAct, bool isPBT, bool isMetal, int metalType, 
			bool isCarcinogen, char formType, string units, string risk) // Constructor
{
	this->name = name;
	this->id = id;
	this->isCleanAirAct = isCleanAirAct;
	this->isPBT = isPBT;
	this->isMetal = isMetal;
	this->metalType = metalType;
	this->isCarcinogen = isCarcinogen;
	this->formType = formType;
	this->units = units;
	this->risk = risk;
}

string Chemical::toString()
{
	string result;
	result = "Name: " + name + "\nCAS Number: " + id + "\nClean Air Act Regulated: ";
	if (isCleanAirAct)
		result += "Yes";
	else 
		result += "No";
	result += "\nClassification: ";
	if (isPBT)
		result += "PBT";
	else
		result += "Non-PBT";
	result += "\nMetal?: ";
	if (isMetal)
		result += "Yes \nMetal Type: " + metalType;
	else
		result += "No";
	result += "\nCarcinogen?: ";
	if (isCarcinogen)
		result += "Yes";
	else
		result += "No";
	result += "\nForm: ";
	string temp(1, formType);
	result += temp + "\nUnits: " + units + "\nRisk: " + risk;
}
void Chemical::setName(string name)
{
	this->name = name;
}
void Chemical::setID(string id)
{
	this->id = id;
}
void Chemical::setUnits(string units)
{
	this->units = units;
}
void Chemical::setRisk(string risk)
{
	this->risk = risk;
}
void Chemical::setIsCleanAirAct(bool isCleanAirAct)
{
	this->isCleanAirAct = isCleanAirAct;
}
void Chemical::setIsPBT(bool isPBT)
{
	this->isPBT = isPBT;
}
void Chemical::setIsMetal(bool isMetal)
{
	this->isMetal = isMetal;
}
void Chemical::setIsCarcinogen(bool isCarcinogen)
{
	this->isCarcinogen = isCarcinogen;
}
void Chemical::setMetalType(int metalType)
{
	this->metalType = metalType;
}
void Chemical::setFormType(char formType)
{
	this->formType = formType;
}
string Chemical::getID()
{
	return id;
}

