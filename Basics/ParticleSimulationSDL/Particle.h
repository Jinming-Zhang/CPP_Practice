#pragma once
#include <iostream>
using namespace std;

class Particle
{
public:
    double m_x, m_y, m_Velocity, m_theta;

public:
    Particle();
    virtual ~Particle();
    void update(int delta);
};