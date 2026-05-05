//BloodSystem.cpp
//author: Sowmya
//RedRush- Emergency Blood Donor Coordination System

#include "BloodSystem.h"
int EmergencyRequest::totalRequests=0;
int BloodBank::totalUnits=0;
BloodBank::BloodBank(){
	count=0;
}
BloodBank::~BloodBank(){
}
void BloodBank::addUnit(BloodUnit u){
	units[count]=u;
	count=count+1;
	totalUnits=totalUnits+1;
}
int BloodBank::isAvailable(string bloodGroup){
	int i=0;
	while(i<count){
		if(units[i].bloodGroup==bloodGroup && units[i].isExpired()==0){
			return 1;
		}
		i=i+1;
	}
	return 0;
}
void BloodBank::displayInventory(){
	if(count==0){
		cout<<endl;
		cout<<"==Blood Bank is empty=="<<endl;
		return;
	}
	cout<<endl;
	cout<<"==Blood Bank inventory=="<<endl;
	int i=0;
	while(i<count){
		units[i].display();
		i=i+1;
	}
	cout<<"Total Units: "<<totalUnits<<endl;
}
void BloodBank::checkExpiry(){
	cout<<endl;
	cout<<"==Expiry Alert=="<<endl;
	int found=0;
	int i=0;
	while(i<count){
		if(units[i].isExpired()==1){
			cout<<"CRITICAL: "<<units[i].bloodGroup<<" HAS EXPIRED!"<<endl;
			found=1;
		}
		else if(units[i].isExpiringSoon()==1){
			cout<<"WARNING!: "<<units[i].bloodGroup<<" EXPIRING IN"<<units[i].expiryDays<<"DAYS"<<endl;
			found=1;
		}
		i=i+1;
	}
	if(found==0){
		cout<<"==No Expiry Alert=="<<endl;
	}
}
int BloodBank::showTotalUnits(){
	return totalUnits;
}
EmergencyRequest::EmergencyRequest(string name, string bg, string urgency){
			patientName=name;
			bloodGroupNeeded=bg;
			urgencyLevel=urgency;
			totalRequests=totalRequests+1;
		}
EmergencyRequest::~EmergencyRequest(){
}
void EmergencyRequest::display(){
	cout<<endl;
	cout<<"====Raise Emergency Request===="<<endl;
	cout<<"Patient Name: "<<patientName<<endl;
	cout<<"Blood Group Needed: "<<bloodGroupNeeded<<endl;
	cout<<"Urgency Level(Critical/Moderate/Low): "<<urgencyLevel<<endl;
	cout<<"Request No: "<<totalRequests<<endl;
}
void EmergencyRequest::display(string extraMessage){
	display();
	cout<<extraMessage<<endl;
}
int EmergencyRequest::operator>(EmergencyRequest r){
		if(urgencyLevel=="CRITICAL" && r.urgencyLevel!="CRITICAL"){
			return 1;
		}
		return 0;
}
void MatchingEngine::matchFromBank(EmergencyRequest req, BloodBank bank){
	cout<<endl;
	cout<<"==Searching Blood Bank=="<<endl;
	if(bank.isAvailable(req.bloodGroupNeeded)==1){
		cout<<endl;
		cout<<"====MATCH FOUND IN BLOOD GROUP===="<<endl;
		cout<<"Blood Group: "<<req.bloodGroupNeeded<<endl;
		cout<<"Patient Name: "<<req.patientName<<endl;
	}
	else{
		cout<<"====MATCH NOT FOUND IN BLOOD BANK===="<<endl;
	}
}
void MatchingEngine::matchFromDonors(EmergencyRequest req, Donor donors[], int donorCount){
	cout<<endl;
	cout<<"==Searching Donors=="<<endl;
	int found=0;
	int i=0;
	while(i<donorCount){
		if(donors[i].bloodGroup==req.bloodGroupNeeded && donors[i].isEligible()==1){
			cout<<endl;
			cout<<"==DONOR FOUND=="<<endl;
			cout<<"Donor Name: "<<donors[i].name<<endl;
			cout<<"Blood Group: "<<donors[i].bloodGroup<<endl;
			cout<<"Patient Name: "<<req.patientName<<endl;
			found=1;
		}
		i=i+1;
	}
	if(found==0){
		cout<<"==NO ELIGIBLE DONOR FOUND=="<<endl;
	}
}
void MatchingEngine::findMatch(EmergencyRequest req, BloodBank bank, Donor donors[], int donorCount){
	cout<<endl;
	cout<<"================================="<<endl;
	cout<<"==START EMERGENCY MATCH=="<<endl;
	cout<<"================================="<<endl;
	req.display();
	if(req.urgencyLevel=="CRITICAL"){
		cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
		cout<<"CRITICAL CASE URGENT"<<endl;
		cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
	}
	if(bank.isAvailable(req.bloodGroupNeeded)==1){
		matchFromBank(req,bank);
	}
	else{
		matchFromDonors(req,donors,donorCount);
	}
}
int EmergencyRequest::showTotalRequests(){
	return totalRequests;
}
