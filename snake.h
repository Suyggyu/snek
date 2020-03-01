#pragma once

#include <string>

class snake
{
    const int mapW, mapH;
    int x, y;
public:
    snake(int mapW, int mapH);
    std::string draw() const;
    void update();
    inline int getX() const {return x;};
    inline int getY() const {return y;};
};