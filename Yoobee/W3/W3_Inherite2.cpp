#include <iostream>
using namespace std;
class Distance //English Distance class
{
private:
    int feet;
    float inches;
public: //constructor (no args)
    Distance() : feet(0), inches(0.0)
    { }
    //constructor (two args)
    Distance(int ft, float in) : feet(ft), inches(in)
    { }
    void getdist() //get length from user
    {
        cout << "\nEnter feet : "; cin >> feet;
        cout << "Enter inches : "; cin >> inches;
    }
    void showdist() //display distance
    {
        cout << feet << "\' - " << inches << '\"';
    }
    Distance add_dist(Distance); //declaration
};

//add lengths d2 and d3
Distance Distance::add_dist(Distance d1)  // change this to return object
{
    Distance temp;
    temp.inches = d1.inches + inches; //add the inches
    temp.feet = 0; //(for possible carry)
    if (temp.inches >= 12.0) //if total exceeds 12.0,
    { //then decrease inches
        temp.inches -= 12.0; //by 12.0 and
        temp.feet++; //increase feet
    } //by 1
    temp.feet += d1.feet + feet; //add the feet
    return temp;
}

int main()
{
    Distance dist1, dist3; //define two lengths
    Distance dist2(11, 6.25); //define and initialize dist2
    dist1.getdist(); //get dist1 from user
    dist3=dist2.add_dist(dist1); //dist3 = dist1 + dist2
    //display all lengths
    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();
    cout << endl;
    return 0;
}