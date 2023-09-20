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
#include <iostream>
#include <vector>
#include <ctime>


// getters
string Motorbike::getCity(){return city;}
int Motorbike::getPointsPerDay(){return pointsPerDay;}
double Motorbike::getRatingAverage(){return ratingAverage;}
double Motorbike::getMinimumRenterScore() { return minimumRenterScore; }

//setters
void Motorbike::setCity(string city) { this->city = city; }
void Motorbike::setPointsPerDay(int pointsPerDay) { this->pointsPerDay = pointsPerDay; }
void Motorbike::setRatingAverage(double ratingAverage) { this->ratingAverage = ratingAverage; }
void Motorbike::setBikeID(string bikeID) {this->bikeID = bikeID; }
void Motorbike::setOwnerID(string ownerID) {this->ownerID = ownerID; }
void Motorbike::setModel(string model) {this->model = model; }
void Motorbike::setColor(string color) {this->color = color; }
void Motorbike::setEngineSize(string engineSize) {this->engineSize = engineSize; }
void Motorbike::setMode(string mode) {this->mode = mode; }
void Motorbike::setYearMade(string yearMade) {this->yearMade = yearMade; }
void Motorbike::setDescription(string description) {this->description = description; }

// sets the minimum renter score
void Motorbike::setMinimumRenter(double score){
    this->minimumRenterScore = score;
};

// sets the renting period for my bike
void Motorbike::setRentingPeriod(){
  
};

void Motorbike::setRentStatus(bool rent){
  this->rent = rent;
}

void Motorbike::pushReview(Review* review){
  reviews.push_back(review);
}

// shows motorbike info
void Motorbike::showDetailedInfo(){
  cout << "Owner: " << ownerID << endl;
  cout << "Model: " << model << endl;
  cout << "Color: " << color << endl;
  cout << "Engine Size: " << engineSize << endl;
  cout << "Mode: " << mode << endl;
  cout << "Year Made: " << yearMade << endl;
  cout << "Description: " << description << endl;
  cout << "Rent: " << rent << endl;
  cout << "Rating Average: " << ratingAverage << endl;
  cout << "Renting Start: " << rentingStart << endl;
  cout << "Renting End: " << rentingEnd << endl;
  cout << "City: " << city << endl;
  cout << "Points Per Day: " << pointsPerDay << endl; 
  cout << "Reviews: " << endl;
  for(int i = 0; i < reviews.size(); i++){
    reviews[i]->showReview();
  }
}

// shows brief info of bike
void Motorbike::showInfo(){
  cout << "\n<  Rented Motorbike Information  >" << endl;
  cout << "Owner: " << ownerID << ", Model: " << model <<", Credit per day: " << pointsPerDay << ", City: " << city << "\n" << endl;
}

void Motorbike::showRentInfo(){

}

void Motorbike::showRentReviews(){
  cout << "\n<  Motorbike Reviews  >" << endl;
  cout << "Motorbike average rating: " << getAverageRating() << endl;
  for(int i = 0; i < reviews.size(); i++){
    cout << i+1 << ". ";
    reviews[i]->showReview();
  }
}
// calculate average bike score
double Motorbike::getAverageRating(){
    double total = 0;
    int index = 0;
    for(int i =0; i < reviews.size(); i++){
        total += reviews[i]->getScore();
        index++;
    }
    this->ratingAverage = total / index;
    return ratingAverage;
}