#include "snake.h"

snake::snake(int mapW, int mapH)
: mapW(mapW), mapH(mapH)
{
    x = mapW / 2;
    y = mapH / 2;
}

std::string snake::draw() const
{
    std::string image;

    for(int b = 0; b < mapH; b++)
    {
        for(int a = 0; a < mapW; a++)
        {
            if(a == 0 || b == 0 || a == mapW - 1 || b == mapH - 1)
            {
                image += '#';
            }else if(a == x && b == y)
            {
                image += 'O';
            }else{
                image += ' ';
            }
        }
        image += '\n';
    }

    return image;
}

void snake::update()
{
    x += 1;
    y += 1;
}