#include <iostream>
#include <string.h>
#include <fstream>
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
    string filename = "binaryFile.wolf";
    fstream fp;
    // fp.open(filename, ios::out | ios::binary);
    fp.open(filename, ios::out | ios::binary);
    if (!fp.is_open())
    {
        cout << "Can't open file " << filename << endl;
        fp.close();
        return 1;
    }
    // write to the file
    Wolf wolf = {"Wolfy", 20, 75};
    fp.write((char *)&wolf, sizeof(Wolf));
    cout << sizeof(Wolf) << endl;
    fp.write(reinterpret_cast<char *>(&wolf), sizeof(Wolf));
    fp.flush();
    fp.close();

    // read from file
    fp.open(filename, ios::in | ios::binary);
    if (!fp.is_open())
    {
        cout << "Can't open file " << filename << endl;
        fp.close();
        return 1;
    }
    Wolf wolf2;
    fp.read(reinterpret_cast<char *>(&wolf2), sizeof(Wolf));
    printf("Got you %d years old %.1f kg wolf %s\n", wolf2.age, wolf2.weight, wolf2.name);
    fp.close();
    return 0;
}