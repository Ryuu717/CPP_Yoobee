#include <iostream>
using namespace std;

// Will try to seperate it from the code so it can access an external source for now
constexpr auto SGD_to_IDK = 10582.01f;
constexpr auto SGD_to_MYR = 3.04f;
constexpr auto MYR_to_IDK = 3477.05f;

// Stupid, change later with a good code
#define Pause_and_Exit {cin.ignore(); cin.get(); return 0;}

struct Currency
{
public:
    float Amount = 0;
    char Curr_Type[4] = "SGD" ;
    char To_Be_Curr_Type[4] = "SGD";
};


//Wasn't working with standard libraries
int compare_string(const char* first, const char* second);
void copy_string(char* first, const char* second);
void ToCaps(char* first);

void To_SGD(float& Amt, char Type[4]);
void To_IDK(float& Amt, char Type[4]);
void To_MYR(float& Amt, char Type[4]);



int main()
{
    Currency Curr1;
    bool b_Flag = false;
   
    cout << "Currency Convertor" <<endl;
    cout << "---------------------------------------" << endl;
    cout << "Enter the amount and the currency type (SGD, MYR, IDK)";
    cin >> Curr1.Amount;
    cin >> Curr1.Curr_Type;
    cout << "To be converted to (SGD, MYR, IDK):";
    cin >> Curr1.To_Be_Curr_Type;
    if (!cin)
    {
        cout << "\nSeriously?????, Are you drunk? go back to school" << endl;
        Pause_and_Exit
    }

    ToCaps(Curr1.Curr_Type);
    ToCaps(Curr1.To_Be_Curr_Type);

    if (compare_string(Curr1.To_Be_Curr_Type, Curr1.Curr_Type))
    {
        //fck off;
    }
    if (compare_string(Curr1.To_Be_Curr_Type, "IDK"))
    {
        To_IDK(Curr1.Amount, Curr1.Curr_Type);
        copy_string(Curr1.Curr_Type, "IDK");
        b_Flag = true;
    }  
    if (compare_string(Curr1.To_Be_Curr_Type, "MYR"))
    {
        To_MYR(Curr1.Amount, Curr1.Curr_Type);
        copy_string(Curr1.Curr_Type, "MYR");
        b_Flag = true;
    }
    if (compare_string(Curr1.To_Be_Curr_Type, "SGD"))
    {
        To_SGD(Curr1.Amount, Curr1.Curr_Type);
        copy_string(Curr1.Curr_Type, "SGD");
        b_Flag = true;
    }
    if (b_Flag)
    {
        cout << endl << "The converted amount is " << Curr1.Amount << ' ' << Curr1.Curr_Type << endl;
        Pause_and_Exit

    }
    cout << "Dont out-pizza the hut" << endl;
    Pause_and_Exit
}

void To_SGD(float& Amt, char Type [4])
{
    if (compare_string(Type, "IDK"))
    {
        Amt /= SGD_to_IDK;
    }
    if (compare_string(Type, "MYR"))
    {
        Amt /= SGD_to_MYR;
    }
}

void To_MYR(float& Amt, char Type[4])
{
    if (compare_string(Type, "IDK"))
    {
        Amt /= MYR_to_IDK;
    }
    if (compare_string(Type, "SGD"))
    {
        Amt *= SGD_to_MYR;
    }
}

void To_IDK(float& Amt, char Type[4])
{
    if (compare_string(Type, "SGD"))
    {
        Amt *= SGD_to_IDK;
    }
    if (compare_string(Type, "MYR"))
    {
        Amt *= MYR_to_IDK;
    }
}

int compare_string(const char* first, const char* second)
{
    while (*first == *second)
    {
        if (*first == '\0' || *second == '\0')
        {
            break;
        }
        first++;
        second++;
    }
    if (*first == '\0' && *second == '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void copy_string(char* first, const char* second)
{

    while (*second != '\0')
    {
        *first = *second;
        first++;
        second++;
    }
    *first = '\0';
}

void ToCaps(char* first)
{
    while (*first != '\0')
    {
        if (*first > 96 && *first < 123 )
        {
            *first = *first - 32;
        }
        first++;
    }
    *first = '\0'; // reduntant
}