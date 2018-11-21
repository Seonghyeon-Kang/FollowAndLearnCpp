#include <iostream>
using namespace std;

class Digit{
private:
    int m_digit;

public:
    Digit(int digit = 0) : m_digit(digit){}

    // prefix
    Digit & operator ++ (){
        ++m_digit;
        return *this;
    }

    // postfix : 인자에 아무 값을 넣으면 postfix로 인식
    Digit operator ++ (int){
        Digit temp(m_digit);
        ++(*this); // prefix 맴버 함수를 사용

        return temp; 
    }

    friend std::ostream & operator << (std::ostream &out, const Digit &d){
        out << d.m_digit;
        return out;
    }
};

int main(){
    
    Digit d(5);

    cout << ++d << endl;
    cout << d << endl;
    cout << d++ << endl;
    cout << d << endl;

    return 0;
}