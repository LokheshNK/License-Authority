#ifndef FINE_H_INCLUDED
#define FINE_H_INCLUDED
class Fine
{
    double fine;
    string FineNum;
public:
    Fine();
    Fine(string num,double f);
    double getFine();
    void setFine(double);
    string getFineNum();
    void setFineNum(string);
    friend istream& operator >>(istream& cin,Fine &fin);
    friend ostream& operator <<(ostream& cout,Fine &fin);
    ~Fine(){}
};


#endif // FINE_H_INCLUDED
