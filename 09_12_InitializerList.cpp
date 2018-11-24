#include <iostream>
#include <cassert>
#include <initializer_list>

using namespace std;

class IntArray
{
private:
    unsigned m_length = 0;
    int* m_pdata = nullptr;

public:
    IntArray(unsigned length) : m_length(length){ m_pdata = new int[length]; }

    IntArray(const std::initializer_list<int>& list) 
    : IntArray(list.size())
    {
        cout << "initializer list" << endl;

        int count = 0;
        for(auto& element : list){
            m_pdata[count] = element;
            ++count;
        }

        // for(unsigned count = 0 ; count < list.size() ; ++count){
        //     m_pdata[count] = list[count]; // 대괄호 operator를 지원하지는 않음
        // }
    }
    
    ~IntArray(){ delete[] this->m_pdata; }

    friend ostream& operator << (ostream& out, IntArray& arr)
    {
        for(unsigned i = 0 ; i < arr.m_length ; ++i)
            out << arr.m_pdata[i] << " ";
        out << endl;
        return out;
    }
};

int main()
{
    int my_arr1[5] = {1, 2, 3, 4, 5};
    int *my_arr2 = new int[5]{1, 2, 3, 4, 5}; 
    auto il = {10, 20, 30};

    IntArray int_array = { 1, 2, 3, 4, 5 }; // 중괄호 배열 형태에서 initializer list 생성자가 호출됨
    cout << int_array << endl;

    return 0;
}