#include <iostream>
using namespace std;
#define M 20
#define S 40



class employee{
	string emp_id, first_name, last_name, DOJ;
	double pay_per_hour, hours_worked, gross_pay, net_pay;
	char tax_code, Gender;
	
	double taxamount = 0;
	

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
		cout << "  Employee id : ";
		cin >> emp_id;
		cout << "  First name : ";
		cin >> first_name;
		cout << "  Last name : ";
		cin >> last_name;
		cout << "  Date of Joining : ";
		cin >> DOJ;
		cout << "  Gender(m/f/o) : ";
		cin >> Gender;
		cout << "  Pay per hour : ";
		cin >> pay_per_hour;
		cout << "  Hours worked : ";
		cin >> hours_worked;

		cout << "  Tax code (m/s) : ";
		cin >> tax_code;
	}


	double calculate_pay(double gross , double tax){
		net_pay = gross - tax;
		return net_pay;
    }


	//gross pay calculation
	double gross_calculation(double hours, double pay){
		gross_pay = hours * pay;
		return gross_pay;
	}

    // tax amount calculation 
	double tax_amount(double gpay , char taxcode){
		gross_pay = gpay;
		if (toupper(tax_code) == 'M'){
			taxamount = gross_pay * M / 100;
		}
		else if (toupper(tax_code) == 'S'){
			taxamount = gross_pay * S / 100;
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
		cout << "\n  Name: \t\t" << first_name << " " << last_name;
		cout << "\n  Employee No: \t\t" << emp_id;
		cout << "\n  Date of Joining: \t" << DOJ;
		cout << "\n  Gender: \t\t" << Gender_return(Gender);
		cout << "\n  Hours Worked: \t" << hours_worked;
		cout << "\n  Pay per hour: \t" << pay_per_hour;
		cout << "\n  Tax code: \t\t" << tax_code;

		double gross = gross_calculation(hours_worked, pay_per_hour);
		cout << "\n  Gross pay: \t\t" << gross;
		
		double tax = tax_amount(gross, tax_code);
		cout << "\n  Tax amount: \t\t" <<tax ;

		cout << "\n  Net pay: \t\t" << calculate_pay(gross, tax);
	}

	double gross_return(){
		return gross_pay;
	}

	double tax_return(){
		return taxamount;
	}
};




int main(){
	employee *e[100];
	int index = 0;
	double amount=0, tax=0;
	char user_choice = 'y';
	
	// Managing multiple record 
	cout << "\n\n*************************************\n";
	cout << "Enter employee information\n";
	cout << "*************************************\n";
	cout << "\t※Tax code(M = 20%, S = 40%)\n\n";
	while (tolower(user_choice) == 'y'){
		e[index] = new employee();
		e[index]->setdata();
		index++;
		cout << "\n Do you want to continoue adding more ? (y/n) : ";
		cin >> user_choice;
	}

	cout << "\n\n*************************************\n";
	cout << "Employee payslip \n";
	cout << "*************************************\n";
	for (int i = 0; i < index; i++){
		e[i]->displaydata();
		amount += e[i]->gross_return();
		tax += e[i]->tax_return();
		cout << "\n------------------------------------\n";
	}
	// cout << "\n  ※Tax code(M = 20%, S = 40%)\n";

	cout << "\n\n*************************************\n";
	cout << "Summary \n";
	cout << "*************************************\n";
	cout << "  Total amount: \t" << amount << "\n";
	cout << "  Total Tax: \t\t" << tax << "\n";
}

