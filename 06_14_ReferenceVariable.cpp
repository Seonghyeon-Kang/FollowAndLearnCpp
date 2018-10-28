#include <iostream>

using namespace std;

void printElements(const int (&arr)[5]){ // 함수 내부에서 실수로 바꾸지 못하게 함
    for (int i=0 ; i<5 ; ++i){
        cout << arr[i] << " ";
    }
    cout << endl;
}

struct s1{
    int v1;
};

struct s2{
    s1 v2;
};


int main(){
    // 1. 참조변수 사용법
    int value = 5;

    int &ref = value; // 선언과 동시에 정의
    cout << ref << endl;

    ref = 10;
    cout << ref << endl; // 별명처럼 동작함

    int *ptr = nullptr;
    ptr = &value;

    cout << &value << endl;
    cout << &ref << endl;
    cout << ptr << endl;  // 주소가 모두 동일함
    cout << &ptr << endl; // 포인터 주소는 다른 주소

    const int y = 8;
    //int &ref2 = y; // error: binding reference of type 'int&' to 'const int' discards qualifiers

    // 2.함수의 인자로 활용
    const int length = 5;
    int arr[length] = {1, 2, 3, 4, 5};

    printElements(arr); // 함수로 값을 Call by reference 방식으로 넘김

    // 3.구조체, 클래스의 맴버 변수의 별명으로 사용
    s2 sample;
    int &ref3 = sample.v2.v1;
    ref3 = 1;

    return 0;
}

