#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>
#include <vector>
#include"Person.h"

class Course;

class Student: public Person
{
private:
	std::vector<Course*> courses;
	int major;

	static int studentCount;
public:
	Student();
	Student(const std::string& firstName, const std::string& lastName);
	Student(const std::string& firstName, const std::string& lastName, int age);
	Student(const std::string& firstName, const std::string& lastName, int age, int major);
	Student(const Student& other);
	Student(Student&& other);
	~Student();

	Student& operator++() {
		++Person::age;
		return *this;
	}
	Student& operator--() {
		--age;
		return *this;
	}
	Student operator+(const Student& other) const {
		return Student(firstName + " & " + other.firstName, lastName + " & " + other.lastName, age + other.age);
	}
	bool operator==(const Student& other) const {
		return firstName == other.firstName && lastName == other.lastName && age == other.age;
	}
	friend std::ostream& operator<<(std::ostream& os, const Student& student) {
		os << "ID: " << student.id << ", Name: " << student.firstName << " " << student.lastName << ", Age: " << student.age
			<< ", Major: " << student.major;
		return os;
	}
	Student& operator=(const Student& other) {
		if (this == &other) return *this;

		firstName = other.firstName;
		lastName = other.lastName;
		age = other.age;
		courses.clear();
		for (const auto& course : other.courses) {
			courses.push_back(course);
		}

		return *this;
	}

	void registerCourse(Course* course);
	void withdrawCourse(Course* course);
	std::vector<Course*> getCourses() const { return courses; };
	void printInfo() const override;
	std::string getName() const;
	int getId() const { return id; }
	static int getStudentCount();
	Student& setAge(int newAge);
	Student& setName(const std::string& firstName, const std::string& lastName);
};

#endif

