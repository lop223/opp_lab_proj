#include "Staff.h"
#include<iostream>



Staff::Staff() 
	: Staff("None", "None", 0, 0, 0) { }

Staff::Staff(const std::string firstName, const std::string lastName) 
	: Staff(firstName, lastName, 0, 0, 0) { }

Staff::Staff(const std::string firstName, const std::string lastName, int age, int salary) 
	: Staff(firstName, lastName, age, salary, 0) { }

Staff::Staff(const std::string firstName, const std::string lastName, int age, int salary, int floor)
	: Employee{firstName, lastName, age, "staff", salary}, floor(floor) { }

Staff::~Staff() { }

void Staff::setFloor(int floor) {
	if (floor > 0) { this->floor = floor; }
}

void Staff::printInfo_() const {
	std::cout << id << " - Employee: " << firstName << " " << lastName << ", age: " << age << ", position: "
		<< position << ", salary: " << salary << ", floor" << floor << "." << std::endl;
}