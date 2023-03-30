// Harshini Oruganti
// COP3502H Spring 2021

#include "SneakyRooks.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Determines whether the rooks on a boardSize x boardSize chess board can attack one another
// Returns 1 if all the rooks are "safe", returns 0 otherwise
int allTheRooksAreSafe(char **rookStrings, int numRooks, int boardSize)
{
    Coordinate coord;
    int *rows = calloc(boardSize, sizeof(int));
    int *cols = calloc(boardSize, sizeof(int));
    int i, j, returnval = 1;

    for (i = 0; i < numRooks; i++)
    {
        parseCoordinateString(rookStrings[i], &coord);

        // two rooks in the same row can attack eachother 
        if (rows[coord.row - 1] == 0)
        {
            rows[coord.row - 1] = 1;
        }
        else
        {
            returnval = 0;
            break;
        }

        // two rooks in the same column can attack eachother
        if (cols[coord.col - 1] == 0)
        {
            cols[coord.col - 1] = 1;
        }
        else
        {
            returnval = 0;
            break;
        }
    }

    free(rows);
    free(cols);

    return returnval;
}

// Converts base26 column coordinate into decimal
int toBase26(char *str)
{
    int i, length = strlen(str), result = 0;

    for (i = 0; i < length; i++)
    {
        result *= 26;
        result += ((str[i] - 'a') + 1);
    }

    return result;
}

// Converts coordinate information of string into Coordinate struct
void parseCoordinateString(char *rookString, Coordinate *rookCoordinate)
{
    char *column, *row;
    int i, j = 0, countCol = 0, countRow = 0;

    // calculating column coordinate

    // counts number of alphabetic characters in column part of coordinate
    for (i = 0; i < strlen(rookString); i++)
    {
        if(isalpha(rookString[i]))
          countCol++;
        else
          break;
    }

    column = malloc(sizeof(char) * (countCol + 1));

    // places column part of rookString in separate string
    for (i = 0; i < countCol; i++)
    {
          column[i] = rookString[i];
    }

    column[countCol] = '\0';

    rookCoordinate->col = toBase26(column);


    //calculating row coordinate

    // counts number of number character in row part of coordinate
    for (i = countCol; i < strlen(rookString); i++)
    {
        if(isdigit(rookString[i]))
          countRow++;
        else
          break;
    }

    row = malloc(sizeof(char) * (countRow + 1));

    // places row part of rookString in separate string to convert into int
    for (i = countCol; i < strlen(rookString); i++)
    {
        if(isdigit(rookString[i]))
        {
            row[j++] = rookString[i];
        }
        else
        {
            printf("Error line 112\n");
        }
    }

    row[countRow] = '\0';

    rookCoordinate->row = atoi(row);

    free(row);
    free(column);
}

// Rating difficulty on a scale of 1.0 to 5.0
double difficultyRating(void)
{
    return 2.7;
}

// Hours spent on programming assignment
double hoursSpent(void)
{
    return 2.5;
}
