#ifndef visualODEs_SYSTEM_h
    #define visualODEs_SYSTEM_h

#include "Particle.h"

class Particle_System{


public:

    Particle_System(){}

    void setup(size_t _N_particles);
    void update();
    void reset();

    size_t N_particles;


    Particle *p;
    ofVec2f a,b,c,d,e,tau;
};


#endif
