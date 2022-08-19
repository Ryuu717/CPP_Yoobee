// #pragma once
#include<string.h>
#include<cstring>

class Bookshop {

	char title[100];
	int price;
	int pages;
public :
	Bookshop(char s =' ' , int p = 0, int page = 0)
	{
		*title = s;
		price = p;
		pages = page;
	}

	void read_Book();
	void display_Book();

};