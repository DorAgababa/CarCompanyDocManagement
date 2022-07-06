#include "Document.h"
#include<stdio.h>
#include<string.h>


Document::Document()//creating a empty document
{
	this->name = NULL;
	this->words=0;
	this->id = CounterID++;
	

}

Document::Document(char* name,  int words)//sets a new doc with all needed
{
	setName(name);
	this->id = CounterID++;
	setWords(words);
}

Document::Document(const Document& other)//using operator = to copy from one to another one
{
	this->name = NULL;
	*this = other;
	this->id = CounterID++;
}

const Document& Document::operator=(const Document& other)//check that they arent same and copy the details exclude id
{
	if (this != &other)
	{
		this->setName(other.name);
		this->setWords(other.words);
		
	}
	return *this;
}

bool Document::operator==(Document& other)//verfy that the data is the same exclude id
{
	return(&other != NULL && !strcmp(other.name, this->name) && other.words == this->words);
}

Document& Document::operator+(const Document& o)// adding the number of words of "o" to "this" words.
{
	this->setWords(this->words + o.words);//using by sets method to validate that is has final valid number
	return *this;
}


void Document::setName(char* name)throw(const char*)//sets the name of the document
{
	if (name == NULL)
		this->name = name;
	if (this->name != NULL)
		delete[] this->name;
	this->name = _strdup(name);//creating dynamic memory for name 
}

void Document::setWords(int words)throw(const char*)
{
	if (words < 0)
		throw("Words Cant be negative number !!!");
	this->words = words;
}



ostream& operator<<(ostream& out, const Document& d)
{
	out << "Doucument name: " << d.name << endl << "Doc ID: "  << d.id << endl << "Number Of Words: " << d.words << endl;
	//d.show();
	return out;
}

istream& operator>>(istream& in, Document& p)//operator >> help us to take from the user an document object
{
	char tmp[256];
	int words;
	cout << "please enter name of document : ";
	in >> tmp;
	p.setName(tmp);//by using sets
	cout << endl<< "please enter positive amount of words:";
	in >> words;
	p.setWords(words);//by using sets
	return in;
}
