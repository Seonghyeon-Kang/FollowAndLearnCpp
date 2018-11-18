#include <iostream>

class Fruit{

public:

    enum class FruitType{ // 클래스 내부에만 사용하는 경우 클래스 내부에 선언할 수 있음
        APPLE, BANANA, CHERRY,
    };

private:
    FruitType m_type;

public:
    Fruit(FruitType type) : m_type(type){
    }

    FruitType gettype(){ return m_type; }
};

int main(){

    Fruit apple(Fruit::FruitType::APPLE);

    if (apple.gettype() == Fruit::FruitType::APPLE){
        std::cout << "Apple" << std::endl;
    }

    return 0;
}
