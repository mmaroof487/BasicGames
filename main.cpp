#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <cstring>

using namespace std;

void rps();
void ht();
void ng();

int main()
{
  int choice, number;
  char exit;

  cout << endl
       << "**** Games ****" << endl
       << "1. Rock-Paper-Scissor" << endl
       << "2. Head-Tails" << endl
       << "3. Number Guessing Game" << endl
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
  default:
    cout << "Invalid Input!";
  }
  cout << endl
       << endl
       << "Press any key and enter to continue: ";
  cin >> exit;
  main();
}

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
