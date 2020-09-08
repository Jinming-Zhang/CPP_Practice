#include <iostream>
#include <iomanip>
#include <limits>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <cmath>
#include <vector>
// #include "Wolf.h"
#include "Wolf.cpp"
using namespace std;

inline void printVector(vector<int> arr)
{
    for (int x : arr)
    {
        cout << x << " " << flush;
    }
    cout << endl;
}

vector<int> MergeSort(vector<int> arr)
{
    if (arr.size() <= 1)
    {
        return arr;
    }
    else
    {
        vector<int> left;
        for (unsigned int i = 0; i < arr.size() / 2; i++)
        {
            left.insert(left.begin() + i, arr[i]);
        }
        vector<int> right;
        for (unsigned int i = arr.size() / 2; i < arr.size(); i++)
        {
            // cout << i << endl;
            // cout << arr[i] << endl;
            right.insert(right.begin() + i - (arr.size() / 2), arr[i]);
        }
        left = MergeSort(left);
        right = MergeSort(right);

        vector<int> result;
        unsigned int leftIndex = 0;
        unsigned int rightIndex = 0;
        unsigned int resultIndex = 0;
        while (leftIndex < left.size() || rightIndex < right.size())
        {
            // added all element from left array
            if (leftIndex >= left.size())
            {
                for (; rightIndex < right.size(); rightIndex++)
                {
                    result.insert(result.begin() + resultIndex, right[rightIndex]);
                    resultIndex++;
                }
                break;
            }
            else if (rightIndex >= right.size())
            {
                for (; leftIndex < left.size(); leftIndex++)
                {
                    result.insert(result.begin() + resultIndex, left[leftIndex]);
                    resultIndex++;
                }
                break;
            }

            if (left[leftIndex] < right[rightIndex])
            {
                result.insert(result.begin() + resultIndex, left[leftIndex]);
                leftIndex++;
                resultIndex++;
            }
            else
            {
                result.insert(result.begin() + resultIndex, right[rightIndex]);
                rightIndex++;
                resultIndex++;
            }
        }
        return result;
    }
}

vector<int> MergeSortTwo(vector<int> arr, long& swapCount){
    if(arr.size()<=1){
        return arr;
    }
    // left
    vector<int> left(arr.size()/2);
    for(unsigned int i = 0; i < arr.size()/2; i++){
        left.insert(left.begin()+i, arr[i]);
    }
    //right
    int rightSize = arr.size()-arr.size()/2;
    vector<int> right;
   for (unsigned int i = arr.size() / 2; i < arr.size(); i++)
        {
            right.insert(right.begin() + i - (arr.size() / 2), arr[i]);
        }

    // sort left and right
    left = MergeSortTwo(left, swapCount);
    right = MergeSortTwo(right, swapCount);

    // merge right and right
    int leftIndex = 0;
    int rightIndex = 0;
    int resultIndex = 0;
    vector<int> result(arr.size());
    while(leftIndex<left.size() || rightIndex<right.size()){
        if(leftIndex>= left.size()){
            while(rightIndex<right.size()){
                rightIndex++;
                result.insert(result.begin()+resultIndex, right[rightIndex]);
                resultIndex++;
            }
            break;
        }
        else if(rightIndex >= right.size()){
            while(leftIndex< left.size()){
                leftIndex++;
                result.insert(result.begin()+resultIndex, left[leftIndex]);
                resultIndex++;
            }
            break;
        }
        else if(right[rightIndex]<left[leftIndex]){
            swapCount += left.size() - leftIndex;
            rightIndex++;
            result.insert(result.begin()+resultIndex, right[rightIndex]);
            resultIndex++;
        }
        else{
            leftIndex++;
            result.insert(result.begin()+resultIndex, left[leftIndex]);
            resultIndex++;
        }
    }
    return result;
}

int main()
{
    srand(time(NULL));
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
    // array
    string animals[3][3] = {{"dog", "wolf", "bear"},
                            {"crocodile", "canine", "lizard"}};
    cout << sizeof(animals) << endl;
    cout << sizeof(animals[0]) << endl;
    cout << sizeof((animals[0][0])) << endl;
    for (unsigned int i = 0; i < sizeof(animals) / sizeof(animals[0]); i++)
    {
        for (unsigned int j = 0; j < sizeof(animals[0]) / sizeof(animals[0][0]); j++)
        {
            cout << animals[i][j] << " " << flush;
        }
        cout << endl;
    }

    Wolf wolf1;
    cout << "confirming address...." << endl;
    cout << &wolf1 << endl;
    cout << wolf1.toString() << endl;

    vector<int> arr2;
    int count = 0;
    while (count < 300)
    {
        arr2.insert(arr2.begin() + count, (rand() % 300)-150);
        count++;
    }
    vector<int> sorted = MergeSort(arr2);
    printVector(sorted);
    cout << "quiting in 3 seconds" << endl;
    cout << 3 << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << 2 << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    cout << 1 << endl;
    this_thread::sleep_for(chrono::milliseconds(1000));
    // string anything;
    // cout << "type enter to quit." << endl;
    // cin >> anything;

    return 0;
}