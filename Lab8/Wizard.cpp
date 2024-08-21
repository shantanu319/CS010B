#include "Wizard.h"
#include <string>
#include <iostream>

using namespace std;


Wizard::Wizard(const string &name, int health, int attackStrength, int rank) : Character(WIZARD, name, health, attackStrength)
{
    this->rank = rank;
}

int Wizard::getRank() const
{
    return rank;
}

void Wizard::attack(Character &rhs)
{
    if (rhs.getType() == WIZARD)
    {
        Wizard &opp = dynamic_cast<Wizard &>(rhs);
        double dmg = attackStrength * (double(rank) / double(opp.getRank()));
        opp.damage(dmg);
        cout << "Wizard " << name << " attacks " << rhs.getName() << " --- POOF!!" << endl;
        cout << rhs.getName() << " takes " << dmg << " damage." << endl;
    }
    else
    {
        //Wizard &opp = dynamic_cast<Wizard &>(rhs);
        double dmg = attackStrength;
        rhs.damage(dmg);
        cout << "Wizard " << name << " attacks " << rhs.getName() << " --- POOF!!" << endl;
        cout << rhs.getName() << " takes " << dmg << " damage." << endl;
    }
}
