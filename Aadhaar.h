#ifndef AADHAAR_H_INCLUDED
#define AADHAAR_H_INCLUDED
#include "Licence.h"
#include<iostream>
using namespace std;
class Aadhaar:public Licence
{
private:
    string aadhaar_Number;
public:
    Aadhaar();
    Aadhaar(string);

    void setAadhaar_Number(string aadhaar_Number);
    string getAadhaar_Number();
    friend istream& operator>>(istream& cin,Aadhaar &aad);
    friend ostream& operator<<(ostream& cout,Aadhaar &aad);
    ~Aadhaar();
};


#endif
