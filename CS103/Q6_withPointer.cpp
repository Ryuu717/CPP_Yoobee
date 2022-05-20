#include "iostream"
using namespace std;

//define the structure
struct Expenses {
    int year;
    int month;
    int day;
    int days;
    int week;
    float transport_cost;
    float meal_cost;
    float entertainment_cost;
    float others;

    //constructor
    Expenses(int y = 1970, int m = 01, int d = 01,  int ds = 0, int w = 0, float tc = 0, float mc = 0, float ec = 0, float o = 0){
        year = y;
        month = m;
        day = d;
        days = ds;
        week = w;
        transport_cost = tc;
        meal_cost = mc;
        entertainment_cost =ec;
        others = o;
    }
};


//funtion prototypes
void menu(struct Expenses* ptr, int days_to_apply);
void input(struct Expenses* ptr, int days_to_apply);
void output(struct Expenses* ptr, int days_to_apply);
void view_daily_expenses(struct Expenses* ptr, int days_to_apply);
void view_weekly_expenses(struct Expenses* ptr, int days_to_apply);
void year_to_date(struct Expenses* ptr);
void separate_week(struct Expenses* ptr);
void calculate_day(struct Expenses* ptr, int days_to_apply);
void calculate_week(struct Expenses* ptr, int days_to_apply);
void ascending(struct Expenses* ptr, int days_to_apply);



int main(){
    int days_to_apply;

    struct Expenses expenses[days_to_apply];
    struct Expenses *ptr = expenses;

    menu(ptr, days_to_apply);

    return 0;
}


void input(struct Expenses* ptr, int days_to_apply){
    cout << "Enter the number of days to apply: ";
    cin >> days_to_apply;

    for (int i = 0; i < days_to_apply; i++){
        cout << "\nEnter the expenses of day " << i + 1 << "\n";
        cout << "------------------------------------------------\n";
        // cout << "Date (dd/mm/yyyy): ";
        // cin >> (ptr+i)->date;
        cout << " Year(e.g. 2022) : ";
        cin >> (ptr+i)->year;
        cout << " Month(e.g. 01) : ";
        cin >> (ptr+i)->month;
        cout << " Day(e.g. 01) : ";
        cin >> (ptr+i)->day;
        cout << " Transport cost (NZD) : ";
        cin >> (ptr+i)->transport_cost;
        cout << " Meal cost (NZD) : ";
        cin >> (ptr+i)->meal_cost;
        cout << " Entertainment cost (NZD) : ";
        cin >> (ptr+i)->entertainment_cost;
        cout << " Others (NZD) : ";
        cin >> (ptr+i)->others;
        cout << "\n";

        year_to_date(ptr+i); 
        separate_week(ptr+i); 
    }

    
    output(ptr, days_to_apply);
}



void output(struct Expenses* ptr, int days_to_apply){

    for (int i = 0; i < days_to_apply; i++){
        cout << (ptr+i)->year << "/" << (ptr+i)->month << "/" << (ptr+i)->day << "\n";
        cout << "  Transport cost (NZD) :\t" << (ptr+i)->transport_cost << "\n"; 
        cout << "  Meal cost (NZD) :\t\t" << (ptr+i)->meal_cost << "\n"; 
        cout << "  Entertainment cost (NZD) :\t" << (ptr+i)->entertainment_cost << "\n"; 
        cout << "  Others (NZD) :\t\t" << (ptr+i)->others << "\n\n"; 
    }
    menu(ptr, days_to_apply);
}


void view_daily_expenses(struct Expenses* ptr, int days_to_apply){
    cout << "================================================================\n";
    cout << "Daily Expenses (NZD)\n";
    cout << "================================================================\n";

    // calculate_day(ptr, days_to_apply);
    ascending(ptr, days_to_apply);
    menu(ptr, days_to_apply);
}



void view_weekly_expenses(struct Expenses* ptr, int days_to_apply){
    cout << "================================================================\n";
    cout << "Weekly Expenses (NZD)\n";
    cout << "================================================================\n";

    calculate_week(ptr, days_to_apply);
    menu(ptr, days_to_apply);
}



void calculate_day(struct Expenses* ptr, int days_to_apply){
    float total_day = 0;

    for (int i = 0; i < days_to_apply; i++){
        total_day = (ptr+i)->transport_cost + (ptr+i)->meal_cost + (ptr+i)->entertainment_cost + (ptr+i)->others;
        cout << (ptr+i)->year << "/" << (ptr+i)->month << "/" << (ptr+i)->day << "  : " << total_day << "\n";
    }
}

void calculate_week(struct Expenses* ptr, int days_to_apply){
    float total_week = 0;
    float total_year = 0;

    for (int i = 0; i < 53; i++){
        total_week = 0;

        for (int j = 0; j < days_to_apply; j++){
            if (i + 1 == (ptr+j)->week){
                total_week += (ptr+j)->transport_cost + (ptr+j)->meal_cost + (ptr+j)->entertainment_cost + (ptr+j)->others;
            }
        }
        if (total_week > 0){
            cout << "Week " << i + 1 << " :\t" << total_week << "\n";
            total_year += total_week; 

        } else {
            cout << "Week " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total :  \t" << total_year << "\n";

}


void year_to_date(struct Expenses* ptr){
    switch (ptr->month){
        case 1:
        ptr->days = ptr->day;
        break;

        case 2:
        ptr->days = 31 + ptr->day;
        break;

        case 3:
        ptr->days = 31 + 28 + ptr->day;
        break;

        case 4:
        ptr->days = 31 + 28 + 31 + ptr->day;
        break;

        case 5:
        ptr->days = 31 + 28 + 31 + 30 + ptr->day;
        break;

        case 6:
        ptr->days = 31 + 28 + 31 + 30 + 31 + ptr->day;
        break;

        case 7:
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + ptr->day;
        break;

        case 8:
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + ptr->day;
        break;

        case 9:
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + ptr->day;
        break;

        case 10:
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + ptr->day;
        break;

        case 11:
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + ptr->day;
        break;

        case 12:
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + ptr->day;
        break;
    }
}

void separate_week(struct Expenses* ptr){
    if (ptr->days % 7 == 0){
        ptr->week = ptr->days / 7;
    } else {
        ptr->week = (ptr->days / 7) + 1;
    }
}


void menu(struct Expenses* ptr, int days_to_apply){
    //Display Main Menu (Play, Final Score and Exit)
    cout << "\n\n=============================\n";
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
            input(ptr, days_to_apply);
            break;

        case 2:
            view_daily_expenses(ptr, days_to_apply);
            break;
        
        case 3:
            view_weekly_expenses(ptr, days_to_apply);
            break;

        case 4:
        cout << "See you again!\n";
            break;
    }
    cout << "\n";
}

void ascending(struct Expenses* ptr, int days_to_apply){
    //declare account size
    int days = days_to_apply;

    //create ranking by comparing each customer balance.
    //show smaller balances in order
    //Continue as many as the number of customers
    while(days > 0){
        int rank = 0;

        for (int i = 0; i < days; i++) {
            rank = 0;                   //everytime reset the ranking

            for (int j = 0; j < days; j++){
                if (((ptr+i)->days - (ptr+j)->days) < 0){
                    rank++;
                }
            }

            if (rank == (days - 1)){
                float total_day = 0;

                total_day = (ptr+i)->transport_cost + (ptr+i)->meal_cost + (ptr+i)->entertainment_cost + (ptr+i)->others;
                cout << (ptr+i)->year << "/" << (ptr+i)->month << "/" << (ptr+i)->day << "  : " << total_day << "\n";

                days--;
            }
        }
    }
    cout << "\n";
}



//1. Add option Ascending or Descending
//2. Minimize the functions
//3. Change the name
//4. Use vector