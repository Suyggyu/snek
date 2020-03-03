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
    int x, y, direction, speed;
    bool alive;
    std::vector<Int2> tail;
    void addTail();
    struct {int x; int y;} fruit;
public:
    snake(int mapW, int mapH);
    std::string draw() const;
    void set_direction(int direction);
    void update();
    inline bool is_alive() { return alive; };
};