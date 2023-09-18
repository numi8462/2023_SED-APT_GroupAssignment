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
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Member {
    private:
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
    public:
        Member(){};
        Member( string fullName, string username, string password, int phoneNumber, int licence, string expiryDate, int points, double rentScoreAverage,Motorbike* rentedBike,Request *myRequest, vector<Review*> rentReviews ){
            this->fullName = fullName;
            this->username = username;
            this->password = password;
            this->phoneNumber = phoneNumber;
            this->licenceNumber = licence;
            this->expiryDate = expiryDate;
            this->points = points;
            this->rentScoreAverage = rentScoreAverage;
            this->rentedBike = rentedBike;
            this->myRequest = myRequest;
            this->rentReviews = rentReviews;
        };
        virtual ~Member() {}
        // shows member information
        void showInfo(){
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
            cout << "Rented Bike: " << endl;
            rentedBike->showInfo();
        }
        
        // getters
        string getFullName(){
            return fullName;
        }
        int getPoints(){
            return points;
        }
        double getRentScoreAverage(){
            return rentScoreAverage;
        }

        Request* getRequest(){
            return myRequest;
        }

        Motorbike* getRentedBike(){
            return rentedBike;
        }

        void pushReview(Review* review){
            rentReviews.push_back(review);
        }

        // sets my request if Member sends rent request
        void setMyRequest(Request &request){
            this->myRequest = &request;
        }

        // rents bike if request status is true
        void rentBike(Motorbike &rentedBike){
            if(myRequest->status == true){
                // rentedBike.setRentStatus(true);
                this->rentedBike = &rentedBike;
                cout <<"Motorbike Rented successfully!" << endl;
            } else {
                cout << "Your request is not accepted yet!" << endl;
            }
            
        }

        // writes review for bike
        void writeReview(){
            Review* review = new Review;

            int score;
            string comment;

            cout << "Please write the review for rented bike:" << endl;
            cout << "Score (1-10): ";
            cin >> score;
            cin.ignore(1);
            cout << "Write comment: ";
            getline(cin,comment);
            review->setScore(score);
            review->setComment(comment);
            rentedBike->pushReview(review);
        }

        // deduct credit if rented successfully
        void creditDeduction(int credit){
            this->points = this->points - credit;
        }

        // show my reviews from Owners
        void showMemberReviews(){
            cout << "\n<    Reviews I received    >" << endl;
            cout << "My average rating: " << getAverageScore() << endl;
            for(int i = 0; i < rentReviews.size(); i++){
                cout << i+1 << ". ";
                rentReviews[i]->showReview();
            }
        }

        // calculate average rating score
        double getAverageScore(){
            double total = 0;
            int index = 0;
            for(int i =0; i < rentReviews.size(); i++){
                total += rentReviews[i]->getScore();
                index++;
            }
            this->rentScoreAverage = total / index;
            return rentScoreAverage;
        }

};