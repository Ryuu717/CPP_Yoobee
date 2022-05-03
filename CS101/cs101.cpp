#include <iostream>
#include <cmath>
#include <cstdlib>
// #include <random>
#include <fstream>
using namespace std;




// void hello(string name="Tom"){
//   cout << "Hello " + name << endl;
// };


// string hi(string name="Tom"){
//   return name ;
// };


// int myFunction(int x, int y) {
//   return x + y;
// }


  // class Car{
  //   public:
  //     string name;
  //     int model;

  //     void drive(){
  //       cout << "Start" << endl;
  //     }
  // };


// class Car {   
// public:   
//   string brand;
//   string model;
//   int year; 
//   Car(string x, string y, int z) { 
//     brand = x;
//     model = y;
//     year = z;
//   }
// };


int main() {
  // string cars[] = {"Toyota", "Tesla", "BMW"};
  // // cout << cars[0] << endl;

  // int carsLength = sizeof(cars)/sizeof(*cars);

  // string carList;
  // for (int i = 0; i < carsLength; i++){
  //   cout << cars[i] << endl;
  //   carList.append(cars[i]+"\n");
  // }
  
  // hello();
  // hello("Bob");

  // cout << hi();
  // cout << hi("Bob");

  // cout << myFunction(10,11);

  // Car toyota;
  // toyota.name = "Vits";
  // toyota.model = 1;

  // cout << toyota.name << "\n";
  // cout << toyota.model << "\n";
  // toyota.drive();


  // Car carObj1("BMW", "X5", 1999);
  // Car carObj2("Ford", "Mustang", 1969);
  // cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  // cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";

  
  // ofstream MyFile("filename.txt");

  // Write to the file
  // MyFile << "Files can be tricky, but it is fun enough!";
  // cout << carList << endl;
  // MyFile << carList;

  // MyFile.close();

  // string myText;

  // ifstream MyReadFile("filename.txt");

  // while (getline (MyReadFile, myText)) {
  //   cout << myText;
  // }

  // MyReadFile.close();


  // try {
  // int age;

  // cout << "How old are you?: ";
  // cin >> age;

  // if (age >= 18) {
  //   cout << "Access granted - you are old enough. \n";
  // } else {
  //   throw (age);
  // }
  // }
  // catch (int myNum) {
  //   cout << "Access denied - You must be at least 18 years old.\n";
  //   cout << "Age is: " << myNum << endl;
  // }

  // for(int i=1; i < 30; i++){
  //   for (int j = 0; j < i; j++)
  //   {
  //     cout << "0";
  //   }
  //   cout << endl;
      
  // }

  //Task1. Write a program to calculate the total cost of 5 pens, where each pen sosts $1.5
  // cout << "Task1" << endl;
  // float penCost = 1.5;
  // int penNum = 5;
  // float totalCost = penCost * penNum;
  
  // cout << "Pen price = $"<< penCost <<endl;
  // cout << "Number = " << penNum <<endl;
  // cout << "Total cost = $" << totalCost <<endl;
  // cout << endl;



  //Task2. write a program to produce the sum of first 5 natural numbers (1+2+3+4+5)
  // cout << "Task2" << endl;
  // int sum = 0;

  // for(int i = 1; i<=5; i++){
  //   sum = sum + i;
  // }
  // cout << "1+2+3+4+5 = " << sum << endl;
  // cout << endl;



  //Task3. write a program to take the name and age of a person and give the output as follows:
  //Your name is Sheila
  //Your age is 35

  // cout << "Task3" << endl;
  // string name;
  // int age;

  // cout << "What's your name?: ";
  // cin >> name;
  // cout << "How old are you?: ";
  // cin >> age;
  // cout << endl;

  // cout << "Your name is " << name << endl;
  // cout << "Your age is " << age << endl;
  



//Task4.
  // int num;

  // cout << "Give me a number: ";
  // cin >> num;

  // for (int i=2; i<num; i++){
  //   if( num % i ==0){
  //     cout << "This is prime" << endl;;
  //   } else if ( num % 2){
  //     cout << "This is even" << endl;
  //   } else {
  //     cout << "This is odd" << endl;
  //   }
  // }


//Task5.
  // cout << 1;

  // int counter = 0;

  // for (int i=1; i<10; i=i*2){
  //   if (counter % 2 == 0){
  //     cout << " - " << i << "/" << i*2;
  //     counter++;

  //   } else {
  //     cout << " + " << i << "/" << i*2; 
  //     counter++;
  //   }
  // }

  // cout << endl;
  
  
  //Task6
  //-3, -5, 105, -23, 0, -4, 80, 0, -20, 9
  // int userNum;

  // int countZeros = 0;
  // int countPositives = 0;
  // int countNegatives = 0;

  // int i =0;

  // while(i<10){
  //   cout << "Give me a number: ";
  //   cin >> userNum;

  //   if (userNum ==0){
  //     countZeros++;

  //   } else if(userNum > 0){
  //     countPositives++;

  //   } else if(userNum < 0){
  //     countNegatives++;
  //   }
  //   i++;
  // }
  
  // cout << "countZeroes = " << countZeros <<endl;
  // cout << "countPositives = " << countPositives <<endl;
  // cout << "countNegatives = " << countNegatives <<endl;




  // task7
  cout << rand()%100 <<endl;

  int a=2, b=4, c=3;
  float d;

  cout << b*b -4*a*c << endl;
  cout << b*b - (4*a*c) << endl;
  cout << b*(b -4)*a*c << endl;

  d =(- b + sqrt (b * b - 4 * a * c) ) / (2 * a);

  // cout << d;
  cout << sqrt(-8);

  return 0;
}