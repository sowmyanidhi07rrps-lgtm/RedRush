# RedRush
# Emergency Blood Donor Coordination System

RedRush is a terminal-based project that coordinates blood donors, manages blood bank inventory, and matches emergency requests with compatible donors in real time. The system aims at "reducing the time taken to find the right blood and right donor at the time of emergencies".

## Team Members and Role
Shubhranshi Srivastava (ConsoleUI Library, Menu and Table display)
Sowmya Nidhi (BloosSystem module, MatchingEngine, main() Function)
Aakriti (Donor Management, BloodUnit, BloodBank)

## Features
1) Register blood donors with an eligibility check
2) Add blood units to the blood bank
3) View the complete blood bank inventory
4) Raise an emergency blood request with urgency levels
5) Automatic matching of requests with the blood bank and donors
6) Expiry alerts for blood units
7) View all registered donors
8) System statistics dashboard
9) Exception handling for invalid inputs

## OOP Concepts Used
1) Classes and Objects -- All 7 classes(Menu,Table,Person,Donor,BloodUnit,BloodBank,EmergencyRequests,MatchingEngine)
2) Constructors and Destructors -- Every class has both
3) Abstract Base Class -- Person class with pure virtual function
4) Polymorphism -- display() overidden in Donor from Person
5) Function Overloading -- display() with and without parameters in Menu and EmergencyRequests 
6) Operator Overloading -- == in Donor, > in EmergencyRequests
7) Static Variables and Functions -- totalDonors, totalUnits, totalRequests
8) Friend Class -- MatchingEngine is a friend class of BloodBank
9) Templates -- showDetail() function in BloodSystem
10) Exception Handling -- try, throw, catch for individual age,quantity and urgency
11) Inheritance -- Donor inherits from Person
