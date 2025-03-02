#ifndef COURSE_H
#define COURSE_H

#include<iostream>
#include<vector>
#include"Student.h"

class Student;

class Course
{
private:
	int id;
	std::string name;
	std::string instructor;
	std::vector<Student*> students;

	static int courseCount;
public:
	Course();
	Course(const std::string& name);
	Course(const std::string& name, const std::string& instructor);
	Course(const Course& other);
	Course(Course&& other);
	~Course();
	void addStudent(Student* student);
	void removeStudent(Student* student);
	std::vector<Student*> getStudents() const { return students; }
	void showAllStudents();
	static int getCourseCount();
};

#endif 

