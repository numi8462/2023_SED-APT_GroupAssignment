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
// class Date {
//     private:
//         string requestID;
//         int year;
//         int month;
//         int day;
//     public:
//         // Default constructor
//         Date() {
//             time_t now = time(0);
//             tm* currentDate = localtime(&now);
//             year = currentDate->tm_year + 1950; // Adjust for year starting from 1950
//             month = currentDate->tm_mon + 1; // Adjust for month starting from 0
//             day = currentDate->tm_mday;
//         }
//         // Parameterized constructor
//         Date(int year, int month, int day);
        
//         // Get the year value
//         int getYear() const;
//         //Get the month value
//         int getMonth() const;
//         //Get the day value
//         int getDay() const;
//         int operator-(const Date &d);
// };
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
        Request(string renterID, string ownerID, int credit, bool status,bool decline){
          this->renterID = renterID;
          this->ownerID = ownerID;
          this->credit = credit;
          this->status = false;
          this->decline = false;
        };
        
    // Parameterized constructor
        // Request(Member renter, Motorbike rentalBike, Date startTime, Date endTime) {
        //   this->renter = renter;
        //   this->rentalBike = rentalBike;
        //   this->startTime = startTime;
        //   this->endTime = endTime;
        //   status = false;
        // }

        //Getter
        bool getStatus();
        int getCredit();
        string getRenterID();
        string getOwnerID();
        bool getDecline();
        // setter
        void setCredit(int credit);
        void setStatus(bool status);
        void setDecline(bool decline);
        void setRenterID(string renterID);
        void setOwnerID(string ownerID);

        friend class Member;
};

#endif