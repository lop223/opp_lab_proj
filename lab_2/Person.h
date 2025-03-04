#ifndef PERSON_H
#define PERSON_H

#include<iostream>

class Person
{
protected:
	int id;
	std::string firstName;
	std::string lastName;
	int age;
public:
	Person(int id);
	Person(int id, const std::string& firstName, const std::string& lastName);
	Person(int id, const std::string& firstName, const std::string& lastName, int age);
	Person(const Person& other);
	Person(Person&& other);
	~Person();
	virtual void printInfo() const;
};

#endif

