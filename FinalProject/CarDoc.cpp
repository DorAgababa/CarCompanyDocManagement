#include "CarDoc.h"
const string CountryArray[2] = { "ISRAEL", "USA" };// the countries that allowed to be used in the Documents
bool CheckIfValidCountry(const string countryname)//check if the Given country is allowed
{
	for (int i = 0; i < 2; i++)
	{
		if (countryname == CountryArray[i])//run until it gets to a valid month with big leeters
		{
			return true;
		}
	}
	return false;
}
CarDoc::CarDoc(double bank_cash, string Cname, string OwnName, int words, char* name, int BankNumber, int Branchnumber, Date* PrintDate, string location, list<long>& CarList):Document(name,words),BankDoc(BankNumber,Branchnumber,PrintDate, name,  words),CompanyDoc(bank_cash,Cname,OwnName)//create car document with given values by using document constractor first and then the fathers constractor
{
	this->location = location;
	this->SetList(CarList);// uses the SetList function to verifie the list is currect
}



bool CarDoc::operator==(CarDoc& other)//make == by the operator == of his fathers that uses == of document , and check car details 
{
	return((BankDoc&)(*this) == (Document&)(other) && (CompanyDoc&)(*this) == (Document&)(other) && this->CarsList == other.CarsList && this->location == other.location);
}

bool CarDoc::Add(long car)throw(long)
{
	if (99999999 < car || car < 10000000)//the range of car licence is 8 
		throw(car);// throws the invalid car number
	if (this->CarExist(car))//check if it has valid number and if is exsit already
	{
		cout << "the car is already exist" << endl;
		return false;
	}
	else
	{
		this->CarsList.push_back(car);
	}
}

void CarDoc::SetLocation(const string name)throw(const char*)
{
	
		if (CheckIfValidCountry(name))//changes only if calid country
		{
			this->location = name;
			return;
		}
		else
			throw("No Such Country , ONLY ISRAEL, USA , and in big LETTERS !!!");
	
}

void CarDoc::SetList(list<long>& CarssList)throw(long int)// puts from Cars list in to my List  and checks if all Valid
{
	list <long>::iterator PointList;
	for (PointList = CarssList.begin(); PointList != CarssList.end(); PointList++)//checks that the values in the list are legal ( 8 digits) 
	{
		if (99999999 < *PointList || *PointList < 10000000)
			throw(*PointList);// throws the invalid car number
	}
	this->CarsList = CarssList;
} 


void CarDoc::AddCountryToCurrent(const string countryname)throw(char*)// function adds country to current countey
{
		if (countryname.find("&") != string::npos && CheckIfValidCountry(countryname))//run until it gets to a valid month with big leeters
		{
			this->location = this->location + " & " + countryname;
			return;
		}
		else
			throw("No Such Country , ONLY ISRAEL,  USA , and in big LETTERS !!!");
}

void CarDoc::deleteFromList(long Car)
{
	if (CarExist(Car)) { this->CarsList.erase(this->ReturnIteratorPlace(Car)) ; }
}

void CarDoc::operator-(long car)
{
	deleteFromList(car);
}

void CarDoc::operator+(long car)
{
	Add(car);
}

list<long>::iterator CarDoc::ReturnIteratorPlace (long car)throw(const char*)// can be used only when used CarExist before
{
	if (99999999 < car || car < 10000000)
		throw("Invalid CarNumber");
	list <long>::iterator PointList;
	for (PointList = this->CarsList.begin(); PointList != this->CarsList.end(); PointList++)//checks that the values in the list are legal ( 8 digits) 
	{
		if (*PointList == car)
			return PointList;
	}
}
bool CarDoc::CarExist(long car)throw(const char*)
{
	if (99999999 < car || car < 10000000)
		throw("Invalid CarNumber");
	list <long>::iterator PointList;
	if (this->CarsList.empty())
		return false;
	for (PointList = this->CarsList.begin(); PointList != this->CarsList.end(); PointList++)//checks that the values in the list are legal ( 8 digits) 
	{
		if (*PointList == car)
			return true;
	}
	return false;
}
 ostream& operator<<(ostream& out, const list<long>& d)
{
	  list <long>::const_iterator  PointList;
	for (PointList = d.begin(); PointList != d.end(); PointList++)
	{
		out << "Car :" << *PointList << endl;
	}
	return out;
}
ostream& operator<<(ostream& out, const CarDoc& d)
{
	out << (BankDoc&)d <<"Company Name: " << d.getCompanyName() << endl << "Owner Name: "<< d.getownerName() << endl << "Owner Name: "<< d.getbankcash() <<endl << "Location Name: "<< d.location <<endl<< d.CarsList;
	return out;
}

void CarDoc::show() const
{
	BankDoc::show();
	CompanyDoc::show();
	cout << this->CarsList << this->location << endl;
}

 istream& operator>>(istream& in, CarDoc& p)throw(const char*)//take input from the user when the value is invalid it throw error
 {
	 string ownerName, Companyname;
	 double bank_cash;
	 int amountCars = 0; long tmpidcar = 0;
	 list <long> CarsList;
	 string location;
	
		 try//in a situation of error in pressing values here 
		 {
			 in >> (BankDoc&)p;
		 }
		 catch (...)//we will catch the exception
		 {
			 throw ("you made mistake and this document will not save\n");//and end the process with execption
			 
		 }
		 try
		{
		 cout << "please enter location name" << endl;
		 in >> location;
		 p.SetLocation(location);
		 cout << "please enter ownerName" << endl;
		 in >> ownerName;
		 p.SetownerName(ownerName);
		 cout << "please enter bankcash" << endl;
		 in >> bank_cash;
		 p.SetBankCash(bank_cash);
		 cout << "please enter Company name" << endl;
		 in >> Companyname;
		 p.SetCompanyName(Companyname);
		 cout << "please enter how many cars you want to insert? if none 0" << endl;
		 in >> amountCars;
		 for (int i = 0; i < amountCars; i++)
		 {
			 cout << "insert Car ID 8 digits" << endl;
			 in >> tmpidcar;
			 p.Add(tmpidcar);
		 }
	 }
	 catch (...)//if something went wrong the document will removed
	 {
		 
		 delete &p;
		 throw ("you made mistake and this document will not save\n");
	 }
	 return in;
}