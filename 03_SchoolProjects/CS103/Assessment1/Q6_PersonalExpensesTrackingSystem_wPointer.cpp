//Section2_Q6 Ryuu Ishita
#include <iostream>
using namespace std;

//define the structure
struct Expenses {
    int year;
    int month;
    int day;
    int days;       //year-to-date (min=1, max=365)     *Needs when creating a chronological order
    int week;       //week1 ~ week53                    *Need when calculating the weekly total cost
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
void calculate_per_day(struct Expenses* ptr, int days_to_apply);
void calculate_per_week(struct Expenses* ptr, int days_to_apply);
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

        year_to_date(ptr+i);        //calcurate year_to_date from month and day information
        separate_week(ptr+i);       //assign week
    }

    
    output(ptr, days_to_apply);
}



void output(struct Expenses* ptr, int days_to_apply){
    cout << "================================================================\n";
    cout << "Your Input\n";
    cout << "================================================================\n";

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

    // calculate_per_day(ptr, days_to_apply);
    ascending(ptr, days_to_apply);
    menu(ptr, days_to_apply);
}



void view_weekly_expenses(struct Expenses* ptr, int days_to_apply){
    cout << "================================================================\n";
    cout << "Weekly Expenses (NZD)\n";
    cout << "================================================================\n";

    calculate_per_week(ptr, days_to_apply);
    menu(ptr, days_to_apply);
}



void calculate_per_day(struct Expenses* ptr, int days_to_apply){
    float total_day_cost = 0;

    for (int i = 0; i < days_to_apply; i++){
        total_day_cost = (ptr+i)->transport_cost + (ptr+i)->meal_cost + (ptr+i)->entertainment_cost + (ptr+i)->others;
        cout << (ptr+i)->year << "/" << (ptr+i)->month << "/" << (ptr+i)->day << "  : " << total_day_cost << "\n";
    }
}


void calculate_per_week(struct Expenses* ptr, int days_to_apply){
    float total_week_cost = 0;
    float total_year_cost = 0;

    for (int i = 0; i < 53; i++){   //1 year = 53 weeks
        total_week_cost = 0;        //initialize total week cost

        for (int j = 0; j < days_to_apply; j++){
            if (i + 1 == (ptr+j)->week){            //calculate from week1 (Day1,2,3,4,5,6,7)
                total_week_cost += (ptr+j)->transport_cost + (ptr+j)->meal_cost + (ptr+j)->entertainment_cost + (ptr+j)->others;
            }
        }
        if (total_week_cost > 0){
            cout << "Week " << i + 1 << " :\t" << total_week_cost << "\n";
            total_year_cost += total_week_cost; 

        } else {
            //Show all week cost including 0
            cout << "Week " << i + 1 << " :\t" << 0 << "\n";
        }
    }
    cout << "Total :  \t" << total_year_cost << "\n";

}

void year_to_date(struct Expenses* ptr){
    switch (ptr->month){
        case 1:     //Jan
        ptr->days = ptr->day;
        break;

        case 2:     //Feb
        ptr->days = 31 + ptr->day;
        break;

        case 3:     //Mar
        ptr->days = 31 + 28 + ptr->day;
        break;

        case 4:     //Apr
        ptr->days = 31 + 28 + 31 + ptr->day;
        break;

        case 5:     //May
        ptr->days = 31 + 28 + 31 + 30 + ptr->day;
        break;

        case 6:     //Jun
        ptr->days = 31 + 28 + 31 + 30 + 31 + ptr->day;
        break;

        case 7:     //Jul
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + ptr->day;
        break;

        case 8:     //Aug
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + ptr->day;
        break;

        case 9:     //Sep
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + ptr->day;
        break;

        case 10:    //Oct
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + ptr->day;
        break;

        case 11:    //Nov
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + ptr->day;
        break;

        case 12:    //Dec
        ptr->days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + ptr->day;
        break;
    }
}


void separate_week(struct Expenses* ptr){
    if (ptr->days % 7 == 0){                //ex) 7%7=0, 14%7=0,....
        ptr->week = ptr->days / 7;          //ex) 7/7=1 (-->week1), 14/7=2 (-->week2), ....
    } else {
        ptr->week = (ptr->days / 7) + 1;    //ex) 3/7=0(int) +1 =1 (week1)
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
    int number_to_organize = days_to_apply;

    //create ranking by comparing each customer balance.
    //show smaller balances in order
    //Continue as many as the number of customers
    while(number_to_organize > 0){
        int rank = 0;

        for (int i = 0; i < days_to_apply; i++) {
            int rank = 0;                   //everytime reset the ranking

            for (int j = 0; j < days_to_apply; j++){
                if (((ptr+i)->days - (ptr+j)->days) < 0){
                    rank++;
                }
            }

            if (rank == (number_to_organize - 1)){
                float total_cost = 0;

                total_cost = (ptr+i)->transport_cost + (ptr+i)->meal_cost + (ptr+i)->entertainment_cost + (ptr+i)->others;
                cout << (ptr+i)->year << "/" << (ptr+i)->month << "/" << (ptr+i)->day << "  : " << total_cost << "\n";

                number_to_organize--;
            }

        }
    }
    cout << "\n";
}