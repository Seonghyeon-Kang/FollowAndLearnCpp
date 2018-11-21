#include <iostream>
using namespace std;

class Cents{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    // 단항 연산자 오버로딩 1
    Cents operator - () const{
        return Cents(-m_cents);
    }

    // 단항 연산자 오버로딩 2
    bool operator ! () const{
        return (m_cents == 0)? true : false;
    }

    // 파일 출력과 콘솔 출력을 담당
    friend std::ostream& operator << (std::ostream &out, const Cents &cents1){
        out << "(" << cents1.m_cents << ")" ;
        return out; // chaining
    }
};

int main(){
    Cents cents1(0);
    Cents cents2(8);

    cout << -cents1 << " " << -cents2 << endl;
    cout << !cents1 << " " << !cents2 << endl;

    return 0;
}

// 주의사항
// 연산자 오버로딩이 안되는 연산자 ?: :: sizeof . .*
// 연산자의 우선순위는 바꿀 수 없음
// ^ 오버로딩 안하는 것을 추천
// 맴버함수로만 가능한 연산자 오버로딩 =, [], (), -> 
