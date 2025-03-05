#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include<iostream>
#include<vector>
#include"Employee.h"
#include"Course.h"

class Instructor : public Employee
{
private:
	std::vector<Course*> courses;
	
	static int instructorCount;
public:
	Instructor();
	Instructor(const std::string& firstName, const std::string& lastName);
	Instructor(const std::string& firstName, const std::string& lastName, int age, int salary);
	Instructor(const Instructor& other);
	Instructor(Instructor&& other);
	~Instructor();
	void assignCourse(Course* course);
	std::vector<Course*> getCourses() const { return courses; }
	void printInfo_() const override;

	int static getInstructorCount();
};

#endif

