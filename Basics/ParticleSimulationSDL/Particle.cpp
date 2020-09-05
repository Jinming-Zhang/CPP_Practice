#include <stdlib.h>
#include "Particle.h"
#include <cmath>
#include "Screen.h"

using namespace std;
using namespace myScreen;
Particle::Particle()
{
    m_x = 0.5 * 8 / 6;
    m_y = 0.5;
    m_theta = ((double)rand() / RAND_MAX) * 3.1415926 * 2;
    m_Velocity = 0.1 * rand() / RAND_MAX;
    m_Velocity *= m_Velocity;
}
Particle::~Particle() {}
void Particle::update(int deltaTime)
{
    m_theta += deltaTime * 0.0001;
    m_x += m_Velocity * cos(m_theta) * deltaTime;
    m_y += m_Velocity * sin(m_theta) * deltaTime;

    // if (m_x < 0 || m_x > 1*8/6 || m_y < 0 || m_y > 1)
    // {
    //     m_x = 0.5 * 8 / 6;
    //     m_y = 0.5;
    //     m_theta = ((double)rand() / RAND_MAX) * 3.1415926 * 2;
    //     m_Velocity = 0.1 * rand() / RAND_MAX;
    //     m_Velocity *= m_Velocity;
    // }
}
