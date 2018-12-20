#include <iostream>
using namespace std;


class A
{
private:
    /* data */
public:
    virtual void print() { cout << "A" << endl; }
};

class B : public A
{
private:
    /* data */
public:
    void print() { cout << "B" << endl; }
};

class C : public B
{
private:
    /* data */
public:
    void print() { cout << "C" << endl; }
};

class D : public C
{
private:
    /* data */
public:
    void print() { cout << "D" << endl; }
};

int main()
{
    A a;
    B b;
    C c;
    D d;

    A& ref = b;
    ref.print();

    A& ref2 = c;  // 클래스 A에만 virtual이 있지만 전부 적용됨
    ref2.print(); // 하지만 최상위 클래스 외 모든 상속받는 클래스에 기입하는 것이 일반적임

    B& ref3 = c;  // 속도에 영향이 있으므로 for문 안쪽과 같이
    ref3.print(); // 빈번하게 쓰이는 함수에는 virtual을 피할 필요

    return 0;
}