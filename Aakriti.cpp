//main.cpp
//author: Sowmya
//RedRush- Emergency Blood Donor Coordination System
#ifndef BLOODBANKMODULE_H
#define BLOODBANKMODULE_H

#include <iostream>
#include <vector>
using namespace std;

// ===================== CLASS 1 : DONOR =====================
class Donor {
private:
    string name;
    int age;
    string bloodGroup;
    int daysSinceLastDonation;

public:
    // Constructor
    Donor(string n, int a, string bg, int days) {
        name = n;
        age = a;
        bloodGroup = bg;
        daysSinceLastDonation = days;
    }

    // Check eligibility
    bool canDonate() {
        if (age >= 18 && age <= 60 && daysSinceLastDonation >= 56)
            return true;
        return false;
    }

    // Display donor info
    void displayDonor() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Blood Group: " << bloodGroup << endl;

        if (canDonate())
            cout << "Status: Eligible to Donate\n";
        else
            cout << "Status: Not Eligible to Donate\n";
    }

    string getBloodGroup() {
        return bloodGroup;
    }
};

// ===================== CLASS 2 : BLOOD UNIT =====================
class BloodUnit {
private:
    string bloodGroup;
    int quantity;      // in ml
    int daysToExpire;

public:
    // Constructor
    BloodUnit(string bg, int qty, int days) {
        bloodGroup = bg;
        quantity = qty;
        daysToExpire = days;
    }

    string getBloodGroup() {
        return bloodGroup;
    }

    int getDaysToExpire() {
        return daysToExpire;
    }

    void displayBloodUnit() {
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Quantity: " << quantity << " ml" << endl;
        cout << "Days to Expire: " << daysToExpire << endl;

        if (daysToExpire < 5)
            cout << "WARNING: Expiry less than 5 days!\n";
    }
};

// ===================== CLASS 3 : BLOOD BANK =====================
class BloodBank {
private:
    vector<BloodUnit> storage;

public:
    void addBloodUnit(BloodUnit unit) {
        storage.push_back(unit);
    }

    bool isAvailable(string group) {
        for (int i = 0; i < storage.size(); i++) {
            if (storage[i].getBloodGroup() == group)
                return true;
        }
        return false;
    }

    void showExpiringUnits() {
        for (int i = 0; i < storage.size(); i++) {
            if (storage[i].getDaysToExpire() < 5) {
                storage[i].displayBloodUnit();
            }
        }
    }

    int totalUnits() {
        return storage.size();
    }
};

#endif

