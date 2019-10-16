#include <iostream>
#include <SFML/Graphics.hpp>
#include "Game.hpp"
#pragma GCC diagnostic ignored "-fpermissive"
using namespace std;

int main()
{
    Game* g = new Game();
    g->gameStart();
    delete g;
    return 0;
}
