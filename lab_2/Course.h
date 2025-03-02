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
public:
	Course();
	Course(int id);
	Course(int id, const std::string& name);
	Course(int id, const std::string& name, const std::string& instructor);
	~Course();
	void addStudent(Student* student);
	void removeStudent(Student* student);
	std::vector<Student*> getStudents() const { return students; }
	void showAllStudents();
};

#endif 

