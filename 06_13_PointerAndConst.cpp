#include <iostream>

using namespace std;

int main(void){

    int val = 5;
    const int *pointer = &val // 주소 내 값을 바꿀 수 없지만 주소는 변경 가능

    int value = 5;
    int *const ptr = &value;

    *ptr = 10;
    cout << *ptr << endl;

    int value2 = 8;
    ptr = &value2; // 컴파일 에러: 주소값이 Const이므로 주소를 바꿀 수 없음

    int value2 = 10;
    const int *const ptr2 = &value2; // 주소도 못 바꾸고 주소의 값도 못 바꿈

    return 0;
}