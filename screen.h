#pragma once

#include <ncurses.h>
#include <string>

struct screen
{
    screen();
    ~screen();
    void print(std::string message);
    bool kbhit();
    char getkey();
};