#include <iostream>
#include <sstream>
#include "Animal.h"
using namespace std;

class Wolf : public Animal
{
public:
    string gender;
    bool isSingle;
    bool hasPack;
    Wolf();
    Wolf():gender(gender), isSingle(isSingle),hasPack(hasPack){};

    string toString();
};