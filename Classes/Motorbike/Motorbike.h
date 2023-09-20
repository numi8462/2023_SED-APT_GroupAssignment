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

#ifndef MOTORBIKE_H
#define MOTORBIKE_H
#include "../Review/Review.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Review;
class Motorbike
{
private:
    string ownerID;
    string model;
    string color;
    string engineSize;
    string mode;
    string yearMade;
    string description;
    bool rent;
    double ratingAverage;
    vector<Review*> reviews;
    string city;
    int pointsPerDay;
    double minimumRenterScore;
public:
    Motorbike(){};
    Motorbike(string ownerID, string model, string color, string engineSize, string mode, string yearMade, string description, bool rent, double ratingAverage, vector<Review*> reviews, string city, int pointsPerDay, double minimumRenterScore){
        this->ownerID = ownerID;
        this->model = model;
        this->color = color;
        this->engineSize = engineSize;
        this->mode = mode;
        this->yearMade = yearMade;
        this->description = description;
        this->rent = rent;
        this->ratingAverage = ratingAverage;
        this->reviews = reviews;
        this->city = city;
        this->pointsPerDay = pointsPerDay;
        this->minimumRenterScore = minimumRenterScore;
    };

    // getters
    string getCity();
    int getPointsPerDay();
    double getRatingAverage();
    double getMinimumRenterScore() ;

    //setters
    void setCity(string city);
    void setPointsPerDay(int pointsPerDay);
    void setRatingAverage(double ratingAverage);
    void setBikeID(string bikeID);
    void setOwnerID(string ownerID);
    void setModel(string model);
    void setColor(string color);
    void setEngineSize(string engineSize);
    void setMode(string mode);
    void setYearMade(string yearMade);
    void setDescription(string description);


    // sets the minimum renter score
    void setMinimumRenter(double score);
   
    // sets the renting period for my bike
    void setRentingPeriod();
    void setRentStatus(bool rent);
    void pushReview(Review* review);

    // shows motorbike info
    void showDetailedInfo();

    // shows brief info of bike
    void showInfo();

    void showRentInfo();

    void showRentReviews();
    // calculate average bike score
    double getAverageRating();

    // function to write review and push to review list
    // void setReview(){
    //   Review* review = new Review;

    //   int score;
    //   string comment;

    //   cout << "Please write the review for rented bike:" << endl;
    //   cout << "Score (1-10): ";
    //   cin >> score;
    //   cin.ignore(1);
    //   cout << "Write comment: " << endl;
    //   getline(cin,comment);
    //   review->setScore(score);
    //   review->setComment(comment);
    //   reviews.push_back(review);
    // }
};


#endif