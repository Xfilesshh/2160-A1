//NAME: Natasha Wagner
//STUDENT NUMBER: 7747861
//COURSE: COMP 2160, SECTION A01
//INSTRUCTOR: FRANKLIN BRISTOW
//ASSIGNMENT: Assignment 1, Question 1

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * extractWord(char input[], int number, char newString[]){
  int element = 0;
  int copyto = 0;
  int i = 0;
  int c = 0;

  while(number-1 > element){
 
    if(isspace(input[i])){
      element++;
    }

  i++;
  }
  copyto = i;
  while(isspace(input[copyto]) == 0){
  copyto++;
  }
  copyto = copyto - i;
  for(c = 0; c < copyto; c++){
  newString[c] = input[i];
  i++;
  }
  newString[c] = '\0';
  return newString;
 
  }

int main( int argc, char *argv[] )
{
 int element = 0;
 const int MAX_CHARS = 500;
char line[MAX_CHARS];
char *word; 
char string[10];

word = fgets(line, MAX_CHARS, stdin);
while (word != NULL)
{
if(isspace(line[0]) == 0){
fscanf(stdin, "%d", &element);
printf("Read line: \"%s\", extracting word [%d]\n", line, element);
printf("Word #%d is: %s\n\n", element, extractWord(line, element, string));
} 
word = fgets(line, MAX_CHARS, stdin);
  } 
  printf("\nProgram completed normally.\n");
  return EXIT_SUCCESS;
}