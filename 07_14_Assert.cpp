#include <iostream>
#include <cassert>
#include <array>

void printValue(const std::array<int, 5> &my_array, const int& ix){
    assert(ix >=0); // 런타임에 오류를 발견함
    assert(ix <= my_array.size() - 1);

    std::cout << my_array[ix] << std::endl;
}

int main(){
    //1. assert 활용
    std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };

    printValue(my_array, 100);

    //2. static_assert // 컴파일에서 오류를 발견함
    const int x = 10;
    //static_assert(x==5, "x should be 5 (jm)")
}
