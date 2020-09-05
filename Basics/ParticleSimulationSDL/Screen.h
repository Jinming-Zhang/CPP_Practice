#pragma once
#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif
#include <iostream>
#include <cstring>
#include "SDL.h"
#include "Util.h"
using namespace std;
namespace myScreen
{
    class Screen
    {
    private:
        SDL_Window *m_window;
        SDL_Renderer *m_renderer;
        SDL_Texture *m_texture;
        Uint32 *m_imageBuffer;
        Uint32 *m_blurBuffer;

    private:
        Screen(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, Uint32 *buffer, Uint32 *blurBuffer);
        // init sdl window
        // SDL_Window *window = SDL_CreateWindow("Particle Fire Exposion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        // if (window == NULL)
        // {
        //     SDL_Quit();
        //     return 2;
        // }

        // // initialize renderer and texture
        // SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
        // SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    public:
        Uint32 *getImageBuffer()
        {
            return this->m_imageBuffer;
        }

    public:
        const static int SCREEN_WIDTH = 800;
        const static int SCREEN_HEIGHT = 600;
        static Screen *Init(const char *name);
        bool processEvents();
        int setPixelColor(int index, unsigned char r, unsigned char g, unsigned char b, unsigned char a);
        void UpdateRenderer();
        void ClearBuffer();
        void close();
        void BoxBlur();
        ~Screen();
    };
} // namespace myScreen