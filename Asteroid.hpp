#ifndef ASTEROID_HPP_INCLUDED
#define ASTEROID_HPP_INCLUDED

#include "Entity.hpp"

class Asteroid : public Entity {
    public:
        Asteroid();
        void update(int width,int height);
};


#endif // ASTEROID_HPP_INCLUDED
