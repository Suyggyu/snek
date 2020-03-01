#include "screen.h"
#include "snake.h"
#include <chrono>
#include <thread>
#include <iostream>

screen scr;
snake player(50, 20);
bool running;
int fps;

void init()
{
    running = true;
    fps = 10;
}

void input()
{
    char key = scr.getkey();

    switch(key)
    {
        case 'q':
            running = false;
            break;
    }
}

int main(int argc, const char** argv)
{  
    init();

    while(running)
    {
        clear();

        scr.print(player.draw());

        player.update();

        input();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000/fps));
    }
    

    return 0;
}