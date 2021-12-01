#include <iostream>
#include <string>
#include "Student.h"
#include "Degree.h"

#pragma once
using namespace std;

//Student Constructor 

Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	this->program = program;
}

//Getters
string Student::getStudentID() { return studentID; }
string Student::getFirstName() { return firstName; }
string Student::getLastName() { return lastName; }
string Student::getEmail() { return email; }
int Student::getAge() { return age; }
int Student::getDaysInCourse1() { return daysInCourse[0]; }
int Student::getDaysInCourse2() { return daysInCourse[1]; }
int Student::getDaysInCourse3() { return daysInCourse[2]; }
DegreeProgram Student::getDegreeProgram() { return program; }

//Setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) { this->daysInCourse[0] = daysInCourse1, this->daysInCourse[1] = daysInCourse2, this->daysInCourse[2] = daysInCourse3; }
void Student::setDegreeProgram(DegreeProgram program) { this->program = program; }

//print function
void Student::print() {
	if (getDegreeProgram() == DegreeProgram::SECURITY) { cout << getStudentID() << "	" << getFirstName() << "	" << getLastName() << "		" << getEmail() << "	" << getAge() << "		{" << getDaysInCourse1() << "," << getDaysInCourse2() << "," << getDaysInCourse3() << "}	 " << "SECURITY" << endl; }
	if (getDegreeProgram() == DegreeProgram::NETWORK) { cout << getStudentID() << "	" << getFirstName() << "	" << getLastName() << "		" << getEmail() << "	" << getAge() << "		{" << getDaysInCourse1() << "," << getDaysInCourse2() << "," << getDaysInCourse3() << "}	 " << "NETWORK" << endl; }
	if (getDegreeProgram() == DegreeProgram::SOFTWARE) { cout << getStudentID() << "	" << getFirstName() << "	" << getLastName() << "		" << getEmail() << "	" << getAge() << "		{" << getDaysInCourse1() << "," << getDaysInCourse2() << "," << getDaysInCourse3() << "}	 " << "SOFTWARE" << endl; }

}


