#include "screen.h"
#include "snake.h"

#ifdef unix
    #include <chrono>
    #include <thread>
    #define CLEAR clear();
    #define SLEEP(x) std::this_thread::sleep_for(std::chrono::milliseconds(x));
#elif defined(_WIN32) || defined(WIN32)
    #include <Windows.h>
    #define CLEAR 
    #define SLEEP(x) Sleep(x);
#endif

int mapW = 50, mapH = 25;
screen scr(mapW, mapH);
snake player(mapW, mapH);
int fps = 15;

void input()
{
    char key = scr.GetKey();

    switch(key)
    {
        case -1:
            break;
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

int main(void)
{  
    while(player.is_alive())
    {
        input();

        player.update();

        CLEAR

        scr.Print(player.draw());

        SLEEP(1000/fps)
    }

    SLEEP(1000)
    
    return 0;
}
