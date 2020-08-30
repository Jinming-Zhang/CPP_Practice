#include <iostream>
using namespace std;

void goesWrong(bool throwBadAlloc, bool throwAnyException)
{
    if (throwBadAlloc)
    {
        throw bad_alloc();
    }

    if (throwAnyException)
    {
        throw exception();
    }
}

int main()
{
    try
    {
        goesWrong(false, true);
    }
    catch (bad_alloc &ba)
    {
        cout << "Catching bad_alloc exception" << endl
             << ba.what() << endl;
    }
    catch (exception &e)
    {
        cout << "Catching a general exception" << endl
             << e.what() << endl;
    }
    return 0;
}