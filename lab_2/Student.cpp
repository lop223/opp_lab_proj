#include "Student.h"


Student::Student()
	: Student(0, "None", "None", 0) { }

Student::Student(int id)
    : Student(id, "None", "None", 0) { }

Student::Student(int id, const std::string& firstName, const std::string& lastName)
	: Student(id, firstName, lastName, 0) { }

Student::Student(int id, const std::string& firstName, const std::string& lastName, int age) :
	id{id}, firstName{firstName}, lastName{lastName}, age{age} { }

Student::Student(const Student& other)
    : id{ other.id }, firstName{ other.firstName }, lastName{ other.lastName }, age{ other.age } {
    for (auto course : other.courses) {
        courses.push_back(course);
    }
}

Student::Student(Student&& other) 
    : id{ other.id }, firstName{ std::move(other.firstName) }, lastName{ std::move(other.lastName) }, age{ other.age } {
    courses = std::move(other.courses);
    other.id = 0;
    other.age = 0;
    other.courses.clear();
}

Student::~Student() { }

void Student::printInfo() const {
	std::cout << id << " - Student: " << firstName << " " << lastName << ", age: " << age << "." << std::endl;
}

std::string Student::getName() const {
    return firstName + " " + lastName;
}

void Student::registerCourse(Course* course) {
    auto it = std::find(courses.begin(), courses.end(), course);
    if (it == courses.end()) {
        courses.push_back(course);
        course->addStudent(this);
    }
    else {
        std::cout << "Course is already registered!" << std::endl;
    }
}

void Student::withdrawCourse(Course* course) {
    auto it = std::remove(courses.begin(), courses.end(), course);
    if (it != courses.end()) {
        courses.erase(it, courses.end()); 
    }
    else {
        std::cout << "There is no such course!" << std::endl;
        course->removeStudent(this);
    }
}
