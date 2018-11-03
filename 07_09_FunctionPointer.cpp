#include <iostream>
#include <array>
#include <functional> // c+11
using namespace std;

int func(int x){
    return 5;
}

int goo(int x){
    return 10;
}

bool isEven(const int& number){
    if(number % 2 == 0) return true;
    else return false;
}

bool isOdd(const int& number){
    if(number % 2 == 1) return true;
    else return false;
}

// void printNumbers(const array<int, 10> &my_array, bool (*check_fcn)(const int&) = isEven){
//     for(auto element : my_array){
//         if (check_fcn(element) == true) cout << element;
//     }
//     cout << endl;
// }

// typedef 를 활용하는 경우
//typedef bool (*check_fcn_t)(const int&);
// using 를 활용하는 경우
using check_fcn_t = bool (*)(const int&);

void printNumbers(const array<int, 10> &my_array, check_fcn_t check_fcn = isEven){
    for(auto element : my_array){
        if (check_fcn(element) == true) cout << element;
    }
    cout << endl;
}

// Functional를 사용하는 경우
void printNumbers2(const array<int, 10> &my_array, std::function<bool(const int&)> check_fcn = isEven){
    for(auto element : my_array){
        if (check_fcn(element) == true) cout << element;
    }
    cout << endl;
}

int main(){

    //1. 예제 1
    int(*fcnptr)(int) = func; // 파라미터와 리턴 타입이 같아야 함
    cout << fcnptr(1) << endl;

    fcnptr = goo;
    cout << fcnptr(1) << endl;

    //2. 예제 2
    std::array<int, 10> my_array{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printNumbers(my_array);
    //printNumbers(my_array, isEven); 기본값이 적용됨
    printNumbers(my_array, isOdd);

    // c++ 11
    std::function<bool(const int&)> fcnptr2 = isEven;
    printNumbers2(my_array, fcnptr2);

    fcnptr2 = isOdd;
    printNumbers2(my_array, fcnptr2);
    
    return 0;
}

