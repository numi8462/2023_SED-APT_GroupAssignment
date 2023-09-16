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
#include <string>
#include <vector>
#include <ctime>
using namespace std;

class Request {
    private:
        Member renter;
        Motorbike rentalBike;
        time_t start;
        time_t end;
        int credit;
        bool status;
    public:
        Request(Member renter,Motorbike rentalBike,time_t start,time_t end,int credit,bool status) : renter(renter), rentalBike(rentalBike), start(start), end(end), credit(credit), status(status) {};

        void setCredit(int credit) {}
        void setStatus(bool status) {}
};