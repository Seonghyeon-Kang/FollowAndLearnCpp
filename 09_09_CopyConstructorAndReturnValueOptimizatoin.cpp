#include <iostream>
#include <cassert>
using namespace std;

class Fraction{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(int num = 0, int den = 1)
    : m_numerator(num), m_denominator(den) {
        assert(den != 0);
    }

    Fraction(const Fraction& fraction)  // copy constructor
    : m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator) {
        cout << "Copy constructor called" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Fraction& f){
        out << f.m_numerator << "/" << f.m_denominator;
        return out;
    }

};

Fraction doSomething(){
    Fraction temp(1, 2);
    cout << &temp << endl;
    return temp;
}

int main(){
    Fraction frac(3, 5);

    // 복사 생성자가 호출되는 경우
    Fraction fr_copy(frac);
    Fraction fr_copy2(Fraction(3, 5));  // 릴리즈 모드에서 컴파일러가 자동
                                        // Fraction fr_copy2(3, 5)로 바꿈
    // Return value optimization
    Fraction result = doSomething();    // 디버그 모드에서는 주소가 다르나
    cout << &result << endl;            // 릴리즈 모드에서는 RVO에 의해 주소가 동일
    cout << result << endl;             

    return 0;
}