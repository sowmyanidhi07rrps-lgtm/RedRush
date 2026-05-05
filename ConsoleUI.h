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
