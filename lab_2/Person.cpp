#include "Person.h"
#include<iostream>



Person::Person(int id) 
	: Person(id, "None", "None", 0) { }

Person::Person(int id, const std::string& firstName, const std::string& lastName)
	: Person(id, firstName, lastName, 0) { }

Person::Person(int id, const std::string& firstName, const std::string& lastName, int age)
	: id{id}, firstName {firstName}, lastName{ lastName }, age{ age } {}

Person::Person(const Person& other) 
	: id{other.id}, firstName{other.firstName}, lastName{other.lastName}, age{other.age} { }

Person::Person(Person&& other)
	: id{ other.id }, firstName{ std::move(other.firstName) }, lastName{ std::move(other.lastName) }, age{ other.age } {
	other.id = 0;
	other.age = 0;
}

Person::~Person() {}

void Person::printInfo() const {
	std::cout << id << " - Person: " << firstName << " " << lastName << ", age: " << age << "." << std::endl;
}