#include "snake.h"

snake::snake(int mapW, int mapH, bool wrap)
: mapW(mapW), mapH(mapH), direction(0), speed(1), alive(true), wrap(wrap)
{
    x = mapW / 2;
    y = mapH / 2;

    srand(time(0));

    AddTail();
    score = 0;
}

void snake::AddTail(void)
{
    do{
        fruit.x = rand()%(mapW-2)+1;
        fruit.y = rand()%(mapH-2)+1;
    }while(IsTail(fruit.x, fruit.y) || (fruit.x == x && fruit.y == y));

    tail.push_back(Vec2i {0, 0});

    score++;
}

bool snake::IsTail(int x, int y) const
{
    for(unsigned int i = 1; i < tail.size(); i++)
    {
        if(tail[i].x == x && tail[i].y == y) return true;
    }

    return false;
}

std::string snake::Draw(void) const
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
            }else if(IsTail(a, b))
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

void snake::Input(char key)
{
    switch(key)
    {
        case -1:
            break;
        case 'a':
            SetDirection(1);
            break;
        case 'w':
            SetDirection(2);
            break;
        case 'd':
            SetDirection(3);
            break;
        case 's':
            SetDirection(4);
            break;
    }
}

void snake::Update(void)
{
    if(!wrap && ((x == 1 && direction == 1) || (x == mapW - 2 && direction == 3) || (y == 1 && direction == 2) || (y == mapH - 2 && direction == 4))){
        alive = false;
        return;
    }

    // Update the head
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

    if(wrap)
    {
        if(x <= 0)
        {
            x = mapW - 2;
        }else if(x >= mapW - 1)
        {
            x = 1;
        }
        
        if(y <= 0)
        {
            y = mapH - 2;
        }else if(y >= mapH - 1)
        {
            y = 1;
        }
    }

    // Update the tail
    if(x == fruit.x && y == fruit.y) AddTail();

    for(int i = tail.size() - 1; i > 0; i--)
    {
        tail[i] = tail[i-1];
    }
    
    tail[0] = Vec2i {x, y};
    
    if(IsTail(x, y))
        alive = false;
}

/**
 * Set the snake's direction:
 * 1 = left, 2 = up, 3 = right, 4 = down
 */
void snake::SetDirection(int direction)
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
