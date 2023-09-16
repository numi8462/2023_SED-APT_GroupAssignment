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
public:
    Motorbike(){};
    Motorbike(string owner, string model, string color, string engineSize, string mode, string yearMade, string description, bool rent, double ratingAverage, time_t rentingStart, time_t rentingEnd, vector<Review*> reviews){
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
    };
    ~Motorbike();

    void setRentingPeriod(){
      
    };
    void showInfo(){
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
      cout << "Reviews: " << endl;
      for(int i = 0; i < reviews.size(); i++){
        reviews[i]->showReview();
      }
    }
};


