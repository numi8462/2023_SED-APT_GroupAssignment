#include "Bike.h"


Bike::Bike(std::string BikeID, std::string location, std::string BikeDescription) {
    this->BikeID = BikeID;
    this->location = location;
    this->BikeDescription = BikeDescription;
    this->isAdded = false;
    this->startingDate = nullptr;
    this->endingDate = nullptr;
    this->owner = nullptr;
    this->minRating = 0;
    this->consumingPointsPerDay = 0;
    this->BikeScores = 0;
}

double Bike::getRatingScore() {
    if(this->listBikeReview.empty()){
        return 0;
    }
    double tempScore = 0;
    for(auto & i : listBikeReview){
        tempScore += i->ratingScore;
    }
    double avgScore = (double ) tempScore / (double ) listBikeReview.size();
    return avgScore;
}
void Bike::viewBikeInfo() {
    std::cout << "\nOwner: " << owner->fullName << "\n";
    std::cout << "Location: " << location << "\n";
    std::cout << "Description: " << BikeDescription << "\n";
    std::cout << "Rating score: " << this->getRatingScore() << "\n";
      if(isAdded){
        std::cout << "Available from: " << this->startingDate->convertDatetoString() << " to " << this->endingDate->convertDatetoString() << "\n";
        std::cout << "Credit per day: " << consumingPointsPerDay << "\n";
        std::cout << "Minimum rating score of customer: " << minRating << "\n";
    }
}
void Bike::viewBikeReview() {
    if(listBikeReview.empty()){
        std::cout << "\nThere are no reviews for this Bike\n";
    }
    else {
        for(auto &i : listBikeReview){
            int tempScore = i->ratingScore;
            std::string tempComment = i->comment;
            auto memReview = i->memberReview;
            std::cout << "\n-----------------------"
                      << "\n\nReview by member: " << memReview->fullName
                      << "\n-----------------------"
                      << "Score: " << tempScore << "\n"
                      << "Comment: " << tempComment;
        }
    }
}
void Bike::addRequestToBikeRequestList(Request *request) {
    listBikeRequest.push_back(request);
    }

void Bike::addReviewToBikeReviewList(Review *review) {
    listBikeReview.push_back(review);
}


Bike :: ~Bike() {
    for(auto &review: listBikeReview) {
        delete review;
    }

    for(auto &request : listBikeRequest) {
        delete request;
    }

    for(auto &rentedBike : listRentedBike) {
        delete rentedBike;
    }

    delete startingDate;
    delete endingDate;
}