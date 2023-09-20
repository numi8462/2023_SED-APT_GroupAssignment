#include "Member.h"

//#include "../Date/Date.h"
//#include "../../System/System.h"
#include "../../define.h"
#include "../Bike/Bike.h"
#include "../Review/Review.h"
#include "../Request/Request.h"
#include "../RentedBike/RentedBike.h"
#include "../Customer/Customer.h"

#include <algorithm>


#include <utility>

Member::Member(std::string username, std::string password, std::string memberID, std::string fullName,
               std::string phoneNum,
               double credit, double score, std::string location) : User(std::move(username), std::move(password)) {
    this->memberId = memberID;
    this->fullName = fullName;
    this->phoneNum = phoneNum;
    this->credit = credit;

    this->score = score;

    this->location = location;
    this->BikeOwner = nullptr;
    CustomerReviewList.clear();
    requestList.clear();


}
double Member::getRatingScore() {
    if (this->CustomerReviewList.empty()) {
        return 10;
    }
    double tempScore = 0;
    for (Review *rv: CustomerReviewList) {
        tempScore += rv->ratingScore;
    }
    double ratingScore = (double) tempScore / (double) CustomerReviewList.size();
    return ratingScore;
}


void Member::showAccountInfo() {
    std::cout << CYAN << "\nYour information: \n" << RESET;
    std::cout << CYAN << "Your username: " << this->username << "\n" << RESET;
    std::cout << CYAN << "Your name: " << this->fullName << "\n" << RESET;
    std::cout << CYAN << "Your phone number: " << this->phoneNum << "\n" << RESET;
    std::cout << CYAN << "Your credit: " << this->credit << "\n" << RESET;
    std::cout << CYAN << "Your location: " << this->location << "\n" << RESET;
    std::cout << CYAN << "Your score: " << this->getRatingScore() << "\n" << RESET;
    if (BikeOwner == nullptr) {
        std::cout << "\n";
    } else {
        std::cout << CYAN << "BikeID: " << BikeOwner->BikeID << "  Location: " << BikeOwner->location << "\n" << RESET;
    }
}
//add credit to member's credit
bool Member::addCredit(double creditPoint) {
    this->credit += creditPoint;
    return true;
}

//minus credit of member
bool Member::minusCredit(double creditPoint) {
    if (this->credit < creditPoint) {
        return false;
    }
    this->credit -= creditPoint;
    return true;
}

bool Member::showReview() {

    if (this->CustomerReviewList.empty()) {
        std::cout << RED << "\nThere are no reviews for this member\n" <<RESET;
    } else {
        std::cout << CYAN << "\nAll review for this member: \n" << RESET;
        for (int i = 0; i < this->CustomerReviewList.size(); i++) {
            Review *review = CustomerReviewList[i];
            std::string tempComment = review->comment;
            int tempScore = review->ratingScore;
            Member *member = review->memberReview;
            std::cout << CYAN << "\n-----------------------"
                      << "\n\nReview by member: " << member->fullName
                      << "\n-----------------------"
                      << "Score: " << tempScore << "\n"
                      << "Comment: " << tempComment << RESET;

        }

    }
    }

bool Member::createBike(Bike *Bike) {
    if (this->BikeOwner != nullptr) {
        return false;
    } else {
        this->BikeOwner = Bike;
        Bike->owner = this;
        return true;
    }
}


bool Member::addBike(Date *startDate, Date *endDate, int consumingPointsPerDay, double scores, std::string status) {


    if (BikeOwner->isAdded) {
        return false;
    }

    BikeOwner->isAdded = true;
    BikeOwner->startingDate = startDate;
    BikeOwner->endingDate = endDate;
    BikeOwner->consumingPointsPerDay = consumingPointsPerDay;
    BikeOwner->BikeStatus = status;
    BikeOwner->minRating = scores;

    return true;
}
bool Member::deleteBike() {

    if (!BikeOwner->isAdded || !BikeOwner->listBikeRequest.empty()) {
        return false;
    }

    BikeOwner->isAdded = false;
    BikeOwner->BikeStatus = STATUS[1];
    BikeOwner->startingDate = nullptr;
    BikeOwner->endingDate = nullptr;
    BikeOwner->consumingPointsPerDay = 0;
    BikeOwner->BikeDescription = "";
    return true;
}


int Member::viewAllRequest() {
    int index = 0;
    if (BikeOwner->listBikeRequest.empty()) {
        std::cout << RED << "\nNo request for you\n" << RESET;
        return 0;
    }
    std::cout
            << CYAN << std::left
            << std::setw(5)
            << "ID"
            << std::left
            << std::setw(10)
            << "Member ID"
            << std::left
            << std::setw(15)
            << "Request Date"
            << std::left
             << std::setw(15)
            << "Status"
            << "\n" << RESET;
    for (Request *i: BikeOwner->listBikeRequest) {
        index++;
        std::cout
                << CYAN << std::left
                << std::setw(5)
                << index
                << std::left
                << std::setw(10)
                << i->requestedByMember->memberId
                << std::left
                << std::setw(15)
                << i->startDate->convertDatetoString()
                << std::left
                << std::setw(15)
                << i->requestStatus
                << "\n" << RESET;
    }
    return index;
}

bool Member:: showRequestSent() {
    int index = 0;
    if(requestList.empty()) {
        std:: cout<< RED << "\nThere are no request that you sent\n" << RESET;
        return false;
    }
    std::cout
            << CYAN << std::left
            << std::setw(5)
             << "ID"
            << std::left
            << std::setw(10)
            << "Bike ID"
            << std::left
            << std::setw(15)
            << "Request Date"
            << std::left
            << std::setw(15)
            << "Status"
            << "\n" << RESET;
    for(Request *i: requestList) {
         index++;
         std::cout
                << CYAN <<std::left
                << std::setw(5)
                << index
                << std::left
                << std::setw(10)
                << i->BikeID
                << std::left
                << std::setw(15)
                << i->startDate->convertDatetoString()
                << std::left
                << std::setw(15)
                << i->requestStatus
                << "\n" << RESET;
    }
}

bool Member::cancelRequest(int ID) {
    int index = 0;
    if(ID - 1 > requestList.size()){
        return false;
          }
    auto request = requestList[ID-1];
    if(request->requestStatus == RE_STATUS[1]){
        return false;
    }
    else {
        requestList.erase(requestList.begin()+(ID-1));
        return true;
    }
}

void Member::reviewBike(Bike *RentedBike, int score, std::string comment) {
    //create object
    Review *review = new Review(score, comment, this);
    //add to review list of Bike
    RentedBike->addReviewToBikeReviewList(review);
}


bool Member::declineRequest(int ID) {
    int indice = 0;
    for (auto i: BikeOwner->listBikeRequest) {
        if (BikeOwner->listBikeRequest[ID] == i) {
            continue;
               }
        if ((i->endDate->countDate() - BikeOwner->listBikeRequest[ID]->startDate->countDate()) < 0 ||
            (BikeOwner->listBikeRequest[ID]->endDate->countDate() - i->startDate->countDate()) < 0) {
            continue;
        }
        indice++;
        i->requestStatus = RE_STATUS[2];
    }
    BikeOwner->listBikeRequest[ID]->requestStatus = RE_STATUS[2];


    return true;
}

bool Member::acceptRequest(int ID) {
    if (ID > BikeOwner->listBikeRequest.size()) {
        return false;
    }


    if(BikeOwner->listBikeRequest[ID]->requestStatus == RE_STATUS[1] || BikeOwner->listBikeRequest[ID]->requestStatus == RE_STATUS[2]) {
        std::cout << RED <<"\nYou can not accept the request has been accepted or declined\n" << RESET;
        return false;
    }
    // cout << "\nThe request does not match\n";
    // return false;
    BikeOwner->BikeStatus = "UNAVAILABLE";
    auto rentDate = BikeOwner->listBikeRequest[ID ]->startDate;
    auto endRentDate = BikeOwner->listBikeRequest[ID]->endDate;
    auto Customer = BikeOwner->listBikeRequest[ID]->requestedByMember;
 // int requiredCredit = (rentDate - endRentDate) *BikeOwner->consumingPointsPerDay;
    declineRequest(ID );
    BikeOwner->listBikeRequest[ID]->requestStatus = RE_STATUS[1];
    RentedBike *RentedBike = new RentedBike(rentDate, endRentDate, Customer);
    Customer *RentedMember = new Customer(rentDate, endRentDate, BikeOwner);
    // add object to Rented list
    Customer->CustomerList.push_back(RentedMember);
    BikeOwner->listRentedBike.push_back(RentedBike);
    // add credit of owner and minus credit of Customer
    this->addCredit(BikeOwner->consumingPointsPerDay * (endRentDate->countDate() - rentDate->countDate()));
    Customer->minusCredit(BikeOwner->consumingPointsPerDay * (endRentDate->countDate() - rentDate->countDate()));
    return true;
}


void Member::viewCustomer() {
    std::cout
            << CYAN << std::left
            << std::setw(15)
            << "Start Date"
            << std::left
            << std::setw(20)
            << "End Date"
            << std::left
            << std::setw(15)
            << "Bike ID"
            << std::left
            << std::setw(15)
            << "Owner ID"
            << "\n" << RESET;
    for (int i = 0; i < CustomerList.size(); i++) {
        auto CustomerStartDate = CustomerList[i]->startFromDate->convertDatetoString();
        auto CustomerEndDate = CustomerList[i]->ToDate->convertDatetoString();
         auto Bike = CustomerList[i]->RentedBike;
        std::cout << CYAN << i+1 << "."
                  << std::left
                  << std::setw(15)
                  << CustomerStartDate
                  << std::left
                  << std::setw(20)
                  << CustomerEndDate
                  << std::left
                  << std::setw(15)
                  << Bike->BikeID
                  << std::left
                  << std::setw(15)
                  << Bike->owner->memberId
                  << "\n" << RESET;
    }
}


bool Member::viewMemberRentedList() {
    if (CustomerList.empty()) {
        std::cout << RED << "\nThere are no Bikes you are Renteding\n" << RESET;
        return false;
    }
    for (int i = 0; i < CustomerList.size(); i++) {
        std::cout << CYAN << i + 1 << '.' << CustomerList[i]->startFromDate->convertDatetoString() << "-->"
                  << CustomerList[i]->ToDate->convertDatetoString() << ":" << CustomerList[i]->RentedBike->BikeID << "\n" << RESET;
    }
    return true;
}

bool Member::checkout(int leaveId) {
    //if input greater than the size of list, return false
    if (leaveId > CustomerList.size()) {
         return false;
    }
    //get object
    auto leaveCustomer = CustomerList[leaveId];
    auto leaveStartDate = leaveCustomer->startFromDate;
    auto leaveDate = leaveCustomer->ToDate;
    auto leaveBike = leaveCustomer->RentedBike;
    //create object
    auto *unrated = new RentedBike(leaveStartDate, leaveDate, this);
    //add object to unrated list
    leaveBike->unratedCustomer.push_back(unrated);
    leaveBike->BikeStatus = STATUS[0];
    //delete from Customer list
    CustomerList.erase(CustomerList.begin() + (leaveId));
    //when leave Bike call member review Bike and member review occupier afterwards in menu
    return true;

}

bool Member::viewUnratedList() {
    //if list is empty
    if (BikeOwner->unratedCustomer.empty()) {
        return false;
    }
    //display data
    std::cout << GREEN << "\nAll unrated Customer will be displayed: \n" << RESET;
    std::cout
            << CYAN <<std::left
            << std::setw(10)
            << "Index"
            << std::left
            << std::setw(20)
            << "Start Date"
                << std::left
            << std::setw(20)
            << "End Date"
            << std::left
            << std::setw(10)
            << "MemberID"
            << "\n" << RESET;
    for (int i = 0; i < BikeOwner->unratedCustomer.size(); i++) {
        std::cout
                << CYAN << std::left
                << std::setw(10)
                << i+1
                << std::left
                << std::setw(20)
                << BikeOwner->unratedCustomer[i]->startFromDate->convertDatetoString()
                << std::left
                << std::setw(20)
                << BikeOwner->unratedCustomer[i]->toDate->convertDatetoString()
                << std::left
                << std::setw(10)
                << BikeOwner->unratedCustomer[i]->Customer->memberId
                << "\n" << RESET;
    }
    return true;
}

bool Member::reviewCustomer(int rateId, int score, std::string comment) {
    if (rateId > BikeOwner->unratedCustomer.size()) {
        return false;
    }
    auto Customer = BikeOwner->unratedCustomer[rateId]->Customer;
      //create review object
    auto review = new Review(score, comment, Customer);
    //add review to review list
    Customer->CustomerReviewList.push_back(review);
    //remove from unrated list
    BikeOwner->unratedCustomer.erase(BikeOwner->unratedCustomer.begin() + (rateId - 1));
    return true;


}

Member :: ~Member() {
    for(auto &request: requestList) {
        delete request;
    }

    for(auto &review : CustomerReviewList) {
        delete review;
    }
    for(auto &Customer : CustomerList) {
        delete Customer;
    }
}