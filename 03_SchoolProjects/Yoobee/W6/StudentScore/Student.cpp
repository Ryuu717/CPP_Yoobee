#include <iostream>
using namespace std;


class student {
    string name;
    int m1, m2, m3;
    string result;

public:
    void read_data();
    void display_marksheet();
};

void student::read_data(){
    try {
        cout << "Enter student name : ";
        cin >> name;
        cout << "Enter M1 : ";
        cin >> m1;
        cout << "Enter M2 : ";
        cin >> m2;
        cout << "Enter M3 : ";
        cin >> m3;

        if (m1 <= 0 || m1 > 100) throw 101;
        if (m2 <= 0 || m2 > 100) throw 101;
        if (m3 <= 0 || m3 > 100) throw 101;
    } catch (...) {		//catch any errors
        throw 101;  //  rethrow 
    }
}

void student::display_marksheet()
{
    cout << "\n\n Mark sheet \n";
    cout << " ********************\n";
    cout << "\n student name : " << name;
    cout << "\n M1 " << m1;

    if (m1 >= 50){
        cout << " Achieved \n";
    } else {
        cout << " Not Achieved \n";
    }
    cout << "\n M2 " << m2;

    if (m2 >= 50){
        cout << " Achieved \n";
	} else {
        cout << " Not Achieved \n";
    }
	cout << "\n M3 " << m3;

    if (m3 >= 50){
        cout << " Achieved \n";
    } else {
        cout << " Not Achieved \n";
    }

    if (m1 >= 50 && m2 >= 50 && m3 >= 50){
        result = "Pass";
    } else {
        result = "Fail";
    }
    cout << "\n Result  :" << result;
}

int main(){
    student s1;

    try {
        s1.read_data();
        s1.display_marksheet();
    } catch (int e) {
        cout << "\n Error Code :" << e << " Null or Out of range";
    }
    cout << "\n\n";

    return 0;
}

