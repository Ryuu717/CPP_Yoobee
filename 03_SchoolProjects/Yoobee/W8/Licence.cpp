#include <iostream>
using namespace std;


class Licence{
//private
    string firstName;
    string lastName;
    int age;

public:
    Licence(string fn = "firstname", string ln = "lastname", int a = 0){
        firstName = fn;
        lastName = ln;
        age = a;
    }

    void setValue(){
        cout << "\n*********************************\n";
        cout << "Enter your information:\n";
        cout << "*********************************\n";
        cout << "First name: ";
        cin >> firstName;
        cout << "Last name: ";
        cin >> lastName;
        cout << "Age: ";
        cin >> age;
    };

    void getValue(){
        cout << "\n*********************************\n";
        cout << "Your Information:\n";
        cout << "*********************************\n";
        cout << "Name: " << firstName << " " << lastName << "\n";
        cout << "Age: " << age << "\n";
    };

    bool check(){
        bool answer;

        cout << "Are you a Lerner?(1/0): ";
        cin >> answer;

        return answer;
    };
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Learner : public Licence{
    int testScore;
    string ro;

public:
    // Learner(string fn, string ln, int a, int ts = 0, string r = " ") : Licence(fn, ln, a){
    //     testScore = ts;
    //     ro = r;
    // }
    Learner(int ts = 0, string r = " "){
        testScore = ts;
        ro = r;
    }

    void setValue(){
        cout << "\n*********************************\n";
        cout << "Enter your Learner information:\n";
        cout << "*********************************\n";
        cout << "Test Score: ";
        cin >> testScore;
        cout << "Roooo??: ";
        cin >> ro;
    }

    void getValue(){
        cout << "\n*********************************\n";
        cout << "Your Learner Information:\n";
        cout << "*********************************\n";
        cout << "Test Score: " << testScore << "\n";
        cout << "Roooo??: " << ro << "\n";
    }

    string result(){
        return "update later";
    }
};


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Restricted : public Licence{
    int noYear;
    bool inLic;
    char crime;
    int nonCrime;
    string result;


public:
    Restricted(int ny = 0, bool il = true, char c = ' ', int nc = 0, string re = " "){
        noYear = ny;
        inLic = il;
        crime = c;
        nonCrime = nc;
        result = re;
    }

    void setValue(){
        cout << "\n*********************************\n";
        cout << "Enter your Restricted information:\n";
        cout << "*********************************\n";
        cout << "noYear: ";
        cin >> noYear;
        cout << "inLic?: ";
        cin >> inLic;
        cout << "crime??: ";
        cin >> crime;
        cout << "nonCrime??: ";
        cin >> nonCrime;
        cout << "result??: ";
        cin >> result;
    }

    void getValue(){
        cout << "\n*********************************\n";
        cout << "Your Restricted Information:\n";
        cout << "*********************************\n";
        cout << "noYear: " << noYear << "\n";
        cout << "inLic??: " << inLic << "\n";
        cout << "crime??: " << crime << "\n";
        cout << "nonCrime??: " << nonCrime << "\n";
        cout << "result??: " << result << "\n";
    }

    string r_result(){
        return "update later";
    }
};



int main(){
    Licence licence;
    Learner learner;
    Restricted restricted;


    licence.setValue();

    if (licence.check() == true){
        learner.setValue();

        licence.getValue();
        learner.getValue();
    } else {
        restricted.setValue();

        licence.getValue();
        restricted.getValue();
    }

    return 0;
}