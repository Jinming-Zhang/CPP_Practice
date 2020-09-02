#include <sstream>
#include "Wolf.h"
Wolf::Wolf() : name("wolfy"), age(18), male(true)
{
    cout << "new wolf lives at" << this << "!!" << endl;
}

Wolf::Wolf(string name, int age, bool male)
{
    this->name = name;
    this->age = age;
    this->male = male;
    cout << "new wolf lives at" << this << "!!" << endl;
}

Wolf::~Wolf()
{
    cout << "Deconstructing... Farewell Wolf " << this->name << "!!" << endl;
}
void Wolf::bark()
{
    cout << "Woof! Woof!" << endl;
}
void Wolf::sleep()
{
    cout << "zZzzzZZZZzzZZ..." << endl;
}

string Wolf::toString()
{
    stringstream ss;
    ss << "I'm " << this->name << ", I'm " << this->age << " years old."
       << " Woofwoof!" << endl;
    return ss.str();
}