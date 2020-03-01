#include "screen.h"

screen::screen()
{
    initscr();
    noecho();
    cbreak();
    nodelay(stdscr, 1);
}

screen::~screen()
{
    nocbreak();
    echo();
    endwin();
    nodelay(stdscr, 0);
}

void screen::print(std::string message)
{
    printw(message.c_str());
    refresh();    
}

bool screen::kbhit()
{
    char ch = getch();
    if(ch != ERR)
    {
        ungetch(ch);
        return 1;
    }else{
        return 0;
    }
}

char screen::getkey()
{
    if(this->kbhit())
    {
        return getch();
    }else{
        return -1;
    }
}