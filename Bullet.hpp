#ifndef BULLET_HPP_INCLUDED
#define BULLET_HPP_INCLUDED

#include "Entity.hpp"

class Bullet : public Entity {
    public:
        Bullet();
        void update(int width,int height);
};


#endif // BULLET_HPP_INCLUDED
