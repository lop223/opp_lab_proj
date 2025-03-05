#ifndef STAFF_H
#define STAFF_H

#include<iostream>
#include"Employee.h"

class Staff: public Employee
{
private:
	int floor;
public:
	Staff();
	Staff(const std::string firstName, const std::string lastName);
	Staff(const std::string firstName, const std::string lastName, int age, int salary);
	Staff(const std::string firstName, const std::string lastName, int age, int salary, int floor);
	~Staff();
	void setFloor(int floor);
	int getFloor() const { return floor; }
	void printInfo_() const override;
};

#endif

