#include <iostream>
using namespace std;

class CanGoWrong
{
public:
    CanGoWrong()
    {
        char *pMemory = new char[1000000000000];
        delete pMemory;
    }
};

int main()
{
    try
    {

        CanGoWrong wrong;
    }
    // note here when catching a Class exception, it's better to catch it by its reference
    catch (bad_alloc &e)
    {
        cout << "Caught exception.." << endl
             << e.what() << endl;
    }
    cout << "Still running..." << endl;
    return 0;
}