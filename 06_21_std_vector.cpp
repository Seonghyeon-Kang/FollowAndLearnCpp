#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int *my_arr = new int[5];
    std::vector<int> array; //동적 할당이 되기 때문에 사이즈를 적을 필요가 없음

    std::vector<int> arr = {1, 2, 3, 4, 5};
    std::vector<int> arr2 {1, 2, 3, 4, 5, 6};

    arr.resize(10); // 사이즈를 늘리거나 줄일 수 있음

    for (auto &itr : arr)
        cout << itr << " ";
    cout << endl;

    cout << arr.size() << endl;
    cout << arr[1] << endl;
    cout << arr.at(1) << endl;

    delete[] my_arr; // vector는 자동으로 지워줌

    return 0;
}