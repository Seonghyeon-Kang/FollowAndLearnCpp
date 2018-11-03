#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int> &stack){
    for (auto &e : stack)
        cout << e << " ";
    cout << endl;
}

int main(){
    //1. 기본 동작
    std::vector<int> v {1, 2, 3};
    // size(실제 사용량), capacity(메모리 량)

    v.resize(2);     // size를 조절
    v.reserve(1024); // 메모리의 용량을 미리 확보(capacity 증가)

    for (auto &e : v)
        cout << e << " ";
    cout << endl;

    cout << v.size() << " " << v.capacity() << endl;

    int *ptr = v.data();
    cout << ptr[2] << endl; // 실제로 있지만 delete, new로 인한 속도 감소를 막기위해
                            // size 만큼만 동작함

    //2. 응용
    std::vector<int> stack;

    stack.push_back(3);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    stack.push_back(3);
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);

    stack.pop_back();
    printStack(stack);
}