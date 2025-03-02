#include "Instructor.h"

int Instructor::instructorCount = 0;

Instructor::Instructor()
	: Instructor("None") { }

Instructor::Instructor(const std::string& name) 
	: id{instructorCount}, name{name} {
    ++instructorCount;
}

Instructor::Instructor(const Instructor& other)
    : id{ other.id }, name{ other.name } {
    for (auto student : other.courses) {
        courses.push_back(student);
    }
    ++instructorCount;
}

Instructor::Instructor(Instructor&& other) 
    : id{ other.id }, name{ std::move(other.name) } {
    courses = std::move(other.courses);
    other.id = 0;
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