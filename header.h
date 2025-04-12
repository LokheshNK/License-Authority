#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

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
    int mobile_Number;
    string address;
    string issue_Authority;
public:
    LLR();
    LLR(string, string, string, string, int, string, string, int, int, int, string, string, int, string, string);

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
    void setMobile_Number(int mn);
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
    int getMobile_Number();
    string getAddress();
    string getIssue_Authority();

    ~LLR();
};

class Licence:public LLR
{
private:
    string licence_Number;
    int lidd,limm,liyyyy;
    int ledd,lemm,leyyyy;
public:

    Licence();
    Licence(string, int, int, int, int, int, int);

    void setLicence_Number(string ln);
    void setLidd(int idd);
    void setLimm(int imm);
    void setLiyyyy(int iyyyy);
    void setLedd(int edd);
    void setLemm(int emm);
    void setLeyyyy(int eyyyy);

    string getLicence_Number();
    int getLidd();
    int getLimm(int imm);
    int getLiyyyy();
    int getLedd();
    int getLemm();
    int getLeyyyy();

    ~Licence();
};

class Fine:public Licence
{
private:
    double fine_Amount;
    string fine_status;
    int fdd,fmm,fyyyy;
    int pdd,pmm,pyyyy;
    string fine_Reason;
    string place_Of_Fine;
public:
    Fine();
    Fine(double, string, int, int, int, int, int, int, string, string);

    void setFine_Amount(double fa);
    void setFine_Status(string fstat);
    void setFdd(int fdd);
    void setFmm(int fmm);
    void setFyyyy(int fyyyy);
    void setPdd(int pdd);
    void setPmm(int pmm);
    void setPyyyy(int pyyyy);
    void setFine_Reason(string fr);
    void setPlace_Of_Fine(string pof);

    double getFine_Amount();
    string getFine_Status();
    int getFdd();
    int getFmm();
    int getFyyyy();
    int getPdd();
    int getPmm();
    int getPyyyy();
    string getFine_Reason();
    string getPlace_Of_Fine();

    ~Fine();
};

class Aadhaar:public Licence
{
private:
    int aadhaar_Number;
public:
    Aadhaar();
    Aadhaar(int);

    void setAadhaar_Number(int aadhaar_Number);
    int getAadhaar_Number();

    ~Aadhaar();
};


#endif // HEADER_H_INCLUDED
