#include <iostream>
#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif
#include "SDL.h"

using namespace std;
int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    }
    else
    {
        cout << "SDL init success!" << endl;
    }
    cout << "SDL Practice Start!" << endl;
    SDL_Quit();
    return 0;
}