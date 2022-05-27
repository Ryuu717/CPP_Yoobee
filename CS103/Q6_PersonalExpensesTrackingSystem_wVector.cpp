//Section2_Q6 Ryuu Ishita
#include <iostream>
#include <vector>
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
void menu(vector <Expenses> &expenses);
void input(vector <Expenses>& expenses);
void output(vector <Expenses> &expenses);
void view_daily_expenses(vector <Expenses> &expenses);
void view_weekly_expenses(vector <Expenses> &expenses);
void year_to_date(vector <Expenses> &expenses);
void separate_week(vector <Expenses> &expenses);
void calculate_per_day(vector <Expenses> &expenses);
void calculate_per_week(vector <Expenses> &expenses);
void ascending(vector <Expenses> &expenses);

int main () {
    vector<Expenses> expenses;

    menu(expenses);

    return 0;
}

void input(vector <Expenses>& expenses){
    struct Expenses e;
    char answer = 'y';                  //yes
    int i = 1;                          // i = day

    while(answer == 'y'){
        cout << "\nEnter the expenses of day " << i << "\n";
        cout << "------------------------------------------------\n";
        cout << " Year(e.g. 2022) : ";
        cin >> e.year;
        cout << " Month(e.g. 01) : ";
        cin >> e.month;
        cout << " Day(e.g. 01) : ";
        cin >> e.day;
        cout << " Transport cost (NZD) : ";
        cin >> e.transport_cost;
        cout << " Meal cost (NZD) : ";
        cin >> e.meal_cost;
        cout << " Entertainment cost (NZD) : ";
        cin >> e.entertainment_cost;
        cout << " Others (NZD) : ";
        cin >> e.others;
        cout << "\nDo you want to continue?(y/n) : ";
        cin >> answer;

        expenses.push_back(e);          //adds a new elements
        i++;                        

        year_to_date(expenses);        //calcurate year_to_date from month and day input data
        separate_week(expenses);       //assign week
    }

    output(expenses);
}

void output(vector <Expenses> &expenses){
    cout << "\n================================================================\n";
    cout << "Your Input\n";
    cout << "================================================================\n";

    for (int i = 0; i < expenses.size(); i++){
        cout << expenses[i].year << "/" << expenses[i].month << "/" << expenses[i].day << "\n";
        cout << "  Transport cost (NZD) :\t" << expenses[i].transport_cost << "\n"; 
        cout << "  Meal cost (NZD) :\t\t" << expenses[i].meal_cost << "\n"; 
        cout << "  Entertainment cost (NZD) :\t" <<expenses[i].entertainment_cost << "\n"; 
        cout << "  Others (NZD) :\t\t" << expenses[i].others << "\n\n"; 
    }

    menu(expenses);
}


void view_daily_expenses(vector <Expenses> &expenses){
    cout << "================================================================\n";
    cout << "Daily Expenses (NZD)\n";
    cout << "================================================================\n";

    // calculate_per_day(expenses, expenses.size());
    ascending(expenses);
    menu(expenses);
}

void view_weekly_expenses(vector <Expenses> &expenses){
    cout << "================================================================\n";
    cout << "Weekly Expenses (NZD)\n";
    cout << "================================================================\n";

    calculate_per_week(expenses);
    menu(expenses);
}

void calculate_per_day(vector <Expenses> &expenses){
    float total_day_cost = 0;

    for (int i = 0; i < expenses.size(); i++){
        total_day_cost = expenses[i].transport_cost + expenses[i].meal_cost + expenses[i].entertainment_cost + expenses[i].others;
        cout << expenses[i].year << "/" << expenses[i].month << "/" << expenses[i].day << "  : " << total_day_cost << "\n";
    }
}

void calculate_per_week(vector <Expenses> &expenses){
    float total_week_cost = 0;
    float total_year_cost = 0;

    for (int i = 0; i < 53; i++){   //1 year = 53 weeks
        total_week_cost = 0;        //initialize total week cost

        for (int j = 0; j < expenses.size(); j++){
            if (i + 1 == expenses[j].week){            //calculate from week1 (Day1,2,3,4,5,6,7)
                total_week_cost += expenses[j].transport_cost + expenses[j].meal_cost + expenses[j].entertainment_cost + expenses[j].others;
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

void year_to_date(vector <Expenses> &expenses){
    for ( int i = 0; i < expenses.size(); i++){
        switch (expenses[i].month){
            case 1:     //Jan
            expenses[i].days = expenses[i].day;
            break;

            case 2:     //Feb
            expenses[i].days = 31 + expenses[i].day;
            break;

            case 3:     //Mar
            expenses[i].days = 31 + 28 + expenses[i].day;
            break;

            case 4:     //Apr
            expenses[i].days = 31 + 28 + 31 + expenses[i].day;
            break;

            case 5:     //May
            expenses[i].days = 31 + 28 + 31 + 30 + expenses[i].day;
            break;

            case 6:     //Jun
            expenses[i].days = 31 + 28 + 31 + 30 + 31 + expenses[i].day;
            break;

            case 7:     //Jul
            expenses[i].days = 31 + 28 + 31 + 30 + 31 + 30 + expenses[i].day;
            break;

            case 8:     //Aug
            expenses[i].days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + expenses[i].day;
            break;

            case 9:     //Sep
            expenses[i].days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + expenses[i].day;
            break;

            case 10:    //Oct
            expenses[i].days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + expenses[i].day;
            break;

            case 11:    //Nov
            expenses[i].days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + expenses[i].day;
            break;

            case 12:    //Dec
            expenses[i].days = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + expenses[i].day;
            break;
        }
    }
}


void separate_week(vector <Expenses> &expenses){
    for (int i = 0; i < expenses.size(); i++){
        if (expenses[i].days % 7 == 0){                         //ex) 7%7=0, 14%7=0,....
            expenses[i].week = expenses[i].days / 7;            //ex) 7/7=1 (-->week1), 14/7=2 (-->week2), ....
        } else {
            expenses[i].week = (expenses[i].days / 7) + 1;      //ex) 3/7=0(int) +1 =1 (week1)
        }
    }
}


void menu(vector <Expenses> &expenses){
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
            input(expenses);
            break;

        case 2:
            view_daily_expenses(expenses);
            break;
        
        case 3:
            view_weekly_expenses(expenses);
            break;

        case 4:
        cout << "See you again!\n";
            break;
    }
    cout << "\n";
}



void ascending(vector <Expenses> &expenses){
    //declare account size
    int number_to_organize = expenses.size();

    //create ranking by comparing each customer balance.
    //show smaller balances in order
    //Continue as many as the number of customers
    while(number_to_organize > 0){
        int rank = 0;

        for (int i = 0; i < expenses.size(); i++) {
            int rank = 0;                   //everytime reset the ranking

            for (int j = 0; j < expenses.size(); j++){
                if ((expenses[i].days - expenses[j].days) < 0){
                    rank++;
                }
            }

            if (rank == (number_to_organize - 1)){
                float total_cost = 0;

                total_cost = expenses[i].transport_cost + expenses[i].meal_cost + expenses[i].entertainment_cost + expenses[i].others;
                cout << expenses[i].year << "/" << expenses[i].month << "/" << expenses[i].day << "  : " << total_cost << "\n";

                number_to_organize--;
            }

        }
    }
    cout << "\n";
}