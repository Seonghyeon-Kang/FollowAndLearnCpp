#include <iostream>
using namespace std;

class Base{
protected:
    int m_i;

public:
    Base(int v_in = 0){
        m_i = v_in;
    }

    void print(){
        cout << "I'm base" << endl;
    }

    friend std::ostream& operator << (std::ostream& out, const Base& b){
        out << "This is base output" << endl;
        return out;
    }
};

class Derived : public Base{
private:
    double m_d;

public:
    Derived(int value)
    : Base(value){}

    void print(){
        Base::print();
        cout << "I'm derived" << endl;
        // print() // 무한반복 주의 
    }

    friend std::ostream& operator << (std::ostream& out, const Derived& b){
        out << static_cast<Base>(b); // Base class에 선언된 프렌드 함수를 호출
        out << "This is derived output" << endl;
        return out;
    }
};

int main(){
    Base base(5);
    base.print();
    cout << base;

    Derived derived(7);
    derived.print();
    cout << derived;

    return 0;
}