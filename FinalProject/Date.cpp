#include "Date.h"

Date::Date(int day, char* month, int year)//sets the date using the Sets Methods
{
	this->setDate(day, month, year);
}

Date::Date()
{
	this->year = 2022;
	this->day = 24;
	this->month = _strdup("FEBRUARY");//defaultive date, great date <3 
}

Date::Date(const Date& other)//using operator = to copy from one to another one
{
	this->month = NULL;//taking care of dynamic alloction
	*this = other;
}

const Date& Date::operator=(const Date& other)//check that they arent same and copy the details
{
	if (this != &other)
	{
		this->day = day;//there is no need to use Set methods because "other" is already has valid details 
		if (this->month != NULL)
			delete[] this->month;
		this->month = _strdup(other.month);
		this->year = other.year;
	}
	return *this;
}

void Date::setDate(int day, char* month, int year)//sets date using the sets we already made in the class
{
	this->setDay(day);
	this->setMonth(month);
	this->setYear(year);
}

void Date::setDay(int day) throw(const char*)//if the day is invalid throws exception 
{
	if ((day >= 1) && (day <= 31))
	{
		this->day = day;
	}
	else
		throw "Invalid day";

}
const char arr[12][10] = { "JANUARY" ,"FEBRUARY","MARCH", "APRIL", "MAY", "JUNE", "JULY","AUGUST","SEPTEMBER","OCTOBER", "NOVEMBER","DECEMBER"};// a local array that will be useful for == and >

void Date::setMonth(char* month)throw(const char*)//Sets the month 
{
	if (month == NULL) { throw("Month cant be NULL !!!"); }//check that isnt null
	for (int i = 0; i < 12; i++)
	{
		if (!strcmp(month, arr[i]))//run until it gets to a valid month with big leeters
		{
			if (this->month != NULL)//in a situation of a month that is already has memory delete it
				delete[] this->month;
			this->month = _strdup(month);
			return;
		}
	}
	throw("Months MUST BE in CAPTIAL Letters! only this months can be chosen : JANUARY ,FEBRUARY,MARCH, APRIL, MAY, JUNE, JULY,AUGUST,SEPTEMBER,OCTOBER, NOVEMBER, DECEMBER");
}

int MontheValue(char* Month) //the functon takes an char* month and return integer value of the month
{
	for (int i = 0; i < 12; i++)
		if (!strcmp(Month, arr[i])) { return  (i + 1); }//as you see each month value is +1 then the array Index
}

void Date::setYear(int year)
{
	this->year = year;// a document can be made before "zero year"
}

bool Date::operator>(const Date& other) const//we chose to return true if the dates are equal or "this" comes from then "other"
{
	int MonthOther = MontheValue(other.month), Monththis = MontheValue(this->month);//use a new function we made names "monthvalue"
	if (this->year > other.year)
		return false;
	else if (this->year < other.year)
		return true;
	else//the year is equal!
	{
		if (Monththis > MonthOther)
			return false;
		else if (Monththis < MonthOther)
			return true;
		else//the month is equal!
		{
			if (this->day > other.day)
				return false;
			return true;
		}
	}

}

bool Date::operator==(const Date& other) const//checks if the dates are the same
{
	return (&other!= NULL && other.day == this->day && !strcmp(other.month, this->month) && this->year == other.year);
}

ostream& operator<<(ostream& out, const Date& p)//prints date
{
	out << p.day << " - " << p.month << " - " << p.year;
	return out;
}

istream& operator>>(istream& in, Date& p)// take input from the user and put them into date object
{
	int day = 0, year = 0;
	char tmp[10];//the max letters in month is 9
	cout << "please enter day: ";
	in >> day;
	cout << endl << "please enter month:\n (Months MUST BE in CAPTIAL Letters! only this months can be chosen : JANUARY ,FEBRUARY,MARCH, APRIL, MAY, JUNE, JULY,AUGUST,SEPTEMBER,OCTOBER, NOVEMBER, DECEMBER)\n";
	in >>tmp ;
	cout <<endl<< "please enter year: ";
	in >> year;
	p.setDate(day, tmp, year);//sets all the detail with our function
	return in;
}

