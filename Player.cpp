#include "Player.hpp"


Player::Player(){
    name = "player";
}

void Player::update(int width,int height){
    if(nitro){
        dx += cos(angle*DEG_TO_RAD)*0.15;
        dy += sin(angle*DEG_TO_RAD)*0.15;
    }else{
        dx *= 0.95;
        dy *= 0.95;
    }

    int maxSpeed = 10;
    float speed = sqrt(dx*dx + dy*dy);
    if(speed>maxSpeed){
        dx *= maxSpeed/speed;
        dy *= maxSpeed/speed;
    }
    x+=dx;
    y+=dy;
    if(x>width) x = 0;
    if(x<0) x = width;
    if(y>height) y = 0;
    if(y<0) y = height;
}
