
#pragma once
#include "Student.h"
#include <string>
using namespace std;




class Roster {
public:

	int index = -1; //keeps track of number of students

	//constructor
	Roster();

	//destructor
	~Roster();

	//array of pointers to student objects
	Student* classRosterArray[5];

	//Roster functions
	DegreeProgram Convert(string data);
	void parse(string data);
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmail();
	void remove(string studentID);
	void printbyDegreeProgram(DegreeProgram degreeProgram);
};


#pragma once
