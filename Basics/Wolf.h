#ifndef _WOLF_H_
#define _WOLF_H_

#include <iostream>
using namespace std;
class Wolf
{
private:
    string name;
    int age;
    bool male;

public:
    Wolf();
    Wolf(string name, int age, bool male);
    void bark();
    void sleep();
    ~Wolf();
    string toString();
};
#endif