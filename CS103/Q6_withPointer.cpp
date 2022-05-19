#include "iostream"
using namespace std;

//define the structure
struct Expenses {
    string date;
    float transport_cost;
    float meal_cost;
    float entertainment_cost;
    float others;

    //constructor
    Expenses(string date= "dd/mm/yyyy", float transport_cost = 0, float meal_cost = 0, float entertainment_cost = 0, float others = 0){
        date = date;
        transport_cost = transport_cost;
        meal_cost = meal_cost;
        entertainment_cost =entertainment_cost;
        others = others;
    }
};


//funtion prototypes
void menu();
void input();
void view_daily_expenses();
void calculate();
// void output(struct Expenses *expenses[], int days_to_apply);



int main(){
    menu();

    return 0;
}


void input(){
    int days_to_apply;

    cout << "Enter the number of days to apply: ";
    cin >> days_to_apply;


    /////////////////////////////////////////////////////////////////////////////////////
    //input for one day
    // struct Expenses expenses;
    // struct Expenses *ptr = &expenses;

    // cout << "Enter the expenses of day " << "\n";
    // cout << "Date (dd/mm/yyyy): ";
    // cin >> ptr->date;
    // cout << "Transport cost (NZD) : ";
    // cin >> ptr->transport_cost;
    // cout << "Meal cost (NZD) : ";
    // cin >> ptr->meal_cost;
    // cout << "Entertainment cost (NZD) : ";
    // cin >> ptr->entertainment_cost;
    // cout << "Others (NZD) : ";
    // cin >> ptr->others;
    // cout << "\n";

    // //output    
    // cout << ptr->date << "\n";
    // cout << "  Transport cost (NZD) :\t" << ptr->transport_cost << "\n"; 
    // cout << "  Meal cost (NZD) :\t\t" << ptr->meal_cost << "\n"; 
    // cout << "  Entertainment cost (NZD) :\t" << ptr->entertainment_cost << "\n"; 
    // cout << "  Others (NZD) :\t\t" << ptr->others << "\n\n"; 

    
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //input for several days  
    struct Expenses expenses[days_to_apply];
    // struct Expenses *ptr = &expenses[days_to_apply];
    struct Expenses *ptr = expenses;
    

    for (int i = 0; i < days_to_apply; i++){
        cout << "Enter the expenses of day " << i + 1 << "\n";
        cout << "Date (dd/mm/yyyy): ";
        cin >> (ptr+i)->date;
        cout << "Transport cost (NZD) : ";
        cin >> (ptr+i)->transport_cost;
        cout << "Meal cost (NZD) : ";
        cin >> (ptr+i)->meal_cost;
        cout << "Entertainment cost (NZD) : ";
        cin >> (ptr+i)->entertainment_cost;
        cout << "Others (NZD) : ";
        cin >> (ptr+i)->others;
        cout << "\n";
    }

    //output
    for (int i = 0; i < days_to_apply; i++){
        cout << (ptr+i)->date << "\n";
        cout << "  Transport cost (NZD) :\t" << (ptr+i)->transport_cost << "\n"; 
        cout << "  Meal cost (NZD) :\t\t" << (ptr+i)->meal_cost << "\n"; 
        cout << "  Entertainment cost (NZD) :\t" << (ptr+i)->entertainment_cost << "\n"; 
        cout << "  Others (NZD) :\t\t" << (ptr+i)->others << "\n\n"; 
    }


     
    // output(&expenses, days_to_apply);
}



// void output(struct Expenses *expenses[], int days_to_apply){
//     int list_length = days_to_apply;

//     for (int i = 0; i < list_length; i++){
//         cout << *(expenses+i)->date << "\n";
//         cout << "  Transport cost (NZD) :\t" << *(expenses+i)->transport_cost << "\n"; 
//         cout << "  Meal cost (NZD) :\t\t" << *(expenses+i)->meal_cost << "\n"; 
//         cout << "  Entertainment cost (NZD) :\t" << *(expenses+i)->entertainment_cost << "\n"; 
//         cout << "  Others (NZD) :\t\t" << *(expenses+i)->others << "\n\n"; 
//     }
// }


void view_daily_expenses(){
    calculate();
}

void view_weekly_expenses(){
    calculate();
}

void calculate(){
    cout << "Update later";
}

void menu(){
    //Display Main Menu (Play, Final Score and Exit)
    cout << "=============================\n";
    cout << "Menu\n";
    cout << "  1. Enter the expenses\n";
    cout << "  2. View Daily Expenses \n";
    cout << "  3. View Weekly Expenses \n";
    cout << "  4. Exit\n";
    cout << "=============================\n";

    int option;

    cout << "Choose the option: ";
    cin >> option;
    cout << "\n";

    switch (option){
        case 1:
            input();
            break;

        case 2:
            view_daily_expenses();
            break;
        
        case 3:
            view_weekly_expenses();
            break;

        case 4:
            break;
    }
    cout << "\n";
}