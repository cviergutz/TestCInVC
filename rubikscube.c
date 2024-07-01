#include <stdio.h>
#include <stdlib.h>

#define SIDES 6
#define TILES_PER_SIDE 9
char Color[6] = {'W', 'R', 'B', 'O', 'G', 'Y'};
enum Hand
{
    LEFT,
    RIGHT
};

char cube[SIDES][TILES_PER_SIDE];

void initCube()
{
    for (int side = 0; side < SIDES; side++)
    {
        for (int tile = 0; tile < TILES_PER_SIDE; tile++)
        {
            cube[side][tile] = Color[side];
        }
    }
}

void listCube()
{
    for (int side = 0; side < SIDES; side++)
    {
        printf("Side %d: ", side);
        for (int tile = 0; tile < TILES_PER_SIDE; tile++)
        {
            printf("%c ", cube[side][tile]);
        }
        printf("\n");
    }
}

void drawCube()
{
    for (int i = 0; i < 3; i++)
    {
        printf("          ");
        for (int j = 0; j < 3; j++)
            printf("%c ", cube[0][i * 3 + j]);
        printf("\n");
    }

    for (int row = 0; row < 3; row++)
    {
        for (int side = 1; side < 5; side++)
        {
            for (int col = 0; col < 3; col++)
            {
                printf("%c ", cube[side][row * 3 + col]);
            }
            printf(" ");
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++)
    {
        printf("          ");
        for (int j = 0; j < 3; j++)
            printf("%c ", cube[5][i * 3 + j]);
        printf("\n");
    }
}

void up(int top, int front, enum Hand h)
{
    
    
    
    switch (h)
    {
    case LEFT:
        char buffer[3] = {cube[front][2], cube[front][5], cube[front][8]};
        cube[front][2] = ;
        cube[front][5] = ;
        cube[front][8] = ;
        break;

    case RIGHT:
        break;
    }
}

int main()
{
    initCube();
    // listCube();
    drawCube();
    return 0;
}