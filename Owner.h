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

#include "Motorbike.h"
#include "Request.h"
#include "Member.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Owner : public Member {
    private:
        vector<Request*> listOfRequests;
        Motorbike *motorbike;
        double minimumRenterScore;
    public:
        Owner(){}

};
