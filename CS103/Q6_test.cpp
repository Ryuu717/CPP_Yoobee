#include "iostream"
using namespace std;


//define the structure
struct Expenses {
    string date;
    float transport_cost;
    float meal_cost;
    float entertainment_cost;
    float others;

    Expenses(string date= "-", float transport_cost = 0, float meal_cost = 0, float entertainment_cost = 0, float others = 0){
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
void view_weekly_expenses();
void calculate();
void output(struct Expenses expenses[], int days_to_apply);



int main(){

    menu();

    return 0;
}


void input(){
    int days_to_apply;

    //user's input
    cout << "Enter the number of days to apply: ";
    cin >> days_to_apply;


    struct Expenses expenses[days_to_apply];

    for (int i = 0; i < days_to_apply; i++){
        cout << "Enter the expenses of day " << i + 1 << "\n";
        cout << "Date (dd/mm/yyyy): ";
        cin >> expenses[i].date;
        cout << "Transport cost (NZD) : ";
        cin >> expenses[i].transport_cost;
        cout << "Meal cost (NZD) : ";
        cin >> expenses[i].meal_cost;
        cout << "Entertainment cost (NZD) : ";
        cin >> expenses[i].entertainment_cost;
        cout << "Others (NZD) : ";
        cin >> expenses[i].others;
        cout << "\n";
    }
    output(expenses, days_to_apply);
}


//output (get structure arrays and number of days)
void output(struct Expenses expenses[], int days_to_apply){

    for (int i = 0; i < days_to_apply; i++){
        cout << expenses[i].date << "\n";
        cout << "  Transport cost (NZD) :\t" << expenses[i].transport_cost << "\n"; 
        cout << "  Meal cost (NZD) :\t\t" << expenses[i].meal_cost << "\n"; 
        cout << "  Entertainment cost (NZD) :\t" << expenses[i].entertainment_cost << "\n"; 
        cout << "  Others (NZD) :\t\t" << expenses[i].others << "\n\n"; 
    }
}


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