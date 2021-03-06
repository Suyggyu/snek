#ifndef _SCREEN_H
#define _SCREEN_H

#ifdef unix
# include <ncurses.h>
#elif defined(_WIN32) || defined(WIN32)
# include <iostream>
# include <conio.h>
#endif

#include <string>

struct screen
{
    int width, height;

    screen(int width, int height);
    ~screen(void);
    void Clear(void) const;
    void Print(const std::string& message) const;
    char GetKey(void) const;
};

#endif