#include <iostream>
#include <ctime>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
// #include <time.h>       /* time */

using namespace std;


int main (){
    srand (time(NULL));

    cout << rand() % 10 << endl;

  return 0;
}