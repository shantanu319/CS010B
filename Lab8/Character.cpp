#include "Character.h"
#include <string>
#include <iostream>

using namespace std;

Character::Character(HeroType type, const string &name, double health, double attackStrength)
{
    this->type = type;
    this->name = name;
    this->health = health;
    this->attackStrength = attackStrength;

}
HeroType Character::getType() const
{
    return type;
}
const string & Character::getName() const
{
    return name;
}
int Character::getHealth() const
{
    return int (health);
}
void Character::damage(double d)
{
    health = health - d;
}
bool Character::isAlive() const
{
    if (getHealth() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
