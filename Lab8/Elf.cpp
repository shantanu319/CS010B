#include "Elf.h"
#include <string>
#include <iostream>

using namespace std;



Elf::Elf(const string &name, double health, double attackStrength, string family) : Character(ELF, name, health, attackStrength)
{
    this->family = family;
}

string Elf::getFamily() const
{
    return family;
}

void Elf::attack(Character &rhs)
{
    double dmg = attackStrength * (health / MAX_HEALTH);
    if (rhs.getType() == ELF)
    {
        Elf &opp = dynamic_cast<Elf &>(rhs);
        if (opp.getFamily() == family)
        {
            cout << "Elf " << name << " does not attack Elf " << opp.getName() << "." << endl;
            cout << "They are both members of the " << family << " family." << endl;
        }
        else
        {
            rhs.damage(dmg);
            cout << "Elf " << name << " shoots an arrow at " << opp.getName() << " --- TWANG!!" << endl;
            cout << opp.getName() << " takes " << dmg << " damage." << endl;
        }
    }
    else
    {
        rhs.damage(dmg);
        cout << "Elf " << name << " shoots an arrow at " << rhs.getName() << " --- TWANG!!" << endl;
        cout << rhs.getName() << " takes " << dmg << " damage." << endl;
    }
}