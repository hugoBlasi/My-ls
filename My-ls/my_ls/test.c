#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void LS();
char my_strcpy(char *destination, char *source);
int my_strcmp(char *strg1, char *strg2);
void my_putchar(char c);
void my_putstr(char *str);

char cwd[PATH_MAX];

int main()
{
   LS();
}

char *test;
int z = 0;
int y = 0;
int x = 0;
int i = 0;
int j = 1;
int n = 100;
int max;
int max2;
void LS()
{
   char **reponse = malloc(sizeof(char *) * 500);
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
            n = max;
            // my_putstr(array[i]);
         }

         if (max >= 1)
         {

            for (z = 0; z < n; z++)
            {
               for (j = z + 1; j < n; j++)
               {
                  reponse[z] = malloc(sizeof(char *));
                  array[z] = malloc(sizeof(char *));
                  if (my_strcmp(array[z], array[j]) > 0)
                  {

                     my_strcpy(reponse[z], array[z]);
                     my_strcpy(array[z], array[j]);
                     my_strcpy(array[j], reponse[z]);
                  }
               }
            }
            my_putstr(array[j]);
            //  my_putstr(array[z]);
         }
      }
   }
}