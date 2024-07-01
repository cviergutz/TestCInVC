#include <stdio.h>
#include <stdlib.h>

#define SIDES 6
#define TILES_PER_SIDE 9

// Colors/Sides   0    1    2    3    4    5
char color[6] = {'W', 'R', 'B', 'O', 'G', 'Y'};

// Define structure of Rubik's cube, based on fixed center stones
// leftOf[top][front] as integer; side 9 = "Not defined"
int leftOf[6][6] = {
    {9, 4, 1, 2, 3, 9}, // Top white
    {2, 9, 5, 9, 0, 4}, // Top red
    {3, 0, 9, 5, 9, 1}, // Top blue
    {4, 9, 0, 9, 5, 2}, // Top orange
    {1, 5, 9, 0, 9, 3}, // Top green
    {9, 2, 3, 4, 1, 9}  // Top yellow
};
int opposite[6] = {5, 3, 4, 1, 2, 0};

enum hand
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
            cube[side][tile] = color[side];
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

void up(int top, int front, enum hand h)
{
    int bottom = opposite[top];
    int back = opposite[front];
    int left = leftOf[top][front];
    int right = opposite[left];

    int buffer[3];
    char sideTiles[9];

    switch (h)
    {
    case RIGHT:
        for (int i = 0; i < TILES_PER_SIDE; i++) {
            sideTiles[i] = cube[right][i];
        }

        buffer[0] = cube[front][2];
        buffer[1] = cube[front][5];
        buffer[2] = cube[front][8];

        cube[front][2] = cube[bottom][2];
        cube[front][5] = cube[bottom][5];
        cube[front][8] = cube[bottom][8];

        cube[bottom][2] = cube[back][0];
        cube[bottom][5] = cube[back][3];
        cube[bottom][8] = cube[back][6];

        cube[back][0] = cube[top][8];
        cube[back][3] = cube[top][5];
        cube[back][6] = cube[top][2];

        cube[top][2] = buffer[0];
        cube[top][5] = buffer[1];
        cube[top][8] = buffer[2];

        cube[right][0] = sideTiles[6];
        cube[right][1] = sideTiles[3];
        cube[right][2] = sideTiles[0];
        cube[right][3] = sideTiles[7];
        cube[right][5] = sideTiles[1];
        cube[right][6] = sideTiles[8];
        cube[right][7] = sideTiles[5];
        cube[right][8] = sideTiles[2];
        break;

    case LEFT:
        for (int i = 0; i < TILES_PER_SIDE; i++) {
            sideTiles[i] = cube[left][i];
        }

        buffer[0] = cube[front][0];
        buffer[1] = cube[front][3];
        buffer[2] = cube[front][6];

        cube[front][0] = cube[bottom][0];
        cube[front][3] = cube[bottom][3];
        cube[front][6] = cube[bottom][6];

        cube[bottom][0] = cube[back][2];
        cube[bottom][3] = cube[back][5];
        cube[bottom][6] = cube[back][8];

        cube[back][2] = cube[top][6];
        cube[back][5] = cube[top][3];
        cube[back][8] = cube[top][0];

        cube[top][0] = buffer[0];
        cube[top][3] = buffer[1];
        cube[top][6] = buffer[2];

        cube[left][0] = sideTiles[2];
        cube[left][1] = sideTiles[5];
        cube[left][2] = sideTiles[8];
        cube[left][3] = sideTiles[1];
        cube[left][5] = sideTiles[7];
        cube[left][6] = sideTiles[0];
        cube[left][7] = sideTiles[3];
        cube[left][8] = sideTiles[6];
        break;
    }
}

int main()
{
    initCube();
    // listCube();
    drawCube();

    printf("\nTurning right up (1):\n");
    up(0, 2, RIGHT);
    drawCube();

    printf("\nTurning right up (2):\n");
    up(0, 2, RIGHT);
    drawCube();

    printf("\nTurning right up (3):\n");
    up(0, 2, RIGHT);
    drawCube();

    printf("\nTurning right up (4):\n");
    up(0, 2, RIGHT);
    drawCube();

    printf("\nTurning left up (1):\n");
    up(0, 2, LEFT);
    drawCube();

    printf("\nTurning left up (2):\n");
    up(0, 2, LEFT);
    drawCube();

    printf("\nTurning left up (3):\n");
    up(0, 2, LEFT);
    drawCube();

    printf("\nTurning left up (4):\n");
    up(0, 2, LEFT);
    drawCube();

    return EXIT_SUCCESS;
}