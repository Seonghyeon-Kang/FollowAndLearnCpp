#include <iostream>
using namespace std;

class A; //forward declaration //B가 있음을 미리 알림
         // Class A 선언 시 B의 존재를 미리 알려주는 용도

class B{
private:
    int m_value = 2;

public:
    void doSomething(A& a);
};

class A{
private:
    int m_value = 1;

    //freind B; 클래스의 모든 맴버의 접근을 허용
    friend void B::doSomething(A& a); // 특정 맴버만 접근을 허용
};

void B::doSomething(A& a){
    cout << a.m_value << endl;  // private 변수를 일반적인 상황에서 접근할 수 없으나
                                // friend 키워드로 접근이 가능함
}

int main(){
    A a;
    B b;
    b.doSomething(a);

    return 0;
}
