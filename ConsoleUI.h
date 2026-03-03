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
 private:
   string title;
 public:
   Menu(string t)
   {
     title=t;
   }
void display(string options[],int size)
{
  cout<<"\n===== "<< title << "====="<<endl;
  for(int i=0;i<size;i++)
  {
    cout<<i+1<<". "<<options[i]<<endl;
  }
  cout<<"Enter your choice: ";
  }
};
class Table
{
  public:
    static void showHeader()
    {
      cout<<"\nName\tBlood Group\tCity\Contact"<<endl;
      cout<<"---------------------------------------"<<endl;
    }
static void showRow(string name,string blood,string city,string contact)
 {
  cout<<name<<"\t"<<blood<<"\t\t"<<city<<"\t"<<contact<<endl;
 }
};
class Alert
{
  public:
    static void success(string msg)
    {
      cout<<"\nSuccess: "<<msg<<endl;
    }
    static void error(string msg)
    {
      cout<,"\nError: "<<msg<<endl;
    }
};
#endif
int main()
{
  string options[]={"Add Donor","Search donor","Exit"};
  Menu m("Blood Bank System");
  m.display(options,3);
Table::showHeader();
Table::showRow("mahi","A+","Lucknow","9874521584");
Alert::success("Donor Found");
return 0;
