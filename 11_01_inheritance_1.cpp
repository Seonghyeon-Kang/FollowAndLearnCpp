#include <iostream>
using namespace std;

class Mother{
private:
    int m_i;

public:
    Mother(const int& i_n)
    : m_i(i_n){
        std::cout << "Mother constructor" << std::endl;
    }

    void setValue(const int& i_in){
        m_i = i_in;
    }

    int getValue(){
        return m_i;
    }
};

class Child : public Mother{ // derived class
private:
    double m_d;

public:
    Child(const int& i_in, const double& d_in)
//    : m_i(i_in), m_d(d_in){   // 접근 범위 때문에 지원이 안됨
    : Mother(i_in), m_d(d_in){  // 부모의 생성자를 호출해서 부모의 값 초기화
    }

    void setValue(const int& i_in, const double& d_in){
        Mother::setValue(i_in);
        m_d = d_in;
    }

    void setValue(const double& d_in){
        m_d = d_in;
    }

    double getValue(){
        return m_d;
    }
};

int main(){
    Mother mother(1024);
    mother.setValue(1024);
    cout << mother.getValue() << endl;

    Child child(1024, 1024);
    child.Mother::setValue(128); // 부모의 함수를 호출하는 경우
    child.setValue(128);
    cout << child.getValue() << endl;

    return 0;
}