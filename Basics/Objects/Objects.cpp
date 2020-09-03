#include <iostream>
#include <sstream>
// #include "Wolf.h"
#include "Animal.h"
#include "Wolf.cpp"
int main()
{
    // create object without new
    Wolf w;
    // create object with new will dynamically allocate memory for that object
    Wolf *w1 = new Wolf();
    // use the delete to free the memory used to allocate the object.
    // note use the deconstructor is not enough for dynamically allocated objects. Since deconstructor only free resources used by the object, but we also need to free the memeory used to allocate the object
    delete w1;
    // to allocate and create a list of objects
    Wolf *wolfs = new Wolf[10];
    delete[] wolfs;
    return 0;
}