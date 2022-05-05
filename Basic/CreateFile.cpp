#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;


int main() {
  string cars[] = {"Toyota", "Tesla", "BMW"};
  int carsLength = sizeof(cars)/sizeof(*cars);
  string carList;

  for (int i = 0; i < carsLength; i++){
    cout << cars[i] << endl;
    carList.append(cars[i]+"\n");
  }

  ofstream MyFile("filename.txt");

  cout << carList << endl;
  MyFile << carList;

  MyFile.close();
  return 0;
}