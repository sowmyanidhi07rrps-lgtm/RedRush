//=========================================================
//donor.cpp
//Author:Aakriti
//Source file for donor management 
//==========================================================

#include "donor.h"


//PERSON CLASS

Person:: Person(string n ,int a){
      name = n;
      age = a;
}

Person:: ~Person(){
}


//DONOR CLASS

int Donor::totalDonors=0;

Donor::Donor() : Person("",0){
     bloodGroup="";
     daysSinceLastDonation = 0;
     medicalCondition="none"; 
}

Donor::Donor(string n,int a,string bg,int days,string condition) : Person (n,a) {
    bloodGroup=bg;
    daysSinceLastDonation =days;
    medicalCondition =condition;  
    totalDonors = totalDonors+1;
}

Donor::~Donor(){
}

int Donor :: isEligible() {
    
    if(age >=18 && age <= 60 && daysSinceLastDonation >= 56 && medicalCondition =="none")
        return 1;
    
return 0;
}
void Donor::checkEligibility(){
cout<<endl;
cout<<"==Eligbility Check=="<<endl;
cout<<"name:"<<name<<endl;
if(age>=18 && age<=60)
      cout<<"age: ok"<<endl;
else
      cout<<"age:fail"<<endl;
if(daysSinceLastDonation>=56)
      cout<<"days:ok"<<endl;
else
      cout<<"Days:Fail"<<endl;
if(medicalCondition=="NONE")
      cout<<"Condition:ok"<<endl;
else
      cout<<"condition:fail"<<endl;
if(isEligible()==1)
      cout<<"Result: NOT ELIBIBLE"<<endl;
}

void Donor :: display(){

    cout<<endl;
    cout<<"-------------------------"<<endl;
    cout<<"Name: "    << name << endl;
    cout<<"Age: "     << age << endl;    
    out << "Blood Group: " << bloodGroup << endl;
    cout<<"last donated:   << daysSinceLastDonation  <<endl;

    if(isEligible()==1)
        cout << "status   :eligible to donate" <<endl;
   else
        cout << "status   :not eligible" <<endl;

  cout<<"------------------------------"<<endl;
}

void Donor :: display(string title){
    cout<<"MEedical conditiom:"<<medicalCondition<<endl;
    cout<<endl;
    cout<<title <<endl;
    display();
}

int Donor :: operator == (Donor d){

    if(bloodGroup == d.bloodGroup)
        return 1;

return 0;
}

int Donor::showTotalDonors(){
      return totalDonors;
}

string Donor :: getName() {
    retun name;
}

string Donor::getbloodGroup() {
    return bloodGroup;
}


//BLOOD UNIT CLASS

BloodUnit :: BloodUnit() {
   bloodGroup=" ";
   quantity=0;
   expiryDays=0;
}

BloodUnit :: BloodUnit(string bg,int qty,int exp) {
    bloodunit=bg;
    quantity=qty;
    expiryDays=exp;
}

BloodUnit :: ~BloodUnit() {
}

int BloodUnit :: isExpired(){

    if(expiryDays <= 0)
        return 1;

return 0;
}

int BloodUnit :: isExpiringSoon() {

    if(expiryDays > 0 && expiryDays <=5)
        return 1;

return 0;
}

void BloodUnit :: display() {

    cout << endl;
    cout<<"-------------------------------"<< endl;
    cout<<"blood":<<"  "<<bloodGroup <<endl;
    cout<<"quantity:   :" <<quantity <<"units" << endl;
    cout<<"expiry:    "<<expiryDays<<"days" <<endl;

if(isexpired())
    cout<<"status:  expired -remove!" <<endl;

else if(isexpiringsoon())
    cout<<"status:  expiring soon!" <<endl;

else 
    cout<<"status:    good!" <<endl;

cout<<"------------------------------------------"<<endl;
}

        

    
