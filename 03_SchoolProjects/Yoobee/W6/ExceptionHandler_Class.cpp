// Catching class type exceptions.
#include <iostream>
#include <cstring>
using namespace std;

class MyException {
public:
	string str_what;
	int what;

	MyException(){ 
        str_what =""; 
        what = 0; 
    }

	MyException(string s, int e) {
		str_what = s;
		what = e;
	}
};

int main(){
	int i;
	try {
		cout << "Enter a positive number: ";
		cin >> i;

		if (i < 0) throw MyException("Not Positive", i);		
	}
	catch (MyException e) { // catch an error
		cout << e.str_what << ": ";
		cout << e.what << "\n";
	}
	return 0;
}
