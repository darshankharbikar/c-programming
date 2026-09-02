#include <stdio.h>

int state = 7;

int my_rand(void)
{
    state = (state * 5 + 1) % 100;

    return state;
}

int main(void)
{
    printf("%d\n", my_rand());
    printf("%d\n", my_rand());
    printf("%d\n", my_rand());
    printf("%d\n", my_rand());

    return 0;
}
