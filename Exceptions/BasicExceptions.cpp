#include <iostream>
using namespace std;
void mightGoWrong();
void usesMightGoWrong();

// nested exception will be propagated to the most outer function withc catches the exception
void usesMightGoWrong()
{
    mightGoWrong();
}

void mightGoWrong()
{
    bool err = false;
    bool err2 = true;
    bool err3 = true;
    if (err)
    {
        // cout<< "there is an error...."<<endl;
        // we can throw an int here
        throw 8;
    }
    if (err2)
    {
        // we can also throw an char* (string) description
        throw "Something went wrong...";
    }
    if (err3)
    {
        // or throw a class exception. 
        // string is a class
        throw string("Something else went wrong...");
    }
}

int main()
{
    try
    {
        usesMightGoWrong();
    }
    catch (int e)
    {
        cout << "An integer exception occurs..." << endl;
    }
    catch (const char *c)
    {
        cout << "An char* exception occurs..." << endl;
    }
    // note here when catching a Class exception, it's better to catch its reference
    catch (string &e)
    {
        cout << "An string exception occurs..." << endl;
    }
    return 0;
}