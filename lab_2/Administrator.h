#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include<iostream>
#include"Employee.h"

class Administrator : public Employee
{
public:
	Administrator();
	Administrator(const std::string& firstName, const std::string& lastName);
	Administrator(const std::string& firstName, const std::string& lastName, int age, int salary);
	~Administrator();
	void setEmployeeSalary(Employee* employee, int amount);
	void printInfo_() const override;
};

#endif

