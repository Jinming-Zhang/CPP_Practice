#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
#include <sstream>
using namespace std;
class Animal
{
public:
    Animal();
    string species;
    string age;
    string toString();
    void speak();
};

#endif
