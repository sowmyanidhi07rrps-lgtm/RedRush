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
void MatchingEngine::matchFromBank(EmergencyRequest req, BloodBank bank){
	cout<<endl;
	cout<<"==Searching Blood Ban==k"<<endl;
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
		if(donors[i].bloodGroup==req.bloodGroupNeeded && donors[i].isEligble()==1){
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
void MatchingEngine::findMatch(EmergencyRequest req, bloodBank bank, Donor donors[], int donorCount){
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
		matchFromBank(req,bank);
		matchFromDonors(req,donors,donorCount);
	}
}
int EmergencyRequest::showTotalRequests(){
	return totalRequests;
}
