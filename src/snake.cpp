#include "snake.h"

snake::snake(screen* scr, bool wrap)
: scr(scr), direction(0), speed(1), score(-1), alive(true), wrap(wrap)
{
    x = scr->width / 2;
    y = scr->height / 2;

    srand(time(0));

    tail.push_back(Vec2i {0, 0});
    EatFruit();
}

void snake::EatFruit(void)
{
    do{
        fruit.x = rand()%(scr->width-2)+1;
        fruit.y = rand()%(scr->height-2)+1;
    }while(IsTail(fruit.x, fruit.y) || (fruit.x == x && fruit.y == y));

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

    for(int b = 0; b < scr->height; b++)
    {
        for(int a = 0; a < scr->width; a++)
        {
            if(a == 0 || b == 0 || a == scr->width - 1 || b == scr->height - 1)
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

void snake::Input(void)
{
    switch(scr->GetKey())
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
    if(!wrap && ((x == 1 && direction == 1) || (x == scr->width - 2 && direction == 3) || (y == 1 && direction == 2) || (y == scr->height - 2 && direction == 4))){
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
            x = scr->width - 2;
        }else if(x >= scr->width - 1)
        {
            x = 1;
        }
        
        if(y <= 0)
        {
            y = scr->height - 2;
        }else if(y >= scr->height - 1)
        {
            y = 1;
        }
    }

    // Update the tail
    if(x == fruit.x && y == fruit.y) tail.push_back(Vec2i {0, 0});

    for(int i = tail.size() - 1; i > 0; i--)
    {
        tail[i] = tail[i-1];
    }
    
    tail[0] = Vec2i {x, y};
    
    if(IsTail(x, y))
        alive = false;

    if(x == fruit.x && y == fruit.y) EatFruit();
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
