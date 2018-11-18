#include <iostream>

using namespace std;

class A{
public:

    A(){
        cout << "Constractor" << endl;        
    }
    ~A(){
        cout << "Destractor" << endl;        
    }

    void print(){
        cout << "Hello Cpp" << endl;
    }
};

class Cents{
    private:
    int m_cents;

    public:
    Cents(int cents) { m_cents = cents; }
    int getCents() const { return m_cents; }
};

Cents add(const Cents &c1, const Cents &c2){
    return Cents(c1.getCents() + c2.getCents());
}

int main()
{
    A a;
    a.print();

    A().print(); //Anonymous

    cout << add(Cents(6), Cents(8)).getCents() << endl;
    cout << int(6) + int(8) << endl;

    return 0;
}