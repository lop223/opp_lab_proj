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

	static int studentCount;
public:
	Student();
	Student(const std::string& firstName, const std::string& lastName);
	Student(const std::string& firstName, const std::string& lastName, int age);
	Student(const Student& other);
	Student(Student&& other);
	~Student();
	void registerCourse(Course* course);
	void withdrawCourse(Course* course);
	std::vector<Course*> getCourses() const { return courses; };
	void printInfo() const;
	std::string getName() const;
	int getId() const { return id; }
	static int getStudentCount();
	Student& setAge(int newAge);
	Student& setName(const std::string& firstName, const std::string& lastName);
};

#endif

