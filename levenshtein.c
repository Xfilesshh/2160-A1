//NAME: Natasha Wagner
//STUDENT NUMBER: 7747861
//COURSE: COMP 2160, SECTION A01
//INSTRUCTOR: FRANKLIN BRISTOW
//ASSIGNMENT: Assignment 1, Question 2

//REMARKS: This program takes two words and determines how many changes would need to be made to change the first word into the second word. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <assert.h>
#include <string.h>


int testsFailed = 0;
int testsExecuted = 0;

int minimum( int minimum, int c, int f);
int levenshtein( char s[], char t[] );
void testDistance( char *s, char *t, int expected );

    int main( int argc, char *argv[] )
{
    
         printf( "Testing typical cases.\n" );
        testDistance( "kitten", "kitten", 0 );
        testDistance( "kitten", "sitting", 3 );
        testDistance( "kitten", "mittens", 2 );
        testDistance( "balloon", "saloon", 2 );
        testDistance( "hello", "doggo", 4 );
        testDistance( "\t\thi", "\t\t\t\thi", 2 );

        printf( "\nTesting empty/edge cases.\n" );
        testDistance( "", "", 0 );
        testDistance( "hello", "", 5 );
        testDistance( "", "doggo", 5 );
        testDistance( "a", "b", 1 );
        testDistance( "b", "b", 0 );
        testDistance( " ", " ", 0 );

       printf( "\nThis might take a while...\n" );
        testDistance( "12345678901", "123456789012", 1 );   // how many chars are we looking at?

        printf( "\nThese tests will be opposite in the C version\n" );
        testDistance( "kitten", "mitten\0s", 3 );           // ????
        testDistance( "\0totally", "\0different", 9 );

        printf( "\nTotal number of tests executed: %d\n", testsExecuted );
        printf( "Number of tests passed: %d\n", (testsExecuted - testsFailed) );
        printf( "Number of tests failed: %d\n", testsFailed );

    printf("\nProgram completed normally.\n");

    return 0;
    }

    //testDistance
    //
    //PURPOSE: This method checks if the amount of changes that had to be made is equal to the expected amount. If it is, a message is printed
    //saying it passed. If it isn't, a message is printed saing it failed.
    //INPUT PARAMETERS: This function has char *s, char *t, and int expected. *s and *t are pointers to the first and second word being analyzed.
    //expected is the int that it was expected to be. It is compared to the amount that it actually took to change it. 
    //OUTPUT PARAMETERS: This function receives the int distance from levenshtein( s, t ), which is compared to the int expected.
    //
    //testDistance 
    void testDistance( char *s, char *t, int expected )
    {
        int distance = levenshtein( s, t );

        if ( distance == expected )
        {
           printf( "Passed! You can get from '%s' to '%s' in %d moves.", s, t, expected );
        }
        else
        {
            printf( "FAILED: I thought it would take %d moves, but apparently it takes %d moves to get from '%s' to '%s'.", expected, distance, s, t );
            testsFailed++;
        }

        testsExecuted++;
    }

//levenshtein
//
    //PURPOSE: This method determines how many changes need to be made to make the two words identical by recursively calling itself to find
    //all the possible solutions to distance and returning the minimum value.
    //INPUT PARAMETERS: This function has char array s and char  array t. They are the first and second word being analyzed.
    //OUTPUT PARAMETERS: This function receives int distance f
    //
    //levenshtein
  int levenshtein( char s[], char t[] )
    {
        int cost;
        int distance;
        char deleteS [15] ;
        char deleteT [15];

        if (strlen(s) == 0)
        {
            distance = strlen(t);
        }
        else if (strlen(t) == 0)
        {
            distance = strlen(s);
        }
        else
        {
            if (s[0] == t[0])
            {
                cost = 0;
            }
            else
            {
                cost = 1;
            }
    
            for(int i = 1; i <= strlen(s); i++ ){
            deleteS[i-1] = s[i];
           } 
            
      
           for(int i = 1; i <= strlen(t); i++ ){
            deleteT[i-1] = t[i];
        }

            assert(strlen(deleteS) == strlen(s) -1);
            assert(strlen(deleteT) == strlen(t) -1);

            assert(s[strlen(s)] == deleteS[strlen(deleteS)]); 
            assert(t[strlen(t)] == deleteT[strlen(deleteT)]);
   
            distance = minimum(levenshtein(deleteS, t) + 1,
                               levenshtein(s, deleteT) + 1,
                               levenshtein(deleteS, deleteT) + cost);
        }

        return distance;
    }

    int minimum( int minimum, int c, int f) 
    {
        int min = minimum;
       
        if(c < min){
        min = c;
        }
        if(f < min){
        min = f;
        }
        return min;
    }
