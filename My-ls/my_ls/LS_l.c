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

void my_putstr_(char *str);
void my_putchar(char c);
int my_putcharspace(char *str);
void my_putnbr(int n);
void my_putstr(char *str);

void LS_l();

size_t strftime(char *s, size_t max, const char *format, const struct tm *tm);

char *formatdate(char *str, time_t t)
{
    strftime(str, 36, " %b %d %R ", localtime(&t));
    return str;
}

void getPermissions(struct stat *st, char *permissionString)
{

    permissionString[0] = '-';
    if (S_ISDIR(st->st_mode))
    {
        permissionString[0] = 'd';
    }
    if (S_ISCHR(st->st_mode))
    {
        permissionString[0] = 'r';
    }
    if (S_ISBLK(st->st_mode))
    {
        permissionString[0] = 'b';
    }
    if (S_ISFIFO(st->st_mode))
    {
        permissionString[0] = 'p';
    }
    if (S_ISLNK(st->st_mode))
    {
        permissionString[0] = 'l';
    }
    if (S_ISSOCK(st->st_mode))
    {
        permissionString[0] = 's';
    }

    permissionString[1] = (st->st_mode & S_IRUSR) == S_IRUSR ? 'r' : '-';
    permissionString[2] = (st->st_mode & S_IWUSR) == S_IWUSR ? 'w' : '-';
    permissionString[3] = (st->st_mode & S_IXUSR) == S_IXUSR ? 'x' : '-';

    permissionString[4] = (st->st_mode & S_IRGRP) == S_IRGRP ? 'r' : '-';
    permissionString[5] = (st->st_mode & S_IWGRP) == S_IWGRP ? 'w' : '-';
    permissionString[6] = (st->st_mode & S_IXGRP) == S_IXGRP ? 'x' : '-';

    permissionString[7] = (st->st_mode & S_IROTH) == S_IROTH ? 'r' : '-';
    permissionString[8] = (st->st_mode & S_IWOTH) == S_IWOTH ? 'w' : '-';
    permissionString[9] = (st->st_mode & S_IXOTH) == S_IXOTH ? 'x' : '-';

    permissionString[10] = '\0';
}

void LS_l()
{

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        DIR *dir = opendir(cwd);
        struct dirent *dp;
        struct stat *st = malloc(sizeof(struct stat));
        char date[36];

        if (!dir)
        {
            my_putcharspace("my_ls: cannot access ");
            my_putcharspace(cwd);
            my_putcharspace(": No such file or directory");

            my_putchar('\n');
            return;
        }
        while ((dp = readdir(dir)) != NULL)
        {
            if (dp->d_name[0] != '.')
            {

                stat(dp->d_name, st);

                my_putcharspace((S_ISDIR(st->st_mode)) ? "d" : "-");
                my_putcharspace((st->st_mode & S_IRUSR) ? "r" : "-");
                my_putcharspace((st->st_mode & S_IWUSR) ? "w" : "-");
                my_putcharspace((st->st_mode & S_IXUSR) ? "x" : "-");
                my_putcharspace((st->st_mode & S_IRGRP) ? "r" : "-");
                my_putcharspace((st->st_mode & S_IWGRP) ? "w" : "-");
                my_putcharspace((st->st_mode & S_IXGRP) ? "x" : "-");
                my_putcharspace((st->st_mode & S_IROTH) ? "r" : "-");
                my_putcharspace((st->st_mode & S_IWOTH) ? "w" : "-");
                my_putcharspace((st->st_mode & S_IXOTH) ? "x" : "-");
                my_putchar(' ');
                my_putnbr(st->st_nlink);
                my_putchar(' ');
                my_putcharspace(getpwuid(st->st_uid)->pw_name);
                my_putchar(' ');
                my_putcharspace(getgrgid(st->st_gid)->gr_name);
                my_putchar(' ');
                my_putnbr(st->st_size);
                my_putcharspace(formatdate(date, st->st_mtime));
                my_putcharspace(dp->d_name);

                my_putchar('\n');
            }
        }

        closedir(dir);
    }
    else
    {
        DIR *dir = opendir(cwd);

        my_putcharspace("my_ls: cannot access ");
        my_putcharspace(cwd);
        my_putcharspace(": No such file or directory");
        return;

        closedir(dir);
    }
}
