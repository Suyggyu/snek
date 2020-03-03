#include "snake.h"

void snake::addTail()
{
    fruit.x = rand()%(mapW-2)+1;
    fruit.y = rand()%(mapH-2)+1;

    tail.push_back(Int2 {x, y});
}

snake::snake(int mapW, int mapH)
: mapW(mapW), mapH(mapH), direction(0), speed(1), alive(true)
{
    x = mapW / 2;
    y = mapH / 2;

    srand(time(0));

    addTail();
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
            }else if(a == fruit.x && b == fruit.y)
            {
                image += 'F';
            }else{
                bool isTail = false;
                for(int i = 1; i < tail.size(); i++)
                {
                    if(tail[i].x == a && tail[i].y == b)
                    {
                        image += 'o';
                        isTail = true;
                        break;
                    }
                }

                if(!isTail)
                {
                    image += ' ';
                }
            }
        }
        image += '\n';
    }

    return image;
}

void snake::update()
{
    if(x == fruit.x && y == fruit.y)
    {
        addTail();
    }

    for(int i = tail.size() - 1; i > 0; i--)
    {
        tail[i] = tail[i-1];
    }

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

    tail[0] = Int2 {x, y};

    for(int i = tail.size() - 1; i > 2; i--)
    {
        if(tail[i].x == x && tail[i].y == y)
        {
            alive = false;
            return;
        }
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