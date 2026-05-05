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

class Person {

public:
    string name;
    int age;
public:
   person(string n, int a);
   ~Person();
};

//================================================
//DONOR CLASS
//===============================================

class Donor : public Person{

public: 
   string bloodGroup;
   int daysSinceLastDonation;
   string medicalCondition;
   static int totaldonors;

public:
  Donor();
  Donor(string n, int a,string bg,int days,string condition);
  ~Donor();

  int isEligible();
  void checkEligiblity();
  void display();
  void display(string title);

  int operator==(Donor d);

  static int show totalDonor();

  string getName()
  string getBloodGroup();
};

//==================================================
//BLOOD UNIT CLASS
//==================================================

class bloodUnit{
public:
   string BloodGroup;
   int quantity;
   int expiryDays;

public:
   BloodUnit();
   BloodUnit(string bg, int qty,int exp);
   ~BloodUnit();

 int isExpired();
 int isExpiringSoon();

 void display();

};

#endif
