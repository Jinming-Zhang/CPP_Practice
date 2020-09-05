#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

inline unsigned int RGBAToHex(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    unsigned int result = 0;
    result += r;
    result <<= 8;
    result += g;
    result <<= 8;
    result += b;
    result <<= 8;
    result += a;
    return result;
}

inline void HexToRGBA(unsigned int hex, int &r, int &g, int &b, int &a)
{
    r = (0xFF000000 & hex) >> 24;
    g = (0x00FF0000 & hex) >> 16;
    b = (0x0000FF00 & hex) >> 8;
    a = 0x000000FF & hex;
}
inline int rcToIndex(int r, int c)
{
    if (r < 0 || r >= 600 || c < 0 || c >= 800)
    {
        return -1;
    }
    // int result = r * 800 + c;
    return r * 800 + c;
    // if (result < 0 || result > 800 * 600)
    // {
    //     return -1;
    // }
}

inline void indexToRC(int index, int &r, int &c)
{
    r = index / 800;
    c = index % 800;
}
