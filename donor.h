//==============================================
//donor.h
//contains class declaration
//===============================================

#ifndef DONOR_H
#define DONOR_H

#include<iostream>
#include<string>

using namespace std;

//===============================================
//PERSON CLASS
//===============================================

class person {

protected:
    string name;
    int age;
public:
   person(string n, int a);
   ~person();
};

//================================================
//DONOR CLASS
//===============================================

class donor : public person{

private: 
   string bloodgroup;
   int dayssincelastdonations;

   static int totaldonors;

public:
  donor();
  donor(string n, int a,string bg,int days);
  ~donor();

  bool iseligible();

  void display();
  void display(string title);

  bool operator==(const donor &d);

  int showtotaldonors();

  string getname()
  string getbloodgroup();
};

//==================================================
//BLOOD UNIT CLASS
//==================================================

class bloodunit{
private:
   string bloodgroup;
   int quantity;
   int expirydays;

public:
   bloodunit();
   bloodunit(string bg, int qty,int exp);
   ~bloodunit();

 bool isexpired();
 bool isexpiringsoon();

 void display();

};

#endif
