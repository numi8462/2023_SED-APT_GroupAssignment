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

#include "RentalService.h"
#include <iostream>
#include <vector>
using namespace std;

//getters
vector<Member> RentalService::getMembers(){return members;}
vector<Motorbike> RentalService::getMotorbikes(){return motorbikes;}
vector<Review> RentalService::getRenterReviews(){return renterReviews;};
vector<Review> RentalService::getBikeReviews(){return bikeReviews;};
vector<Request> RentalService::getRequests(){return requests;};

// collects data from database
void RentalService::getDataFromDatabase(){
    Database database;
    database.getAllMembers();
    database.getAllMotorbikes();
    database.getAllReviews();
    database.getAllRequests();
    this->members = database.getMembersVector();
    this->motorbikes = database.getMotorbikesVector();
    this->renterReviews = database.getRenterReviewsVector();
    this->bikeReviews = database.getBikeReviewsVector();
    this->requests = database.getRequestsVector();
}
// saves data to database
void RentalService::saveDataToDatabase(){
    Database database;
    database.deleteDatabase();
    for(auto m : members){
        database.writeMemberData(m);
    }
    for(auto mb : motorbikes){
        database.writeMotorbikeData(mb);
    }
    for(auto rq : requests){
        database.writeRequestData(rq);
    }
    for(auto rv : renterReviews){
        database.writeReviewData(rv);
    }
    for(auto rvb : bikeReviews){
        database.writeReviewData(rvb);
    }
};

// register guest to member
void RentalService::registerMember(){

}

void RentalService::rentBike(string id){
    for(auto &member : members){
        if(member.getMemberID() == id){
            member.setRentStatus(true);
            cout <<"Motorbike Rented successfully!" << endl;
        }
    }
}
void RentalService::viewRentedBike(string renterID){
    string owner = "";
    for(auto &member : members){
        if(member.getMemberID() == renterID){
            if(member.getRentStatus() == true){
                for(auto rq : requests){
                    if(rq.getRenterID() == renterID){
                        owner = rq.getOwnerID();
                    }
                }
            } else {
                cout << "You have not rented any motorbike!" << endl;
            }
            
        }
    }

    for(auto &m : motorbikes){
        if(m.getOwnerID() == owner){
            m.showDetailedInfo();
        }
    }
}
void RentalService::viewMyBike(string ownerID){
    for(auto b : motorbikes){
        if(b.getOwnerID() == ownerID){
            b.showDetailedInfo();
        }
    }
};
void RentalService::writeReviewForRenter(string renterID){
    Review* review = new Review;

    int score;
    string comment;

    cout << "Please write the review for Renter:" << endl;
    cout << "Score (1-10): ";
    cin >> score;
    cin.ignore(1);
    cout << "Write comment: ";
    getline(cin,comment);
    review->setReviewType("renter");
    review->setScore(score);
    review->setComment(comment);
    review->setID(renterID);
    renterReviews.push_back(*review);
    saveDataToDatabase();
};
void RentalService::writeReviewForBike(string ownerID){
    Review* review = new Review;

    int score;
    string comment;

    cout << "Please write the review for Renter:" << endl;
    cout << "Score (1-10): ";
    cin >> score;
    cin.ignore(1);
    cout << "Write comment: ";
    getline(cin,comment);
    review->setReviewType("renter");
    review->setScore(score);
    review->setComment(comment);
    review->setID(ownerID);
    bikeReviews.push_back(*review);
    saveDataToDatabase();
};

// set average renter score, if non default is 10
void RentalService::getAverageRatingForRenter(string renterID){
    double score = 10;
    double average = 0;
    double total = 0;
    int count = 0;
    for(auto r : renterReviews){
        if(r.getID() == renterID){
            total += r.getScore();
            count++;
        }
    }
    average = total/count;
    for(auto &m : members){
        if(m.getMemberID() == renterID){
            if(count != 0){
                m.setRentScoreAverage(average);
            } else {
                m.setRentScoreAverage(score);
            }
        }
    }
};
void RentalService::getAverageRatingForBike(string ownerID){
    double score = 10;
    double average = 0;
    double total = 0;
    int count = 0;
    for(auto r : bikeReviews){
        if(r.getID() == ownerID){
            total += r.getScore();
            count++;
        }
    }
    average = total/count;
    for(auto &b : motorbikes){
        if(b.getOwnerID() == ownerID){
            if(count != 0){
                b.setRatingAverage(average);
            } else {
                b.setRatingAverage(score);
            }
        }
    }
};
void RentalService::viewBikeReviews(string id){
    int index = 1;
    double average = 0;
    for(auto m : motorbikes){
        if(m.getOwnerID() == id){
            average = m.getRatingAverage();
        }
    }
    cout << "\n<    Reviews For My bike    >" << endl;
    cout << "Bike's average rating: " << average << endl;
    for(auto r : bikeReviews){
        if(r.getID() == id){
            cout << index << ". ";
            r.showReview();
            cout << endl;
        }
    }


};
// creates a new request if member does not have a pending request
void RentalService::createRequest(string renterID, string ownerID){
    bool hasRequest = false;
    for(auto rq : requests){
        if(rq.getRenterID() == renterID){
            cout << "\n\033[31m You already have a pending request \033[0m" << endl;
            hasRequest = true;
            break;
        }
    }
    if(hasRequest == false){
        Request* request = new Request;
        int points = 0;
        int days = 0;
        int total = 0;
        cout << "Type the amount of days to rent:";
        cin >> days;
        for(auto bike : motorbikes){
            if(bike.getOwnerID() == ownerID){
                points = bike.getPointsPerDay();
            }
        }
        total = days * points;
        for(auto &m : members){
            if(m.getMemberID() == renterID){
                int myPoints = m.getPoints();
                if(myPoints < total){
                    cout << "Not enough credit. Please charge credits" << endl;
                } else {
                    cout <<"Request sent to Owner" << endl;
                    request->setRenterID(renterID);
                    request->setOwnerID(ownerID);
                    request->setCredit(total);
                    request->setStatus(false);
                    request->setDecline(false);
                    requests.push_back(*request);
                }
            }
        }
    }
    saveDataToDatabase();
};
void RentalService::acceptRequest(string renterID, string ownderID){
    for(auto &rq : requests){
        if(rq.getRenterID() == renterID && rq.getOwnerID() == ownderID){
            int credit = rq.getCredit();
            rq.setStatus(true);
            for(auto &m : members){
                if(m.getMemberID() == renterID){
                    m.setRentStatus(true);
                    m.setPoints(m.getPoints() - credit);
                    cout << "Approved" << endl;
                    break;
                }
            }
        }
    }
    saveDataToDatabase();
};
void RentalService::declineRequest(string renterID, string ownderID){
    for(auto &rq : requests){
        if(rq.getRenterID() == renterID && rq.getOwnerID() == ownderID){
            rq.setDecline(true);
            rq.setStatus(false);
        }
    }
    saveDataToDatabase();
};
// checks status of request
void RentalService::checkRequest(string renterID){
    int index = 0;
    int found = 0;
    for(auto &rq : requests){
        if(rq.getRenterID() == renterID){
            cout << "Found Reqeust" << endl;
            if(rq.getDecline() == true){
                cout << "\n Your Request have been Declined. Your Request will be deleted" << endl;
                requests.erase(requests.begin() + index);
                found = 1;
                break;
            } else if(rq.getStatus() == false){
                cout << "\n Your Request is pending" << endl;
                found = 1;
                break;
            } else {
                cout << "\n Your Request have been Accepted." << endl;
                found = 1;
                break;
            }
        }
        index++;
    }

    if(found == 0){
        cout << "\n No request found" << endl;
    }
    saveDataToDatabase();
};

// shows list of motorbikes which filters by city, points, and member's rating
void RentalService::showMotorbikeList(string city, int myPoints, double myRating){
    int listNumber = 1;
    int index = 0;
    // cout << "asd" << endl;
    for (int i = 0; i < motorbikes.size(); i++)
    {
    // filters
    if(motorbikes[i].getCity() == city && motorbikes[i].getPointsPerDay() <= myPoints && motorbikes[i].getMinimumRenterScore() <= myRating){
        cout << listNumber << ". ";
        motorbikes[i].showInfo();
        listNumber++;
    }
    }
    
}


// main menu
void RentalService::menuMain(){
    cout << "\nEEET2482/COSC2082 ASSIGNMENT" << endl;
    cout << "MOTORBIKE RENTAL APPLICATION\n" << endl;
    cout << "Instructor: Dr. Ling Huo Chong" << endl;
    cout << "Group: Group No. 25" << endl;
    cout << "s3726115, Youngho Kim" << endl;
    cout << "s3790421, Kien Chau" << endl;
     cout << "s3976442, Thien Do" << endl;
    cout << "s3979772, Tri Ngo\n" << endl;
    cout << "Use the app as 1.Guest   2.Member    3.Admin\n" << endl;
    cout << "Enter your choice: ";
}

// menu for guests
void RentalService::menuGuest(){
    cout << "" << endl;
}

// menu for searching bike
void RentalService::menuSearchBike(Member& member){
    cout << "\nChoose a city to borrow:   1.Hanoi   2.Saigon\n" << endl;
    int choice;
    do {
        cout << "Enter your choice: ";  
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:{
            cout << "Avaiable bike for you are: (Credit less than " << member.getPoints() << ", Renter rating more than " << member.getRentScoreAverage() << ")\n" << endl;
            showMotorbikeList("Hanoi", member.getPoints(), member.getRentScoreAverage());
            string inputId;
            cout << "Enter ID of bike owner to borrow: ";
            getline(cin,inputId);
            menuRentBike(member,inputId);
            menuMember(member);
            break;
        }

        case 2: {
            cout << "Avaiable bike for you are: (Credit less than " << member.getPoints() << ", Renter rating more than " << member.getRentScoreAverage() << ")\n" << endl;
            showMotorbikeList("Saigon", member.getPoints(), member.getRentScoreAverage());
            string inputId;
            cout << "Enter ID of bike owner to borrow: ";
            getline(cin,inputId);
            menuRentBike(member,inputId);
            menuMember(member);
            break;
        }

        default: {
            cout << "Invalid Choice. Please try again." << endl;
            break;
        }

        }
    } while (choice < 1 || choice > 2);
    
    
}

// menu for member
void RentalService::menuMember(Member &member){

    int choice;
    do {
        cout << "\nThis is your Member Menu\n" << endl;
        cout << "0. Exit" << endl;
        cout << "1. View my Information" << endl;
        cout << "2. View rented bike" << endl;
        cout << "3. Search Bike for rent" << endl;
        cout << "4. View my Bike" << endl;
        cout << "5. Check my request" << endl;
        cout << "6. View requests I received" << endl;
        cout << "7. Add credit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "<          Your Information          >" << endl;
            member.showInfo();
            break;
        case 2:
            viewRentedBike(member.getMemberID());
            break;
        case 3:
            menuSearchBike(member);
            choice = 0;
            break;
        case 4:
            viewMyBike(member.getMemberID());
            break;
        case 5:
            checkRequest(member.getMemberID());
            break;
        case 6:
            menuRequest(member);
            break;
        case 7:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 0);
    
}


// menu for admin
void RentalService::menuAdmin(){

}

// menu for renting bike
void RentalService::menuRentBike(Member& member,string bikeOwnerID){
    bool found = false;
    for(auto b : motorbikes){
        if(b.getOwnerID() == bikeOwnerID){
            createRequest(member.getMemberID(),bikeOwnerID);
            found = true;
        }
    }
    if(found == false){
        cout << "No bike found" << endl;
    }
}

void RentalService::menuRequest(Member& member){
    bool found = false;
    int number = 1;
    cout << "List of Requests:" << endl;
    for(auto rq : requests){
        if(rq.getOwnerID() == member.getMemberID()){
            cout << number << ". ";
            rq.showInfo();
            cout << endl;
            number++;
            found = true;
        }
    }
    if(found == false){
        cout << "None" << endl;
    }
    cout << "\n1. Approve Request" << endl;
    cout << "2. Decline Request" << endl;
    cout << "Enter your choice: ";
    int choice;
    do
    {
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            string id;
            bool foundID = false;
            cout << "Type in the renter id you want to approve: ";
            getline(cin,id);
            for(auto rq : requests){
                if(rq.getOwnerID() == member.getMemberID() && rq.getRenterID() == id){
                    acceptRequest(id,member.getMemberID());
                    foundID = true;
                }
            }
            if(foundID == false){
                cout << "No Matching ID" << endl;
            }
            break;
        } else if (choice == 2){
            string mID;
            bool foundMID = false;
            cout << "Type in the renter id you want to decline: ";
            getline(cin,mID);
            for(auto rq : requests){
                if(rq.getOwnerID() == member.getMemberID() && rq.getRenterID() == mID){
                    declineRequest(mID,member.getMemberID());
                    foundMID = true;
                }
            }
            if(foundMID == false){
                cout << "No Matching ID" << endl;
            }
            break;
        }
    } while (choice < 1 || choice > 2);
    

};

