// This example will not work.
#include <iostream>
#include <vector>
using namespace std;

class Stack{
// private:
  // int value;
  vector<int> list;
  static int i;

public:
  // Stack(int v = 0){
  //   value = v;
  // }

  void push(int value){
    list.push_back(value);
    i = size(list);
  }

  int pop(){
    i--;
    return list[i];
  }
};

int Stack::i;   // define static variable


int main(){
  Stack s1; 
  s1.push(11); 
  s1.push(22); 
  
  cout << "1: " << s1.pop() << endl; //22 
  cout << "2: " << s1.pop() << endl; //11
  s1.push(33); 
  s1.push(44); 
  s1.push(55); 
  s1.push(66); 
  cout << "3: " << s1.pop() << endl; //66 
  cout << "4: " << s1.pop() << endl; //55 
  cout << "5: " << s1.pop() << endl; //44 
  cout << "6: " << s1.pop() << endl; //33 

  return 0; 
}

