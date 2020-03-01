#include "screen.h"
#include "snake.h"
#include <chrono>
#include <thread>
#include <iostream>

screen scr;
snake player(50, 20, 1);
int fps = 20;

void input()
{
    char key = scr.getkey();

    switch(key)
    {
        case 'a':
            player.set_direction(1);
            break;
        case 'd':
            player.set_direction(3);
            break;
        case 'w':
            player.set_direction(2);
            break;
        case 's':
            player.set_direction(4);
            break;
    }
}

int main(int argc, const char** argv)
{  
    while(player.is_alive())
    {
        clear();

        scr.print(player.draw());

        player.update();

        input();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
    }
    
    return 0;
}