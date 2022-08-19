// Multilevel_Inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class person {

    string name;
    string contact_no;

public :

    person()
    {
        name = " ";
        contact_no = " ";
    }


    void read_person(string n, string contact)
    {
        name = n;
        contact_no =contact;

    }

    void display_person()
    {
        cout << "\nName : " << name;
        cout << "\nContact No : " << contact_no;
        
    }


};


class student 

{

    string course_name;
    float course_fee;

public :
    student()
    {
        course_name = " ";
        course_fee = 0;

    }

    void read_stu(string course, float f)
    {
        course_name = course;
        course_fee = f;
       
        
    }


    void display_course()
    {
       
        cout << "\nCourse  Name : " << course_name;
        cout << "\ncourse Fee   : " << course_fee;

    }


};


class Academic : public student,public person
{
    int mark1, mark2, mark3;

public :
    
    Academic()
    {
        mark1 = 0;
        mark2 = 0;
        mark3 = 0;
    }

    Academic(int m1, int m2, int m3)
    {
        mark1 = m1;
        mark2 = m2;
        mark3 = m3;
       
    }

    void display_marksheet()
    {
        

        cout << "\n Mark 1 " << mark1;

        if (mark1 >= 50)
            cout << " Achieved";
        else 
            cout << " Not Achieved";

        cout << "\n Mark 2 " << mark2;

        if (mark2 >= 50)
            cout << " Achieved";
        else
            cout << " Not Achieved";

        cout << "\n Mark 3 " << mark3;
        if (mark3 >= 50)
            cout << " Achieved";
        else
            cout << " Not Achieved";
    }


};

int main()
{
   
    
    Academic marksheet(67, 67, 45);

    marksheet.read_person("Manju", "1233434");
    marksheet.read_stu("BSE", 10000);
    marksheet.display_person();
    marksheet.display_course();
    marksheet.display_marksheet();


    return 0;
}

