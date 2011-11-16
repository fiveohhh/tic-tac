#include "common.h"
#include "moves.h"
#include "types.h"

// changes x and y to move computer should make.
// This assumes circle (human) always goes first
void GetComputerMove(int turn, int circs[5][2], int xs[5][2])
{

   // if humans first move was in the center
    if (circs[0][X] == 2 && circs[0][Y] == 2)
    {

        switch (turn)
        {
            case 0:
                xs[turn][X] = 1;
                xs[turn][Y] = 3;
                return;
            case 1:
                if (circs[1][X] == 3 && circs[1][Y] == 1)// human moved to opposite corner
                {
                    xs[turn][X] = 1;
                    xs[turn][Y] = 1;
                    return;
                }
                else
                {
                    GetWinningMove(turn,circs,xs);
                    if (xs[turn][X] == 0)// if a winning move was not found, look for blocking
                    {
                        GetBlockingMove(turn,circs,xs);
                    }


                    return;
                }
            case 2:
            case 3:
            case 4:
            case 5:
                GetWinningMove(turn,circs,xs);
                    if (xs[turn][X] == 0)// if a winning move was not found, look for blocking
                    {
                        GetBlockingMove(turn,circs,xs);
                    }
                return;
        }

    }

    return;
}

// assumes human goes first
void GetBlockingMove(int turn, int circs[5][2], int xs[5][2])
{
    int i;// for each page of winning moves
    int j;// for a location for each move
    int c;// for move number


    for (i = 0; i < 8; i++)
    {

      int matchCircs = 0;

      for (j = 0; j < 3; j++)
      {
          int missingMove[2];
          for (c = 0; c< 5; c++)
          {

              if (circs[c][X] == WinningCombos[i][j][X] &&
                  circs[c][Y] == WinningCombos[i][j][Y])
              {
                  matchCircs++;
              }
              else
              {
                  // else let's store the missing entry to win(the move we want to block
                  missingMove[X]= WinningCombos[i][j][X];
                  missingMove[Y]= WinningCombos[i][j][Y];

              }

          }
          if (matchCircs == 2)
          {
              // check if missing spot is taken
              // if it ismove on else, return that move
              if (CheckIfSpotIsTaken(missingMove[X],missingMove[Y],circs,xs) == 1)
              {

              }
              else
              {
                  xs[turn][X] = missingMove[X];
                  xs[turn][Y] = missingMove[Y];
                  return;
              }
          }
      }
    }
}

// assumes human goes first, populates xs[turn] if winning move is false, else exits
void GetWinningMove(int turn, int circs[5][2], int xs[5][2])
{
    int i;// for each page of winning moves
    int j;// for a location for each move
    int c;// for move number


    for (i = 0; i < 8; i++)
    {

      int matchXs = 0;

      for (j = 0; j < 3; j++)
      {
          int missingMove[2];
          for (c = 0; c< 5; c++)
          {

            int tx = WinningCombos[i][j][X];
            int ty = WinningCombos[i][j][Y];
            int ttx = xs[c][X];
            int tty = xs[c][Y];
              if (xs[c][X] == WinningCombos[i][j][X] &&
                  xs[c][Y] == WinningCombos[i][j][Y])
              {
                  matchXs++;
              }
              else
              {

                   missingMove[X]= WinningCombos[i][j][X];
                   missingMove[Y]= WinningCombos[i][j][Y];


              }

          }
          if (matchXs == 2)
          {
              // check if missing spot is taken
              // if it ismove on else, return that move
              if (CheckIfSpotIsTaken(missingMove[X],missingMove[Y],circs,xs))
              {

              }
              else
              {
                  xs[turn][X] = missingMove[X];
                  xs[turn][Y] = missingMove[Y];
                  return;
              }
          }
      }
    }
}
