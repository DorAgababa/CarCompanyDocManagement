#ifndef _DATE_H_
#define _DATE_H_
#define CURRENT_YEAR 2022
#include <iostream>
#define SEPT 9
using namespace std;
class Date
{
protected:
	int day;
	char* month;
	int year;
public:
	Date(int day, char* month, int year = CURRENT_YEAR);
	Date();
	~Date() { delete[] month; }
	Date(const Date& other);
	const Date& operator=(const Date& other);
	//virtual void show() const = 0;
	void setDate(int day, char* month, int year);
	void setDay(int day);
	void setMonth(char* month);
	void setYear(int year);
	friend ostream& operator<<(ostream& out, const Date& p);
	friend istream& operator>>(istream& in, Date& p);
	int getDay() const { return day; }
	char* getMonth() const { return month; }
	int getYear() const { return year; }
	bool operator > (const Date& other) const;
	bool operator== (const Date& other) const;
};
#endif