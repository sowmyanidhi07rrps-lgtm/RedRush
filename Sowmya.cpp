//main.cpp
//author: Sowmya
//RedRush- Emergency Blood Donor Coordination System
#include<string>
using namespace std;

//storing detail of one emergency request
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
		//shows total number of request
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
