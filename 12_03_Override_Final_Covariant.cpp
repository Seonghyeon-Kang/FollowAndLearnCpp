/* Keywords
- final : 자식 클래스에서 특정함수의 override를 명시적으로 막음
- override : 자식 클래스에서 특정함수가 override한 것임을 명시함
- 공명반환값 : 부모의 인스턴스에 자식의 포인터가 매핑되어 있는 경우 부모의 인스턴스가 포인터 혹은 레퍼런스인 경우
              override된 자식의 함수를 호출하지만 반환값은 부모의 포인터로 변환된 반환값
*/


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
    ref.getThis()->print(); //b가 실행을 하지만 this에서 b가 아닌 a로 변환되어 반환됨

    cout << typeid(b.getThis()).name() << endl;
    cout << typeid(ref.getThis()).name() << endl;

    return 0;
}