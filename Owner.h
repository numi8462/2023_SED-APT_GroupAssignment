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

class Owner : public Member {
    private:
        vector<Request*> listOfRequests;
        Motorbike *motorbike;
    public:
        Owner(){}

        Owner(string fullName, string username, string password, int phoneNumber, int licence, string expiryDate, int points, double rentScoreAverage,Motorbike* rentedBike, Request myRequest,vector<Review*> rentReviews, vector<Request*> listOfRequests, Motorbike *motorbike) : 
        Member(fullName, username, password, phoneNumber, licence, expiryDate, points, rentScoreAverage, rentedBike, myRequest, rentReviews),
        listOfRequests(listOfRequests),
        motorbike(motorbike)
        {}


        

        // sets my motobike that is for rent
        void setMotorbike(Motorbike *motorbike){
            this->motorbike = motorbike;
        };

        string getName(){
            return getFullName();
        }

        friend class Motorbike;
};
