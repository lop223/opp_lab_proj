#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include<iostream>
#include<vector>
#include"Course.h"

class Course;

class Instructor
{
private:
	int id;
	std::string name;
	std::vector<Course*> courses;
	
	static int instructorCount;
public:
	Instructor();
	Instructor(const std::string& name);
	Instructor(const Instructor& other);
	Instructor(Instructor&& other);
	~Instructor();
	void assignCourse(Course* course);
	std::vector<Course*> getCourses() const { return courses; }

	int static getInstructorCount();
};

#endif

