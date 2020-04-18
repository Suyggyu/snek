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

    void AddTail(void);
    bool IsTail(int x, int y) const;
    void SetDirection(int direction);
public:
    snake(int mapW, int mapH);
    std::string Draw(void) const;
    void Input(char key);
    void Update(void);
    inline bool IsAlive(void) const { return alive; }
    inline int GetScore(void) const { return score; }
};