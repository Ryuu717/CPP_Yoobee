#include <iostream>
using namespace std;
int main()
{
  cout << "Start\n";
  try {                       // start a try block
    cout << "Inside try block\n";
    cout << "Still inside try block\n";
    throw  "z";
  }
  catch (int i) {             // catch an error
    cout << "Caught an exception -- value is: ";
    cout << i << "\n";
  }
  cout << "End";
  return 0;
}
