#include <iostream>
#include <string>

using namespace std;

//1. 활용
// int getRandom(int x){}
// double getRandom(double x){}
void getRandom(int &x){}
void getRandom(double &x){}

//2. 에러 유형
// typedef int my_int;  // 동일한 타입으로 인식하기 때문에
// void print(int x) {} // 실행되지 않음
// void print(my_int x) {}

//3. 모호성
void print(const char *value) {}
void print(int) {}
void print(unsigned int value) {}
void print(float value) {}

int main(){
    int x;
    getRandom(x); // 좋은 표현은 아닌 듯
    // int x = getRandom() // 선호하는 표현

    // 컴파일러가 가장 유사한 함수에 맞추어 주지만 모호한 경우
    print('a');
    print(0);
    print(3.14159);
}