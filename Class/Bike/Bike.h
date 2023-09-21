#ifndef BIKE_B
#define BIKE_B

#include "../Review/Review.h"

#include "../Member/Member.h"
#include "../Request/Request.h"
#include "../Bike/Bike.h"

#include "../Date/Date.h"

#include <iostream>

#include <vector>

class Member;

class Review;

class Date;

class Request;

class Bike;

class Bike {
private:

    std::string BikeID;
    std::string location;
    std::string BikeDescription;
    std::string BikeStatus;

    Member *owner;


    bool isAdded;
    Date *startingDate;
    Date *endingDate;
    double consumingPointsPerDay;
    double minRating;
    double BikeScores;

    std::vector<Review *> listBikeReview;

    std::vector<Request *> listBikeRequest;

    std::vector<Bike*> listRentedBike;

    std::vector<Bike *> unratedCustomer;


public:

    Bike(std::string BikeID, std::string location, std::string BikeDescription);


    double getRatingScore();

    void addRequestToBikeRequestList(Request *request);

    bool removeRequestFromBikeRequestList(Request *request);


    void addReviewToBikeReviewList(Review *review);


    void viewBikeInfo();


    void viewBikeReview();

    std::string viewBikeInfoByGuest();
    

    ~Bike();

    friend class Member;

    friend class System;

};


#endif //BIKE_B