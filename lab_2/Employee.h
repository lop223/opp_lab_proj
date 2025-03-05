#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include"Person.h"

class Employee : protected Person
{
protected:
	std::string position;
	int salary;
	static int employeeCount;
public:
	Employee();
	Employee(const std::string& firstName, const std::string& lastName, int age);
	Employee(const std::string& firstName, const std::string& lastName, int age, std::string position, int salary);
	Employee(const Employee& other);
	Employee(Employee&& other);
	~Employee();
	void setSalary(int amount);
	virtual void printInfo_() const;
};

#endif

