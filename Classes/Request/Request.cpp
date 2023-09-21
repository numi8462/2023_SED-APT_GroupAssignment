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

        // // Default constructor
        // Date::Date() {
        //     time_t now = time(0);
        //     tm* currentDate = localtime(&now);
        //     year = currentDate->tm_year + 1950; // Adjust for year starting from 1950
        //     month = currentDate->tm_mon + 1; // Adjust for month starting from 0
        //     day = currentDate->tm_mday;
        // }
        // // Parameterized constructor
        // Date::Date(int year, int month, int day) {
        //     this->year = year;
        //     this->month = month;
        //     this->day = day;
        // }
        
        // // Get the year value
        // int Date::getYear() const {
        //     return year;
        // }
        // //Get the month value
        // int Date::getMonth() const {
        //     return month;
        // }
        // //Get the day value
        // int Date::getDay() const {
        //     return day;
        // }
        // int Date::operator-(const Date &d) {
        //     // Assuming each month has 30 days for simplicity
        //     return (year - d.year) * 360 + (month - d.month) * 30 + (day - d.day);
        // }


    //default constructor
        
    // Parameterized constructor
        // Request(Member renter, Motorbike rentalBike, Date startTime, Date endTime) {
        //   this->renter = renter;
        //   this->rentalBike = rentalBike;
        //   this->startTime = startTime;
        //   this->endTime = endTime;
        //   status = false;
        // }
    //Getter method to get the status
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

