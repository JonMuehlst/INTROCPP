// my first game in C++
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main ()
{
  int user;
  int pc;
  int PAPER = 1;
  int SCISSORS = 2;
  int ROCK = 3;

  cout << "Let's play a game of rock paper scissors \n";
  cout << "Type in:\n 1 for paper \n";
  cout << " 2 for scissors \n";
  cout << " 3 for rock\n\n";
  
  cin >> user;
  
  srand((unsigned)time(0));
  pc = rand() % 3 + 1;

    if( pc == user){
  	cout << "It's a tie \n";
    } 
    else if ( pc == ROCK && user == PAPER) 
    { 
        cout << "\nPaper wraps rock, you win \n"; 
    } 
    else if (pc == ROCK && user == SCISSORS) 
    { 
        cout << "\nRock smashes scissors, pc wins \n"; 
    } 
    else if (pc == PAPER && user == ROCK) 
    { 
        cout <<"\nPaper wraps rock, pc wins \n"; 
    } 
    else if ( pc == PAPER && user == SCISSORS) 
    { 
        cout <<"\nScissors cut paper, you win \n"; 
    } 
    else if ( pc == SCISSORS && user == PAPER) 
    { 
        cout << "\nScissors cut paper, pc wins \n"; 
    } 
    else if (pc == SCISSORS && user == ROCK) 
    { 
        cout << "\nRock smashes scissors, you win \n"; 
    } 

    
  return 0;
}
