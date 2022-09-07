#include <iostream>
using namespace std;
#define M 20
#define S 40



class employee{
	string emp_id, first_name, last_name, DOJ;
	double pay_per_hour, hours_worked, gross_pay, net_pay, gross, totalGross;
	char tax_code, Gender;

public:
	employee(){
		emp_id = " ";
		first_name = " ";
		last_name = " ";
		DOJ = " ";
		Gender = 'o';
		pay_per_hour = 0;
		hours_worked = 0;
		gross_pay = 0;
		net_pay = 0;
		tax_code = M;
	}

	void setdata(){
		cout << " Enter Emp_id : ";
		cin >> emp_id;
		cout << " Enter first name : ";
		cin >> first_name;
		cout << " Enter last name : ";
		cin >> last_name;
		cout << " Enter Date of Joining : ";
		cin >> DOJ;
		cout << " Enter Gender(m/f/o) : ";
		cin >> Gender;
		cout << " Enter Pay per hour : ";
		cin >> pay_per_hour;
		cout << " Enter hours worked : ";
		cin >> hours_worked;
		cout << " Enter tax code (m/s) : ";
		cin >> tax_code;

	}

	double calculate_pay(double gross , double tax){
		net_pay = gross - tax;
		return net_pay;
    }

	//gross pay calculation
	double gross_calculation(double hours, double pay){
		return (hours*pay);
	}

    // tax amount calculation 
	double tax_amount(double gpay , char taxcode){
		double taxamount = 0;
		gross_pay = gpay;

		if (toupper(tax_code) == 'M'){
			taxamount = gross_pay * (M / 100);
			cout << taxamount;
		} else if (toupper(tax_code) == 'S'){
			taxamount = gross_pay * (S / 100);
			cout << taxamount;
		}
		return taxamount;
	}

	string Gender_return(char g){
		Gender = tolower(g);
		if (Gender == 'f')
			return "Female";
		else if (Gender == 'm')
			return "Male";
		else
			return "Others";
	}

	void displaydata(){
		cout << "\n\n employee payslip \n";
		cout << "************************\n";
		cout << "\nName  : " << first_name << " " << last_name;
		cout << "\nEmployee No : " << emp_id;
		cout << "\nDate of Joining  : " << DOJ;
		cout << "\nGender : " << Gender_return(Gender);
		cout << "\nHours Worked  : " << hours_worked;
		cout << "\nPay per hour   : " << pay_per_hour;
		cout << "\nTax code   : " << tax_code;
		double gross = gross_calculation(hours_worked, pay_per_hour);
		cout << "\nGross pay   : " << gross;
		double tax = tax_amount(gross, tax_code);
		cout << "\nTax amount   : " <<tax ;
		cout << "\nNet pay  : " << calculate_pay(gross, tax);
	}

	double total_gross(){
		totalGross += gross;
		cout << "\nTotal gross : " << totalGross << "\n";
		return totalGross;
	}
};



int main(){
	// employee emp;
	int n = 0;
    employee* e[100];
    char isContinue = 'y';

    while(isContinue == 'y'){
        e[n] = new employee();

        e[n]->setdata();
        n++;

        cout << "Do you want to continue?(y/n): ";
        cin >> isContinue;
    }

    for(int i = 0; i < n; i++){
        e[i]->displaydata();
    }

	

}

