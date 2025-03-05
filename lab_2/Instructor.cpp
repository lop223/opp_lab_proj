#include "Instructor.h"

int Instructor::instructorCount = 0;

Instructor::Instructor()
	: Instructor("None", "None", 0, 0) { }

Instructor::Instructor(const std::string& firstName, const std::string& lastName)
    : Instructor(firstName, lastName, 0, 0) { }

Instructor::Instructor(const std::string& firstName, const std::string& lastName, int age, int salary)
    : Employee{ firstName, lastName, age, "instructor", salary} {
    ++instructorCount;
}

Instructor::Instructor(const Instructor& other)
    : Employee{ other } {
    for (auto student : other.courses) {
        courses.push_back(student);
    }
    ++instructorCount;
}

Instructor::Instructor(Instructor&& other) 
    : Employee{ other } {
    courses = std::move(other.courses);
    ++instructorCount;
}

Instructor::~Instructor() {
    --instructorCount;
}

void Instructor::assignCourse(Course* course) {
    auto it = std::find(courses.begin(), courses.end(), course);
    if (it == courses.end()) {
        courses.push_back(course);
    }
    else {
        std::cout << "This course is already assigned!" << std::endl;
    }
}

int Instructor::getInstructorCount() {
    return instructorCount;
}

void Instructor::printInfo_() const {
    std::cout << id << " - Employee: " << firstName << " " << lastName << ", age: " << age << ", position: "
        << position << ", salary: " << salary << "." << std::endl;
}