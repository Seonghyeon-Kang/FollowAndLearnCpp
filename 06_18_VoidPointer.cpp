#include <iostream>

using namespace std;

int main(void){

    int i = 5;
    float f = 3.0;
    char c = 'a';

    void *ptr = nullptr;

    // 모든 타입의 저장 가능
    ptr = &i;
    ptr = &c;
    ptr = &f;

    // 포인터 캐스팅
    cout << &f << " " << ptr << endl;
    cout << *static_cast<float*>(ptr) << endl;

    // 포인터 연산
    int *ptr_i = &i;

    cout << ptr_i << endl;
    cout << ptr_i + 1 << endl;

    //cout << ptr + 1 << endl; // 보이드 포인터는 연산을 할 수 없음

    return 0;
}