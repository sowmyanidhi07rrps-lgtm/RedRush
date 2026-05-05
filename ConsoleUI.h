//ConsoleUI.h
//Author: Shubhranshi
//RedRush display library
#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <string>
using namespace std;
class Menu
{
 public:
   string title;
   Menu(string t);
   ~Menu();
   void display(string options[],int size);
   void display(string options[],int size,string message);
};
class Table
{
  public:
    string heading;
    Table(string h);
    ~Table();
    void printHeader(string col1,string col2,string col3);
    void printRow(string v1,string v2,string v3);
    void printFooter();
};
#endif
#include "ConsoleUI.h"
Menu::Menu(string t)
{
  title=t;
}
Menu::~Menu()
{
}
void Menu::display(string options[],int size)
{
  cout<<endl;
  cout<<"===== "<<title<< "====="<<endl;
  int i=0;
  while(i<size)
  {
    cout<<i+1<<". "<<options[i]<<endl;
    i=i+1;
  }
  cout<<"Enter your choice: ";
  }
 Table::Table(string h)
 {
   heading=h;
 }
 Table::~Table()
 {
 }
 void Table::printHeader(string col1,string col2,string col3)
 {
      cout<<endl;
      cout<<" "<< heading <<endl;
      cout<<"+----------------+----------------+-----------------+"<<endl;
      cout<<"|"<<col1;
      int i=col1.length();
      while(i<17)
      {
        cout<<" ";
        i=i+1;
      }
      cout<<"|"<<col2;
      i=col2.length();
      while(i<17)
      {
        cout<<" ";
        i=i+1;
      }
      cout<<"|"<<col3;
      i=col3.length();
      while(i<17)
      {
        cout<<" ";
        i=i+1;
      }
      cout<<"|"<<endl;
      cout<<"+-------------+---------------+--------------+"<<endl;
    }
    void Table::printRow(string v1,string v2,string v3)
    {
      cout<<"|"<<v1;
      int i= v1.length();
      while(i<17)
      {
        cout<<" ";
        i=i+1;
      }
      cout<<"|"<<v2;
      i=v2.length();
      while(i<17)
      {
        cout<<" ";
        i=i+1;
      }
      cout<<"|"<<v3;
      i=v3.length();
      while(i<17)
      {
        cout<<" ";
        i=i+1;
      }
      cout<<"|"<<endl;
    }
    void Table::printFooter()
    {
      cout<<"+-----------------+------------------+-----------------+"<<endl;
    }
  return 0;
}
