#include"Bookshop.h"
#include<iostream>
#include<string.h>
#include <string>
using namespace std;


void Bookshop:: read_Book(){
	cout << "Enter Title : ";
	cin.getline(title, 30);

	cout << "Enter Price : ";
	cin >> price;
   
	cout << "Enter Pages : ";
	cin >> pages;
}

void Bookshop::display_Book()
{
	cout << "\nTitle : " << title;
	cout << "\nPrice : "<< price;
	cout << "\nPages : "<< pages;
	cout << "\n\n";

}

int main()
{
	int n = 0;
	Bookshop* p[100];
	char user_response = 'y';

	do {
		p[n] = new Bookshop();
		p[n]->read_Book();

		n++;

		cout << "\n\n Do you wish to continue ...(y/n) :";
		cin >> user_response;
		cin.clear();   // clear the buffer 
		cin.ignore();  // ignoring the numeric limits 


	} while (user_response == 'y' || user_response == 'Y');

	cout << n;
	// prining the records 
	
	cout << "\n\n Books details ...\n";
	for (int i = 0; i < n; i++)
	{
		p[i]->display_Book();
	}
	 
   
}

