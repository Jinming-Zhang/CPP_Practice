#pragma once
#include "Particle.h"
#ifndef SDL_MAIN_HANDLED
#define SDL_MAIN_HANDLED
#endif
#include "SDL.h"
class Swarm
{
private:
    Particle *m_particles;
    int m_particleNo;
    Uint32 elapseTime;

public:
    Swarm();
    Swarm(int);
    Particle *const getParticle()
    {
        return m_particles;
    }
    void update(Uint32 delta);
    virtual ~Swarm();
};