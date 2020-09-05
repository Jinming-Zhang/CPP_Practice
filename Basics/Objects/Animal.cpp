#include "Animal.h"
#include <sstream>
namespace objects
{
    Animal::Animal()
    {
        age = "0";
        species = "undefined";
    };

    string Animal::toString()
    {
        stringstream ss;
        ss << "I'm " << species << " of age " << age << "." << endl;
        return ss.str();
    };

    void Animal::speak()
    {
        cout << "I can't speek..." << endl;
    }
} // namespace objects