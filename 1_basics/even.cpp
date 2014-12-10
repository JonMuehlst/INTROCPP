// Determine whether the user input is an even or an odd number
#include <iostream>
using namespace std;

int main () {
  int num;

  cout << "Enter a number \n";
  cin >> num;
  
  if(num % 2 == 0){
  	cout << "The number is even \n";
  } else {  
  	cout << "The number is odd \n";
  }
  return 0;
}
