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

	Student& operator++() {
		++age;
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
		os << "ID: " << student.id << ", Name: " << student.firstName << " " << student.lastName << ", Age: " << student.age;
		return os;
	}
	Student& operator=(const Student& other) {
		if (this == &other) return *this; // захист від самоприсвоєння

		// Очищаємо поточний стан
		firstName = other.firstName;
		lastName = other.lastName;
		age = other.age;

		// Очищаємо старі курси
		courses.clear();

		// Копіюємо нові курси
		for (const auto& course : other.courses) {
			courses.push_back(course); // Пряме копіювання курсу
		}

		return *this;
	}

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

