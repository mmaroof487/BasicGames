#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>

using namespace std;

void rps();
void ht();
void ng();
void tt();

int main()
{
  int choice, number;
  char exit;

  cout << endl
       << "**** Games ****" << endl
       << "1. Rock-Paper-Scissor" << endl
       << "2. Head-Tails" << endl
       << "3. Number Guessing Game" << endl
       << "4. Tic-Tac-Toe Game" << endl
       << endl
       << "Enter your Choice: ";
  cin >> choice;

  switch (choice)
  {
  case 1:
    rps();
    break;
  case 2:
    ht();
    break;
  case 3:
    ng();
    break;
  case 4:
    tt();
    break;
  default:
    cout << "Invalid Input!";
  }
  cout << endl
       << endl
       << "Press any key and enter to continue: ";
  cin >> exit;
  main();
}

// ROCK-PAPER-SCISSOR

char inputUser();
int getComputerChoice(string option[]);
void result(int comp, char user);

void rps()
{
  char userChoice;
  string options[] = {"Rock", "Paper", "Scissor"};

  cout << endl
       << "**** Rock Paper Scissor Game ****" << endl
       << "*********************************" << endl;

  userChoice = inputUser();
  int number = getComputerChoice(options);
  result(number, userChoice);
}

char inputUser()
{
  char userChoice, cap;
  cout << endl
       << "Enter Your Choice(r/p/s): ";
  cin >> userChoice;
  cap = toupper(userChoice);
  cout << endl;
  switch (userChoice)
  {
  case 'R':
    cout << "Your choice: Rock.";
    break;
  case 'P':
    cout << "Your choice: Paper.";
    break;
  case 'S':
    cout << "Your choice: Scissor.";
    break;
  default:
    cout << "Invalid input";
  };
  cout << endl;
  return cap;
}

int getComputerChoice(string option[])
{
  srand(time(nullptr));
  int number = rand() % 3;

  cout << "Computer Choice: " << option[number] << "." << endl;
  return number;
}

void result(int comp, char user)
{
  cout << endl;
  switch (user)
  {
  case 'R':
    if (comp == 0)
    {
      cout << "It was a Draw.";
    }
    else if (comp == 1)
    {
      cout << "You Lost...";
    }
    else
    {
      cout << "You Won!";
    }
    break;
  case 'P':
    if (comp == 0)
    {
      cout << "You Won!";
    }
    else if (comp == 1)
    {
      cout << "It was a Draw.";
    }
    else
    {
      cout << "You Lost...";
    }
    break;
  case 'S':
    if (comp == 0)
    {
      cout << "You Lost...";
    }
    else if (comp == 1)
    {
      cout << "You Won!";
    }
    else
    {
      cout << "It was a Draw.";
    }
    break;
  }
}

// HEAD-TAIL

void ht()
{
  string guess, heta[] = {"head", "tail"};
  int num, number;
  cout << endl
       << "**** Head Tail Game ****" << endl
       << "*********************************" << endl;
  cout << endl
       << "Your guess(head/tail): ";
  cin >> guess;
  srand(time(nullptr));
  number = rand() % 2;

  if (guess == heta[0] || guess == heta[1])
  {
    if (guess == heta[number])
    {
      cout << "You Won!" << endl;
    }
    else
    {
      cout << "You Lose..." << endl;
    }
  }
  else
  {
    cout << "Invalid Input." << endl;
    ht();
  }
}

// NUMBER-GUESSING

void ng()
{
  int guess, num, tries = 0;
  cout << endl
       << "**** Number Guessing Game ****" << endl
       << "*********************************" << endl;
  cout << endl
       << "Your guess(1-100): ";
  srand(time(nullptr));
  num = rand() % 100 + 1;
retry:
  cin >> guess;
  if (guess != num)
  {
    if (guess > num)
    {
      cout << "Lower";
    }
    else
    {
      cout << "Higher";
    }
    tries++;
    cout << endl
         << endl
         << "Another guess: ";
    goto retry;
  }
  cout << endl
       << "YES! That is right. It took you " << tries << " tries" << endl;
}

// TIC-TAC-TOE

void drawBoard(char board[3][3]);
bool checkWin(char board[3][3], char player);

void tt()
{

  char board[3][3] = {{' ', ' ', ' '},
                      {' ', ' ', ' '},
                      {' ', ' ', ' '}};
  char player = 'X';
  int row, col;
  int turn;

  cout << endl
       << "Welcome to Tic-Tac-Toe!\n";

  for (turn = 0; turn < 9; turn++)
  {
    drawBoard(board);

    while (true)
    {
      cout << "Player " << player
           << ", enter row (0-2) and column (0-2): ";
      cin >> row >> col;

      if (board[row][col] != ' ' || row < 0 || row > 2 || col < 0 || col > 2)
      {
        cout << "Invalid move. Try again.\n";
      }
      else
      {
        break;
      }
    }

    board[row][col] = player;

    drawBoard(board);

    if (checkWin(board, player))
    {
      drawBoard(board);
      cout << endl
           << "Player " << player << " wins!" << endl;
      break;
    }

    player = (player == 'X') ? 'O' : 'X';
  }

  if (turn == 9 && !checkWin(board, 'X') && !checkWin(board, 'O'))
  {
    cout << endl
         << "It's a draw!" << endl;
  }
}

void drawBoard(char board[3][3])
{
  cout << "-------------\n";
  for (int i = 0; i < 3; i++)
  {
    cout << "| ";
    for (int j = 0; j < 3; j++)
    {
      cout << board[i][j] << " | ";
    }
    cout << "\n-------------\n";
  }
}

bool checkWin(char board[3][3], char player)
{
  for (int i = 0; i < 3; i++)
  {
    if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
      return true;
    if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
      return true;
  }
  if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    return true;
  if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    return true;
  return false;
}
