#pragma once

#include <string>
#include <vector>
#include <random>
#include <time.h>

struct Int2
{
    int x, y;
};

class snake
{
    const int mapW, mapH;
    int x, y, direction, speed, score;
    bool alive;
    std::vector<Int2> tail;
    Int2 fruit;

    void addTail();
    bool isTail(int x, int y) const;
public:
    snake(int mapW, int mapH);
    std::string draw() const;
    void set_direction(int direction);
    void update();
    inline bool is_alive() const { return alive; };
};