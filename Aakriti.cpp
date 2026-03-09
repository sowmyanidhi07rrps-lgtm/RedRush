// ================================================
// Donor.cpp
// Author: Akriti
// Source file for donor management
// ================================================

#include "Donor.h"


// PERSON CLASS

Person::Person(string n, int a) {
    name = n;
    age = a;
}

Person::~Person() {
}


// DONOR CLASS

int Donor::totalDonors = 0;

Donor::Donor() : Person("",0) {
    bloodGroup = "";
    daysSinceLastDonation = 0;
}

Donor::Donor(string n,int a,string bg,int days) : Person(n,a) {
    bloodGroup = bg;
    daysSinceLastDonation = days;
    totalDonors = totalDonors + 1;
}

Donor::~Donor() {
}

int Donor::isEligible() {

    if(age >= 18 && age <= 60 && daysSinceLastDonation >= 56)
        return 1;

    return 0;
}

void Donor::display() {

    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Name        : " << name << endl;
    cout << "Age         : " << age << endl;
    cout << "Blood Group : " << bloodGroup << endl;
    cout << "Last Donated: " << daysSinceLastDonation << " days ago" << endl;

    if(isEligible()==1)
        cout << "Status      : Eligible to Donate" << endl;
    else
        cout << "Status      : Not Eligible" << endl;

    cout << "--------------------------" << endl;
}

void Donor::display(string title) {

    cout << endl;
    cout << title << endl;
    display();
}

int Donor::operator==(Donor d) {

    if(bloodGroup == d.bloodGroup)
        return 1;

    return 0;
}

int Donor::showTotalDonors() {
    return totalDonors;
}

string Donor::getName() {
    return name;
}

string Donor::getBloodGroup() {
    return bloodGroup;
}


// BLOOD UNIT CLASS

BloodUnit::BloodUnit() {
    bloodGroup="";
    quantity=0;
    expiryDays=0;
}

BloodUnit::BloodUnit(string bg,int qty,int exp) {
    bloodGroup=bg;
    quantity=qty;
    expiryDays=exp;
}

BloodUnit::~BloodUnit() {
}

int BloodUnit::isExpired() {

    if(expiryDays <= 0)
        return 1;

    return 0;
}

int BloodUnit::isExpiringSoon() {

    if(expiryDays > 0 && expiryDays <= 5)
        return 1;

    return 0;
}

void BloodUnit::display() {

    cout << endl;
    cout << "--------------------------" << endl;
    cout << "Blood Group : " << bloodGroup << endl;
    cout << "Quantity    : " << quantity << " units" << endl;
    cout << "Expiry      : " << expiryDays << " days" << endl;

    if(isExpired())
        cout << "Status      : EXPIRED - Remove!" << endl;

    else if(isExpiringSoon())
        cout << "Status      : Expiring Soon!" << endl;

    else
        cout << "Status      : Good" << endl;

    cout << "--------------------------" << endl;
}
