#include <iostream>
#include <cassert>
using namespace std;

class IntList{

private:
    int m_list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

public:
    void setItem(int index, int value){
        m_list[index] = value;
    }

    int getItem(int index){
        return m_list[index];
    }

    int* getList(){
        return m_list;
    }

    int & operator [] (const int index){ // 대괄호 안에 string 등 다른 데이터형 적용도 가능
        assert(index >= 0);
        assert(index < 10);
        return m_list[index];
    }

    const int & operator [] (const int index) const{
        assert(index >= 0);
        assert(index < 10);
        return m_list[index];
    }
};

int main(){
    IntList my_list;

    my_list[3] = 10;
    cout << my_list[3] << endl;

    const IntList my_list_c;
    cout << my_list_c[3] << endl; 

    // Pointer 사용 시 주의
    IntList *my_list_p = new IntList;
    (*my_list_p)[3] = 10; // derefferencing 을 먼저 해야함
    cout << (*my_list_p)[3] << endl; 

    return 0;
}