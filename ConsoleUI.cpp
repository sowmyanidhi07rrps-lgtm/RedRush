//ConsoleUI.cpp
#include "ConsoleUI.h"
static void printCell(const string& val,int colWidth)
{
  cout<<"|"<<val;
  int spaces=colWidth-(int)val.length();
  if(spaces<1)spaces=1;
  for(int i=0;i< spaces;i++)
    cout<<" ";
}
static void printDivider(int cols,int colWidth)
{
  for(int c=0;c< cols;c++)
    {
      cout<<"+";
      for(int i=0;i< colWidth+1;i++)
        cout<<"-";
    }
  cout<<"+"<<endl;
}
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
void Menu::display(string options[],int size,string message)
{
  cout<<endl;
  cout<<"===== "<<title<<" ====="<<endl;
  if(!message.empty())
    cout<<">> "<<message<<endl;
  for(int i=0;i<size;i++)
    {
      cout<<i+1<<". "<<options[i]<<endl;
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
static int calcColWidth(string col1,string col2,string col3,string v1,string v2,string v3)
{
  int w=10;
  if((int)col1.length()>w)w=col1.length();
  if((int)col2.length()>w)w=col2.length();
   if((int)col3.length()>w)w=col3.length();
   if((int)v1.length()>w)w=v1.length();
   if((int)v2.length()>w)w=v2.length();
   if((int)v3.length()>w)w=v3.length();
  return w+2;
}
 void Table::printHeader(string col1,string col2,string col3)
 {
      int w=10;
      if((int)col1.length()>w)w=col1.length();
      if((int)col2.length()>w)w=col2.length();
      if((int)col3.length()>w)w=col3.length();
      w+=2;
      cout<<endl;
      cout<<" "<< heading <<endl;
      printDivider(3,w);
      printCell(col1,w);
      printCell(col2,w);
      printCell(col3,w);
      cout<<"|"<<cendl;
      printDivider(3,w);
    }
    void Table::printRow(string v1,string v2,string v3)
    {
      int w=10;
      if((int)v1.length()>w)w=v1.length();
      if((int)v2.length()>w)w=v2.length();
      if((int)v3.length()>w)w=v3.length();
      w+=2;
      printCell(v1,w);
      printCell(v2,w);
      printCell(v3,w);
      cout<<"|"<<endl;
    }
    void Table::printFooter(int colWidth)
    {
      printDivider(3, colWidth);
    }
  return 0;
}
