#ifndef _SNAKE_H
#define _SNAKE_H

#include <string>
#include <vector>
#include <random>
#include <time.h>

struct Vec2i
{
    int x, y;
};

class snake
{
    const int mapW, mapH;
    int x, y, direction, speed, score;
    bool alive, wrap;
    std::vector<Vec2i> tail;
    Vec2i fruit;

    void AddTail(void);
    bool IsTail(int x, int y) const;
    void SetDirection(int direction);
public:
    snake(int mapW, int mapH, bool wrap);
    std::string Draw(void) const;
    void Input(char key);
    void Update(void);
    inline bool IsAlive(void) const { return alive; }
    inline int GetScore(void) const { return score; }
};

#endif