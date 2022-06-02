#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
#include <stdint.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
char *test;

void my_putstr_(char *str);
void my_putchar(char c);
int my_putcharspace(char *str);
void my_putnbr(int n);
void my_putstr(char *str);

int i = 0;
int j = 1;

int max = 0;

char cwd[PATH_MAX];
void LS_r()
{

   char **array = malloc(sizeof(char *) * 500);

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

         if (dp->d_name[0] != '.')
         {
            max++;
            i++;
            test = dp->d_name;
            array[i] = test;

            my_putstr(array[i]);
         }

         if (((array[i]) = "\0"))
         {
            my_putstr(array[max]);
            max--;
         }
      }
   }
}