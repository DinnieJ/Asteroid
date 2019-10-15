#include "Entity.hpp"

Entity::Entity(){
    life = 1;
}

Entity::Entity(Animation &a,int X,int Y,float ang=0,int radius=1){
        anim = a;
        x = X;
        y = Y;
        angle = ang;
        r = radius;
}


void Entity::draw(sf::RenderWindow &window){
    anim.sprite.setPosition(x,y);
    anim.sprite.setRotation(angle+90);
    window.draw(anim.sprite);
}

