#include "screen.h"

#ifdef unix
screen::screen(int width, int height)
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, 1);
}

screen::~screen(void)
{
    nocbreak();
    echo();
    endwin();
    nodelay(stdscr, 0);
}

void screen::Print(std::string message)
{
    printw(message.c_str());
    refresh();    
}

char screen::GetKey(void)
{
    char ch = getch();

    if(ch != ERR)
    {
        return ch;
    }else{
        return -1;
    }
}

#elif defined(_WIN32) || defined(WIN32)

screen::screen(int width, int height)
{
    std::string resize_command = "mode con:cols=" + std::to_string(width) + " lines=" + std::to_string(height+3);
    system(resize_command.c_str());
}

screen::~screen(void)
{
    system("mode con:cols=120 lines=35");
}

char screen::GetKey(void)
{
    if(_kbhit())
        return _getch();
    else
        return -1;
}

void screen::Print(std::string message)
{
    std::cout << message;
}

#endif