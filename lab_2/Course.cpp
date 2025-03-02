#include "Course.h"

Course::Course()
	: Course(0, "None", "None") { }

Course::Course(int id, const std::string& name)
	: Course(id, name, "None") { }

Course::Course(int id)
    : Course(id, "None", "None") {
}

Course::Course(int id, const std::string& name, const std::string& instructor) 
	: id{id}, name{name}, instructor{instructor} { }

Course::~Course() { }

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
