#define _CRT_SECURE_NO_WARNINGS
#include "MenuManager.h"
#include <iostream>
#include <fstream> 

void main()
{
	ifstream MyFile("OUT.txt", ios::in);
	MenuManager a;
	char* c1 = new char[5];
	strcpy(c1,"dodo");
	Document* doc1 = new CompanyDoc(150,"YUval","bar",8,c1);
	Document* doc2 = new CompanyDoc(120, "AHMED", "MUHAMAD", 10, c1);
	a.AddDoc(doc1);
	a.AddDoc(doc2);
	a.AddAllText();
	a.StartProgram();
	a.WriteToTXTFile();
	delete[] c1;

}