#include "snake.h"

void snake::addTail()
{
    do{
        fruit.x = rand()%(mapW-2)+1;
        fruit.y = rand()%(mapH-2)+1;
    }while(isTail(fruit.x, fruit.y));

    tail.push_back(Int2 {0, 0});
}

snake::snake(int mapW, int mapH)
: mapW(mapW), mapH(mapH), direction(0), speed(1), score(0), alive(true)
{
    x = mapW / 2;
    y = mapH / 2;

    srand(time(0));

    addTail();
}

bool snake::isTail(int x, int y) const
{
    for(unsigned int i = 1; i < tail.size(); i++)
    {
        if(tail[i].x == x && tail[i].y == y) return true;
    }

    return false;
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
            }else if(isTail(a, b))
            {
                image += 'o';
            }else{
                image += ' ';
            }
            
        }
        image += '\n';
    }

    image += "\nScore: " + std::to_string(score) + "\n";

    return image;
}

void snake::update()
{

    for(int i = tail.size() - 1; i > 0; i--)
    {
        tail[i] = tail[i-1];
    }

    switch(direction)
    {
        case 1:
            if(x <= 1)
            {
                alive = false;
                return;
            }

            x -= speed;
            break;
        case 3:
            if(x >= mapW - 2)
            {
                alive = false;
                return;
            }

            x += speed;
            break;
        case 2:
            if(y <= 1)
            {
                alive = false;
                return;
            }

            y -= speed;
            break;
        case 4:
            if(y >= mapH - 2)
            {
                alive = false;
                return;
            }
            
            y += speed;
            break;
    }

    
    tail[0] = Int2 {x, y};

    if(x == fruit.x && y == fruit.y)
    {
        addTail();
        score++;
    }

    if(isTail(x, y) || x <= 0 || y <= 0 || x >= mapW - 1 || y >= mapH - 1)
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
