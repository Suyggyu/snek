#include "screen.h"

#ifdef unix
screen::screen(int width, int height)
: width(width), height(height)
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

void screen::Clear(void) const
{
    clear();
}

void screen::Print(const std::string& message) const
{
    printw(message.c_str());
    refresh();    
}

char screen::GetKey(void) const
{
    char ch = getch();

    if(ch != ERR){
        return ch;
    }else{
        return -1;
    }
}

#elif defined(_WIN32) || defined(WIN32)

screen::screen(int width, int height)
: width(width), height(height)
{
    std::string resize_command = "mode con:cols=" + std::to_string(width+1) + " lines=" + std::to_string(height+3);
    system(resize_command.c_str());
}

screen::~screen(void)
{
    system("mode con:cols=120 lines=30");
}

void screen::Clear(void) const
{
    return;
}

void screen::Print(const std::string& message) const
{
    std::cout << message;
}

char screen::GetKey(void) const
{
    if(_kbhit()){
        return _getch();
    }else{
        return -1;
    }
}

#endif
