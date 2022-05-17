#include <iostream>
using namespace std;


//funtion prototypes
void input();
void sum(int* array, int size);



//main
int main() {

    //call input function
    input();

    return 0;
}



// void sum(int array[], int size){
void sum(int* array, int size){
    float sum = 0;

    for(int i=0; i<size; i++){
        sum += *(array + i);    //*(array + i) = array[i]
    }
    cout << "================================\n";
    cout << "Total = " << sum << endl;
    cout << "================================\n";
}


void input(){
    int size;
    int array[size];
    int* p = array;

    //get array size
    cout << "\nEnter the array size: ";
    cin >> size;
    cout << "\n";

    //get array numbers from user
    for(int i=0; i<size; i++){    
        cout << "Enter the number " << i+1 << " : ";
        cin >> array[i];
    }

    //show array
    cout << "Array = [";
    for (int i=0; i<size; i++){
        if (i < size -1){
            cout << array[i] << ", ";
        } else {
            cout << array[i];       //last number don't need space
        }   
    }
    cout << "] \n\n";


    // sum(array pointer, size);
    sum(p, size);
}
