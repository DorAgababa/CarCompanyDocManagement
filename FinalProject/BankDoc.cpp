#include "BankDoc.h"


int BankDoc::NumberOfBankDocs = 0;//choose to take as strat the static to 0 
BankDoc::BankDoc() :Document()//create bank doc with defultive details by using empty constractor
{
	this->bankNumber = 1;
	this->branchnumber = 130;
	NumberOfBankDocs++;
	this->printDate = new Date();
}

BankDoc::BankDoc(const BankDoc& other):Document(other)//in this situation we create a copy with the same data ,by calling the father copy constractor without worte it
{
	this->printDate = NULL;//validate that is get null (operator = will create memory for him)
	NumberOfBankDocs++;
	*this = other;//using operator = of date

}

const BankDoc& BankDoc::operator=(const BankDoc& other)//duplicates the data from one doc to another but each doc has a unique number for himself that cannot be changed 
{
	Document::operator=(other);//make us the life easy to say the father to do all his part
	if (this != &other)
	{
		this->bankNumber = other.bankNumber;
		this->branchnumber = other.branchnumber;
		if (this->printDate == NULL)//if its null so make a place for him 
			this->printDate = new Date();
		*this->printDate = *other.printDate;//using operator = of date
	}
	return *this;
}

BankDoc::BankDoc(int BankNumber, int Branchnumber, Date* PrintDate)throw(const char*)//using the defultive empty constractor of Document with defualt values
{
	
	this->bankNumber = bankNumber;
	this->branchnumber = branchnumber;
	NumberOfBankDocs++;
	if (printDate == NULL) { throw("Date cant be a NULL!!!!"); }
	this->printDate = new Date();//create memory
	*this->printDate = *printDate;//using date = method
}

BankDoc::BankDoc(int BankNumber, int Branchnumber, Date* PrintDate, char* Sname, int words)throw(const char*) :Document(Sname,words)//creatin bankdoc using document constractor
{
	
	this->bankNumber = bankNumber;
	this->branchnumber = branchnumber;
	NumberOfBankDocs++;
	if (printDate == NULL) { throw("Date cant be a NULL!!!!"); }
	this->printDate = new Date();
    *this->printDate=*printDate;//using date = method

}

void BankDoc::SetBunkNumber(int number)throw(const char*)//bank can be from 1-99
{
	if (number < 1 || number >99) { throw("bank can be from 1-99!!!"); }
	this->bankNumber = number;
}

void BankDoc::Setbranchnumber(int number)throw(const char*)//bank can be from 100-999
{
	if (number < 100 || number >999) { throw("bank can be from 100-999!!!"); }
	this->branchnumber = number;
}

void BankDoc::SetDate(const Date* date)throw(const char*)//create memory and using operator = to make all 
{
	if(date==NULL){ ("Date cant be a NULL!!!!"); }
	this->printDate = new Date();
	*this->printDate = *date;//using date = method, we dont need to check the date we got cause if he already date so its ok
}

void BankDoc::show() const//we must to make show for unstract the class,printing the uniqe values for this
{
	cout << "bank Number: " << bankNumber << endl << "branch number: " << branchnumber << endl << "NumberOfDocs: " << NumberOfBankDocs << endl <<"Print Date:" << *printDate<<endl;
}

 bool BankDoc::operator==(Document& other)throw(bad_cast)//redefinition of operator== ,so for make sure that isnt fault we make dynamic cast ,if it goes wrong it will throw bad cast
{
	 BankDoc check = dynamic_cast<BankDoc&>(other);
	return(Document::operator==(other) && this->bankNumber== check.bankNumber && this->branchnumber==check.branchnumber && *(this->printDate)==*(check.printDate));
}

 void BankDoc::changebankdetails(int bankNumber, int branchnumber)//change your bank number and your branch number for another valid details
 {
	 this->SetBunkNumber(bankNumber);
	 this->Setbranchnumber(branchnumber);
 }

 bool BankDoc::Fairness(BankDoc& me)//check if your numberof bankdocks is more than 1000 
 {
	 return (me.NumberOfBankDocs > 1000);
 }

 bool BankDoc::operator>(BankDoc& other)//we choose the operator > to be how is older by using our > of date
 {
	 return (*(this->printDate) > *(other.printDate));
 }

 bool BankDoc::operator%(BankDoc& other)////who has bigger precent of bank number/words,return true if "this" has bigger 
 {
	 return((bankNumber / this->getWords()) > (other.bankNumber / other.getWords()));
 }



ostream& operator<<(ostream& out, const BankDoc& d)throw(bad_cast)//printing by using our document <<
{
	
	out << (Document&)d<< "bank Number : " << d.bankNumber << endl << "branch number : " << d.branchnumber << endl << "NumberOfDocs : " << d.NumberOfBankDocs << endl << "Print Date : " << *(d.printDate) << endl;
	return out;
}

//void BankDoc::RealTimeCash(BankDoc& me) 
//{
//	cout << "At : " << me.GetDate() << endl;
//	cout << "your bank deposite:" << CompanyDoc::getbankcash() << endl;
//}

istream& operator>>(istream& in, BankDoc& p)throw(const char*)// take input from the user and put them into document object
{
	int bankNumber;
	int branchnumber;
	Date printDate;
	try
	{
		in >> (Document&)p;//using father >>
		cout << "please enter bank number between :  1-99" << endl;
		in >> bankNumber;
		p.SetBunkNumber(bankNumber);
		cout << "please enter branch number number between : 100-999" << endl;
		in >> branchnumber;
		p.Setbranchnumber(branchnumber);
		cout << "please enter print date" << endl;
		in >> printDate;
		p.SetDate(&printDate);
	}
	catch (...)//in case of any throw ,i will want to delete what have been saved, and tell that to the user
	{
		p.~BankDoc();
		throw("You made Mistake and this document will not be saved\n");
	}
	return in;
}
