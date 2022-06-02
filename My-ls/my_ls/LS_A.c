#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void my_putstr_(char *str);
void my_putchar(char c);
int my_putcharspace(char *str);
void my_putnbr(int n);
void my_putstr(char *str);

void LS_a()
{
    char cwd[PATH_MAX];

    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        struct dirent *dp;
        DIR *dir = opendir(cwd);
        if (!dir)
        {
            my_putstr("Current directory doesn't exist");
        }
        while ((dp = readdir(dir)) != NULL)
        {
            my_putstr(dp->d_name);
        }
        closedir(dir);
    }
    else
    {
        my_putstr("Current directory doesn't exist");
    }
}