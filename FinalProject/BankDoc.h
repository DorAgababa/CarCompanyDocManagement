#ifndef __DOCUMENT_BANK
#define __DOCUMENT_BANK
#include "Document.h"
#include "Date.h"
#include "CompanyDoc.h"

class BankDoc : virtual public Document
{
	int bankNumber;
	int branchnumber;
	static int NumberOfBankDocs;
	Date* printDate;

public:
	BankDoc();
	virtual ~BankDoc() {  delete printDate; }
	BankDoc( int BankNumber, int Branchnumber,  Date* PrintDate, char* Sname, int words);
	BankDoc( int BankNumber, int Branchnumber,  Date* PrintDate);//using defaultive Constractor Document
	BankDoc(const BankDoc& other);
	const BankDoc& operator=(const BankDoc& other);
	int GetbankNumber() const { return bankNumber; }
	int Getbranchnumber() const { return branchnumber; }
	int GetNumberOfBankDocs() const { return NumberOfBankDocs; }
	Date* GetDate() const { return printDate; }
	void SetBunkNumber(const int number);
	void Setbranchnumber(const int number);
	void SetDate(const Date* date);
	void show() const;
	 //לשנות את הגישה מSHOW לגישה לפונקציה אחרת
	friend ostream& operator<<(ostream& out, const BankDoc& d);
	virtual bool operator==(Document& other);
	void changebankdetails(int bankNumber, int branchnumber);
	bool Fairness(BankDoc& me);//has more than 1000 
	bool operator>(BankDoc& other);//check if you print after or older
	bool operator%(BankDoc& other);//who has bigger precent of bank number/words,return true if "this" has bigger
	friend istream& operator>>(istream& in, BankDoc& p);// take input from the user and put them into document object


	


};

#endif
