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



// shows member information
void Member::showInfo(){
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
string Member::getFullName(){
    return fullName;
}
int Member::getPoints(){
    return points;
}
double Member::getRentScoreAverage(){
    return rentScoreAverage;
}

Request* Member::getRequest(){
    return myRequest;
}

Motorbike* Member::getRentedBike(){
    return rentedBike;
}

void Member::pushReview(Review* review){
    rentReviews.push_back(review);
}

// sets my request if Member sends rent request
void Member::setMyRequest(Request &request){
    this->myRequest = &request;
}

// rents bike if request status is true
void Member::rentBike(Motorbike &rentedBike){
    if(myRequest->status == true){
        // rentedBike.setRentStatus(true);
        this->rentedBike = &rentedBike;
        cout <<"Motorbike Rented successfully!" << endl;
    } else {
        cout << "Your request is not accepted yet!" << endl;
    }
    
}

// writes review for bike
void Member::writeReview(){
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
//Take in the Motorbike object and the rental time as parameters.
// void Member::sendRequest(Motorbike &motorbike, Date start, Date end) {
//         Request *request = new Request();
//         request->renter = this;
//         request->rentalBike = &motorbike;
//         request->start = start;
//         request->end = end;
//         int rentingDays = end - start; // Calculate renting days
//         request->credit = rentingDays * motorbike.getPointsPerDay(); // Use to calculate credit
// }
// deduct credit if rented successfully
void Member::creditDeduction(int credit){
    this->points = this->points - credit;
}
// charge credit
void Member::chargeCredit(){

}
// add credit if motorbike is rented
void Member::addCredit(){

}

// show my reviews from Owners
void Member::showMemberReviews(){
    cout << "\n<    Reviews I received    >" << endl;
    cout << "My average rating: " << getAverageScore() << endl;
    for(int i = 0; i < rentReviews.size(); i++){
        cout << i+1 << ". ";
        rentReviews[i]->showReview();
    }
}

// calculate average rating score
double Member::getAverageScore(){
    double total = 0;
    int index = 0;
    for(int i =0; i < rentReviews.size(); i++){
        total += rentReviews[i]->getScore();
        index++;
    }
    this->rentScoreAverage = total / index;
    return rentScoreAverage;
}


