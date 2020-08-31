#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

int main(char **args)
{
    // flush the output to console with a newline char
    cout << "Flush something with new line..." << endl;
    // flush the output to the console without a newline char
    cout << "Flush something without a new line..." << flush;
    cout << "previous output doesn't end with a new line..." << endl;
    // find limits of numbers
    cout << "Limits of Data types:\n";
    cout << "char\t\t\t: " << static_cast<int>(numeric_limits<char>::min()) << " to " << static_cast<int>(numeric_limits<char>::max()) << endl;
    cout << "unsigned char\t\t: " << static_cast<int>(numeric_limits<unsigned char>::min()) << " to " << static_cast<int>(numeric_limits<unsigned char>::max()) << endl;
    cout << "short\t\t\t: " << numeric_limits<short>::min() << " to " << numeric_limits<short>::max() << endl;
    cout << "unsigned short\t\t: " << numeric_limits<unsigned short>::min() << " to " << numeric_limits<unsigned short>::max() << endl;
    cout << "int\t\t\t: " << numeric_limits<int>::min() << " to " << numeric_limits<int>::max() << endl;
    cout << "unsigned int\t\t: " << numeric_limits<unsigned int>::min() << " to " << numeric_limits<unsigned int>::max() << endl;
    cout << "long\t\t\t: " << numeric_limits<long>::min() << " to " << numeric_limits<long>::max() << endl;
    cout << "unsigned long\t\t: " << numeric_limits<unsigned long>::min() << " to " << numeric_limits<unsigned long>::max() << endl;
    cout << "long long\t\t: " << numeric_limits<long long>::min() << " to " << numeric_limits<long long>::max() << endl;
    cout << "unsiged long long\t: " << numeric_limits<unsigned long long>::min() << " to " << numeric_limits<unsigned long long>::max() << endl;
    cout << "float\t\t\t: " << numeric_limits<float>::min() << " to " << numeric_limits<float>::max() << endl;
    cout << "double\t\t\t: " << numeric_limits<double>::min() << " to " << numeric_limits<double>::max() << endl;
    cout << "long double\t\t: " << numeric_limits<long double>::min() << " to " << numeric_limits<long double>::max() << endl;
    cout << numeric_limits<unsigned int>::max() << endl;
    return 0;
}