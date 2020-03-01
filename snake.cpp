#include "snake.h"

snake::snake(int mapW, int mapH, int speed)
: mapW(mapW+2), mapH(mapH+2), direction(0), speed(speed), alive(true)
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
    switch(direction)
    {
        case 1:
            x -= speed;
            break;
        case 3:
            x += speed;
            break;
        case 2:
            y -= speed;
            break;
        case 4:
            y += speed;
            break;
    }

    if(x <= 0 || y <= 0 || x >= mapW - 1 || y >= mapH - 1)
    {
        alive = false;
    }
}

/**
 * Set the snake's direction:
 * 1 = left, 2 = up, 3 = right, 4 = down
 */
void snake::set_direction(int direction)
{
    if(direction == 1 && this->direction != 3)
    {
        this->direction = 1;
    }else if(direction == 2 && this->direction != 4)
    {
        this->direction = 2;
    }else if(direction == 3 && this->direction != 1)
    {
        this->direction = 3;
    }else if(direction == 4 && this->direction != 2)
    {
        this->direction = 4;
    }
}