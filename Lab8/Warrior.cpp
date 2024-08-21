#include "Warrior.h"
#include <string>
#include <iostream>

using namespace std;

Warrior::Warrior(const string& name, double health, double attackStrength, string allegiance) : Character(WARRIOR, name, health, attackStrength)
{
    this->allegiance = allegiance;
    
}
string Warrior::getAllegiance() const
{
    return allegiance;
}
void Warrior::attack(Character &rhs)
{
    double dmg = attackStrength * (health / MAX_HEALTH);
    if (rhs.getType() == WARRIOR)
    {
        Warrior &opp = dynamic_cast<Warrior &>(rhs);
        if (opp.getAllegiance() == allegiance)
        {
            cout << "Warrior " << name << " does not attack Warrior " << opp.getName() << "." << endl;
            cout << "They share an allegiance with " << allegiance << "." << endl;
        }
        else
        {
            rhs.damage(dmg);
            cout << "Warrior " << name << " attacks " << opp.getName() << " --- SLASH!!" << endl;
            cout << opp.getName() << " takes " << dmg << " damage." << endl;
        }
    }
    else
    {
        rhs.damage(dmg);
        cout << "Warrior " << name << " attacks " << rhs.getName() << " --- SLASH!!" << endl;
        cout << rhs.getName() << " takes " << dmg << " damage." << endl;
            
    }
}