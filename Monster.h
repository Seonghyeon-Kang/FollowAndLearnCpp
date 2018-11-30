#pragma once

#include "Position2D.h"
#include <string>

class Monster{
private:
    // Position2D는 monster과 composition 즉, 부분인 관계
    // 나눠야 할 것은 과감하게 빨리 나눌 수 록 좋음
    std::string m_name;
    Position2D m_location;

public:
    Monster(const std::string name_in, const Position2D& pos_in)
        : m_name(name_in), m_location(pos_in)
    {}

    void moveTo(const Position2D& pos_target){
        m_location.set(pos_target);
    }

    friend std::ostream& operator << (std::ostream& out, const Monster& monster){
        out << monster.m_name << " " << monster.m_location;
        return out;
    }
};
