#include "Student.h"

int Student::studentCount = 0;

Student::Student()
	: Student("None", "None", 0) { }

Student::Student(const std::string& firstName, const std::string& lastName)
    : Student(firstName, lastName, 0) { }

Student::Student(const std::string& firstName, const std::string& lastName, int age) :
	id{studentCount}, firstName{firstName}, lastName{lastName}, age{age} {
    ++studentCount;
}

Student::Student(const Student& other)
    : id{ other.id }, firstName{ other.firstName }, lastName{ other.lastName }, age{ other.age } {
    for (auto course : other.courses) {
        courses.push_back(course);
    }
    ++studentCount;
}

Student::Student(Student&& other) 
    : id{ other.id }, firstName{ std::move(other.firstName) }, lastName{ std::move(other.lastName) }, age{ other.age } {
    courses = std::move(other.courses);
    other.id = 0;
    other.age = 0;
    other.courses.clear();
    ++studentCount;
}

Student::~Student() {
    --studentCount;
}

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

int Student::getStudentCount() {
    return studentCount;
}

Student& Student::setAge(int age) {
    if (17 < age < 50) {
        this->age = age;
    }
    return *this;
}
Student& Student::setName(const std::string& firstName, const std::string& lastName) {
    this->firstName = firstName;
    this->lastName = lastName;
    return *this;
}