//main.cpp
//author: Sowmya, Aakriti, Shubhranshi
//RedRush- Emergency Blood Donor Coordination System
#include<iostream>
#include<string>
#include"ConsoleUI.h"
#include"Donor.h"
#include"BloodSystem.h"
int main(){
	BloodBank bank;
	Donor donors[100];
	int DonorCount=0;
	MatchingEngine engine;
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
		"Check Donor Eligibility",
		"View Statistics",
		"Exit"
	};
	int choice;
	do{
		mainMenu.display(options,9);
		cin>>choice;
		if(choice==1){
			string name,bg,condition;
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
			cout<<"Any Medical Condition?"<<endl;
			cout<<"(HIV/HEPATITIS/DIABETES/CANCER/NONE)";
			cin>>condition;
			try{
				if(age<0){
					throw "Age can't be negative!";
				}
				if(days<0){
					throw "Days can't be negative!";
				}
				donors[donorCount]=Donor(name,age,bg,days,condition);
				donorCount=donorCount+1;
				cout<<"====Donor Regitered Successfully!===="<<endl;
			}
		catch(const char* error){
			cout<<endl;
			cout<<"Error: "<<error<<endl;
			cout<<"Please try again"<<endl;
		}
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
			try{
				if(qty<=0){
					throw "Quantity must be greater than 0!";
				}
				if(exp<=0){
					throw "Expiry days must be greater than 0!";
				}
				bank.addUnit(BloodUnit(bg,qty,exp));
				cout<<endl;
				cout<<"====Blood Unit Added Successfully!===="<<endl;
			}
			catch(const char* error){
			cout<<endl;
			cout<<"Error: "<<error<<endl;
			cout<<"Please try again"<<endl;
		}
	}
		else if(choice==3){
			bank.displayInventory();
		}
		
		else if(choice==4){
			string name,bg,urgency;
			cout<<endl;
			cout<<"====Raise Emergency Request===="<<endl;
			cout<<"Patient Name: ";
			cin>>name;
			cout<<"Blood Group Needed: ";
			cin>>bg;
			cout<<"Urgency Level(Critical/Moderate/Low): ";
			cin>>urgency;
			try{
				if(urgency!="CRITICAL" && urgency!="MODERATE" && urgency!="LOW") {
                    throw"Invalid urgency! Use Critical, Moderate or Low only";
                }
			EmergencyRequest req(name,bg,urgency);
			engine.findMatch(req,bank,donors,donorCount);
		}
			catch(const char* error){
			cout<<endl;
			cout<<"Error: "<<error<<endl;
			cout<<"Please try again"<<endl;
		}
	}
		else if(choice==5){
			bank.checkExpiry();
		}
		else if(choice==6){
			if (donorCount==0){
				cout<<endl;
				cout<<"==No Donors Registered=="<<endl;
			}
			else{
				donorTable.printHeader("Name","Blood Group","Status");
				int i=0;
				while(i<donorCount){
					string status;
					if(donors[i].isEligible()==1){
						status="==ELIGIBLE==";
					}
					else{
						status="==NOT ELIGIBLE==";
					}
					donorTable.printRow(donors[i].name,donors[i].bloodGroup,status);
					i=i+1;
				}
				donorTable.printFooter();
			}
		}
		else if(choice==7){
            if(donorCount==0){
                cout<<endl;
                cout<<"==No donors registered=="<<endl;
            }
			else{
                string searchName;
                cout<<endl;
                cout<<"====Check Donor Eligibility===="<<endl;
                cout<<"Enter Donor Name: ";
				cin>>searchName;
                int found=0;
                int i=0;
                while(i<donorCount){
                    if(donors[i].name==searchName){
                        donors[i].checkEligibility();
                        found=1;
                    }
                    i=i+1;
                }
                if(found==0){
                    cout<<endl;
                    cout<<"==Donor not found=="<<endl;
                }
            }
        }
		else if(choice==8){
            cout<<endl;
            cout<<"========================"<<endl;
            cout<<"SYSTEM STATISTICS"<<endl;
            cout<<"========================="<<endl;
            cout<<"Total Donors Registered: "<<DonorCount<<endl;
            cout<<"Total Blood Units: "<< BloodBank::showTotalUnits()<<endl;
            cout<<"Total Emergency Requests: "<<EmergencyRequest::showTotalRequests()<<endl;
        }
        else if(choice==9){
            cout<<endl;
            cout<<"====================================="<<endl;
            cout<<"Thank you for using RedRush"<<endl;
            cout<<"Saving lives one match at a time"<<endl;
            cout<<"====================================="<<endl;
        }
        else{
            cout<<endl;
            cout<<"Invalid choice! Please try again"<<endl;
        }

    } while(choice != 9);

    return 0;
}
