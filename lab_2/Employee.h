#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"Person.h"

class Employee : public Person
{
private:
	static int employeeCount;
protected:
	std::string position;
	int salary;
public:
	Employee();
	Employee(const std::string& firstName, const std::string& lastName, int age);
	Employee(const std::string& firstName, const std::string& lastName, int age, std::string position, int salary);
	Employee(const Employee& other);
	Employee(Employee&& other);
	~Employee();
};

#endif

