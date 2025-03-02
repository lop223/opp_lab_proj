#include <iostream>
#include<vector>
#include"Student.h"
#include"Instructor.h"
#include"Course.h"

int main()
{
    std::vector<Instructor*> instructors;
    instructors.push_back(new Instructor("Mr. Bush"));
    instructors.push_back(new Instructor("Mr. Smith"));
    instructors.push_back(new Instructor("Mr. Stark"));
    instructors.push_back(new Instructor("Mr. Black"));
	std::vector<Student*> students;
    students.push_back(new Student("Maksum", "Dolhiy", 17));
    students.push_back(new Student("Anna", "Petrova", 18));
    students.push_back(new Student("Igor", "Shevchenko", 19));
    students.push_back(new Student("Olga", "Kovalenko", 20));
    students.push_back(new Student("Dmitriy", "Ivanov", 21));
    students.push_back(new Student("Svetlana", "Zhuk", 22));
    students.push_back(new Student("Alexey", "Semenov", 23));
    students.push_back(new Student("Yulia", "Timoshenko", 24));
    students.push_back(new Student("Vladimir", "Pushkin", 25));
    students.push_back(new Student("Ekaterina", "Baranova", 26));
    students[0]->setAge(32);
    students[1]->setAge(32);
    students[1]->setName("Andrew", "Paushac");
    std::vector<Course*> courses;
    courses.push_back(new Course("Math", "Mr. Bush"));
    courses.push_back(new Course("Physics", "Mr. Smith"));
    courses.push_back(new Course("Chemistry", "Mr. Stark"));
    courses.push_back(new Course("Biology", "Mr. Black"));
    courses.push_back(new Course("Computer Science", "Mr. Bush"));
    courses.push_back(new Course("History", "Mr. Smith"));
    courses.push_back(new Course("Literature", "Mr. Stark"));
    courses.push_back(new Course("Art", "Mr. Black"));

    std::cout << "Student count: " << Student::getStudentCount() << std::endl;



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
