//change the structure for the phone entity
//let the phone structure have phone name /model, phone price, camera resolution;
//give hard coded values for android and apple phones
//take input from the user in one of the functions. Pass the pointer to structure into the function
//return the pointer to the main function
//Then call a function from main  to display the output



#include <iostream>
#include <string>
using namespace std;

struct Phone{
	string phoneName;
	string model;
	int price;
	float cameraPixel;
	//string animal;//cat or phone or camel

	//constructor is used to initialize member variables. It helps when input is not given to the program. Otherwise warning and bugs would occur.
	Phone(string dn="iPhone", string dm="model15", int dp=100, float dc=500.5) {
		phoneName = dn;
		model = dm;
		price = dp;
		cameraPixel = dc;
	}

};

//function prototypes
struct Phone* inputValue(struct Phone *p);//passing and returning pointer to structure
//struct Phone inputValue(struct Phone anim); //passing and returning structure
void outputValue(struct Phone* p);


int main()
{
	Phone phone;
	//int x = 0;// data type, variable name and initial value of x //initalizing x
	//cout << animal.cameraPixel+5;
	Phone* ptr;
	ptr = &phone; //& refers to the memory address to be assigned to ptr

	// cout << "\nThe value of Phone name is " << animal.phoneName;
	// cout << "\nThe memory address of phone is " << ptr;


	/*int x = 5;
	int* xp;
	xp = &x;
	cout << "\nThe value of x is " << x;
	cout << "\nThe memory address of x is " << xp;

	int y = 5;
	int* yp;
	yp = &y;
	cout << "\nThe value of y is " << y;
	cout << "\nThe memory address of y is " << yp;*/
	//inputValue(animal);//passing structure variable
	inputValue(ptr);//passing pointer to structure
	outputValue(ptr);//passing pointer to structure
}

//Notes:

//& operator is called ampersand to give reference to the memory address
//use dot(.) operator when handling structures to access the members
//use arrow(->)operator when handling pointers to structures to access members 



//function
//struct Phone inputValue(struct Phone ani) {
//	cout << "\nInput name of the phone: ";  
//	getline(cin, ani.phoneName);
//	cout << "\nInput model of the phone: ";
//	getline(cin, ani.model);
//	cout << "\nInput price of the phone: ";
//	cin >> ani.price;
//	cout << "\nInput cameraPixel of the phone: ";
//	cin >> ani.cameraPixel;
//	return(ani);
//}

struct Phone* inputValue(struct Phone *p) {
	cout << "\nInput name of the phone: ";  
	getline(cin, p->phoneName);
	cout << "\nInput model of the phone: ";
	getline(cin, p->model);
	cout << "\nInput price of the phone: ";
	cin >> p->price;
	cout << "\nInput cameraPixel of the phone: ";
	cin >> p->cameraPixel;
	return(p);
}

//function to output values received from inputValues function
void outputValue(struct Phone* p) {
	cout << "\nName of the phone: " << p->phoneName;	
	cout << "\nmodel of the phone: " << p->model;	
	cout << "\nprice of the phone: " << p->price;
	cout << "\ncameraPixel of the phone: " << p->cameraPixel << "\n";
}