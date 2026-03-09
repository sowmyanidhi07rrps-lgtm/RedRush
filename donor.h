// ================================================
// Donor.h
// Header file for donor management
// Contains class declarations
// ================================================

#ifndef DONOR_H
#define DONOR_H

#include<iostream>
#include<string>

using namespace std;


// ================================================
// PERSON CLASS
// ================================================

class Person {

protected:
    string name;
    int age;

public:
    Person(string n, int a);
    ~Person();
};


// ================================================
// DONOR CLASS
// ================================================

class Donor : public Person {

private:
    string bloodGroup;
    int daysSinceLastDonation;

    static int totalDonors;

public:
    Donor();
    Donor(string n, int a, string bg, int days);
    ~Donor();

    int isEligible();

    void display();
    void display(string title);

    int operator==(Donor d);

    int showTotalDonors();

    string getName();
    string getBloodGroup();
};


// ================================================
// BLOOD UNIT CLASS
// ================================================

class BloodUnit {

private:
    string bloodGroup;
    int quantity;
    int expiryDays;

public:
    BloodUnit();
    BloodUnit(string bg, int qty, int exp);
    ~BloodUnit();

    int isExpired();
    int isExpiringSoon();

    void display();
};

#endif
