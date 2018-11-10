#include <iostream>
#include <cstdarg> // for ellipsis

using namespace std;

double findAverage(int count, ...){
    double sum = 0;

    va_list list;
    va_start(list, count);

    for (int arg=0 ; arg<count ; ++arg){
        sum += va_arg(list, int);
    }

    va_end(list);

    return sum / count;
}

int main(){
    cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl; // Count가 1이므로 뒤의 Arg를 무시함
    cout << findAverage(3, 1, 2, 3) << endl; // 1, 2, 3의 평균을 구함
}
