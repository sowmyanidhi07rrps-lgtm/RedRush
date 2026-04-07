//=========================================================
//donor.cpp
//Author:Aakriti
//Source file for donor management 
//==========================================================

#include "donor.h"


//PERSON CLASS

person:: person(string n int a);{
      name = n;
      age = a;
}

person:: ~person(){
}


//DONOR CLASS

int donor::totaldonors=0

donor::donor() : person("",0){
     bloodgroup="";
    dayssincelastdonation = 0;
}

donor::donor(string n,int a,string bg,int days) : person (n,a) {
    bloodgroup=bg;
    dayssincelastdonation =0;
    totaldonors = totaldonors+1;
}

donors::~donors(){
}

int donor :: iseligible() {
    
    if(age >=18 && age <= 60 && dayssincelastdonation >= 56)
        return 1;
    
return 0;
}

void donor :: display(){

    cout<<endli;
    cout<<"-------------------------"<<endl;
    cout<<"name:     << name << endl;
    cout<<"age:      << age << endl;    
    cout<<"blood group:   << bloodgroup <<endl;
    cout<<"last donated:   << dayssincelastdonation  <<endl;

    if(iseligible()==1)
        cout << "status   :eligible to donate" <<endl;
   else
        cout << "status   :not eligible" <<endl;

  cout<<"------------------------------"<<endl;
}

void donor :: display(string title){

    cout<<endl;
    cout<<title <<endl;
    display();
}

int donor :: operator == (donor d){

    if(bloodgroup == d.bloodgroup)
        return 1;

return 0;
}

int donor :: showtotaldonors(){
    return totaldonors;
}

string donor :: getname() {
    retun name;
}

string donors :: getbloodgroup() {
    return bloodgroup;
}


//BLOOD UNIT CLASS

bloodunit :: bloodunit() {
   bloodgroup=" ";
   quantity=0;
   expirydays=0;
}

bloodunit :: bloodunit(string bg,int qty,int exp) {
    bloodunit=bg;
    quantity=qty;
    expirydays=exp;
}

bloodunit :: ~bloodunit() {
}

int bloodunit :: isexpired(){

    if(expirydays <= 0)
        return 1;

return 0;
}

int bloodunit :: isexpiringsoon() {

    if(expirydays > 0 && expirydays <=5)
        return 1;

return 0;
}

void bloodunit :: display() {

    cout << endl;
    cout<<"-------------------------------"<< endl;
    cout<<"blood group :  "<<bloodgroup <<endl;
    cout<<"quantity:   :" <<quantity <<"units" << endl;
    cout<<"expiry:    "<<expirydays<<"days" <<endl;

if(isexpired())
    cout<<"status:  expired -remove!" <<endl;

else if(isexpiringsoon())
    cout<<"status:  expiring soon!" <<endl;

else 
    cout<<"status:    good!" <<endl;

cout<<"------------------------------------------"<<endl;
}

        

    
