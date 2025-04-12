#include "Licence.h"
#include <fstream>
#include<limits>
Licence::Licence()
{
    licence_Number="";
    lidd=0;
    limm=0;
    liyyyy=0;
    ledd=0;
    lemm=0;
    leyyyy=0;
}
Licence::Licence(string lno, int dd, int mm, int yyyy, int edd, int emm, int eyyyy)
{
    licence_Number=lno;
    lidd=dd;
    limm=mm;
    liyyyy=yyyy;
    ledd=edd;
    lemm=emm;
    leyyyy=eyyyy;
}

void Licence::setLicence_Number(string ln)
{
    licence_Number=ln;
}
void Licence::setLidd(int idd)
{
    lidd=idd;
}
void Licence::setLimm(int imm)
{
    limm=imm;
}
void Licence::setLiyyyy(int iyyyy)
{
    liyyyy=iyyyy;
}
void Licence::setLedd(int edd)
{
    ledd=edd;
}
void Licence::setLemm(int emm)
{
    lemm=emm;
}
void Licence::setLeyyyy(int eyyyy)
{
    leyyyy=eyyyy;
}

string Licence::getLicence_Number()
{
    return licence_Number;
}
int Licence::getLidd()
{
    return lidd;
}
int Licence::getLimm()
{
    return limm;
}
int Licence::getLiyyyy()
{
    return liyyyy;
}
int Licence::getLedd()
{
    return ledd;
}
int Licence::getLemm()
{
    return lemm;
}
int Licence::getLeyyyy()
{
    return leyyyy;
}

Licence::~Licence() {}


istream& operator>>(istream& cin, Licence& lic)
{
    string llrNo;
    cout << "Enter the LLR number to add the licence details: ";
    cin >> llrNo;

    ifstream inFile("LICENCE.TXT");
    if (!inFile.is_open())
    {
        cerr << "Error opening file LICENCE.TXT" << endl;
        return cin;
    }

    string line;
    ofstream tempFile("temp.txt");
    bool llrFound = false;

    while (getline(inFile, line))
    {
        size_t pos = line.find(llrNo);
        if (pos != string::npos)
        {
            llrFound = true;
            string licence_Number;
            int lidd, limm, liyyyy, ledd, lemm, leyyyy;
            cout << "Enter licence number: ";
            cin.ignore();
            getline(cin, licence_Number);
            while (true)
            {
                try
                {
                    cout << "Enter issue date (DD MM YYYY): ";
                    cin >> lidd >> limm >> liyyyy;
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
            while (true)
            {
                try
                {
                    cout << "Enter expiry date (DD MM YYYY): ";
                    cin >> ledd >> lemm >> leyyyy;
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


            line +=licence_Number + "|" + to_string(lidd) + "/" + to_string(limm) + "/" + to_string(liyyyy)
                   + "|" + to_string(ledd) + "/" + to_string(lemm) + "/" + to_string(leyyyy)+ "|";

            tempFile << line << endl;
        }
        else
        {
            tempFile << line << endl;
        }
    }

    if (!llrFound)
    {
        cerr << "LLR number not found in the file." << endl;
    }
    inFile.close();
    tempFile.close();
    remove("LICENCE.TXT");
    rename("temp.txt", "LICENCE.TXT");

    return cin;
}

ostream& operator <<(ostream& cout,Licence &lic)
{
    cout << " licence number: ";
    cout<<lic.getLicence_Number()<<endl;
    cout << "issue date (DD MM YYYY): ";
    cout<<lic.getLidd()<< " " ;
    cout<<lic.getLimm()<<" ";
    cout<<lic.getLiyyyy()<<endl;
    cout << "expiry date (DD MM YYYY): ";
    cout<<lic.getLedd()<<" ";
    cout<<lic.getLemm()<<" ";
    cout<<lic.getLeyyyy()<<endl;
    return cout;
}
