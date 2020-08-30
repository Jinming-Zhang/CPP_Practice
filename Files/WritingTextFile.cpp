#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    string filename = "text.txt";
    // output file stream for writing to files
    // ofstream outputFile;
    // outputFile.open(filename);
    // alternatively we can also use file stream with out mode
    fstream outputFile;
    outputFile.open(filename, ios::out);

        if (outputFile.is_open())
    {
        outputFile << "Hello there" << endl;
        outputFile << "Im " << 20 << " years old wolf" << endl;
        outputFile.close();
    }
    else
    {
        cout << "Could not create file " << filename << endl;
    }
    return 0;
}