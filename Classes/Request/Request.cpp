/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Group Assignment
  Group: 25
  Compiler used: Compiler version g++ 9.2.0
  Created  date: 14/09/2023
  Acknowledgement: https://codereview.stackexchange.com/questions/182480/date-class-in-c
*/
#include "Request.h"
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Member;
class Motorbike;

//Getter method to get the status
int Request::getCredit(){return credit;}
bool Request::getStatus() { return status; }
bool Request::getDecline() { return decline;}
string Request::getRenterID() { return renterID;}
string Request::getOwnerID() { return ownerID;}

// sets the required amount of credit for rent
void Request::setCredit(int credit) {
  this->credit = credit;
}

// sets request status
void Request::setStatus(bool status) {
  this->status = status;
}

void Request::setDecline(bool decline){
  this->decline = decline;
}

void Request::setRenterID(string renterID) {
  this->renterID = renterID;
}

void Request::setOwnerID(string ownerID) {
  this->ownerID = ownerID;
}

void Request::showInfo(){
  cout << "Renter ID: " << renterID;
  cout << ", Owner ID: " << ownerID;
  cout << ", Total Payment: " << credit;
  if(status == false){
    cout << ", Status: Pending";
  } else {
    cout << ", Status: Approved";
  }
  cout << ", Decline: " << decline;

}

