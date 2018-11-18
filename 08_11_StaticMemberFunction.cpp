#include <iostream>

using namespace std;

class Something{
public:
    class _init{
    public:
        _init(){
            s_value = 9789;
        }
    };

private:
    //static int s_value = 1; //생성과 함께 초기화 불가
    static int s_value;
    int m_value;

    static _init s_initializer;

public:
    // Something() : m_value(123), s_value(9789){   // 정적 변수는 생성자에서 초기화가 불가하므로
    // }                                            // 내부클래스를 통한 우회적인 방법이 필요함

    static int getValue(){
        //return this->s_value; //static에서는 this로 접근해야하는 모든 맴버에 접근이 되지 않음
        //return m_value;
        return s_value;
    }

    int temp(){
        return this->s_value + this->s_value;
    }
};

int Something::s_value = 1;
Something::_init Something::s_initializer; // 내부 생성자를 실행하게 하여 정적변수를 초기화하게 하는 방법

int main(){
    cout << Something::getValue() << endl;

    Something st1;
    cout << st1.getValue() << endl;

    int (Something::*fptr1)() = &Something::temp;   // 일반 맴버함수는 클래스를 지정해야 함
    cout << (st1.*fptr1)() << endl;                 // 인스터스를 지정해야만 실행이 가능

    int (*fptr2)() = &Something::getValue;          // 정적 맴버함수는 클래스를 지정하지 않음
    cout << fptr2() << endl;                        // 인스터스를 지정하지 않아야 실행 가능

    return 0;    
}
