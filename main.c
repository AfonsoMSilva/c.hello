#include<stdio.h>
#include <stdlib.h>
#include <string.h>

//*
// Make a simple tokenizer that can parse a hello would program in c and print the individual tokens along with their respective coordenates.
//*

typedef struct Location
{
  int cur;
  int row;
}Location;
struct Location loc={0, 0};

void next_char(char *source, struct Location)
  {
    printf("%c :", source[loc.cur]);
    loc.cur++;
    printf("%d\n", loc.cur);
  }



int main()
{
  // Open the file
  FILE *fptr;
  fptr = fopen("test.c", "r");
  if (NULL == fptr)
    {
      printf("File couldn't be opened");
      return 69;
    }
  // Find the size of the file and allocate the necessary memory to source[].
fseek(fptr, 0, SEEK_END);
long fsize = ftell(fptr);
fseek(fptr, 0, SEEK_SET); 

char *source = malloc(fsize + 1);
fread(source, fsize, 1, fptr);
fclose(fptr);

source[fsize] = 0;
 int i;
 for(i = 0; i != 30; i++)
   {
     next_char(source, loc);
   }

}

/*void is_not_empty(char *source, struct Location)
{
  len = strlen(source);
  if (loc.cur != len -1)
    {
      return
    }
};

void drop_line()
{
  
};

void chop_char()
{
 
};*/


/*void next_char(char *source, )
 {
   int len = strlen(source);
   int i;
   for (i = 0; i != len; i++)
   {
     printf("%c\n", source[i]);
   }
 }

*/
