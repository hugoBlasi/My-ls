void my_strcpy(char *destination, char *source)
{

    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
}
