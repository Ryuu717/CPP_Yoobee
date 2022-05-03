#include <iostream>
#include <cmath>
using namespace std;


// 1. string-----------------------------------------------
//
// int main() {
//   string name = "Good morning";
  
//   cout << name.length() << endl;
//   cout << name.find("mo") << endl;
//   cout << name.substr(5,4) << endl;

//   return 0;
// }


// 2. math-----------------------------------------------
// int main() {
//   int num1 = 1 ;
//   float num2 = 1.5 ;
//   double num3 = 1.55 ;

//   cout << num1 + num2 << endl;
//   cout << pow(2,8) << endl;
//   cout << sqrt(25) << endl;
//   cout << round(1.5) << endl;
//   cout << ceil(1.5) << endl;
//   cout << floor(1.5) << endl;
//   cout << fmax(2, 10) << endl;

//   return 0;
// }


// 3. input-----------------------------------------------
// int main() {
//   string name;
  
//   cout << "Wha's your name: ";
//   cin >>name;
//   // getline(cin, name);
//   cout << "Hello" <<" "<< name <<endl;
  
//   return 0;
// }


// 4. math2-----------------------------------------------
// int main() {
//   double num1, num2;

//   cout << "Enter first number: " << endl;
//   cin >> num1;

//   cout << "Enter second number: " << endl;
//   cin >> num2;

//   cout << num1 + num2 << endl;
  
//   return 0;
// }


int main() {
  // string cars[] = {"Volvo", "BMW", "Ford", "Mazda", "Tesla"};

  // for(int i=0; i < 5; i++){
  //   cout << cars[i] << endl;
  // }

  string food = "Pizza";
  cout << &food << endl;
  cout << *&food << endl;
  
  return 0;
}

