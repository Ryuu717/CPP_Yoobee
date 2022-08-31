#include <iostream>
using namespace std;


float biggest(float priceArray[], int arraySize);
float smallest(float priceArray[], int arraySize);


int main(){
    float price[] = { 2.5, 1.2, 4.3, 5.1 };
    cout << "The biggest in the array is: " << biggest(price, 4) << endl;
    cout << "The smallest in the array is: " << smallest(price, 4) << endl;
}


float biggest(float priceArray[], int arraySize) {
    float big = 0;

    for (int i = 0; i < arraySize; i++) {
        // cout << "Price of product " << i << " is " << priceArray[i] << endl;
        if (priceArray[i] > big) {
            big = priceArray[i];
        }
    }
    return big;
}

float smallest(float priceArray[], int arraySize) {
    float small = 100;

    for (int i = 0; i < arraySize; i++) {
        // cout << "Price of product " << i << " is " << priceArray[i] << endl;
        if (priceArray[i] < small) {
            small = priceArray[i];
        }
    }
    return small;
}
