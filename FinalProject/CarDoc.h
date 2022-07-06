#ifndef __DOCUMENT_Car
#define __DOCUMENT_Car
#include "BankDoc.h"
#include "CompanyDoc.h"
#include <List>
#include <iterator>

class CarDoc :public BankDoc,public CompanyDoc
{
	list <long> CarsList;
	string location;
	list<long>::iterator ReturnIteratorPlace(long car);//internal function ,private cause for only internal use 
public :
	CarDoc() :Document(), BankDoc(), CompanyDoc(), location("Israel"), CarsList(NULL) {  };//create car document by using document constractor first and then the fathers constractor
	CarDoc(double bank_cash, string Cname, string OwnName, int words, char* name, int BankNumber, int Branchnumber, Date* PrintDate, string location, list<long>& CarList);//create car document with given values by using document constractor first and then the fathers constractor
	virtual void show() const;//print all the uniqe 
	friend ostream& operator<<(ostream& out, const CarDoc& d);//print the car doc by using the << of Bank doc that use << of document, and then printing the uniqe values of company and car
	virtual bool operator==(CarDoc& other);//make == by the operator == of his fathers that uses == of document , and check car details 
	bool Add(long car);// add car to my list
	string GetLocation() const { return location; }//return the location
	list<long> GetList() const { return CarsList; }//return the list
	void SetLocation(const string name);//sets the location with given location
	void SetList(list<long>& CarssList);//sets the list with another list given
	void AddCountryToCurrent(const string countryname);//add function represent the option to car company to have work at another country
	void deleteFromList(long Car);//delete ab car from the list
	void operator-(long car);//remove a car by the the licence car
	void operator+(long car);//add a car by the the licence car
	bool CarExist(long car);//checks if the car exist
	friend ostream& operator<<(ostream& out, list<long>& d);//we add a option to print list of cars that use us to the general print
	friend istream& operator>>(istream& in, CarDoc& p);//taking all details in 
};
#endif

