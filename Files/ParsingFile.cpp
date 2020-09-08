#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;

#pragma pack(push, 1)
typedef struct
{
    char name[256];
    int age;
    double weight;
} Wolf;
#pragma pack(pop)

int main()
{
    // ******************* parsing file *******************//
    string filename = "formattedFile.txt";

    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cout << "Can't open the file " << filename << endl;
        return 1;
    }
    while (file)
    {
        string line;
        getline(file, line, ':');
        int population;
        file >> population;
        file >> ws;
        if (!file)
        {
            break;
        }
        cout << line << " -- " << population << endl;
    }
    file.close();
    // ******************* struct and padding *******************//
    Wolf wolf;
    cout << sizeof(wolf) << endl;
    return 0;
}