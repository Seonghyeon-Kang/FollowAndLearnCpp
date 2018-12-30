/*
Dynamic Case : 함수의 매개변수 등으로 부모를 자식형으로 혹은 자식을 부모형으로 
               변환하는 것을 의미
*/


#include <iostream>
#include <string>

using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print(){
        cout << "I'm Base" << endl;
    }
};

class Derived1 : public Base
{
public:
    int m_j = 1024;

    virtual void print() override {
        cout << "I'm derived1" << endl;
    }
};

class Derived2 : public Base
{
public:
    string m_name = "Dr.Two";

    virtual void print() override {
        cout << "I'm derived2" << endl;
    }
};

int main()
{
    // 1.일반
    Derived1 d1;
    d1.m_j = 2048;
    Base *base = &d1; // 함수의 매개변수로 형변환되어 들어온 경우를 가정

    auto base_to_d1 = dynamic_cast<Derived1*>(base); // 동적 형변환
    cout << base_to_d1->m_j << endl;                  // 가급적 안쓰는 것이 좋지만 가능은 함

    base_to_d1->m_j = 256;
    cout << d1.m_j << endl;

    // 2.다른 자식으로 변환하는 경우
    auto base_to_d2 = dynamic_cast<Derived2*>(base);

    if(base_to_d2 != nullptr)   cout << base_to_d2->m_name << endl;
    else                        cout << "Failed" << endl; // 형 변환에 실패하는 경우 null을 반환

    // 3. static_case는 가능한 모든 방법을 동원(error 체크가 어려우므로 비추천)
    auto comvertWithStaticCase = static_cast<Derived2*>(base);

    if(comvertWithStaticCase != nullptr)
        comvertWithStaticCase->print();
    else
        cout << "Failed" << endl;

    return 0;
}
