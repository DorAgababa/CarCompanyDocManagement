#include "CompanyDoc.h"

CompanyDoc::CompanyDoc():Document()//creating defultive company document with defultive values ,by using document consractor
{
	this->bank_cash = 0;
	this->Companyname = "Davidor";
	this->ownerName = "Muhamad";
}

CompanyDoc::CompanyDoc(double bank_cash, string Cname, string OwnName):Document()//creating company document with given values and default values for document part
{
	this->bank_cash = bank_cash;
	this->Companyname = Cname;
	this->ownerName = ownerName;
}

CompanyDoc::CompanyDoc(double bank_cash,string Cname, string OwnName, int words, char* name) :Document(name, words)//creating company document with given values by using document constractor
{
	this->bank_cash = bank_cash;
	this->Companyname = Cname;
	this->ownerName = ownerName;
}

void CompanyDoc::show() const//printing the unique detail for him ,make the class unabstract
{
	cout << "Owner Name: " << ownerName << endl << "Company: " << Companyname << endl << "Bank Cashe:" << bank_cash << endl;
}

bool CompanyDoc::operator==(Document& other)throw(bad_cast)//redefinition of operator== ,so for make sure that isnt fault we make dynamic cast ,if it goes wrong it will throw bad cast
{
	CompanyDoc check = dynamic_cast<CompanyDoc&>(other);
		return (Document::operator==(other) && this->bank_cash == check.bank_cash && this->Companyname == check.Companyname && this->ownerName == check.ownerName);
}

CompanyDoc& CompanyDoc::operator+(const CompanyDoc& o)//addding to owner ,adding bank cash,adding name using addOWnerTocompany
{
	addOwnerToCompany(o.Companyname);
	this->bank_cash += o.bank_cash;
	this->Companyname = Companyname+" & "+o.Companyname;
	return *this;
}

void CompanyDoc::addOwnerToCompany(string name)//add owner to the company
{
	this->ownerName = ownerName + " & " + name;
}

void CompanyDoc::MakeTheOwnerToTheCompanyName()
{
	this->SetCompanyName(this->ownerName);
}



CompanyDoc& CompanyDoc::operator+(double amoutToAdd)//overload for this operator , this time with double as argument , adding money
{
	this->bank_cash += amoutToAdd;
	return *this;
}


ostream& operator<<(ostream& out, const CompanyDoc& d)
{
	out << (Document&)d  << "company name : " << d.Companyname << endl << "owner name : " << d.ownerName << endl << "cash bank : " << d.bank_cash << endl;
	return out;
}

istream& operator>>(istream& in, CompanyDoc& p)throw(const char*)
{
	string Companyname;
	string ownerName;
	double bank_cash;
	try 
	{
		in >> (Document&)p;
		cout << "please enter Company name" << endl;
		in >> Companyname;
		p.SetCompanyName(Companyname);
		cout << "please enter ownerName" << endl;
		in >> ownerName;
		p.SetownerName(ownerName);
		cout << "please enter bankcash" << endl;
		in >> bank_cash;
		p.SetBankCash(bank_cash);
	}
	catch (...)
	{
		p.~CompanyDoc();
		throw ("you made mistake and this document will not save\n");
	}
	
	return in;
}
