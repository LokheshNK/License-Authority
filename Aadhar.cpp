#include "Aadhaar.h"
#include<fstream>
Aadhaar::Aadhaar()
{
    aadhaar_Number="";
}

Aadhaar::Aadhaar(string ad)
{
    aadhaar_Number=ad;
}

void Aadhaar::setAadhaar_Number(string aadhaar_Number)
{
    this->aadhaar_Number=aadhaar_Number;
}


string Aadhaar::getAadhaar_Number()
{
    return aadhaar_Number;
}
Aadhaar::~Aadhaar()
{

}

istream& operator>>(istream& cin, Aadhaar &aad)
{
    ifstream inFile("LICENCE.TXT");
    ofstream tempFile("temp.txt");
    if (!inFile.is_open() || !tempFile.is_open())
    {
        throw runtime_error("Error opening file for appending Aadhaar details.");
    }

    string llr_Number;
    cout << "Enter LLR number to access the row: ";
    cin >> llr_Number;

    string line;
    bool found = false;
    string aadhaar_Number;
    while (getline(inFile, line))
    {
        size_t pos = line.find(llr_Number);
        if (pos != string::npos)
        {
            found = true;
            while(true)
            {
                cout << "Enter Aadhaar number: ";

                cin >> aadhaar_Number;
                if (aadhaar_Number.length() == 12)
                {
                    line +=aadhaar_Number;
                    break;
                }
                else
                {
                    cout << "Invalid Aadhaar number. Please enter a valid Aadhaar number." << endl;

                }
            }

        }
        tempFile << line << '\n';
    }

    inFile.close();
    tempFile.close();

    remove("LICENCE.TXT");
    rename("temp.txt", "LICENCE.TXT");

    if (found)
    {
        cout << "Aadhaar details added to file successfully." << endl;
    }
    else
    {
        cout << "LLR number not found." << endl;
    }

    return cin;
}


ostream& operator<<(ostream& cout,Aadhaar &aad)
{
    cout << "Aadhaar number: ";
    cout<<aad.getAadhaar_Number()<<endl;
    return cout;
}
