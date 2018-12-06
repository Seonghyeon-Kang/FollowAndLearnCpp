#include "Student.h"
#include "Teacher.h"

int main(){
    Student std("Jack Jack");
    Teacher teacher("Dr. H");

    std::cout << std.getName() << std::endl;
    std::cout << teacher.getName() << std::endl;

    std.setName("Shyeon");
    teacher.setName("Dr. K");    

    std::cout << std.getName() << std::endl;
    std::cout << teacher.getName() << std::endl;

    std.doNothing();
    teacher.doNothing();

    return 0;
}