#include <iostream>
#include <stdio.h>
#include <cstdlib> //random lib
#include <chrono>
#include <thread>
#include <iomanip>
#include <math.h>
#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif
#include "SDL.h"
#include "Util.h"
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

using namespace myScreen;
using namespace std;

const int PARTICLE_NO = 15550;

int main()
{
    srand(time(NULL));
    // init sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return false;
    }
    cout << "SDL init success, Practice Start!" << endl;
    Screen *screen = Screen::Init("Particle Firewwork");
    // game loo
    Uint32 *buffer = new Uint32[Screen::SCREEN_WIDTH * Screen::SCREEN_HEIGHT];

    Swarm swarm(PARTICLE_NO);
    while (true)
    {
        Uint32 elapse = SDL_GetTicks();
        // screen->ClearBuffer();
        swarm.update(elapse);

        unsigned char clr = floor((1 + sin((double)SDL_GetTicks() / 1000)) / 2 * 255);
        Particle *particles = swarm.getParticle();
        for (int i = 0; i < PARTICLE_NO; i++)
        {
            Particle p = particles[i];
            int x = floor(p.m_x * Screen::SCREEN_HEIGHT);
            int y = floor(p.m_y * Screen::SCREEN_HEIGHT);
            if (x > 0 && x < Screen::SCREEN_WIDTH && y > 0 && y < Screen::SCREEN_HEIGHT)
            {
                screen->setPixelColor(rcToIndex(y, x), 100, clr, 255, 255);
            }
        }
        screen->BoxBlur();

        screen->UpdateRenderer();

        if (!(screen->processEvents()))
        {
            break;
        }
    }
    delete[] buffer;
    fprintf(stdout, "Bye bye particle system...!!");
    delete screen;
    SDL_Quit();
    return 0;
}