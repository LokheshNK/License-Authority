#ifndef LLR_H_INCLUDED
#define LLR_H_INCLUDED

#include<iostream>
using namespace std;
class LLR
{
private:
    string name;
    string fName;
    string blood_Group;
    string llr_Number;
    int age;
    string licence_type;
    string dob;
    int llredd,llremm,llreyyyy;
    string gender;
    string status;
    string mobile_Number;
    string address;
    string issue_Authority;
public:
    LLR();
    LLR(string, string, string, string, int, string, string, int, int, int, string, string, string, string, string);

    void setName(string n);
    void setFname(string fn);
    void setBlood_Group(string bg);
    void setLlr_Number(string llrno);
    void setAge(int a);
    void setLicence_Type(string lt);
    void setDob(string dob);
    void setLlredd(int dd);
    void setLlremm(int mm);
    void setLlreyyyy(int yyyy);
    void setGender(string gen);
    void setStatus(string stat);
    void setMobile_Number(string mn);
    void setAddress(string ad);
    void setIssue_Authority(string ia);

    string getName();
    string getFname();
    string getBlood_Group();
    string getLlr_Number();
    int getAge();
    string getLicence_Type();
    string getDob();
    int getLlredd();
    int getLlremm();
    int getLlreyyyy();
    string getGender();
    string getStatus();
    string getMobile_Number();
    string getAddress();
    string getIssue_Authority();
    friend istream& operator>>(istream& cin,LLR &llr);
    friend ostream& operator<<(ostream& cout,LLR &llr);
    ~LLR();
};

#endif // LLR_H_INCLUDED
