#include <iostream>
using namespace std;


class A
{
public:
    // 자식 클래스에서 print 함수의 override 을 막을 때 사용
    void print() /*final*/ { cout << "A" << endl; }
    
    virtual A* getThis() {
        cout << "A::getThis()" << endl;
        return this;
    }

};

class B : public A
{
public:
    // 부모 클래스에서 해당 함수를 override 함을 명시적으로 알림 (컴파일 에러 방지)
    void print() /*override*/ { cout << "B" << endl; }

    virtual B* getThis() {
        cout << "B::getThis()" << endl;
        return this;
    } // 리턴값이 달라도 상속관계이기 때문에 virtual이 동작함 (공명 반환값)
};

int main()
{
    A a;
    B b;

    A& ref = b;
    b.getThis()->print();
    ref.getThis()->print();

    cout << typeid(b.getThis()).name() << endl;
    cout << typeid(ref.getThis()).name() << endl;

    return 0;
}