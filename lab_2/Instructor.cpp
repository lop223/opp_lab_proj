#include "Instructor.h"

Instructor::Instructor()
	: Instructor(0, "None") { }

Instructor::Instructor(int id)
	: Instructor(id, "None") {
}

Instructor::Instructor(int id, const std::string& name) 
	: id{id}, name{name} { }

void Instructor::assignCourse(Course* course) {
    auto it = std::find(courses.begin(), courses.end(), course);
    if (it == courses.end()) {
        courses.push_back(course);
    }
    else {
        std::cout << "This course is already assigned!" << std::endl;
    }
}