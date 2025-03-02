#include "Course.h"

int Course::courseCount = 0;

Course::Course()
	: Course("None", "None") { }

Course::Course(const std::string& name)
	: Course(name, "None") { }



Course::Course(const std::string& name, const std::string& instructor) 
	: id{courseCount}, name{name}, instructor{instructor} {
    ++courseCount;
}

Course::Course(const Course& other)
    : id{ courseCount }, name{ other.name }, instructor{ other.instructor } {
    for (auto student : other.students) {
        students.push_back(student);
    }
    ++courseCount;
}

Course::Course(Course&& other) 
    : id{ courseCount }, name{ std::move(other.name) }, instructor{ std::move(other.instructor) } {
    students = std::move(other.students);
    other.id = 0;
    ++courseCount;
}

Course::~Course() {
    --courseCount;
}

void Course::addStudent(Student* student) {
    auto it = std::find(students.begin(), students.end(), student);
    if (it == students.end()) {
        students.push_back(student);
    }
    else {
        std::cout << "This studetn is already registered!" << std::endl;
    }
}

void Course::removeStudent(Student* student) {
    auto it = std::remove(students.begin(), students.end(), student);
    if (it != students.end()) {
        students.erase(it, students.end());
    }
    else {
        std::cout << "There is no student: " << student->getId() << " - " << student->getName() << std::endl;
    }
}

void Course::showAllStudents() {
    std::cout << name << ":" << std::endl;
    std::cout << "   ";
    for (Student* student : students) {
        std::cout << student->getName() << ", ";
    }
    std::cout << "." << std::endl;
}

int Course::getCourseCount() {
    return courseCount;
}
