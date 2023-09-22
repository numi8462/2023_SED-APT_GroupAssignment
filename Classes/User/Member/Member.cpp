/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Group Assignment
  Group: 25
  Compiler used: Compiler version g++ 9.2.0
  Created  date: 14/09/2023
  Acknowledgement: 
*/

#include "Member.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;



// shows member information
void Member::showInfo(){
    cout << "Full Name: " << fullName << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "ID Type: " << idType << endl;
    cout << "ID Number: " << idNumber << endl;
    cout << "Licence Number: " << licenceNumber << endl;
    cout << "Expiry Date: " << expiryDate << endl;
    cout << "Points: " << points << endl;
    cout << "Rent Score Average: " << rentScoreAverage << endl;
    cout << "Rent Status: " << rentStatus << endl;
}

// getters
string Member::getMemberID(){return memberID;}
string Member::getFullName(){return fullName;}
string Member::getUsername(){return username;}  
string Member::getPassword(){return password;}
int Member::getPhoneNumber(){return phoneNumber;}
string Member::getIdType(){return idType;}
int Member::getIdNumber(){return idNumber;}
int Member::getLicenceNumber(){return licenceNumber;}
string Member::getExpiryDate(){return expiryDate;}
int Member::getPoints(){return points;}
double Member::getRentScoreAverage(){return rentScoreAverage;}
bool Member::getRentStatus(){return rentStatus;};

//setters

void Member::setMemberID(string memberID){this->memberID = memberID;}
void Member::setFullName(string fullName){this->fullName = fullName;}
void Member::setUsername(string username){this->username = username;}
void Member::setPassword(string password){this->password = password;}
void Member::setPhoneNumber(int phoneNumber){this->phoneNumber = phoneNumber;}
void Member::setIdType(string idType){this->idType = idType;}
void Member::setIdNumber(int idNumber){this->idNumber = idNumber;}
void Member::setLicenceNumber(int licenceNumber){this->licenceNumber = licenceNumber;}
void Member::setExpiryDate(string expiryDate){this->expiryDate = expiryDate;}
void Member::setPoints(int points){this->points = points;}
void Member::setRentScoreAverage(double rentScoreAverage){this->rentScoreAverage = rentScoreAverage;}
void Member::setRentStatus(bool rentStatus){this->rentStatus = rentStatus;}





