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
        Motorbike *myBike;

    public:
        Owner(){}

        Owner(string fullName, string username, string password, int phoneNumber, int licence, string expiryDate, int points, double rentScoreAverage,Motorbike* rentedBike, Request *myRequest,vector<Review*> rentReviews, vector<Request*> listOfRequests, Motorbike *myBike) : 
        Member(fullName, username, password, phoneNumber, licence, expiryDate, points, rentScoreAverage, rentedBike, myRequest, rentReviews),
        listOfRequests(listOfRequests),myBike(myBike){}

        ~Owner() override {}

        void writeReview(Member &member){
            Review* review = new Review;
            int score;
            string comment;

            cout << "\nPlease write the review for the renter:" << endl;
            cout << "Score (1-10): ";
            cin >> score;
            cin.ignore(1);
            cout << "Write comment: ";
            getline(cin,comment);
            review->setScore(score);
            review->setComment(comment);
            member.pushReview(review);
        }

        // sets my motobike that is for rent
        void setMotorbike(Motorbike &myBike){
            this->myBike = &myBike;
        };

        string getName(){
            return getFullName();
        }

        friend class Motorbike;
};
