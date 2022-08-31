// This example will not work.
#include <iostream>
using namespace std;

int main() {
  int myarray[10];
  try{
    for(int i = 0; i <= 11; i++){
      // cout << i << "\n";

      if(i > 9){
        throw 101;
      }
      myarray[i] = i;
    }
  } catch (int j){
    cout << "Exception: Out of range\n"; 
  }


  //output the array
  for (int i = 0; i < size(myarray) ; i++){
    cout << myarray[i] << "\n";
  }

  return 0;
}
