#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void LS_1();
void LS_a();
void LS_A();
void LS_l();
void LS_r();
void LS();

int main(int argc, char *argv[])
{
   int opt;
   while ((opt = getopt(argc, argv, "aA1lr")) != -1)
   {
      switch (opt)
      {
      case ('a'):
         LS_a();
         break;
      case ('l'):
         LS_l();
         break;
      case ('A'):
         LS_A();
         break;
      case ('r'):
         LS_r();
         break;
      case ('1'):
         LS_1();
         break;
      }
   }
   if (argc == 1)
   {
      LS();
   }
}