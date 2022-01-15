#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    Zero::Game game(800, 600, "Your Mother");
    game.Run();

    return 0;
}