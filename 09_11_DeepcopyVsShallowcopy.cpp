#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;

class MyString{
public:
    char* m_pdata = nullptr;
    int m_length = 0;

public:
    MyString(const char* source = ""){
        assert(source);

        m_length = std::strlen(source) + 1; // 공백문자 길이 추가
        m_pdata = new char[m_length];

        for (int i = 0 ; i < m_length ; i++){
            m_pdata[i] = source[i];
        }

        m_pdata[m_length - 1] = '\0';
    }

    MyString(const MyString& source){
        //deep copy
        cout << "Copy constructor" << endl;

        m_length = source.m_length;

        if (source.m_pdata != nullptr){
            m_pdata = new char[m_length];

            for (int i = 0 ; i < m_length ; ++i){
                m_pdata[i] = source.m_pdata[i];
            }
        }
        else
            m_pdata = nullptr;
    }

    MyString& operator = (const MyString& source){
        //deep copy
        cout << "Assignment operator" << endl;

        if(this == &source) return *this; // prevent self-assignment
        delete[] m_pdata;

        m_length = source.m_length;

        if (source.m_pdata != nullptr){
            m_pdata = new char[m_length];

            for (int i = 0 ; i < m_length ; ++i){
                m_pdata[i] = source.m_pdata[i];
            }
        }
        else
            m_pdata = nullptr;
    }

    ~MyString(){ delete[] m_pdata; }

    char* getString() { return m_pdata; }
    int getLength() { return m_length; }
};

int main(){
    MyString hello("Hello");
    cout << (int*)hello.m_pdata << endl;
    cout << hello.getString() << endl;

    {
        MyString copy = hello;
        cout << (int*)hello.m_pdata << endl;
        cout << copy.getString() << endl;       
    } // shallow copy 인 경우 copy에 의해 hello까지 영향을 줌

    cout << hello.getString() << endl; // shallow copy의 경우 쓰레기value가 나옴

    return 0;
}

