#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    // Foreach 특징
    int fibonacci[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    for (int number : fibonacci) // 값이 바뀌지 않음
        number = 10;
    
    for (int number : fibonacci)
        cout << number << " ";
    cout << endl;

    for (auto &number : fibonacci) // 값이 바뀜
        number = 10;

    for (auto number : fibonacci)
        cout << number << " ";
    cout << endl;

    // Max 찾기
    vector<int> fibonacci2 = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};
    int max_number = numeric_limits<int>::lowest();

    for(const auto &n : fibonacci2){
        max_number = std::max(max_number, n);
    }

    cout << max_number << endl;
}