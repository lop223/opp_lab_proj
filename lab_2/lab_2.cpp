#include <iostream>
#include<vector>
#include"Person.h"
#include"Student.h"
#include"Instructor.h"
#include"Course.h"

int main()
{
    std::vector<Instructor*> instructors;
    instructors.push_back(new Instructor("Sarra","Bush", 30, 10000));
    instructors.push_back(new Instructor("Tom", "Smith", 29, 10000));
    instructors.push_back(new Instructor("Ben", "Stark", 31, 10000));
    instructors.push_back(new Instructor("Andrew", "Black", 30, 10000));
	std::vector<Student*> students;
    students.push_back(new Student("Maksum", "Dolhiy", 17, 121));
    students.push_back(new Student("Anna", "Petrova", 18, 123));
    students.push_back(new Student("Igor", "Shevchenko", 19, 141));
    students.push_back(new Student("Olga", "Kovalenko", 20, 141));
    students.push_back(new Student("Dmitriy", "Ivanov", 21, 123));
    students.push_back(new Student("Svetlana", "Zhuk", 22, 141));
    students.push_back(new Student("Alexey", "Semenov", 23, 152));
    students.push_back(new Student("Yulia", "Timoshenko", 24, 141));
    students.push_back(new Student("Vladimir", "Pushkin", 25, 152));
    students.push_back(new Student("Ekaterina", "Baranova", 26, 152));
    std::vector<Course*> courses;
    courses.push_back(new Course("Math", "Mr. Bush"));
    courses.push_back(new Course("Physics", "Mr. Smith"));
    courses.push_back(new Course("Chemistry", "Mr. Stark"));
    courses.push_back(new Course("Biology", "Mr. Black"));
    courses.push_back(new Course("Computer Science", "Mr. Bush"));
    courses.push_back(new Course("History", "Mr. Smith"));
    courses.push_back(new Course("Literature", "Mr. Stark"));
    courses.push_back(new Course("Art", "Mr. Black"));

    for (Student* student : students) {
        student->printInfo();
    }

    courses[0]->addStudent(students[0]);
    courses[0]->addStudent(students[3]);
    courses[0]->addStudent(students[5]);
    courses[0]->addStudent(students[7]);
    courses[0]->addStudent(students[9]);

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
