#include <iostream>

class Mother{
public:
    int m_i;

    Mother(const int& i_in = 0){ // 인자에 기본값을 설정하여 기본생성자 역할까지 함
        std::cout << "Mother default construction" << std::endl;
    }
};

class Child : public Mother{
public:
    double m_d;

public:
    Child()
    : Mother(2), m_d(1.0){ //Mother는 기본으로 숨어 있음
        std::cout << "Child construction" << std::endl;
    }
};

int main(){
    Child t1;

    return 0;
}