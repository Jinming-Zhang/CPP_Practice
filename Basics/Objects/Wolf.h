#include <iostream>
#include <sstream>
#include "Animal.h"
using namespace std;
namespace objects
{
    class Wolf : public Animal
    {
    public:
        Wolf() : Animal("0", "wolf") { cout << "Hi new wolf!" << endl; };
        Wolf(string gender, bool isSingle, bool hasPack) : Animal("0", "wolf"), gender(gender), isSingle(isSingle), hasPack(hasPack) { cout << "Hi new wolf!" << endl; };
        ~Wolf() { cout << "bye wolf~" << endl; };
        string gender;
        bool isSingle;
        bool hasPack;

        string toString();
    };
} // namespace objects