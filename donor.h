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
    Person(string n, int a);
   ~Person();
    virtual ~Person();
    virtual void display() = 0;
};

//================================================
//DONOR CLASS
//===============================================

class Donor : public Person{

public: 
   string bloodGroup;
   int daysSinceLastDonation;
   string medicalCondition;
   static int totalDonors;

public:
  Donor();
  Donor(string n, int a,string bg,int days,string condition);
  ~Donor();

  int isEligible();
  void checkEligibility();
  void display();
  void display(string title);

  int operator==(Donor d);

  static int showTotalDonors()

  string getName();
  string getBloodGroup();
};

//==================================================
//BLOOD UNIT CLASS
//==================================================

class BloodUnit{
public:
   string bloodGroup;
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
