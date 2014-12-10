// i\o practive in C++
#include <iostream>
using namespace std;

int main ()
{
  int userOneOmelettes;
  int userTwoOmelettes;
  int userThreeOmelettes;
  int userFourOmelettes;
  int userFiveOmelettes;

  cout << "Enter the number of omelettes eaten by user one \n";
  cin >> userOneOmelettes;
  
  cout << "Enter the number of omelettes eaten by user two \n";
  cin >> userTwoOmelettes;

  cout << "Enter the number of omelettes eaten by user three \n";
  cin >> userThreeOmelettes;

  cout << "Enter the number of omelettes eaten by user four \n";
  cin >> userFourOmelettes;

  cout << "Enter the number of omelettes eaten by user five \n";
  cin >> userFiveOmelettes;

  cout << "User one ate " << userOneOmelettes << " omelettes \n";

  cout << "User two ate " << userTwoOmelettes << " omelettes \n";
  
  cout << "User three ate " << userThreeOmelettes << " omelettes \n";

  cout << "User four ate " << userFourOmelettes << " omelettes \n";

  cout << "User five ate " << userFiveOmelettes << " omelettes \n";

  return 0;
}
