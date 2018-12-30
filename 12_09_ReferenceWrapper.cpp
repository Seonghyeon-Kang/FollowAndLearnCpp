/* keywords
Object slicing : 정보가 많은 자식의 오프젝트를 부모에 대입할 때 정보의 일부가 잘리는 현상 
reference  wrapper : Object slicing 문제를 예방하는 기법 
*/

#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Base
{
public:
    int m_i = 0;

    virtual void print(){
        cout << "I'm Base" << endl;
    }
};

class Derived : public Base
{
public:
    int m_j = 1;

    virtual void print() override{
        cout << "I'm derived" << endl;
    }
};

void doSomthing(Base& b){
    b.print();
}

int main(){
    Derived d;
    //1. 다형성이 사라지는 경우(Object slicing)
    //Base& b = d;
    Base b = d;     // Base에 있는 함수만 호출가능 (다형성이 사라짐)
    b.print();
    doSomthing(d);  // 함수로 다형성을 보장하는 경우

    //2. 백터 사용 사례
    //std::vector<Base> my_vec;     // slicing 문제가 발생함
    //std::vector<Base&> my_vec;    // reference를 바로 vector에 사용할 수 없음
    std::vector<Base*> my_vec;      // 포인터는 다형성 유지 가능
    my_vec.push_back(&b);
    my_vec.push_back(&d);

    for(auto& ele : my_vec)
        ele->print();

    //3. reference wrapper 사용방법
    std::vector<std::reference_wrapper<Base>> my_vec2;
    my_vec2.push_back(b);
    my_vec2.push_back(d);

    for(auto& ele : my_vec2)
        ele.get().print();   

    return 0;
}