#include <iostream>

using namespace std;

void doSomething(const int& x){
    cout << x << endl;
}

int main(){
    const int &ref_x = 3+4; //const에서만 리터럴 대입이 가능함

    cout << ref_x << endl;
    cout << &ref_x << endl;

    int a = 1;

    doSomething(a);
    doSomething(1);   // Const 참조이기 때문에 가능
    doSomething(a+3);
    doSomething(3*4);

    return 0;
}