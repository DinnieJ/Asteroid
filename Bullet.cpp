#include "Bullet.hpp"


Bullet::Bullet(){
    name="bullet";
}

void Bullet::update(int width,int height){
    dx = cos(angle*DEG_TO_RAD)*6;
    dy = sin(angle*DEG_TO_RAD)*6;
    x += dx;
    y += dy;

    if(x>width || x<0 || y>height || y<0){
        life = 0;
    }
}


