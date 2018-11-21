#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Cents{
private:
    int m_cents;

public:
    Cents(int cents = 0) { m_cents = cents; }
    int getCents() const { return m_cents; }
    int& getCents() { return m_cents; }

    friend bool operator == (const Cents &c1, const Cents &c2){
        return c1.m_cents == c2.m_cents;
    }

    // 파일 출력과 콘솔 출력을 담당
    friend std::ostream& operator << (std::ostream &out, const Cents &cents1){
        out << "(" << cents1.m_cents << ")" ;
        return out; // chaining
    }

    // sort를 위해서 부등호 방향에 주의할 것
    friend bool operator < (const Cents &c1, const Cents &c2){
        return c1.m_cents < c2.m_cents;
    }
};

int main(){
    Cents cents1(6);
    Cents cents2(0);

    if (cents1 == cents2) cout << "Equal" << endl;


    vector<Cents> arr(20);
    for (unsigned i = 0; i < 20; ++i){
        arr[i].getCents() = i;
    }

    std::random_shuffle(begin(arr), end(arr));
    for(auto &e : arr)
        cout << e << " ";
    cout << endl;

    std::sort(begin(arr), end(arr));
    for(auto &e : arr)
        cout << e << " ";
    cout << endl;
    
    return 0;
}

// 주의사항
// 연산자 오버로딩이 안되는 연산자 ?: :: sizeof . .*
// 연산자의 우선순위는 바꿀 수 없음
// ^ 오버로딩 안하는 것을 추천
// 맴버함수로만 가능한 연산자 오버로딩 =, [], (), -> 
