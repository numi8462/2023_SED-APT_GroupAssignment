#ifndef MEMBER_B
#define MEMBER_B

#include "../User/User.h"


#include "../Bike/Bike.h"
#include "../Request/Request.h"



#include "../RentedBike/RentedBike.h"
#include "../../System/System.h"

#include "../Review/Review.h"

// #include "../../System/System.h"


#include "../Customer/Customer.h"

#include <iostream>
#include <vector>
#include <sstream>

#include<iomanip>

class RentedBike;

class Customer;

class System;

class Bike;

class Review;

class Request;

class Date;


class Member : public User {
private:

    std::string memberId;
    std::string fullName;
    std::string phoneNum;
    Bike *BikeOwner;
    double credit;
    double score;
    std::string location;
    std::vector<Review *> CustomerReviewList; //review cua owner
    std::vector<Request *> requestList; // Request da sent
    std::vector<Customer *> CustomerList; // list Bike ma minh da thue


public:

    Member(std::string username, std::string password, std::string memberID, std::string fullName, std::string phoneNum,
           double credit, double score, std::string location);


    bool addBike(Date *startDate, Date *endDate, int consumingPointsPerDay, double scores, std::string status);


    bool deleteBike();

    int viewAllRequest();

    bool cancelRequest(int ID);


    void showAccountInfo();

    double getRatingScore();

    bool minusCredit(double creditPoint);

    bool addCredit(double creditPoint);

    bool createBike(Bike *Bike);

    void showAllAvailableBike();

    bool acceptRequest(int ID);

    bool declineRequest(int ID);


    void reviewBike(Bike *RentedBike, int score, std::string comment);

    bool showRequestSent();

    void viewCustomer();

    bool reviewCustomer(int rateId, int score, std::string comment);


    bool showReview();

    bool checkout(int leaveId);

    bool viewMemberRentedList();

    bool viewUnratedList();


    void CustomerLeaveBike();

    void getBikeIndex(int BikeID);
    
     ~Member();

    friend class Bike;

    friend class System;

};


#endif //MEMBER_B