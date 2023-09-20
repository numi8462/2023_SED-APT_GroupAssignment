#ifndef REVIEW_B
#define REVIEW_B
#include <iostream>
//#include "../Member/Member.h"
//#include "../Bike/Bike.h"

class Bike;
class Member;
class Review {
private:
    double ratingScore;
    std::string comment;
    Member *memberReview;
public:
    Review(double ratingScore, std::string comment, Member *memberReview);
    friend class Member;
    friend class Bike;
    friend class System;
};


#endif //REVIEW_B