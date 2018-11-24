#include <iostream>
using namespace std;

class Cents{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    void setCents(int cents) { m_cents = cents; }

    operator int(){
        cout << "cast here" << endl;
        return m_cents;
    }
};

class Dollar{
private:
    int m_dollars = 0;

public:
    Dollar(const int& input) : m_dollars(input) {}
    operator Cents(){ return Cents(m_dollars * 100); }
};

void printInt(const int &value){
    cout << value << endl;
}

int main(){
    Cents cents(7);

    // 형 변환 방법
    int value = (int)cents;         // 1
    value = int(cents);             // 2
    value = static_cast<int>(cents);// 3
    printInt(cents);                // 4번의 형 변환 

    // 사용자 정의 클래스로 형 변환
    Dollar dol(2);
    Cents cents2 = dol;              // 변환
    printInt(cents2);
    return 0;
}
