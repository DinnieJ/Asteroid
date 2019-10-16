#ifndef PLAYER_HPP_INCLUDED
#define PLAYER_HPP_INCLUDED

#include "Entity.hpp"


class Player : public Entity {
    public:
        bool nitro;
        Player();
        void update(int width, int height);
};

#endif // PLAYER_HPP_INCLUDED
