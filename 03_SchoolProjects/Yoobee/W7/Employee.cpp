#include <iostream>
using namespace std;

#define M 10
#define S 20

class Employee{
private:
    string empId, firstName, lastName, doj, gender;
    double payPerHour, hour_worked, grossPay, netPay;
    char taxCode;

public:
    Employee(){
        empId = " ";
        firstName = " ";
        lastName = " ";
        doj = " ";
        gender = ' ';
        payPerHour = 0;
        hour_worked = 0;
        grossPay = 0;
        netPay = 0;
        taxCode = ' ';
    }

    void setData(){
        cout << "Enter your information\n";
        cout << "  Employee ID: ";
        cin >> empId;
        cout << "  First name: ";
        cin >> firstName;
        cout << "  Last name: ";
        cin >> lastName;
        cout << "  DOJ: ";
        cin >> doj;
        cout << "  Gennder: ";
        cin >> gender;
        cout << "  Pay per hour: ";
        cin >> payPerHour;
        cout << "  Hour_Worked: ";
        cin >> hour_worked;
        cout << "  Gross pay: ";
        cin >> grossPay;
        cout << "  Tax code: ";
        cin >> taxCode;
    }
    void displayData(){
        cout << "\nResult\n";
        cout << "  Employee ID: " << empId << "\n";
        cout << "  First name: " << firstName << "\n";
        cout << "  Last name: " << lastName << "\n";
        cout << "  DOJ: " << doj << "\n";
        cout << "  Gennder: " << gender << "\n";
        cout << "  Pay per hour: " << payPerHour << "\n";
        cout << "  hour_Worked: " << hour_worked << "\n";
        cout << "  Gross pay: " << grossPay << "\n";
        cout << "  Tax code: " << taxCode << "\n";
        cout << "  Net pay: " << caluculateData() << "\n";
    }

    double caluculateData(){
        netPay = payPerHour * hour_worked;
        if (toupper(taxCode) == 'M'){
            netPay = grossPay - (grossPay * M / 100);
        } else if (toupper(taxCode) == 'S'){
            netPay = grossPay - (grossPay * S / 100);
        }
        return netPay;
    }

    // string genderText(char g){
    //     genderReturn;

    //     if (toupper(g) == 'M'){
    //         return "Male";
    //     } else if (toupper(g) == 'F'){
    //         return "Feale";
    //     }
    //     return genderReturn;  
    // }
};

int main(){
    Employee e;

    e.setData();
    e.displayData();

    return 0;
}
