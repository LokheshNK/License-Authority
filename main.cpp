#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "Aadhar.cpp"
#include "Licence.cpp"
#include "LLR.cpp"
#include "Fine.cpp"
#include <conio.h>
#include <windows.h>

#include "functions.cpp"
using namespace std;



int main()
{
    int choice,checker=0;
    string num,numberPlate,state,username, password,title;
    char ch;
    cout<<"\t\t\t\t\t\t\t\t";
    title="DRIVING LICENCE AUTHORITY";
    for(int i=0; i<title.length(); i++)
    {
        cout<<title[i];
        Sleep(75);
    }
    cout<<endl;
    cout<<"LOGIN:"<<endl;
    while(checker==0)
    {
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        ch = _getch();
        while(ch != 13)
        {
            password.push_back(ch);
            cout << '*';
            ch = _getch();
        }
        cout << endl;

        if (login(username, password))
        {
            cout << "Login successful!" << endl;
            checker=1;
        }
        else
        {
            cout << "Invalid username or password." << endl;
        }
    }
    do
    {
        cout << "\n********** MENU **********" << endl;
        cout << "1. Add User Details" << endl;
        cout << "2. Add Fine Details" << endl;
        cout << "3. Access Row" << endl;
        cout << "4. Edit Details" << endl;
        cout << "5. Display File Contents" << endl;
        cout << "6. Exit" << endl;
        while (true)
                {
                    try
                    {
                        cout << "Enter your choice: ";
                        cin >> choice;
                        if (cin.fail())
                        {
                            throw runtime_error("Invalid input. Date must be a number.");
                        }
                        break;
                    }
                    catch (const exception& e)
                    {
                        cerr << e.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }


        switch(choice)
        {
        case 1:
            addPersonalDetails();
            break;
        case 2:
            addFineDetails();
            break;
        case 3:
            accessRow();
            break;
        case 4:
            editDetails();
            break;
        case 5:
            displayFileContents();
            break;
        case 6:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    while(choice != 6);

    return 0;
}
