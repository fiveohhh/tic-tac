#include <stdio.h>
#include "types.h"
#include "common.h"
#include "moves.h"


void DisplayGrid(int circs[5][2], int xs[5][2]);
int32_t CheckIfSpotIsTaken(int x, int y, int circs[5][2], int xs[5][2]);
int32_t CheckForWinner(int circs[5][2], int xs[5][2]);

// [z][x][y]
const int WinningCombos[8][3][2] = {1,1,1,2,1,3, 2,1,2,2,2,3, 3,1,3,2,3,3, 1,1,2,1,3,1, 1,2,2,2,3,2, 1,3,3,2,3,3, 1,1,2,2,3,3, 1,3,2,2,3,1};


int32_t main ()
   {
        int32_t xs[5][2] = {{0},{0}};
        int32_t circs[5][2] = {{0},{0}};
        int32_t winner = 0; // turns to 1 if circs wins or 2 if xs win
        int32_t turn = 0;
        printf("You are circles\n");
        while (!winner)
        {
            int32_t tempX;
            int32_t tempY;
            while(1)
            {
                printf("pick a Row(1-3)");
                scanf("%d",&tempY);

                printf("pick a column(1-3)");
                scanf("%d",&tempX);

                if (tempX > 3 || tempY > 3 || tempX < 1 || tempY < 1)
                {
                    printf("Values must be between 1 and 3\n");
                    continue;
                }
                if (CheckIfSpotIsTaken(tempX,tempY,circs,xs))
                {
                    printf("Spot is already taken, try again\n");
                }
                else
                {
                    break;
                }

            }

            // accept move
            circs[turn][X] = tempX;
            circs[turn][Y] = tempY;

            GetComputerMove(turn, circs, xs);

            turn++;



            winner = CheckForWinner(circs, xs);
            printf("win Results: %d\n",CheckForWinner(circs, xs));
            DisplayGrid(circs, xs);
        }

    if (winner == 1)
    {
        printf("You Win!");
    }
    else
    {
        printf("Sorry you lost\n");
    }
    DisplayGrid(circs, xs);

    return 0;
   }


// checks for a winner, 1 if circs is winner found 2 if xs is winner and 0 if no winner is found
int32_t CheckForWinner(int32_t circs[5][2], int32_t xs[5][2])
{
    int32_t i;// for each page of winning moves
    int32_t j;// for a location for each move
    int32_t c;// for move number


        for (i = 0; i < 8; i++)
        {
              int32_t matchX = 0;
              int32_t matchCircs = 0;

              for (j = 0; j < 3; j++)
              {

                   for (c = 0; c< 5; c++)
                   {
                        int32_t x = WinningCombos[i][j][X];
                        int32_t y = WinningCombos[i][j][Y];
                        int32_t mX =xs[c][X];
                        int32_t my = xs[c][Y];

                        if (circs[c][X] == WinningCombos[i][j][X] &&
                            circs[c][Y] == WinningCombos[i][j][Y])
                        {
                            matchCircs++;
                        }

                        if (xs[c][X] == WinningCombos[i][j][Y] &&
                            xs[c][Y] == WinningCombos[i][j][X])
                        {
                            matchX++;
                        }


                  }


              }
              if (matchCircs == 3)
                        {
                            return 1;
                        }
                        else if (matchX == 3)
                        {
                            return 2;
                        }

        }

    return 0;
}

// returns 0 if array doesn't contain the value else returns the zero based index number of the
// first occurance of value
int32_t ArrayContainsValue(int32_t * array, int32_t arrayLength, int32_t value)
{
    int32_t i;
    for(i = 0; i < arrayLength; i++)
    {
        if (*(array + 1) == value)
        {
            return i;
        }
    }
    return 0;
}

// returns 1 if a circle has the spot, 2 if an X, or 0 if neither
int32_t CheckIfSpotIsTaken(int32_t x, int32_t y, int32_t circs[5][2], int32_t xs[5][2])
{
    int32_t i;

    for (i = 0; i < 5; i++)
    {
        if (circs[i][X] == x && circs[i][Y] == y)
        {
            return 1;
        }
    }

    for (i = 0; i < 5; i++)
    {
        if (xs[i][X] == x && xs[i][Y] == y)
        {
            return 2;
        }
    }

    return 0;
}

// displays a tic-tac-toe grid that with the x and y positions of circles and x's filled in
void DisplayGrid(int32_t circs[5][2], int32_t xs[5][2])
{

    char lineOne[] = " | | \n";
    char horizLine[] = "-----\n";
    char lineTwo[] = " | | \n";
    char lineThree[] = " | | \n";

    int32_t i;

        for (i = 0; i < 5; i++)
        {
            int32_t xLoc;
            int32_t yLoc;
            xLoc = circs[i][X];
            yLoc = circs[i][Y];
            switch (yLoc)
            {
                case 1:
                    if (xLoc == 1)
                    {
                        lineOne[0] = 'O';
                    }
                    else if (xLoc == 2)
                    {
                        lineOne[2] = 'O';
                    }
                    else if (xLoc == 3)
                    {
                        lineOne[4] = 'O';
                    }
                    break;

                    case 2:
                    if (xLoc == 1)
                    {
                        lineTwo[0] = 'O';
                    }
                    else if (xLoc == 2)
                    {
                        lineTwo[2] = 'O';
                    }
                    else if (xLoc == 3)
                    {
                        lineTwo[4] = 'O';
                    }
                    break;

                    case 3:
                    if (xLoc == 1)
                    {
                        lineThree[0] = 'O';
                    }
                    else if (xLoc == 2)
                    {
                        lineThree[2] = 'O';
                    }
                    else if (xLoc == 3)
                    {
                        lineThree[4] = 'O';
                    }
                    break;
            }
        }

        for (i = 0; i < 5; i++)
        {
            int32_t xLoc;
            int32_t yLoc;
            xLoc = xs[i][X];
            yLoc = xs[i][Y];
            switch (yLoc)
            {
                case 1:
                    if (xLoc == 1)
                    {
                        lineOne[0] = 'X';
                    }
                    else if (xLoc == 2)
                    {
                        lineOne[2] = 'X';
                    }
                    else if (xLoc == 3)
                    {
                        lineOne[4] = 'X';
                    }
                    break;

                    case 2:
                    if (xLoc == 1)
                    {
                        lineTwo[0] = 'X';
                    }
                    else if (xLoc == 2)
                    {
                        lineTwo[2] = 'X';
                    }
                    else if (xLoc == 3)
                    {
                        lineTwo[4] = 'X';
                    }
                    break;

                    case 3:
                    if (xLoc == 1)
                    {
                        lineThree[0] = 'X';
                    }
                    else if (xLoc == 2)
                    {
                        lineThree[2] = 'X';
                    }
                    else if (xLoc == 3)
                    {
                        lineThree[4] = 'X';
                    }
                    break;
            }
        }


        printf(lineOne);
        printf(horizLine);
        printf(lineTwo);
        printf(horizLine);
        printf(lineThree);

        return;

}
