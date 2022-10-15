#include <iostream>
#include "menu.h"
#include "read.hpp"
#include <sstream>
#define menuCount 8

using namespace std;

bool check(int a){return a>=0 && a<=menuCount;}
bool validate(int a){return true;}

void Menu::Run()
{
    int v;
    do{
        v=MenuPrint();
        switch(v)
        {
            case 1:
                insertElement();
                print();
                break;
            case 2:
                removeElement();
                print();
                break;
            case 3:
                isEmpty();
                break;
            case 4:
                isIn();
                print();
                break;
            case 5:
                rands();
                break;
            case 6:
                evens();
                break;
            case 7:
                print();
                break;
            case 8:
                loadTest();
                break;
            default:
                cout<<"\nGoodbye!\n";
                break;
        }
    }while(v!=0);
}

int Menu::MenuPrint()
{
    int choice;
    cout<<"\n****************************************\n";
    cout<<"0. Exit\n";
    cout<<"1. Insert an element\n";
    cout<<"2. Remove an element\n";
    cout<<"3. Check if the set is empty\n";
    cout<<"4. Check if an element exists in the set\n";
    cout<<"5. Get a random element from the set\n";
    cout<<"6. Number of even elements in the set\n";
    cout<<"7. Print the set\n";
    cout<<"8. Load test (how many integers we can put in to the set)\n";
    cout<<"****************************************\n";

    ostringstream s;
    s<<"Please choose a number between 0 and "<<menuCount<<"!";
    string errmsg=s.str();
    choice=read("Choose a menuitem: ",errmsg,check);

    return choice;
}

void Menu::insertElement()
{
    int e= read<int>("Integer element to be inserted into the set: ","Please input only integer type value!",validate);
    try{
        S.insert(e);
        cout<<"Success!\n"<<endl;
    }
    catch(Set::ExistingElementException err)
    {
        cerr<<"Insertion is unsuccessful. The element already exists!\n";
    }
}

void Menu::removeElement()
{
    int elem = read("Element to be removed from the set: ","Please input only integer type value!",validate);
    try{
        S.remove(elem);
        cout<<"Success!\n"<<endl;
    }
    catch(Set::NonExistingElementException err)
    {
        cerr<<"Removal is unsuccessful, the element does not exist!\n";
    }
}

void Menu::isEmpty()
{
    if(S.isEmpty()){
        cout<<"The set is empty!\n";
    }
    else{
        cout<<"The set is NOT empty!\n";
    }
}

void Menu::isIn()
{
    int elem = read("Element to be checked: ","Please input only integer type value!",validate);
    if (S.isIn(elem)) { cout<<"The element is IN the set!\n"<<endl; }
    else { cout<<"The element is NOT in the set!\n"<<endl; }
}

void Menu::rands(){
    try{
        cout<<"The random element from the set: "<<S.rand_elem();
    }
    catch(Set::EmptySetException err){
        cout<<"Cannot get a random element from the empty set!";
    }
}

void Menu::evens(){
    cout<<"The count of even element(s) in the set: "<<S.getEvens();
}

void Menu::print()
{
    cout<<S;
}

void Menu::loadTest()
{
    const int size=1000000;
    Set K;
    cout<<"Follow the current size of the set:\n";
    try{
        for(int i=1; i<size; ++i)
        {
            if(i%10000==0) cout<<i<<endl;
            K.insert(i);
        }
    }catch(...)
    {
        cout<<"The size of the set: "<<S.count()<<endl;
    }
}
