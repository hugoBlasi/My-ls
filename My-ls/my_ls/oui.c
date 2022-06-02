#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "my_putchar.c"
#include "my_strcmp.c"
#include "my_strcpy.c"

char *file;
char cwd[PATH_MAX];

int main(int argc, char *argv[])
{

    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'A')
            {
                LS_A();
            }
            if (argv[i][1] == 'a')
            {
                LS_a();
            }
        }
    }

    if (argc == 1)
    {
        LS();
    }
}

char *ps;
char **ppfile;
char *pfile;

void LS()
{
    ps = malloc(100 * sizeof(char));
    file = malloc(100 * sizeof(char));
    ppfile = malloc(100 * sizeof(char));
    pfile = malloc(100 * sizeof(char));
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
            int i, j, n;
            n = 100;
            // char s[PATH_MAX];
            // char *ps = s;
            // malloc(sizeof(s));

            // file = dp->d_name;
            // ppfile = &file;

            // for(i=0;i<n;i++){
            //     for(j=i+1;j<n;j++){
            //         if(my_strcmp(file[i],file[j])>0){
            //             my_strcpy(ps,file[i]);
            //             my_strcpy(file[i],file[j]);
            //             my_strcpy(file[j],ps);
            //         }
            //     }
            // }
            // pfile = &**ppfile;
            // my_putstr(pfile);
            // char a;
            // a = 'a';
            // for ( a = 'a'; a < 'z'+1; a++)
            // {
            //      if (dp->d_name[0] == a)
            // {
            //     a++;
            //     my_putstr(dp->d_name);
            // }

            // }
        }
        closedir(dir);
    }
    else
    {
        my_putstr("Current directory doesn't exist");
    }
}
// void LS_r()
// {
//     if (getcwd(cwd, sizeof(cwd)) != NULL)
//     {
//         struct dirent *dp;
//         DIR *dir = opendir(cwd);
//         if (!dir)
//         {
//             my_putstr("Current directory doesn't exist");
//         }
//         while ((dp = readdir(dir)) != NULL)
//         {
//             file = dp->d_name;
//             if (file[0] != '.')
//             {
//                 my_putstr(file);
//             }
//         }
//         closedir(dir);
//     }
//     else
//     {
//         my_putstr("Current directory doesn't exist");
//     }
// }