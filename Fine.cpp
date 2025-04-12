#include "Fine.h"
#include<fstream>
#include <stdexcept>
Fine::Fine()
{
    fine=0;
    FineNum="";
}
Fine::Fine(string num,double f)
{
    fine=f;
    FineNum=num;
}
double Fine::getFine()
{
    return fine;
}
void Fine::setFine(double f)
{
    fine=f;
}
string Fine::getFineNum()
{
    return FineNum;
}
void Fine::setFineNum(string num)
{
    FineNum=num;
}
istream& operator >>(istream& cin,Fine &fin)
{
    string reason;
    try
    {
        string searchKey;
        cout << "Enter LLR number to edit the details: ";
        cin >> searchKey;

        ifstream inFile("LICENCE.TXT");
        ofstream tempFile("temp.txt");

        if (!inFile.is_open() || !tempFile.is_open())
        {
            cerr << "Error opening files for reading or writing." << endl;
            return cin;
        }

        string line;
        bool found = false;

        while (getline(inFile, line))
        {
            size_t pos = line.find(searchKey);
            if (pos != string::npos)
            {
                found = true;
                int fieldChoice=13;

                string newValue;
                cout << "Enter updated value: ";
                cin.ignore();
                getline(cin, newValue);
                cout<<"Enter the reason for the fine : ";
                getline(cin,reason);
                size_t start = line.find('|');
                for (int i = 1; i < fieldChoice; ++i)
                {
                    start = line.find('|', start + 1);
                    if (start == string::npos)
                    {
                        cerr << "Invalid field choice." << endl;
                        return cin;
                    }
                }
                size_t end = line.find('|', start + 1);

                line.replace(start + 1, end - start - 1, newValue);
            }
            tempFile << line << '\n';
        }

        inFile.close();
        tempFile.close();

        if (!found)
        {
            cout << "Row with LLR number '" << searchKey << "' not found." << endl;
            return cin;
        }

        remove("LICENCE.TXT");
        rename("temp.txt", "LICENCE.TXT");

        cout << "Details updated successfully." << endl;
    }
    catch (const exception &e)
    {
        cerr << e.what() << endl;
    }
}
ostream& operator <<(ostream& cout,Fine &fin)
{
    cout<<"LLR or LIcenceNumber : "<<fin.getFineNum()<<endl<<"Fine :"<<fin.getFine()<<endl;
    return cout;
}
