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
#ifndef MEMBER_H
#define MEMBER_H
#include "../../Motorbike/Motorbike.cpp"
#include "../../Request/Request.cpp"
#include "../../Review/Review.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Member {
    private:
        string memberID;
        string fullName;
        string username;
        string password;
        int phoneNumber;
        string idType;
        int idNumber;
        int licenceNumber;
        string expiryDate;
        int points;
        double rentScoreAverage;
        Motorbike* rentedBike;
        Request* myRequest;
        vector<Review*> rentReviews;
        vector<Request*> listOfRequests;
        Motorbike *myBike;
    public:
        Member(){};
        Member( string fullName, string username, string password, int phoneNumber, int licence, string expiryDate){
            this->fullName = fullName;
            this->username = username;
            this->password = password;
            this->phoneNumber = phoneNumber;
            this->licenceNumber = licence;
            this->expiryDate = expiryDate;
            this->points = 20;
            this->rentScoreAverage = 10;
            this->rentedBike = nullptr;
            this->myRequest = nullptr;
            this->rentReviews = {};
        };
        virtual ~Member() {}
        // shows member information
        void showInfo();
        
        // getters
        string getFullName();
        int getPoints();
        double getRentScoreAverage();

        Request* getRequest();

        Motorbike* getRentedBike();

        void pushReview(Review* review);

        // sets my request if Member sends rent request
        void setMyRequest(Request &request);

        // rents bike if request status is true
        void rentBike(Motorbike &rentedBike);

        // writes review for bike
        void writeReview();
        //Take in the Motorbike object and the rental time as parameters.
        // void sendRequest(Motorbike &motorbike, Date start, Date end);
        // deduct credit if rented successfully
        void creditDeduction(int credit);
        // charge credit
        void chargeCredit();
        // add credit if motorbike is rented
        void addCredit();

        // show my reviews from Owners
        void showMemberReviews();

        // calculate average rating score
        double getAverageScore();

};

#endif