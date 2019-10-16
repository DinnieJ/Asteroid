#ifndef ENTITY_HPP_INCLUDED
#define ENTITY_HPP_INCLUDED
#pragma GCC diagnostic ignored "-fpermissive"

#include<iostream>
#include "Animation.hpp"

class Entity{
    protected:
        const float DEG_TO_RAD = 0.017453f;
    public:
        float dx;
        float dy;
        float x;
        float y;
        float r;
        Animation anim;
        float angle;
        bool life;
        std::string name;
        Entity();
        void init(Animation &a,int X,int Y,float ang=0,int radius=1);
        virtual void update(int width,int height){};
        void draw(sf::RenderWindow* window);
        virtual ~Entity(){};
};

#endif // ENTITY_HPP_INCLUDED
