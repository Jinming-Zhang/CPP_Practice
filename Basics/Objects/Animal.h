#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>
#include <sstream>
using namespace std;
namespace objects
{
    class Animal
    {
    public:
        Animal();
        Animal(string age, string species) : age(age), species(species){};
        ~Animal() { cout << "bye animal~" << endl; }
        string species;
        string age;
        string toString();
        void speak();
    };
} // namespace objects

#endif
