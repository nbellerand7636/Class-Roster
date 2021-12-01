#pragma once
#include "Student.h"
#include "Roster.h"
#include "Degree.h"
#include <string>
#include<iostream>

using namespace std;

//Default roster constructor	
Roster::Roster() {




};

//Roster Destructor
Roster::~Roster() {
	cout << "Releasing Dynamic memory:" << endl << endl;

	//Loop through array and delete each student object created.
	for (int i = 0; i < index; i++) {
		delete classRosterArray[i];
		index--;
	}



};

//Function to convert string to enumerated data type
DegreeProgram Roster::Convert(string data) {
	if (data == "SECURITY") {
		return DegreeProgram::SECURITY;
	}
	else if (data == "SOFTWARE") {
		return DegreeProgram::SOFTWARE;
	}
	else if (data == "NETWORK") {
		return DegreeProgram::NETWORK;
	}
}

//function to parse student data array and store in variables

void Roster::parse(string data) {
	size_t rhs = data.find(",");
	string studentID = data.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string firstName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string lastName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string email = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int age = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string degreeInput = data.substr(lhs, rhs - lhs);
	DegreeProgram program = Convert(degreeInput);
	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, program); //call add method after parsing
	/*cout << firstName;*/
};

//create a new student object using parsed data
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program) {
	index++;
	classRosterArray[index] = new Student(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, program);



};

//print all students
void Roster::printAll() {
	cout << "Displaying all students:" << endl << endl;
	for (int i = 0; i < index + 1; i++) {
		classRosterArray[i]->print();
	}

	cout << endl << endl;
};
//print average day in course 
void Roster::printAverageDaysInCourse(string studentID) {
	cout << "StudentID: " << studentID << ", Average Days In Course: ";
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i]->getStudentID() == studentID) {
			int sum = 0;

			sum += classRosterArray[i]->getDaysInCourse1();
			sum += classRosterArray[i]->getDaysInCourse2();
			sum += classRosterArray[i]->getDaysInCourse3();


			int averageDays = sum / 3;
			cout << averageDays;

		}
	}
	cout << endl;
};

//print invalid emails
void Roster::printInvalidEmail() {
	cout << "Printing invalid Emails:" << endl << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getEmail().find(" ") != string::npos || //if array has a space
			classRosterArray[i]->getEmail().find("@") == string::npos || //or if it doesnt have a @ 
			classRosterArray[i]->getEmail().find(".") == string::npos) { //or a period then it is invalid.
			cout << classRosterArray[i]->getEmail() << endl;
		}
	}
	cout << endl;
};

// remove a student from array
void Roster::remove(string studentID) {
	cout << "Removing " << studentID << endl << endl;

	bool found = false;
	for (int i = 0; i < index + 1; i++) {

		if (classRosterArray[i]->getStudentID() == studentID) {
			found = true;

			for (int j = i; j < index; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}

			index--;
		}


	}
	if (!found) { cout << studentID << " was not found." << endl << endl; }
};
void Roster::printbyDegreeProgram(DegreeProgram degreeProgram) {
	cout << "Printing by Degree Program" << endl << endl;
	for (int i = 0; i < 5; i++) {
			if (classRosterArray[i]->getDegreeProgram() == DegreeProgram::SOFTWARE) {
				classRosterArray[i]->print();
			}
	}
	cout << endl;
}