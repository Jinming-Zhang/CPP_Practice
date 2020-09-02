#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// passing reference as parameter to function
void passingByReference(string (&texts)[3])
{
    cout << sizeof(texts) << endl;
}

void passingByReference(int &grade)
{
    cout << "Get grade of " << grade << endl;
    grade = 100;
}

int main()
{
    const int ARRAY_LENGTH = 5;
    string texts[] = {"one", "two", "three", "four", "five"};
    cout << "Size of a file element string array:" << sizeof(texts) << endl;
    // use pointer to loop through list
    cout << "use pointer to loop through list" << endl;
    string *start = texts;
    for (int i = 0; i < sizeof(texts) / sizeof(texts[0]); i++)
    {
        cout << *start << " " << flush;
        start++;
    }
    cout << endl;
    // use pointer to loop through list using while loop
    cout << "use pointer to loop through list using while loop" << endl;
    start = texts;
    string *end = &texts[ARRAY_LENGTH - 1];
    while (true)
    {
        cout << *start << " " << flush;
        if (start == end)
        {
            break;
        }
        start++;
    }
    cout << endl;
    // reverse the array
    cout << "reversing the array using pointers" << endl;
    start = texts;
    end = &(texts[ARRAY_LENGTH - 1]);
    while (start < end)
    {
        // its a string array
        string tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        cout << texts[i] << " " << flush;
    }
    cout << endl;
    // const with pointer
    // this is a pointer that points to a constant int, which means we can't chane the value that the pointer is pointing to.
    // const int *intPtr;
    // this is a constant pointer that points to an int, which means we can't change the address that the pointer is pointing to, but we can change the value that the pointer is pointing at.
    // int const *intPtr;
    vector<int> vect{10, 20, 30, 40};

    // We can modify elements if we
    // use reference
    for (int &x : vect)
    {
        x = x + 5;
    }

    // Printing elements
    for (int x : vect)
    {
        cout << x << " ";
    }
    cout << endl;

    string texts3[] = {"one", "two", "three"};
    passingByReference(texts3);

    int grade = 50;
    int &cpGrade = grade;
    passingByReference(cpGrade);
    cout << "Now your grade is " << grade << endl;
    return 0;
}