#include <iostream>

class Base
{
public:
    Base() {}

    friend std::ostream& operator << (std::ostream& out, const Base& b){
        return b.print(out);
    } // 맴버가 아니므로 직접 overriding을 할 수 없음

    virtual std::ostream& print(std::ostream& out) const{
        out << "Base";
        return out;
    } // Print를 위임할 수 있는 맴버함수를 생성하여 이 맴버함수를 overriding함
};

class Derived : public Base
{
public:
    Derived() {}

    virtual std::ostream& print(std::ostream& out) const override{
        out << "Derived";
        return out;
    }
};

int main()
{
    Base b;
    std::cout << b << '\n';

    Derived d;
    std::cout << d << '\n';

    Base& bref = d;
    std::cout << bref << '\n';

    return 0;
}