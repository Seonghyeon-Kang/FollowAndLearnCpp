#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int getValue(int x){
    int value = x * 2;
    return value;
}

int* allocateMemory(int size){
    return new int [size];
}

int& getValue_ref(int x){
    int value = x * 2;
    return value;
}

int& get(std::array<int, 100>& my_array, int ix){
    return my_array[ix];
}

struct S{
    int a, b, c, d;
};

S getStruct(){
    return S{1, 2, 3, 4};
}

std::tuple<int, double> getTuple(){
    int a = 10;
    double d = 3.14;
    return std::make_tuple(a, d);
}

int main()
{   
    // 1. 일반변수 반환
    //int value = getValue(3); // 사라질 변수의 주소를 받기 때문에 위험함

    // 2. 주소 반환
    //int *array = allocateMemory(1024);
    //delete[] array;

    // 3. 레퍼런스 반환
    //int value_ref = getValue_ref(5);
    //int &value_ref = getValue_ref(5); // 사라질 변수의 주소를 받기 때문에 위험함

    //cout << value_ref << endl;
    //cout << value_ref << endl; // OS에 메모리를 반납한 후이기 때문에 원하는 결과가 아님

    std::array<int, 100> my_array;
    my_array[30] = 10;

    get(my_array, 30) = 1024;
    cout << my_array[30] << endl;

    // 4. 복수개의 반환
    S my_s = getStruct(); // 리턴할 때 마다 구조체 생성이 요구됨(C 스타일)

    std:tuple<int, double> my_tp = getTuple(); // C++ 11
    cout << std::get<0>(my_tp) << endl; //a
    cout << std::get<1>(my_tp) << endl; //d

    auto [a, d] = getTuple(); // C++ 17
    cout << a << endl;
    cout << d << endl;    

    return 0;
}