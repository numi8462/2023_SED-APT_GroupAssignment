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

#include "Review.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Review;
class Motorbike
{
private:
    string owner;
    string model;
    string color;
    string engineSize;
    string mode;
    string yearMade;
    string description;
    bool rent;
    double ratingAverage;
    time_t rentingStart;
    time_t rentingEnd;
    vector<Review*> reviews;
    string city;
    int pointsPerDay;
    double minimumRenterScore;
public:
    Motorbike(){};
    Motorbike(string owner, string model, string color, string engineSize, string mode, string yearMade, string description, bool rent, double ratingAverage, time_t rentingStart, time_t rentingEnd, vector<Review*> reviews, string city, int pointsPerDay, double minimumRenterScore){
        this->owner = owner;
        this->model = model;
        this->color = color;
        this->engineSize = engineSize;
        this->mode = mode;
        this->yearMade = yearMade;
        this->description = description;
        this->rent = rent;
        this->ratingAverage = ratingAverage;
        this->rentingStart = rentingStart;
        this->rentingEnd = rentingEnd;
        this->reviews = reviews;
        this->city = city;
        this->pointsPerDay = pointsPerDay;
        this->minimumRenterScore = minimumRenterScore;
    };

    // getters
    string getCity(){return city;}
    int getPointsPerDay(){return pointsPerDay;}
    double getRatingAverage(){return ratingAverage;}
    double getMinimumRenterScore() { return minimumRenterScore; }

    // sets the minimum renter score
    void setMinimumRenter(double score){
        this->minimumRenterScore = score;
    };
   
    // sets the renting period for my bike
    void setRentingPeriod(){
      
    };

    void setRentStatus(bool rent){
      this->rent = rent;
    }

    void pushReview(Review* review){
      reviews.push_back(review);
    }

    // shows motorbike info
    void showDetailedInfo(){
      cout << "Owner: " << owner << endl;
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
    void showInfo(){
      cout << "\n<  Rented Motorbike Information  >" << endl;
      cout << "Owner: " << owner << ", Model: " << model <<", Credit per day: " << pointsPerDay << ", City: " << city << "\n" << endl;
    }

    void showRentInfo(){

    }

    void showRentReviews(){
      cout << "\n<  Motorbike Reviews  >" << endl;
      cout << "Motorbike average rating: " << getAverageRating() << endl;
      for(int i = 0; i < reviews.size(); i++){
        cout << i+1 << ". ";
        reviews[i]->showReview();
      }
    }
    // calculate average bike score
    double getAverageRating(){
        double total = 0;
        int index = 0;
        for(int i =0; i < reviews.size(); i++){
            total += reviews[i]->getScore();
            index++;
        }
        this->ratingAverage = total / index;
        return ratingAverage;
    }
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


