#ifndef __MENU
#define __MENU
#include "CarDoc.h"
#include <vector>
#include <algorithm>  
#include <iostream>
#include <fstream>


class MenuManager
{
	vector<Document*> MyDocGarage;// all the douments that found in my garage, yes we had a car business
public:
	MenuManager() :MyDocGarage(NULL) { };
	MenuManager(vector<Document*>& Doc);
	MenuManager(MenuManager& other);
	void DeleteDoc(Document* Doc);
	void AddDoc(Document* Doc);
	Document* ScanDoc(long int id);
	friend ostream& operator<<(ostream& out, const MenuManager& d);
	void Print();
	void StartProgram();
	bool HonesteyLiscens(Document* Doc);
	void TotalWords();
	string WhoPrintedFirst(Document* Doc1, Document* Doc2);
	~MenuManager();
	CarDoc* MakeCarDoc(ifstream& MyFile);
	CompanyDoc* MakeCompanyDoc(ifstream& MyFile);
	BankDoc* MakeBankDoc(ifstream& MyFile);
	void AddAllText();
	void WriteToTXTFile();
};

#endif