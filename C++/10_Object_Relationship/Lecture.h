#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
    std::string m_name;

    Teacher *teacher;
    std::vector<Student*> students;

public:
    Lecture(const std::string & name_in)
        : m_name(name_in)
    {}

    ~Lecture()
    {
        // Do not delete Teacher
        // Do not delete Student
    }

    void assignTeacher(Teacher * const teacher_input)
    {
        teacher = teacher_input;
    }

    void resisterStudent(Student * const student_input)
    {
        students.push_back(student_input);
    }

    void study()
    {
        std::cout << m_name << " Study " << std::endl << std::endl;

        for (auto element : students)
            element->setIntel(element->getIntel() + 1);
        // for (auto element : students)
        //     (*element).setIntel((*element).getIntel() + 1);
    }

    friend std::ostream & operator << (std::ostream & out, const Lecture & lecture)
    {
        out << "Lecture Name: " << lecture.m_name << std::endl;

        out << lecture.teacher << std::endl;
        for (auto e : lecture.students)
            out << *e << std::endl;

        return out;
    }
};