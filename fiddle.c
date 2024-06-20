// First testing program to fiddle with
#include <stdio.h>
#include <stdlib.h>

/// @brief Returns the Fibonacci number with base k
/// @param k Calculate the k-th Fibonaccci number
/// @return The k-th Fibonacci number
int fibonacci(int k) {
    if (k < 2) return 1;
    return fibonacci(k-1)+fibonacci(k-2);    
}

int main() {

    typedef struct {
        int x;
        int y;
    } point;

    point *p = malloc(sizeof(point));

    p->x=10;
    p->y=20;

    printf("Coordinates: (%d,%d)\n",p->x,p->y);

    for (int i = 0; i  < 10; i++)
    {
        printf("Fibo(%d) = %d\n", i, fibonacci(i));
    }
    
    
    free(p);
}