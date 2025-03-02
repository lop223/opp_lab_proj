#include <iostream>
#include<vector>
#include"Student.h"
#include"Instructor.h"
#include"Course.h"

int main()
{
    std::vector<Instructor*> instructors;
    instructors.push_back(new Instructor(0, "Mr. Bush"));
    instructors.push_back(new Instructor(1, "Mr. Smith"));
    instructors.push_back(new Instructor(2, "Mr. Stark"));
    instructors.push_back(new Instructor(3, "Mr. Black"));
	std::vector<Student*> students;
    students.push_back(new Student(0, "Maksum", "Dolhiy", 17));
    students.push_back(new Student(1, "Anna", "Petrova", 18));
    students.push_back(new Student(2, "Igor", "Shevchenko", 19));
    students.push_back(new Student(3, "Olga", "Kovalenko", 20));
    students.push_back(new Student(4, "Dmitriy", "Ivanov", 21));
    students.push_back(new Student(5, "Svetlana", "Zhuk", 22));
    students.push_back(new Student(6, "Alexey", "Semenov", 23));
    students.push_back(new Student(7, "Yulia", "Timoshenko", 24));
    students.push_back(new Student(8, "Vladimir", "Pushkin", 25));
    students.push_back(new Student(9, "Ekaterina", "Baranova", 26));
    std::vector<Course*> courses;
    courses.push_back(new Course(0, "Math", "Mr. Bush"));
    courses.push_back(new Course(1, "Physics", "Mr. Smith"));
    courses.push_back(new Course(2, "Chemistry", "Mr. Stark"));
    courses.push_back(new Course(3, "Biology", "Mr. Black"));
    courses.push_back(new Course(4, "Computer Science", "Mr. Bush"));
    courses.push_back(new Course(5, "History", "Mr. Smith"));
    courses.push_back(new Course(6, "Literature", "Mr. Stark"));
    courses.push_back(new Course(7, "Art", "Mr. Black"));

    courses[0]->addStudent(students[0]);
    courses[0]->addStudent(students[3]);
    courses[0]->addStudent(students[5]);
    courses[0]->addStudent(students[7]);
    courses[0]->addStudent(students[9]);

    for (Student* student : students) {
        student->printInfo();
    }
    std::cout << std::endl;

    courses[0]->showAllStudents();


    for (Student* student : students) {
        delete student;
    }
    for (Course* course : courses) {
        delete course;
    }
    for (Instructor* instructor : instructors) {
        delete instructor;
    }
}
