void my_putchar(char c);
void my_putcharspace(char *str)

{
    int j;

    j = 0;
    while (str[j] != '\0')
    {
        my_putchar(str[j]);
        j++;
    }
}
