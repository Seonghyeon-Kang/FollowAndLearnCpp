#pragma once

#include <vector>
#include "Student.h"
#include "Teacher.h"

class Lecture{
private:
    std::string m_name;

    Teacher* m_teacher;
    std::vector<Student*> m_students;

public:
    Lecture(const std::string& name_in)
      : m_name(name_in)
    {}

    ~Lecture(){}

    void assignTeacher(Teacher* teacher_in){
        m_teacher = teacher_in;
    }

    void registerStudent(Student* student_in){
        m_students.push_back(student_in);

        // &m_students[0] != &student_in // push를 할 때 복사가 이루어지므로(주소가 다름)
        // Jack Jack이 서로 공유되지 않음
    }

    void study(){
        std::cout << m_name << "Study" << std::endl;

        for (auto& e : m_students)
            e->setIntel(e->getIntel() + 1);
    }

    friend std::ostream& operator << (std::ostream& out, const Lecture& lecture){
        out << "Lecture name : " << lecture.m_name << std::endl;
        out << *(lecture.m_teacher) << std::endl;

        for (auto e : lecture.m_students)
            out << *e << std::endl;

        return out;
    }
};