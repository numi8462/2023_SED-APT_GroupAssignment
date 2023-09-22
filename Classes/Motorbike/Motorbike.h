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
    string city;
    int pointsPerDay;
    double minimumRenterScore;

public:
    Motorbike(){};
    Motorbike(string ownerID, string model, string color, string engineSize, string mode, string yearMade, string description, bool rent, double ratingAverage, string city, int pointsPerDay, double minimumRenterScore){
        this->ownerID = ownerID;
        this->model = model;
        this->color = color;
        this->engineSize = engineSize;
        this->mode = mode;
        this->yearMade = yearMade;
        this->description = description;
        this->rent = rent;
        this->ratingAverage = ratingAverage;
        this->city = city;
        this->pointsPerDay = pointsPerDay;
        this->minimumRenterScore = minimumRenterScore;
    };

    // getters
    string getOwnerID();
    string getModel();
    string getColor();
    string getEngineSize();
    string getMode();
    string getYearMade();
    string getDescription();
    bool getRent();
    double getRatingAverage();
    string getCity();
    int getPointsPerDay();
    double getMinimumRenterScore() ;

    //setters
    void setOwnerID(string ownerID);
    void setModel(string model);
    void setColor(string color);
    void setEngineSize(string engineSize);
    void setMode(string mode);
    void setYearMade(string yearMade);
    void setDescription(string description);
    void setRentStatus(bool rent);
    void setRatingAverage(double ratingAverage);
    void setCity(string city);
    void setPointsPerDay(int pointsPerDay);
    void setMinimumRenter(double score);
    
    void setRentingPeriod();
    

    // shows motorbike info
    void showDetailedInfo();

    // shows brief info of bike
    void showInfo();

    void showRentInfo();

    void showRentReviews();
};


#endif