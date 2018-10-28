#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void printLength(const array<int, 5>& my_arr){
    cout << my_arr.size() << endl;
}

int main(){
    //int array[5] = {1, 2, 3, 4, 5};
    array<int, 5> my_arr = {1, 2, 3, 4, 5}; // 크기를 꼭 지명해야함

    //my_arr = {0, 1, 2, 3, 4, 5}; // 많으면 안됨
    //my_arr = {0, 1, 2, 3};       // 적으면 작동함

    //cout << my_arr[10] << endl;
    //cout << my_arr.at(10) << endl; // 예외 처리 됨

    cout << my_arr.size() << endl;
    printLength(my_arr);

    my_arr = {1, 21, 3, 40, 4};

    for (auto &element : my_arr)
        cout << element << " ";
    cout << endl;

    std::sort(my_arr.begin(), my_arr.end());
    //std::sort(my_arr.rbegin(), my_arr.rend()); // 역순 정렬

    for (auto &element : my_arr)
        cout << element << " ";
    cout << endl;

    return 0;
}