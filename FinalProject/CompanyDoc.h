#ifndef _COMPANY_DOC
#define _COMPANY_DOC
#include "Document.h"
#include "BankDoc.h"

using namespace std;

class CompanyDoc :virtual public Document
{
    string Companyname;
    string ownerName;
    double bank_cash;
public:
    string getCompanyName()const { return Companyname; }//return company name
    double getbankcash()const { return bank_cash; }//return bankcash
    string getownerName() const { return ownerName; }//return owner name
    void SetCompanyName(const string Cname) { Companyname = Cname; }//sets the company name
    void SetBankCash(const double amount) { bank_cash = amount; }//Sets Bank Cash
    void SetownerName(const string name) { ownerName = name; }//Sets owner Name
    CompanyDoc();
    CompanyDoc(double bank_cash,string Cname, string OwnName);
    CompanyDoc(double bank_cash,string Cname, string OwnName, int words, char* name);
    void show() const;
    friend ostream& operator<<(ostream& out, const CompanyDoc& d);
    virtual bool operator==(Document& other);//redefinition of operator== ,so for make sure that isnt fault we make dynamic cast ,if it goes wrong it will throw bad cast
    CompanyDoc& operator+(const CompanyDoc& o);//addding to owner ,adding bank cash,adding name using addOWnerTocompany
    void addOwnerToCompany(string name);  
    void MakeTheOwnerToTheCompanyName();//the function sets the company name as the owner name
    CompanyDoc& operator+(double amoutToAdd);//overload for this operator , this time with double as argument , adding money
    virtual ~CompanyDoc() {  };//distractor is empty cause we have no dynamic values, calling to his father distractor
    friend istream& operator>>(istream& in, CompanyDoc& p);// take input from the user and put them into document object
};
#endif

