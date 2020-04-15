#pragma once

#ifdef unix
    #include <ncurses.h>
#elif defined(_WIN32) || defined(WIN32)
    #include <iostream>
    #include <conio.h>
    #include <Windows.h>
#endif

#include <string>

struct screen
{
    screen(int width, int height);
    ~screen(void);
    void Print(std::string message);
    char GetKey(void);
};