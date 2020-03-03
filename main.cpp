#include "screen.h"
#include "snake.h"
#include <chrono>
#include <thread>

screen scr;
snake player(50, 20);
int fps = 15;

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
        input();

        player.update();

        clear();

        scr.print(player.draw());

        std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
    }
    
    return 0;
}