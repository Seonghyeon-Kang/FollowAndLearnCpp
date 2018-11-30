#include "Monster.h"

using namespace std;

int main(){
    Monster mon1("Sanson", Position2D(0, 0));
    Monster mon2("Parsival", Position2D(3, 3));

    do{
        //event
        mon1.moveTo(Position2D(1, 1));
        std::cout << mon1 << std::endl;
    }while(false); // game loop

    return 0;
}