#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string filename = "text.txt";
    // similar to writing to a file
    // we can open a ifstream
    // ifstream inFile;
    // inFile.open(filename);
    // or alternatively, we can open a filestream with reading mode
    fstream inFile;
    inFile.open(filename, ios::in);

    if (inFile.is_open())
    {
        string line;
        // read the file word by word
        inFile >> line;
        cout << line << endl;
        // or use the built-in function in <fstream> to read line by line
        getline(inFile, line);
        cout << line << endl;
        getline(inFile, line);
        cout << line << endl;
        // read the whole file into lines
        cout << "******* Reading the whole file into lines ******" << endl;
        inFile.clear();
        inFile.seekg(0);
        while (!inFile.eof())
        {
            getline(inFile, line);
            cout << line << endl;
        }
        inFile.close();
    }
    else
    {
        cout << "Couldn't open file " << filename << endl;
    }
    return 0;
}