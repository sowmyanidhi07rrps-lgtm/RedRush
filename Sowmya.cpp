//main.cpp
//author: Sowmya
//RedRush- Emergency Blood Donor Coordination System

//==========================================
//EMERGENCYREQUEST CLASS
//STORIES DETAILS OF ONE EMERGENCY REQUEST
//==========================================
#include<string>
using namespace std;

//storing details of one emergency request
class EmergencyRequest{
	public:
		string PatientName, BloodGroupNeeded, UrgencyLevel;
		static int TotalRequests;
		
		EmergencyRequest(string name, string bg, string urgency){
			PatientName=name;
			BloodGroupNeeded=bg;
			UrgencyLevel=urgency;
			TotalRequests=TotalRequests+1;
		}
		~EmergencyRequest(){
		}
		void display(){
			cout<<endl;
			cout<<"============================"<<endl;
			cout<<"EMERGENCY REQUEST DETAILS"<<endl;
			cout<<"============================"<<endl;
			cout<<"Patient Name: "<<PatientName<<endl;
			cout<<"Blood Needed: "<<BloodGroupNeeded<<endl;
			cout<<"Urgency Level: "<<UrgencyLevel<<endl;
			cout<<"Request No: "<<TotalRequests<<endl;
			cout<<"============================"<<endl;
		}
		//operator overloading to check if the request is more urgent than the other
		int operator>(EmergencyRequest r){
			if(UrgencyLevel=="CRITICAL" && r.UrgencyLevel!="CRITICAL"){
				return 1;
			}
			return 0;
		}
		//shows the total number of requests
		static int showtotal(){
			return TotalRequests;
		}
};
int EmergencyRequest::TotalRequests=0;

int main(){
	string name,bg,urgency;
	cout<<endl;
	cout<<"----Raise Emergency Request----"<<endl;
	cout<<"Patient Name: ";
	cin>>name;
	cout<<"Blood Group Needed: ";
	cin>>bg;
	cout<<"Urgency Level(Critical/Moderate/Low): ";
	cin>>urgency;
	
	EmergencyRequest req(name,bg,urgency);
}

//==========================================
//MATCHINGENGINE CLASS
//FINDS RIGHT BLOOD FOR RIGHT PATIENT
//==========================================
//finds the right blood for the right patient
class MatchingEngine{
	public:
		//searching the blood bank for matching blood groups
		void MatchFromBank(EmergencyRequest req, BloodBank bank){
			cout<<endl;
			cout<<"==Searching Blood Ban==k"<<endl;
			if(bank.isAvailable(req.BloodGroupNeeded)==1){
				cout<<endl;
				cout<<"====MATCH FOUND IN BLOOD GROUP===="<<endl;
				cout<<"Blood Group: "<<req.BloodGroupNeeded<<endl;
				cout<<"Patient Name: "<<req.PatientName<<endl;
			}
			else{
				cout<<"====MATCH NOT FOUND IN BLOOD BANK===="<<endl;
			}
		}
		void MatchFromDonors(EmergencyRequest req, Donor donors[], int DonorCount){
			cout<<endl;
			cout<<"==Searching Donors=="<<endl;
			int found=0;
			int i=0;
			while(i<DonorCount){
				if(donors[i].BloodGroup==req.BloodGroupNeeded && donors[i].isEligble()==1){
					cout<<endl;
					cout<<"==DONOR FOUND=="<<endl;
					cout<<"Donor Name: "<<donors[i].Name<<endl;
					cout<<"Blood Group: "<<donors[i].BloodGroup<<endl;
					cout<<"Patient Name: "<<req.PatientName<<endl;
					found=1;
				}
				i=i+1;
			}
			if(found==0){
				cout<<"==NO ELIGIBLE DONOR FOUND=="<<endl;
			}
		}
		//checking bank then donor
		void FindMatch(EmergencyRequest req, BloodBank bank, Donor donors[], int DonorCount){
			cout<<endl;
			cout<<"================================="<<endl;
			cout<<"==START EMERGENCY MATCH=="<<endl;
			cout<<"================================="<<endl;
			req.display();
			if(req.UrgencyLevel=="CRITICAL"){
				cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
				cout<<"CRITICAL CASE URGENT"<<endl;
				cout<<"!!!!!!!!!!!!!!!!!!!!!"<<endl;
			}
			if(bank.isAvailable(req.BloodGroupNeeded)==1){
				MatchFromBank(req,bank);
			}
			else{
				MatchFromBank(req,bank);
				MatchFromDonors(req,donors,DonorCount);
			}
			cout<<"================================="<<endl;
		}
};





int main(){
	BloodBank bank;
	Donor donors[100];
	int DonorCount=0;
	MatchingEngine=engine;
	Menu mainMenu("RedRush- Blood Donation Coordination System");
	Table donorTable("Registered Donors");
	
	cout<<endl;
	cout<<"========================================="<<endl;
	cout<<"==Welcome to RedRush=="<<endl;
	cout<<"==Blood Donation Coordination System=="<<endl;
	cout<<"========================================="<<endl;
	
	string options[]={
		"Register Donor",
		"Add blood unit to blood bank",
		"View Blood Bank Inventory",
		"Raise Emergency Request",
		"Check Expiry Alerts",
		"View All Donors",
		"View Statistics",
		"Exit"
	};
	int choice;
	do{
		mainMenu.display(options,8);
		cin>>choice;
		if(choice==1){
			string name,bg;
			int age,days;
			cout<<endl;
			cout<<"====Regiser New Donor===="<<endl;
			cout<<"Enter Name: ";
			cin>>name;
			cout<<"Enter Age: ";
			cin>>age;
			cout<<"Enter Blood Group: ";
			cin>>bg;
			cout<<"Days since last donation: "<<endl;
			cout<<"Enter 0 if donation is for the first time";
			cin>>days;
			donors[DonorCount]=Donor(name,age,bg,days);
			DonorCount=DonorCount+1;
			cout<<endl;
			cout<<"====Donor Regitered Successfully!===="<<endl;
		} 
		else if(choice==2){
			string bg;
			int qty,exp;
			cout<<endl;
			cout<<"====Add Blood Unit===="<<endl;
			cout<<"Enter Blood Group: ";
			cin>>bg;
			cout<<"Enter Quantity: ";
			cin>>qty;
			cout<<"Enter Expiry Days: ";
			cin>>exp;
			bank.addUnit(new BloodUnit(bg,qty,exp))
			cout<<endl;
			cout<<"====Blood Unit Added Successfully!===="<<endl;
		}
		else if(choice==3){
			bank.displayInventory();
		}
		
	}
}
