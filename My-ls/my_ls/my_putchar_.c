void my_putchar(char c);

void my_putstr_(char *str)
{
    int j;

    j = 0;
    while (str[j] != '\0')
    {
        my_putchar(str[j]);
        j++;
    }
    my_putchar(' ');
    my_putchar(' ');
}