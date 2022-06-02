#include <stdio.h>
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int j;

    j = 0;
    while (str[j] != '\0')
    {
        my_putchar(str[j]);
        j++;
    }
    my_putchar('\n');
}
