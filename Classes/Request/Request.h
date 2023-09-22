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
#ifndef REQUEST_H
#define REQUEST_H
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Member;
class Motorbike;

class Request {
    private:
        string renterID;
        string ownerID;
        // Date start;
        // Date end;
        int credit;
        bool status;
        bool decline;
    public:
        //default constructor
        Request(){};
        Request(string renterID, string ownerID, int credit, bool status,bool decline){
          this->renterID = renterID;
          this->ownerID = ownerID;
          this->credit = credit;
          this->status = status;
          this->decline = decline;
        };

        //Getter
        string getRenterID();
        string getOwnerID();
        int getCredit();
        bool getStatus();
        bool getDecline();
        // setter
        void setCredit(int credit);
        void setStatus(bool status);
        void setDecline(bool decline);
        void setRenterID(string renterID);
        void setOwnerID(string ownerID);
        void showInfo();
        friend class Member;
};

#endif