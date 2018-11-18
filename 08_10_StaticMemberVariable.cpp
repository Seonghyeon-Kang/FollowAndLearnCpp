#include <iostream>

using namespace std;

class Something{
public:
    //static int s_value = 1; //생성과 함께 초기화 불가
    static int s_value;
    static const int c_value = 1; // const는 초기화 가능
    static constexpr int ct_value = 1;

public:
    int getValue(){
        return s_value;
    }
};

int Something::s_value = 1;

int main(){
    cout << &Something::s_value << " " << Something::s_value << endl;

    Something st1;
    Something st2;
    
    st1.s_value = 2;

    cout << &st1.s_value << " " << st1.s_value << endl;
    cout << &st2.s_value << " " << st2.s_value << endl;

    return 0;    
}