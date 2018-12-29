/* Keyword
가상 소멸자 : 상속 관계의 클래스에서 부모의 클래스 소멸자에 virual을 명시하면
             다형성을 활용하는 경우 자식의 클래스 소멸자도 함께 실행시킬 수 있음
*/

#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout << "~Base()" << endl;
    }
};

class Derived : public Base
{
private:
    int* m_array;

public:
    Derived(int length)
    {
            m_array = new int[length];
    }

    virtual ~Derived() override
    {
        cout << "~Derived" << endl;
        delete[] m_array;
    }
};

int main()
{
    // 일반적인 상황
    Derived derived(5);

    // 다형성을 사용하는 상황, 부모 클래스의 소멸자에 virual을 명시하면 자식 -> 부모 순으로 호출됨 
    Derived* derived2 = new Derived(5);
    Base* base = derived2;
    delete base;

    return 0;
}