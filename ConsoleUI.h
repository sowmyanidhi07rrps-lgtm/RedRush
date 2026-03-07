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
   Menu(string t)
   {
     title=t;
   }
void display(string options[],int size)
{
  cout<<endl;
  cout<<"===== "<< title << "====="<<endl;
  int i=0;
  while(i<size)
  {
    cout<<i+1<<". "<<options[i]<<endl;
    i=i+1;
  }
  cout<<"Enter your choice: ";
  }
};
class Table
{
  public:
    string heading;
    Table(string h)
    {
      heading=h;
    }
    ~Table()
    {
    }
    void printHeader(string col1,string col2,string col3)
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
    void printRow(string v1,string v2,string v3)
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
    void printFooter()
    {
      cout<<"+---------------+------------------+-----------------+"<<endl;
    }
};
#endif
int main()
{
  string options[]={"Add Donor","Search donor","Exit"};
  Menu m("Blood Bank System");
  m.display(options,3);
  Table t("Donor List");
  t.printHeader("Name","Blood","City");
  t.printRow("Ravi","A+","Delhi");
  t.printRow("Aman","O+]","Lucknow");
  t.printFooter();
  return 0;
}
