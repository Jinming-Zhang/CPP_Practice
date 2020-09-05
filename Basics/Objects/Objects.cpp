#include <iostream>
#include <sstream>
// #include "Wolf.h"
#include "Animal.cpp"
#include "Wolf.cpp"
int main()
{
    cout << "notes on object" << endl;
    // create object without new
    objects::Wolf w;
    // create object with new will dynamically allocate memory for that object
    objects::Wolf *w1 = new objects::Wolf();
    // use the delete to free the memory used to allocate the object.
    // note use the deconstructor is not enough for dynamically allocated objects. Since deconstructor only free resources used by the object, but we also need to free the memeory used to allocate the object
    delete w1;
    // to allocate and create a list of objects
    objects::Wolf *wolfs = new objects::Wolf[10];
    delete[] wolfs;

    objects::Wolf wolf("male", true, false);
    cout << wolf.species << endl;
    objects::Wolf wolf2 = wolf;
    wolf2.gender = "good-looking";
    cout << wolf.toString() << endl;
    cout << wolf2.toString() << endl;

    cout << "end of notes" << endl;
    return 0;
}