#pragma once

#include <string>

class snake
{
    const int mapW, mapH;
    int x, y, direction, speed;
    bool alive;
public:
    snake(int mapW, int mapH, int speed);
    std::string draw() const;
    void set_direction(int direction);
    void update();
    inline int getX() const {return x;};
    inline int getY() const {return y;};
    inline bool is_alive() { return alive; };
};