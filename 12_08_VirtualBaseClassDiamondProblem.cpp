/*
(A)    (A)          (A)  
 ↑      ↑            ↑   
(B1)---(B2)  ▶  (B1)---(B2)
     ↑               ↑
    (C)             (C)
*/

#include <iostream>
using namespace std;

class PoweredDevice{
    public:
    int m_i;

    PoweredDevice(int power){
        cout << "PowerDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice{ // PoweredDevice(부모)를 하나만 생성
    public:
    Scanner(int scanner, int power)
        : PoweredDevice(power){
        cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice{ // PoweredDevice(부모)를 하나만 생성
    public:
    Printer(int printer, int power)
        : PoweredDevice(power){
        cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer{
    public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
          PoweredDevice(power){ // virtual keyword 사용 시 추가해야 함       
    }
};

int main(){
    Copier cop(1, 10, 100); // 생성자 호출

    cout << &cop.Scanner::PoweredDevice::m_i << endl; // virtual이 없는 경우 Powered가 두 번 호출 됨(주소 상이함)
    cout << &cop.Printer::PoweredDevice::m_i << endl; // virtual이 있는 경우 Powered가 한 번 호출 됨(주소 동일함)

    return 0;
}