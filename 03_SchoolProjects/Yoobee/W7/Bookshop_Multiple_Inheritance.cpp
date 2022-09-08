#include <iostream>
using namespace std;


class Person {
	int age;
	string firstname, lastname;
	char gender;

public :
	Person(){
		firstname = "unknown";
		lastname = "unknown";
		gender = 'o';
		age = 0;
	}

	Person(string first , string last, char gender, int age){
		firstname = first;
		lastname = last;
		this->gender = gender;
		this->age = age;
	}

	void setdata(){
		cout << " \n Enter first name : ";
		cin >> firstname;
		cout << " \n Enter last name : ";
		cin >> lastname;
		cout << " \n Enter Gender(f/m/o) : ";
		cin >> gender;
		cout << " \n Enter Age  : ";
		cin >> age;

		cin.clear();
		cin.ignore();
		fflush(stdin);
    }

	string Gender_return(char g){
		gender = tolower(g);
		if (gender == 'f')
			return "Female";
		else if (gender == 'm')
			return "Male";
		else
			return "Others";
	}



	void getdata(){
		cout << "\n Name " << firstname << "  " << lastname;
		cout << "\n Gender " << Gender_return(gender);
		cout << "\n Age " << age;
	}

};



class Book {
	char bookname[100];
	string edition;
	double price;

public :

	Book(){
	 	 edition = " ";
		 price = 0.0;
	}

public :
	void setBookddata(){
		cout << " \n Enter Book name : ";
		cin.getline(bookname, 100);
		cout << " \n Enter Edition details : ";
		cin >> edition;
		cout << " \n Enter Price  : ";
		cin >> price;
		cin.clear();
		fflush(stdin);
	}

	double return_price(){
		return price;
	}

	void getBook(){
		cout << "  " << bookname;
		cout <<"\t"<<  edition;
		cout <<"\t"<< price;
	}
};


class shop : public Person , public Book{
	double discount;
	double total_cost;

public :
	shop(){
		discount = 0;
		total_cost = 0;
	}

	void setDiscount(){
		cout << " \n Enter the discount percentage : ";
		cin >> discount;
	}

	double getDiscount(){
		return discount;
	}

	void DisplayShoppingCart(){
		getdata();
		getBook();
		cout << "\n Discount : " << discount;
		
		double discount_cal = return_price() * discount / 100;

		cout << "\n Price after discount  : " << return_price()-discount_cal;
	}
};



int main(){
	shop* s = new shop();
	Book* b[10];
	int index = 0;
	char user_choice = 'n';
	double total_price = 0;
	double discount_amount = 0;

	cout << "\n\n Welcome to NewLynn Bookshop\n";
	cout << "\n Add Books .. ";

	s->setdata();

	do {
		b[index] = new Book();
		b[index]->setBookddata();
		index++;
		
		cout << " Do you wish to contionue ? (y/n) : ";
		cin >> user_choice;
		cin.clear();
		cin.ignore();
		fflush(stdin);

	} while (tolower(user_choice) == 'y');
	
	s->setDiscount();	
	s->getdata();

	cout << "\n**********************************\n";
	for (int i = 0; i < index; i++){
		cout <<"\n" << i + 1 << ". ";
		b[i]->getBook();
		total_price += b[i]->return_price();
	}
	
	cout << "\n**********************************\n";
	cout << "\n Total Price          :  " << total_price;
	cout << "\n Discount             :  " << s->getDiscount() << "%";
	
	discount_amount = total_price * s->getDiscount() / 100;
	cout << "\n Discount Amount      :  " << discount_amount;
	cout << "\n Payment              :  " << total_price -discount_amount;
	cout << "\n***********************************\n";

	//s->DisplayShoppingCart();	 
}

