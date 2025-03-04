#include "Employee.h"
#include<iostream>



int Employee::employeeCount = 0;

Employee::Employee()
	: Employee("None", "None", 0, "None", 0) { }

Employee::Employee(const std::string& firstName, const std::string& lastName, int age)
	: Employee(firstName, lastName, age, "None", 0) { }

Employee::Employee(const std::string& firstName, const std::string& lastName, int age, std::string position, int salary) 
	: Person{employeeCount, firstName, lastName, age}, position{position}, salary{salary} { 
	employeeCount++;
}

Employee::Employee(const Employee& other)
	: Person{ other }, position{ other.position }, salary{ other.salary } {
	employeeCount++;
}

Employee::Employee(Employee&& other)
	: Person{ other }, position{ std::move(other.firstName) }, salary{ other.salary } {
	other.salary = 0;
	employeeCount++;
}

Employee::~Employee() {
	employeeCount--;
}

void Employee::setSalary(int amount) {
	salary = amount;
}