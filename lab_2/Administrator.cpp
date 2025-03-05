#include "Administrator.h"
#include<iostream>



Administrator::Administrator()
	: Administrator("None", "None", 0, 0) { }

Administrator::Administrator(const std::string& firstName, const std::string& lastName) 
	: Administrator(firstName, lastName, age, salary) { }

Administrator::Administrator(const std::string& firstName, const std::string& lastName, int age, int salary) 
	: Employee{firstName, lastName, age, "administrator", salary} { }

void Administrator::setEmployeeSalary(Employee* employee, int amount) {
	if (employee != this) {
		employee->setSalary(amount);
	}
}

void Administrator::printInfo_() const {
	std::cout << id << " - Employee: " << firstName << " " << lastName << ", age: " << age << ", position: " 
		<< position << ", salary: " << salary << "." << std::endl;
}