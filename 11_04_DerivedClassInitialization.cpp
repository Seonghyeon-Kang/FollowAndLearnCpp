#include <iostream>

class A{
public:
    A(int a){
        std::cout << "A : " << a << std::endl;
    }
    ~A(){
        std::cout << "Destructor A" << std::endl;
    }
};

class B : public A{
public:
    B(int a, double b)
    : A(a){
        std::cout << "B : " << b << std::endl;
    }
    ~B(){
        std::cout << "Destructor B" << std::endl;
    }
};

class C : public B{
public:
    C(int a, double b, char c)
    : B(a, b){
        std::cout << "C : " << c << std::endl;
    }
    ~C(){
        std::cout << "Destructor C" << std::endl;
    }
};

int main(){
    C c(1024, 3.14, 'a');
    return 0;
}