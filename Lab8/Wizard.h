#include <string>
#include "Character.h"
using namespace std;

#ifndef __WIZARD_H__
#define __WIZARD_H__

class Wizard : public Character{
    private:
        int rank;
    public:
        Wizard(const string &name, int health, int attackStrength, int rank);
        int getRank() const;
        void attack(Character &rhs);

};

#endif