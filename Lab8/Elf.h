#include <string>
#include "Character.h"
using namespace std;

#ifndef __ELF_H__
#define __ELF_H__

class Elf : public Character {
    private:
        string family;
    public:
        Elf(const string &name, double health, double attackStrength, string family);
        string getFamily() const;
        void attack(Character &rhs);

 	
};

#endif