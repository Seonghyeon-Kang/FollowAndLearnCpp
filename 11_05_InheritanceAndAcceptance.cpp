#include <iostream>

class Base{
public:
    int m_public;
protected:
    int m_protected;
private:
    int m_private;
};

class Derived : public Base{
public:
    Derived(){
        m_public = 123;
        m_protected = 123;  // 자식에서만 사용가능
        // m_private = 123; // 자식에서도 불가
    }
};

class Derived2 : private Base{
public:
    Derived2(){
        Base::m_public = 123; // this->m_public; m_public 동일
        Base::m_protected = 123;  // 자식에서만 사용가능
        // Base::m_private = 123; // 자식에서도 불가
    }
};

class GrandChild : public Derived2{
public:
    GrandChild(){
        //Derived2::m_public == 123; // public과 Private가 만나 더 엄격한 쪽으로 동작함
    }
};

int main(){
    Base base;
    base.m_public = 123; // public만 접근이 됨

    Derived derived;
    derived.m_public = 123;

    Derived2 derived2;
    //derived2.m_public = 123;

    return 0;
}