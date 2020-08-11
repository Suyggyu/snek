#ifndef _SNAKE_H
#define _SNAKE_H

#include <string>
#include <vector>
#include <random>
#include <time.h>
#include "screen.h"

struct Vec2i
{
    int x, y;
};

class snake
{
    screen* scr;
    int x, y, direction, speed, score;
    bool alive, wrap;
    std::vector<Vec2i> tail;
    Vec2i fruit;

    void EatFruit(void);
    bool IsTail(int x, int y) const;
    void SetDirection(int direction);
public:
    snake(screen* scr, bool wrap);
    std::string Draw(void) const;
    void Input(void);
    void Update(void);
    inline bool IsAlive(void) const { return alive; };
    inline int GetScore(void) const { return score; };
};

#endif