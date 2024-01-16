#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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



int is_space(char *source, struct Location)
{
  if (isspace(source[loc.cur]))
    {
      return true;
    }
  else return false;
}

int is_not_empty(char *source, struct Location)
{
  int len;
  len = strlen(source);
  if (loc.cur < len)
    {
      return 1;
    }
  else return false;
}

int is_empty(char *source, struct Location)
{
  int len;
  len = strlen(source);
  if (loc.cur >= len)
    {
      return true;
    }
  else return false;
}

void drop_line(int is_not_empty(), char *source, void chop_char(), struct Location)
{
  char x;
  x = "\n";
  while (is_not_empty() && source[loc.cur] != x)
    {
    chop_char();
    }
  if (is_not_empty())
    {
      chop_char();
    }
}

void chop_char(int is_not_empty(), char *source)
{
  char x;
  if (is_not_empty())
    {
      x = source[loc.cur];
      loc.cur++;
      if (x == '\n')
	{
	  loc.row++;
	}
    }
}

void trim_left(void chop_char(), int is_not_empty(), char *source, struct Location)
{
  while(is_not_empty() && isspace(source[loc.cur]))
    {
      chop_char();
    }
}

int next_token(int is_not_empty(), char *source, void drop_line(), void trim_left(), struct Location, int is_empty())
{
  char x;
  x = "#";
  
  trim_left();
  while (is_not_empty())
    {
      if (source[loc.cur] == x)
	{
      break;
      drop_line();
      trim_left();
	}
    }
  if (is_empty())
    {
    return 69;
    }
  return 0;
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
//int i;

 void print_everything();

 return 0;

}

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
