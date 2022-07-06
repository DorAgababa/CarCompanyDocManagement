#include "MenuManager.h"

MenuManager::MenuManager(vector<Document*>& Doc)//create menu manager by document* vector given
{
    this->MyDocGarage = Doc;
}
 
MenuManager::MenuManager(MenuManager& other)//create menu manager by other menu manager given
{
    this->MyDocGarage = other.MyDocGarage;
}

void MenuManager::DeleteDoc(Document* Doc)throw(char*)//delete speciphic doc from the menu manager
{
    if (this->MyDocGarage.empty())//check isnt empty
        throw("Cant DELETE From empty Document !!!");
   vector<Document*>::iterator it;
    it = find(this->MyDocGarage.begin(), this->MyDocGarage.end(), Doc);//using find that return us the iterator for the item in the vector
    if (it != this->MyDocGarage.end())
    {
        this->MyDocGarage.erase(it);
        delete  Doc;//USING distractor by polymorphis ,it's go to the correct distractor and then from there to dad distractor ...
        cout << "Item Deleted" << endl;
        return;
    }
    else
        cout << "No such item"<<endl;
}

void MenuManager::AddDoc(Document* Doc)//adding doc by push_back 
{
    this->MyDocGarage.push_back(Doc);//there is no need to check if it valid cause its already doc
}

Document* MenuManager::ScanDoc(long int id)//the function found a doc in the vector by id
{
    vector <Document*>::iterator PointList;
   
    for (PointList = this->MyDocGarage.begin(); PointList != this->MyDocGarage.end(); PointList++)
    {
        if (id == (*PointList)->getID())//run until find the iter with the same id, id is uniqe so there is only one
            return *PointList;
    }
    cout << "no such ID" << endl;
    return NULL;//in a way of no such one like that
}
void printOne(Document* printMe)
{
    if (dynamic_cast<CarDoc*>(printMe))//verfy wich type is it 
    {
        cout << *(dynamic_cast<CarDoc*>(printMe)) << endl;//printing by the suitable << 
        return;
    }
    if (dynamic_cast<BankDoc*>(printMe))//verfy wich type is it 
    {
        cout << *(dynamic_cast<BankDoc*>(printMe)) << endl;//printing by the suitable << 
        return;
    }
    if (dynamic_cast<CompanyDoc*>(printMe))//verfy wich type is it 
    {
        cout << *(dynamic_cast<CompanyDoc*>(printMe)) << endl;//printing by the suitable << 
        return;
    }
}
void MenuManager::Print()// print all docs
{
    vector <Document*>::const_iterator PointList;
    for (PointList = this->MyDocGarage.begin(); PointList != this->MyDocGarage.end(); PointList++)//run on the vector 
    {
        printOne(*PointList);
    }
}

void MenuManager::StartProgram()//menu 
{
    
    int internalRes = -1;
    long ScanedId;
    do {
        try {
            cout << "Choose What to do 1-7 , 0 to stop" << endl;//all the method we worte
            cout << "1 to Add Document" << endl << "2 to Delete Document " <<endl<< "3 Find Document" << endl << "4 to Check Honesty of Document" << endl << "5 to Who Printed First" << endl << "6 how many words at all Docs" << endl << "7 print all documents" << endl;
            cin >> internalRes;
            switch (internalRes)
            {
            case(1)://case of add 
            {
                cout << "Please enter Type of Doc: " << endl << "1 to CompanyDoc, 2 to BankDoc, 3 to CarDoc" << endl;
                int switch_on = -1;
                cin >> switch_on;
                switch (switch_on)// create doc accort to what you press
                {
                case(1):
                {
                    CompanyDoc* tmp = new CompanyDoc();
                    cin >> *tmp;
                    cout << *tmp;
                    AddDoc(tmp);
                    break;
                }
                case(2):
                {
                    BankDoc* tmp = new BankDoc();
                    cin >> *tmp;
                    cout << *tmp;
                    AddDoc(tmp);
                    break;
                }

                case(3):
                {
                    CarDoc* tmp = new CarDoc();
                    cin >> *tmp;
                    cout << *tmp << endl;
                    AddDoc(tmp);
                    break;
                }
                }
                break;
            }
            case(2):
            {
                cout << "please enter id of document that you want to erase: ";
                cin >> ScanedId;
                DeleteDoc(ScanDoc(ScanedId));//to check wich distractor
                break;
            }
            case(3):
            {
                cout << "please enter id of document that you want to find: ";
                cin >> ScanedId;
                printOne(ScanDoc(ScanedId));//printing by id
                break;
            }
            case(4):
            {
                cout << "please enter id of document that you want to check honesty for him: ";
                cin >> ScanedId;
                cout << endl;
                if (HonesteyLiscens(ScanDoc(ScanedId)))
                    cout << "true" << endl;
                else
                    cout << "false" << endl;
                break;
            }
            case(5):
            {
                long scan2;
                cout << "please enter id of document that you want to compare: ";
                cin >> ScanedId;
                cout << "please enter another id of document that you want to compare: ";
                cin >> scan2;
                cout << WhoPrintedFirst(ScanDoc(ScanedId), ScanDoc(scan2)) << endl;//check how is older and write what is the name
                break;
            }
            case(6):
            {
                TotalWords();//print sum of the words
                break;
            }
            case(7):
            {
                Print();//printing all 
                break;
            }
            }
        }
        catch (const char* ex)//catch many things
        {
            cout << ex;
        }
        catch (long exp)
        {
            cout << exp;
        }
        catch (bad_cast er)
        {
            cout << "you try to make casting but its failed";
        }
        catch (...) { cout << "another exption happend" << endl; }
    } while (internalRes != 0);

}

bool MenuManager::HonesteyLiscens(Document* Doc)// checks if cash is more then 10000, if the company is Fair(like in method) and if there are more then 1000 words in doc
{
    if (!strcmp(typeid(Doc).name(), typeid(CarDoc).name()))
    {
        CarDoc* tmp = dynamic_cast<CarDoc*>(Doc);
        return(tmp->getbankcash() > 10000 && tmp->Fairness(*tmp)&& tmp->longg());
    }
}

void MenuManager::TotalWords()// sum all words in all docs
{
    int sum = 0;
    vector <Document*>::const_iterator PointList;
    for (PointList = this->MyDocGarage.begin(); PointList != this->MyDocGarage.end(); PointList++)
    {
        sum += (*PointList)->getWords();
    }
    cout << sum << endl;
}

string MenuManager::WhoPrintedFirst(Document* Doc1, Document* Doc2)// checks who printed first between two docs, needs to be or BanDoc or CarDoc
{
    if (!strcmp(typeid(*Doc1).name(), typeid(CarDoc).name()) || !strcmp(typeid(*Doc1).name(), typeid(BankDoc).name()))
    {
        if((!strcmp(typeid(*Doc2).name(), typeid(CarDoc).name())) || (!strcmp(typeid(*Doc2).name(), typeid(BankDoc).name())))
        {
            string a = " Is First";
            BankDoc docopy1 = dynamic_cast<BankDoc&>(*Doc1);
            BankDoc docopy2 = dynamic_cast<BankDoc&>(*Doc2);
            if (docopy1 > docopy2)//turns on the operator of date
            {
                return docopy1.getName() + a;
            }
            else
                return docopy2.getName() + a;
        }
    }
    return "there are no match between the function and the given parameters";
}

MenuManager::~MenuManager()//distractor work by polymorphizem
{
    vector <Document*>::const_iterator PointList;
    for (PointList = this->MyDocGarage.begin(); PointList != this->MyDocGarage.end(); PointList++)
    {
        delete * PointList;
    }
    this->MyDocGarage.clear();
}

CarDoc* MenuManager::MakeCarDoc(ifstream& MyFile)throw(const char*)//reading from the file cardoc
{
    if (!MyFile.is_open()) { throw("Cant Open File!"); }
    CarDoc* a = new CarDoc();
    MyFile >> *a;
    return a;
}

CompanyDoc* MenuManager::MakeCompanyDoc(ifstream& MyFile)throw(const char*)//reading from the file companydoc
{
    if (!MyFile.is_open()) { throw("Cant Open File!"); }
    CompanyDoc* a = new CompanyDoc();
    MyFile >> *a;
    return a;
}

BankDoc* MenuManager::MakeBankDoc(ifstream& MyFile)throw(const char*)//reading from the file bank doc
{
    if (!MyFile.is_open()) { throw("Cant Open File!"); }
    BankDoc* a = new BankDoc();
    MyFile >> *a;
    return a;
}

void MenuManager::AddAllText()//read from the input file to the vector by using the upper methods
{
    ifstream MyFile("input.txt", ios::in);
    char buf2[256]="sss";
    if (!MyFile.is_open()) { throw("Cant Open File!"); }
    while (!MyFile.eof())
    {
        MyFile.getline(buf2, 100);//read the type of the object
        if (strstr(typeid(CarDoc).name(), buf2))//goes to the one who is suitable
        {
            AddDoc((Document*)MakeCarDoc(MyFile));
            if (!MyFile.eof())
            {
                MyFile.seekg(2, ios::cur);//this one move the pointer of the file to after the /0 or /n
            }
            continue;
        }
        if (strstr(typeid(BankDoc).name(), buf2))
        {
            AddDoc((Document*)MakeBankDoc(MyFile));
            if (!MyFile.eof())
            {
                MyFile.seekg(2, ios::cur);
            }
            continue;
        }
        if (strstr(typeid(CompanyDoc).name(), buf2))
        {
            AddDoc((Document*)MakeCompanyDoc(MyFile));
            if (!MyFile.eof())
            {
                MyFile.seekg(2, ios::cur);
            }
            continue;
        }
    }system("CLS");
}

ostream& operator<<(ostream& out, const MenuManager& d)//printing operator ,turn in each object the suitable <<
{
    vector <Document*>::const_iterator PointList;
    for (PointList = d.MyDocGarage.begin(); PointList != d.MyDocGarage.end(); PointList++)
    {
        if (dynamic_cast<const CarDoc*>(*PointList))
        {
            out << *(dynamic_cast<CarDoc*>(*PointList)) << endl;
            continue;
        }
        if (dynamic_cast<BankDoc*>(*PointList))
        {
            out << *(dynamic_cast<BankDoc*>(*PointList)) << endl;
            continue;
        }
        if (dynamic_cast<CompanyDoc*>(*PointList))
        {
            out << *(dynamic_cast<CompanyDoc*>(*PointList)) << endl;
            continue;
        }
    }
    return out;
}
void MenuManager::WriteToTXTFile()//writing by the << operator of each one into OUT.txt in the end
{
    vector <Document*>::const_iterator PointList;
    ofstream MyFile("OUT.txt", ios::out);
    for (PointList = this->MyDocGarage.begin(); PointList != this->MyDocGarage.end(); PointList++)
    {
        if (dynamic_cast<CarDoc*>(*PointList))
        {
            MyFile << *(dynamic_cast<CarDoc*>(*PointList)) << endl;
            continue;
        }
        if (dynamic_cast<BankDoc*>(*PointList))
        {
            MyFile << *(dynamic_cast<BankDoc*>(*PointList)) << endl;
            continue;
        }
        if (dynamic_cast<CompanyDoc*>(*PointList))
        {
            MyFile << *(dynamic_cast<CompanyDoc*>(*PointList)) << endl;
            continue;
        }
    }
}

