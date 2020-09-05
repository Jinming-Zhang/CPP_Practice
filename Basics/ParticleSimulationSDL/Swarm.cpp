#include "Swarm.h"

Swarm::Swarm(int particleNo)
{
    m_particles = new Particle[particleNo];
    m_particleNo = particleNo;
    elapseTime = 0;
}

Swarm::~Swarm()
{
    delete[] m_particles;
}

void Swarm::update(Uint32 timePassed)
{
    for (int i = 0; i < m_particleNo; i++)
    {
        (m_particles[i]).update(timePassed - elapseTime);
    }
    elapseTime = timePassed;
}