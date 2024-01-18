#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

void rps();
void ht();
void ng();

int main()
{
  int choice, number;
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
  char userChoice;
  cout << endl
       << "Enter Your Choice(r/p/s): ";
  cin >> userChoice;
  cout << endl;
  switch (userChoice)
  {
  case 'r':
    cout << "Your choice: Rock.";
    break;
  case 'p':
    cout << "Your choice: Paper.";
    break;
  case 's':
    cout << "Your choice: Scissor.";
    break;
  default:
    cout << "Invalid input";
  };
  cout << endl;
  return userChoice;
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
  case 'r':
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
  case 'p':
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
  case 's':
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
  cout << endl
       << endl
       << "*********************************"
       << endl
       << endl
       << "Exiting to MainMenu." << endl;
  main();
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
      cout << "You Won!";
    }
    else
    {
      cout << "You Lose...";
    }
  }
  else
  {
    cout << "Invalid Input." << endl;
    ht();
  }

  cout << endl
       << endl
       << "*********************************"
       << endl
       << endl
       << "Exiting to MainMenu." << endl;
  main();
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
       << "YES! That is right. It took you " << tries << " tries";
  cout << endl
       << endl
       << "*********************************"
       << endl
       << endl
       << "Exiting to MainMenu." << endl;
  main();
}
