#pragma once
#include <iostream>
#include <string>
#include "Student.h"
#include "Roster.h"
#include"Degree.h"

using namespace std;




int main() {
	cout << "C867-Scripting & Programming; Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 002410908" << endl;
	cout << "Naim Bellerand" << endl;

	//Store strings in student data array
	const string studentData[] =

	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Naim,Bellerand,naim.bellerand@gmail.com,27,20,50,20,SOFTWARE" };

	//Create an instance of the roster class
	Roster classroster;


	//loop through student data array and create an object for each element	

	for (int i = 0; i < 5; i++) {
		classroster.parse(studentData[i]);
	}


	//print all students

	classroster.printAll();

	//Print invalid Emails
	classroster.printInvalidEmail();

	//Print average days in course for each student
	for (int i = 0; i < 5; i++) {
		string id = classroster.classRosterArray[i]->getStudentID();
		classroster.printAverageDaysInCourse(id);
	}
	
	cout << endl;
	
	//Print students in the Software Degree Program
	classroster.printbyDegreeProgram(DegreeProgram::SOFTWARE);

	//Remove student and print all students then try to remove again
	
	classroster.remove("A3");
	classroster.printAll();
	classroster.remove("A3");


	return 0;
}
