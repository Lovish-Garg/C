/*
  This is a tic-tac-toe game 
*/
#include <stdio.h>
#include <stdlib.h>
#define SIZE 9 // length of the array 

// functions
void board(void);
int check_win();

// array for keeping record 
char arr[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9' };

// in mark variable I will keep 'X' and 'O' value
char mark;

int main(void)
{

  int player = 1, i = 1, choice;

  do
  {
    board();

    /*
     here I'm assigning player a number as it has value of 1 so 1 % 2 == 1
     and so player would assign the value of 1 then at last the value of the player will increment the 2 % 2 == 0 and player will get the value of 2 
    */
    player = (player % 2) ? 1 : 2;

    // simple if player % 2 == 1 then mark = O else mark = X
    mark = (player % 2) ? 'O' : 'X'; 

    printf("\nPlayer %d's turn: ", player);
    scanf("%d", &choice);

    /*
    Here the user wants to place an X or O to the desire place . Here what I'm doing is checking if that place where the user wants to place 'X' or 'O' is empty or not. If the place is empty then I will simply assign mark variable where 'X' and 'O' is stored to the array after which I can simply print it using my board function 
    */
    if (choice == 1 && arr[0] == '1')
        arr[0] = mark;
        
    else if (choice == 2 && arr[1] == '2')
        arr[1] = mark;
        
    else if (choice == 3 && arr[2] == '3')
        arr[2] = mark;
        
    else if (choice == 4 && arr[3] == '4')
        arr[3] = mark;
        
    else if (choice == 5 && arr[4] == '5')
        arr[4] = mark;
        
    else if (choice == 6 && arr[5] == '6')
        arr[5] = mark;
        
    else if (choice == 7 && arr[6] == '7')
        arr[6] = mark;
        
    else if (choice == 8 && arr[7] == '8')
        arr[7] = mark;
        
    else if (choice == 9 && arr[8] == '9')
        arr[8] = mark;
    else
    {
        printf("Invalid move !");

      // fflush function wasnot working so I used this method on my system
        while (getchar() != '\n');

        // so to pause the screen otherwise the system("clear") will clear the console
        char t = getchar();

        // as you can see before while condition below player is incrementing but I want that user hasnot properly input the value so I want the user to reinput that value.
        player--;
    }
    i = check_win();

    player++;
  }
  while (i == -1);
  // calling board funcction because if I don't do so the final result won't display to the user.
  board();

  // check check_win function for this logic
  if (i == 1)
  {
    printf("\nWinner => Player %d\n", --player);
  }
  else
  {
    printf("\nGame =>darw\n");
  }

  return 0;
}

// printing tic-tac-toe box with values 
void board(void)
{
  system("clear");
  printf("\tTic Tac Toe\n\n");
  printf("Player 1 (X)  -  Player 2 (O)\n\n\n");

  printf("     |     |     \n  %c  |  %c  |  %c\n", arr[0], arr[1], arr[2]);
  printf("_____|_____|_____\n     |     |     \n");
  
  printf("  %c  |  %c  |  %c \n", arr[3], arr[4], arr[5]);

  printf("_____|_____|_____\n     |     |     \n");
  
  printf("  %c  |  %c  |  %c \n", arr[6], arr[7], arr[8]);

  printf("     |     |     \n");
}

/*
  Here i'm returning -1 while game is in prgress.
  Returning 1 when someone has win the game.
  Returning 0 when the game is draw.
*/
int check_win()
{
  if (arr[0] == arr[1] && arr[1] == arr[2])
        return 1;
        
    else if (arr[3] == arr[4] && arr[4] == arr[5])
        return 1;
        
    else if (arr[6] == arr[7] && arr[7] == arr[8])
        return 1;
        
    else if (arr[0] == arr[3] && arr[3] == arr[6])
        return 1;
        
    else if (arr[1] == arr[4] && arr[4] == arr[7])
        return 1;
        
    else if (arr[2] == arr[5] && arr[5] == arr[8])
        return 1;
        
    else if (arr[0] == arr[4] && arr[4] == arr[8])
        return 1;
        
    else if (arr[2] == arr[4] && arr[4] == arr[6])
        return 1;
        
    else if (arr[0] != '1' && arr[1] != '2' && arr[2] != '3' &&
        arr[3] != '4' && arr[4] != '5' && arr[5] != '6' && arr[6] 
        != '7' && arr[7] != '8' && arr[8] != '9')
        return 0;
    else
        return  - 1;
}
