#include <iostream>
#include <cassert>
using namespace std;

class Fraction{
private:
    int m_numerator;
    int m_denominator;

public:
    Fraction(char) = delete;

    explicit Fraction(int num = 0, int den = 1)
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

void doSomething(Fraction frac){
    cout << frac << endl;
}

int main(){
    Fraction frac(7);

    // 모두 정상 적동함
    doSomething(frac);
    doSomething(Fraction(7));
    // doSomething(7); // explicit 키워드로 인해 실행되지 않음

    // Fraction frac_char('c'); // delete에 의해 지워졌으므로 생성자 실행 불가
    return 0;
}