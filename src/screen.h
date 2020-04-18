#pragma once

#ifdef unix
# include <ncurses.h>
# include <chrono>
# include <thread>
#elif defined(_WIN32) || defined(WIN32)
# include <iostream>
# include <conio.h>
# include <Windows.h>
#endif

#include <string>

struct screen
{
    screen(int width, int height);
    ~screen(void);
    void Sleep(int milliseconds) const;
    void Clear(void) const;
    void Print(const std::string& message) const;
    char GetKey(void) const;
};