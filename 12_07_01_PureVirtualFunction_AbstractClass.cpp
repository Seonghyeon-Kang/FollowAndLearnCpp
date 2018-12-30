/* keywords
Pure virtual function : 바디가 없는 함수(class::function()으로 구현 가능하나 의미가 없음)
Abstract class        : 순수 가상함수를 포함
Interface class       : 순수 가상함수로만 구성
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
    protected:
    string m_name;

    public:
    Animal(string name)
        : m_name(name)
    {}

    public:
    string getName() { return m_name;}
    virtual void speak() const = 0; // pure virtual function
};

class Cat : public Animal
{
    public:
    Cat(string name)
        : Animal(name)
    {}

    void speak() const
    {
        cout << m_name << "Meow" << endl;
    }
};

class Dog : public Animal
{
    public:
    Dog(string name)
        : Animal(name)
    {}

    void speak() const
    {
        cout << m_name << "Woof" << endl;
    }
};

int main()
{
    //Animal ani('Hi'); // 순수가상함수가 구현되지 않으면 인스턴스를 생성할 수 없음
    
    Dog d("dog");
    d.speak(); // speak를 구현한 Dog은 인스턴스 생성이 가능

    return 0;
}

