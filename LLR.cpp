#include "LLR.h"
#include<iomanip>
#include<exception>
#include<limits>
#include<string>
#include <fstream>
using namespace std;
LLR::LLR()
{
    name="";
    fName="";
    blood_Group="";
    llr_Number="";
    age=0;
    licence_type="";
    dob="";
    llredd=0;
    llremm=0;
    llreyyyy=0;
    gender="";
    status="";
    mobile_Number="";
    address="";
    issue_Authority="";
}

LLR::LLR(string n, string fn, string bg, string llrno, int a, string lt, string dob, int dd, int mm, int yyyy, string gen, string stat, string mn, string ad, string ia)
{
    name=n;
    fName=fn;
    blood_Group=bg;
    llr_Number=llrno;
    age=a;
    licence_type=lt;
    this->dob=dob;
    llredd=dd;
    llremm=mm;
    llreyyyy=yyyy;
    gender=gen;
    status=stat;
    mobile_Number=mn;
    address=ad;
    issue_Authority=ia;
}

void LLR::setName(string n)
{
    name=n;
}
void LLR::setFname(string fn)
{
    fName=fn;
}
void LLR::setBlood_Group(string bg)
{
    blood_Group=bg;
}
void LLR::setLlr_Number(string llrno)
{
    llr_Number=llrno;
}
void LLR::setAge(int a)
{
    this->age=a;
}
void LLR::setLicence_Type(string lt)
{
    licence_type=lt;
}
void LLR::setDob(string dob)
{
    this->dob=dob;
}
void LLR::setLlredd(int dd)
{
    llredd=dd;
}
void LLR::setLlremm(int mm)
{
    llremm=mm;
}
void LLR::setLlreyyyy(int yyyy)
{
    llreyyyy=yyyy;
}
void LLR::setGender(string gen)
{
    gender=gen;
}
void LLR::setStatus(string stat)
{
    status=stat;
}
void LLR::setMobile_Number(string mn)
{
    mobile_Number=mn;
}
void LLR::setAddress(string ad)
{
    address=ad;
}
void LLR::setIssue_Authority(string ia)
{
    issue_Authority=ia;
}

string LLR::getName()
{
    return name;
}
string LLR::getFname()
{
    return fName;
}
string LLR::getBlood_Group()
{
    return blood_Group;
}
string LLR::getLlr_Number()
{
    return llr_Number;
}
int LLR::getAge()
{
    return age;
}
string LLR::getLicence_Type()
{
    return licence_type;
}
string LLR::getDob()
{
    return dob;
}
int LLR::getLlredd()
{
    return llredd;
}
int LLR::getLlremm()
{
    return llremm;
}
int LLR::getLlreyyyy()
{
    return llreyyyy;
}
string LLR::getGender()
{
    return gender;
}
string LLR::getStatus()
{
    return status;
}
string LLR::getMobile_Number()
{
    return mobile_Number;
}
string LLR::getAddress()
{
    return address;
}
string LLR::getIssue_Authority()
{
    return issue_Authority;
}

LLR::~LLR()
{

}

istream& operator>>(istream& cin, LLR &llr)
{
    float fine = 0;
    int ageChecker=0;
    string result;
    fstream outFile;
    outFile.open("LICENCE.TXT", ios::app);
    if (!outFile.is_open())
    {
        throw runtime_error("Error opening file for appending personal details.");
    }
    string name, fName, blood_Group, llr_Number, licence_type, dob, gender, status, address, issue_Authority, mobile_Number;
    int age, llredd, llremm, llreyyyy;

    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    llr.setName(name);
    cout << "Enter father's name: ";
    getline(cin, fName);
    llr.setFname(fName);
    while (true)
    {
        cout << "Enter blood group (A+, B+, AB+, O+,A-, B-, AB-, O-): ";
        getline(cin,blood_Group);
        if (blood_Group == "A+" || blood_Group == "B+" || blood_Group == "AB+" || blood_Group == "O+" || blood_Group == "A-" || blood_Group == "B-" || blood_Group == "AB-" || blood_Group == "O-")
        {
            llr.setBlood_Group(blood_Group);
            break;
        }
        else
        {
            cout << "Invalid blood group. Please enter a valid blood group." << endl;
        }
    }
    cout << "Enter LLR number (LLRXXXXXXXX): ";
    getline(cin, llr_Number);
    try
    {
        ifstream checkFile("LICENCE.TXT");
        if (checkFile.is_open())
        {
            string line;
            while (getline(checkFile, line))
            {
                size_t pos = line.find(llr_Number);
                if (pos != string::npos)
                {
                    throw runtime_error("LLR number already exists. Please enter a different LLR number.");
                }
            }
            checkFile.close();
        }
        if (llr_Number[0] != 'L' || llr_Number[1] != 'L' || llr_Number[2] != 'R')
            throw 'e';
    }
    catch (const char a)
    {
        cout << "\nThe first three characters must be LLR for the llr number " << endl;
        cout << "Re-Enter the llr number : ";
        cin >> llr_Number;
    }
    catch (const runtime_error &e)
    {
        cerr << e.what() << endl;
        return cin;
    }
    llr.setLlr_Number(llr_Number);
    while (true)
    {
        try
        {
            cout << "Enter age: ";
            cin >> age;
            if (cin.fail())
            {
                throw runtime_error("Invalid input. Age must be a number.");
            }
            if (age < 18)
            {
                throw runtime_error("You must be at least 18 years old.");
            }
            break; // Break the loop if age is valid
        }
        catch (const exception& e)
        {
            cerr << e.what() << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }
    llr.setAge(age);
    cout << "Enter licence type: ";
    cin.ignore();
    getline(cin, licence_type);
    llr.setLicence_Type(licence_type);
    while (true)
    {
        try
        {
            cout << "Enter LLR expiry date (DD MM YYYY): ";
            cin >> llredd >> llremm >> llreyyyy;
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
    llr.setLlredd(llredd);
    llr.setLlremm(llremm);
    llr.setLlreyyyy(llreyyyy);
    cout << "Enter gender: ";
    cin.ignore();
    getline(cin, gender);
    llr.setGender(gender);
    cout << "Enter status: ";
    getline(cin, status);
    llr.setStatus(status);
    while(true)
    {
        cout << "Enter mobile number: ";
        cin >> mobile_Number;
        if(mobile_Number.length()!=10)
        {
            cout<<"\nError ..Mobile number should be 10 digit"<<endl;
        }
        else
            break;
    }

    llr.setMobile_Number(mobile_Number);
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    llr.setAddress(address);
    cout << "Enter issue authority: ";
    getline(cin, issue_Authority);
    llr.setIssue_Authority(issue_Authority);
    outFile << "|" << left << setw(15) << name << "|" << setw(15) << fName << "|" << setw(5) << blood_Group << "|" << setw(12)
            << llr_Number << "|" << setw(4) << age << "|" << setw(10) << licence_type << "|" << setw(2)
            << llredd << "/" << setw(2) << llremm << "/" << setw(4) << llreyyyy << "|" << setw(2) << gender << "|" << setw(10) << status << "|" << setw(12)
            << mobile_Number << "|" << setw(25) << address << "|" << setw(10) << issue_Authority << "|" << setw(4) << fine << "|\n";
    outFile << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Personal details added to file successfully." << endl;
    outFile.close();
    return cin;
}

ostream& operator<<(ostream& cout,LLR &llr)
{
    cout << " name: ";
    cout<<llr.getName()<<endl;
    cout << " father's name: ";

    cout<<llr.getFname()<<endl;
    cout << "Enter blood group: ";
    cout<<llr.getBlood_Group()<<endl;
    cout << "Enter LLR number: ";

    cout<<llr.getLlr_Number()<<endl;
    cout << "Enter age: ";
    cout<<llr.getAge()<<endl;
    cout << "Enter licence type: ";

    cout<<llr.getLicence_Type()<<endl;
    cout << "Enter gender: ";
    cout<<llr.getGender()<<endl;
    cout << "Enter status: ";
    cout<<llr.getStatus()<<endl;
    cout << "Enter mobile number: ";
    cout<<llr.getMobile_Number()<<endl;
    cout << "Enter address: ";
    cout<<llr.getAddress()<<endl;
    cout << "Enter issue authority: ";
    cout<<llr.getIssue_Authority()<<endl;
    return cout;
}
