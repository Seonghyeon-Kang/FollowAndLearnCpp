#include <iostream>
#include <vector>
#include <string>
#include "Lecture.h"

int main(){
    using namespace std;

    Student* pStd1 = new Student("Jack Jack", 0);
    Student* pStd2 = new Student("Dash", 1);
    Student* pStd3 = new Student("Violet", 2);

    Teacher* pTeacher1 = new Teacher("Prof. Hong");
    Teacher* pTeacher2 = new Teacher("Prof. Good");    
    
    // Composition Relationship
    Lecture lec1("Introduction to Computer Programming");
    lec1.assignTeacher(pTeacher1); // 포인터를 사용하여 Aggregation Relationship으로 변경
    lec1.registerStudent(pStd1); 
    lec1.registerStudent(pStd2);
    lec1.registerStudent(pStd3);

    Lecture lec2("Computational Thinking");
    lec2.assignTeacher(pTeacher2);
    lec2.registerStudent(pStd1);

    //test
    {
        cout << lec1 << endl;
        cout << lec2 << endl;

        lec2.study(); // Composition Relationship 에서는 공부를 했음에도 Jack Jack의 인텔리전스가 서로 다름

        cout << lec1 << endl;
        cout << lec2 << endl;
    }

    return 0;
}