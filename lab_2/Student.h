#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include <vector>
#include"Course.h"

class Course;

class Student
{
private:
	int id;
	std::string firstName;
	std::string lastName;
	int age;
	std::vector<Course*> courses;
public:
	Student();
	Student(int id);
	Student(int id, const std::string& firstName, const std::string& lastName);
	Student(int id, const std::string& firstName, const std::string& lastName, int age);
	~Student();
	void registerCourse(Course* course);
	void withdrawCourse(Course* course);
	std::vector<Course*> getCourses() const { return courses; };
	void printInfo() const;
	std::string getName() const;
	int getId() const { return id; }
};

#endif

