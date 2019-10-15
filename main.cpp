#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.cpp"
#pragma GCC diagnostic ignored "-fpermissive"
using namespace std;

int main()
{
    Game* g = new Game();
    g->gameStart();
    return 0;
}
