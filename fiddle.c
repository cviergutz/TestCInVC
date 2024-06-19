#include <stdio.h>
#include <stdlib.h>

int main() {

    typedef struct {
        int x;
        int y;
    } point;

    point *p = malloc(sizeof(point));

    p->x=10;
    p->y=20;

    printf("Coordinates: (%d,%d)\n",p->x,p->y);

    free(p);
}