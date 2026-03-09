//BloodSystem.cpp
//author: Sowmya
//RedRush- Emergency Blood Donor Coordination System

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
	cout<<"Patient Name: ";
	cin>>patientName;
	cout<<"Blood Group Needed: ";
	cin>>bloodGroupNeeded;
	cout<<"Urgency Level(Critical/Moderate/Low): ";
	cin>>urgencyLevel;
	cout<<"Request No: ";
	cin>>totalRequests;
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
int EmergencyRequest::showTotalRequests(){
	return totalRequests;
}
