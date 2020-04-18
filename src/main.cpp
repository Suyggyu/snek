#include "screen.h"
#include "snake.h"
#include <string.h>
#include <stdio.h>

int main(int argc, const char **argv)
{  
    int mapW = 50, mapH = 25;
    int fps = 15;

    if(argc >= 2)
    {
        for(int i = 1; i < argc; i++)
        {
            if(!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h"))
            {
                printf("Usage: %s [OPTION]...\n\n", argv[0]);
                printf("Arguments:\n");
                printf("%-30s set the game's frames per second (the default is %d)\n", "--fps [VALUE]", fps);
                printf("%-30s set the game's map width/height (by default the map is %dx%d)\n", "--mapw, --maph [VALUE]", mapW, mapH);
                exit(EXIT_SUCCESS);
            }else if(!strcmp(argv[i], "--fps"))
            {
                if(argc <= i+1)
                {
                    printf("You need to provide a value for the fps\n");
                    exit(EXIT_SUCCESS);
                }

                fps = atoi(argv[i+1]);
                i++;
            }else if(!strcmp(argv[i], "--mapw"))
            {
                if(argc <= i+1)
                {
                    printf("You need to provide a value for the map width\n");
                    exit(EXIT_SUCCESS);
                }

                mapW = atoi(argv[i+1]);
                i++;
            }else if(!strcmp(argv[i], "--maph"))
            {
                if(argc <= i+1)
                {
                    printf("You need to provide a value for the map height\n");
                    exit(EXIT_SUCCESS);
                }

                mapH = atoi(argv[i+1]);
                i++;
            }else{
                printf("Unknown argument '%s', try %s -h\n", argv[i], argv[0]);
                exit(EXIT_SUCCESS);
            }
        }
    }

    screen scr(mapW, mapH);
    snake player(mapW, mapH);

    while(player.IsAlive())
    {
        player.Input(scr.GetKey());

        player.Update();

        scr.Clear();

        scr.Print(player.Draw());

        scr.Sleep(1000/fps);
    }

    scr.Sleep(2000);

    return 0;
}