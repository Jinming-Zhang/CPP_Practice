#include <stdio.h>
#include "Screen.h"
namespace myScreen
{
    Screen::Screen(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *texture, Uint32 *buffer, Uint32 *blrBuffer) : m_window(window), m_renderer(renderer), m_texture(texture), m_imageBuffer(buffer), m_blurBuffer(blrBuffer)
    {
    }
    Screen *Screen::Init(const char *windowName)
    {
        SDL_Window *window = SDL_CreateWindow(windowName, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if (window == NULL)
        {
            return NULL;
        }
        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RendererFlags::SDL_RENDERER_PRESENTVSYNC);
        if (renderer == NULL)
        {
            SDL_DestroyWindow(window);
            return NULL;
        }
        SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
        if (texture == NULL)
        {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            return NULL;
        }
        Uint32 *imageBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        if (imageBuffer == NULL)
        {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyTexture(texture);
            return NULL;
        }
        Uint32 *blurBuffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
        if (blurBuffer == NULL)
        {
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            SDL_DestroyTexture(texture);
            return NULL;
        }
        // 0xFA9801FF
        std::fill_n(imageBuffer, SCREEN_WIDTH * SCREEN_HEIGHT, 0x00000000);
        std::fill_n(blurBuffer, SCREEN_WIDTH * SCREEN_HEIGHT, 0x00000000);
        Screen *newScreen = new Screen(window, renderer, texture, imageBuffer, blurBuffer);
        return newScreen;
    }

    void Screen::ClearBuffer()
    {
        memset(m_imageBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
        memset(m_blurBuffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
    }

    int Screen::setPixelColor(int index, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
        if (index < SCREEN_WIDTH * SCREEN_HEIGHT && index >= 0)
        {
            this->m_imageBuffer[index] = RGBAToHex(r, g, b, a);
            return 0;
        }
        return 1;
    }
    // \brief process events, return true if the event processed successfully
    // return false if error occurs or a quit events is received
    bool Screen::processEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                return false;
            }
        }
        return true;
    }
    void Screen::close()
    {
    }
    void Screen::UpdateRenderer()
    {
        SDL_UpdateTexture(this->m_texture, NULL, m_imageBuffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(this->m_renderer);
        SDL_RenderCopy(this->m_renderer, this->m_texture, NULL, NULL);
        SDL_RenderPresent(this->m_renderer);
    }
    void Screen::BoxBlur()
    {
        // std::memcpy(m_blurBuffer, m_imageBuffer, sizeof(Uint32) * SCREEN_HEIGHT * SCREEN_HEIGHT);
        Uint32 *tmp = m_imageBuffer;
        m_imageBuffer = m_blurBuffer;
        m_blurBuffer = tmp;
        // cout << "entering boxblur" << endl;
        for (int r = 0; r < SCREEN_HEIGHT; r++)
        {
            for (int c = 0; c < SCREEN_WIDTH; c++)
            {
                // printf("[%d, %d]\n", r, c);
                // int rTotal = 0;
                // int gTotal = 0;
                // int bTotal = 0;
                // for (int row = -1; row < 1; row++)
                // {
                //     for (int col = -1; col < 1; col++)
                //     {
                //         int currentCol = c + col;
                //         int currentRow = r + row;
                //         if (currentRow >= 0 && currentRow < SCREEN_HEIGHT && currentCol >= 0 && currentCol < SCREEN_WIDTH)
                //         {
                //             Uint32
                //         }
                //     }
                // }

                int rTotal = 0;
                int gTotal = 0;
                int bTotal = 0;
                int red = 0;
                int g = 0;
                int b = 0;
                int a = 0;
                int index;
                // top row
                index = rcToIndex(r - 1, c - 1);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                index = rcToIndex(r - 1, c);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                index = rcToIndex(r - 1, c + 1);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                //current row
                index = rcToIndex(r, c - 1);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                index = rcToIndex(r, c);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                index = rcToIndex(r, c + 1);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                // bottom row
                index = rcToIndex(r + 1, c - 1);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                index = rcToIndex(r + 1, c);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                index = rcToIndex(r + 1, c + 1);
                if (index >= 0)
                {
                    HexToRGBA(m_blurBuffer[index], red, g, b, a);
                    rTotal += red;
                    gTotal += g;
                    bTotal += b;
                }
                // printf("final rgb: [%d %d %d]\n", rTotal, gTotal, bTotal);
                unsigned char finalR = rTotal / 9;
                unsigned char finalG = gTotal / 9;
                unsigned char finalB = bTotal / 9;
                setPixelColor(rcToIndex(r, c), finalR, finalG, finalB, 255);
            }
        }
        // cout << "exiting boxblur" << endl;

        // std::memcpy(m_blurBuffer, m_imageBuffer, sizeof(Uint32) * SCREEN_HEIGHT * SCREEN_HEIGHT);
    }
    Screen::~Screen()
    {
        SDL_DestroyWindow(this->m_window);
        SDL_DestroyRenderer(this->m_renderer);
        SDL_DestroyTexture(this->m_texture);
        delete[] this->m_imageBuffer;
        delete[] this->m_blurBuffer;
    };
} // namespace myScreen