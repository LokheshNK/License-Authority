#ifndef LICENCE_H_INCLUDED
#define LICENCE_H_INCLUDED
#include "LLR.h"
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
    int getLimm();
    int getLiyyyy();
    int getLedd();
    int getLemm();
    int getLeyyyy();
    friend istream& operator >>(istream& cin,Licence &lic);
    friend ostream& operator <<(ostream& cout,Licence &lic);
    ~Licence();
};


#endif // LICENCE_H_INCLUDED
