//QUESTION - 2

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class emp
{
public:
    int emp_no;
    string emp_name;
    int emp_dob;
    int emp_contact;
    int emp_salary;

    //Setting initial values zero.
    emp()
    {
        int emp_no = 0;
        string emp_name = "NULL";
        int emp_dob = 0;
        int emp_contact = 0;
        int emp_salary = 0;
    }

    //Displaying the messages to get the following details.
    void set_emp_details()
    {
        cout << "Enter employee no.: ";
        cin >> emp_no;
        cout << "Enter employee name: ";
        cin >> emp_name;
        cout << "Enter DOB: ";
        cin >> emp_dob;
        cout << "Enter phone no.: ";
        cin >> emp_contact;
        cout << "Enter salary: ";
        cin >> emp_salary;
    }

    void get_emp_details()
    {
        cout << "\n" << emp_no << "\n" << emp_name << "\n" << emp_dob << "\n" << emp_contact << "\n" << emp_salary << endl;
    }

    //Storing the details.
    void store_emp()
    {
        ofstream fout;
        fout.open("emp_details.dat", ios::app | ios::binary);  //Storing details.
        fout.write((char*)this, sizeof(*this));
        fout.close();
    }

    //Displaying details
    void display_emp()
    {
        ifstream fin;
        fin.open("emp_details.dat", ios::in | ios::binary); 
        if (!fin)
        {
            cout << "\nFile Not Found";
        }
        else
        {
            fin.read((char*)this,sizeof(*this));
            while (!fin.eof())
            {
                get_emp_details();
                fin.read((char*)this, sizeof(*this));
            }
            fin.close();
        }
    }
};

//MAIN FUNCTION
int main()
{
    emp e1, e2, e3, e4, e5, e6, e7, e8, e9, e10;
    e1.set_emp_details();
    e1.store_emp();
    e2.set_emp_details();
    e2.store_emp();
    e3.set_emp_details();
    e3.store_emp();
    e4.set_emp_details();
    e4.store_emp();
    e5.set_emp_details();
    e5.store_emp();
    e6.set_emp_details();
    e6.store_emp();
    e7.set_emp_details();
    e7.store_emp();
    e8.set_emp_details();
    e8.store_emp();
    e9.set_emp_details();
    e9.store_emp();
    e10.set_emp_details();
    e10.store_emp();

    e1.display_emp();
}