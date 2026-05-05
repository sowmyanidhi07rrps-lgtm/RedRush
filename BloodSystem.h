//========================================
//BloodSystem.h
//Header File for blood coordination
//Author:Sowmya
//========================================

#include<iostream>
#include<string>
#include "Donor.h"
using namespace std;
template <class T>
void ShowDetail(string label, T value){
	cout<<label<<":"<<value<<endl;
}
class BloodBank{
public:
	BloodUnit units[100];
	int count;
	static int totalUnits;
	BloodBank();
	~BloodBank();
	void addUnit(BloodUnit u);
	int isAvailable(string bloodGroup);
	void displayInventory;
	void checkExpiry();
	static int showTotalUnits();
	friend class MatchingEngine;
};
class EmergencyRequest{
	public:
		string patientName, bloodGroupNeeded, urgencyLevel;
		static int totalRequests;
		EmergencyRequest(string name, string bg, string urgency);
		~EmergencyRequest();
		void display();
		void display(string straMessage);
		int operator>(EmergencyRequest r);
		static int showTotalRequests();
};
class MatchingEngine{
	public:
			void MatchFromBank(EmergencyRequest req, BloodBank bank);
			void matchFromDonors(EmergencyRequest req, Donor donors[], int DonorCount);
			void findMatch(EmergencyRequest req, BloodBank bank, Donor donors[], int donorCount);
};

