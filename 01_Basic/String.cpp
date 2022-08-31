#include <iostream>
using namespace std;


int main() {
  string name = "Good morning";
  
  cout << name.length() << endl;
  cout << name.find("mo") << endl;
  cout << name.substr(5,4) << endl;

  return 0;
}

