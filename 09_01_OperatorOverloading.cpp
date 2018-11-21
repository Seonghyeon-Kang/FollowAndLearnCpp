#include <iostream>
using namespace std;

class Cents{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    // 연산자 오버로딩
    friend Cents operator + (const Cents &c1, const Cents &c2){
        return Cents(c1.getCents() + c2.getCents());
    }

    // 맴버함수를 통한 연산자 오버로딩
    Cents operator + (const Cents &c2){
        return Cents(this->m_cents + c2.m_cents);
    }
};

// 인수를 통한 리턴
void add(const Cents &c1, const Cents &c2, Cents &c_out){
    c_out.getCents() = c1.getCents() + c2.getCents();
}

// 리턴형을 선언하여 반환
Cents add(const Cents &c1, const Cents &c2){
    return c1.getCents() + c2.getCents();
}

int main(){
    Cents cents1(6);
    Cents cents2(8);

    Cents sum;
    add(cents1, cents2, sum);
    cout << sum.getCents() << endl;

    cout << add(cents1, cents2).getCents() << endl;

    cout << (cents1 + cents2 + Cents(6)).getCents() << endl;

    return 0;
}

// 주의사항
// 연산자 오버로딩이 안되는 연산자 ?: :: sizeof . .*
// 연산자의 우선순위는 바꿀 수 없음
// ^ 오버로딩 안하는 것을 추천
// 맴버함수로만 가능한 연산자 오버로딩 =, [], (), -> 
