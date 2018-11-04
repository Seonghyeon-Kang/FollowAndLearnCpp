#include <iostream>
using namespace std;

void countDown(int count){
    cout << count << endl;
    if(count > 0)   countDown(count - 1); // 재귀호출은 종료 조건이 없으면
                                          // 무한루프에 빠지므로 주의 필요
}

int sumTo(int sumto){
    if (sumto <= 0)
        return 0;
    else if (sumto <= 1)
        return 1;
    else 
        return sumTo(sumto - 1) + sumto;
}

int main(){
    // 1. 1씩 빼기
    countDown(5);

    // 2. 현재 수에서 0까지 더하기
    cout << "sumTo : " << sumTo(10) << endl;

    return 0;
}