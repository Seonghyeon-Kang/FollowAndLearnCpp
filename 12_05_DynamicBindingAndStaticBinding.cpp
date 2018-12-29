/* Keywords
정적바인딩 : 컴파일 시점에 미리 모든 함수나 변수가 정해져 있는 상황 (속도 유리)
동적바인딩 : 컴파일이 아닌 실행 시점에 정해지는 상황 (프로그래밍이 유연해 짐)
*/

#include <iostream>
using namespace std;

int add(int x, int y)
{
    return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    int x, y;
    cout << "Type two numbers : " << endl;
    cin >> x >> y;

    int op;
    cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
    cin >> op;

    int result;

    // 1. static binding (early binding)
    // switch (op)
    // {
    // case 0: result = add(x, y); break;
    // case 1: result = subtract(x, y); break;
    // case 2: result = multiply(x, y); break;
    // }

    // cout << "Result : " << result << endl;

    // 2. dynamic binding (late binding)
    int(*func_ptr)(int, int) = nullptr;
    switch (op)
    {
    case 0: func_ptr = add; break;
    case 1: func_ptr = subtract; break;
    case 2: func_ptr = multiply; break;
    }

    cout << func_ptr(x, y) << endl;

    return 0;
}