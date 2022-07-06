#ifndef __DOCUMENT_H
#define __DOCUMENT_H
#include <iostream>
#include <iostream>
#include <fstream>
static long CounterID = 0;
using namespace std;
#include <stdlib.h>
class Document //abstract
{

	char* name;
	long id;
	int words;
public:
	Document();
	Document(char* name, int words);
	Document(const Document& other);
	virtual ~Document() { delete[] name; }
	const Document& operator=(const Document& other);
	friend ostream& operator<<(ostream& out, const Document& d);
	virtual void show() const = 0;
	bool operator==(Document& other);
	Document& operator+(const Document& o);
	char* getName() const { return name; }
	long getID() const { return id; }
	int getWords() const { return words; }
	void setName(char* name);
	void setWords(int words);
	bool longg() { return(words > 1000); } //length over 1000 words
	friend istream& operator>>(istream& in, Document& p);// take input from the user and put them into document object
};
#endif