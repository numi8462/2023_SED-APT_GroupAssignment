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

void RentalService::viewAllMember(){
    cout << "\n";
    int count = 1;
    for(auto m : members){
        cout << "MEMBER " << count << endl;
        m.showInfo();
        cout << "\n";
        count++;
    }
}
// view all bike
void RentalService::viewAllBike(){
    cout << "\n";
    int count = 1;
    for(auto bike : motorbikes){
        cout << count << ". ";
        bike.showInfo();
        count++;
    }
}
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
// return bike to owner
void RentalService::returnBike(string renterID, string ownerID){
    bool hasRent = false;
    for(auto m : members){
        if(m.getMemberID() == renterID){
            if(m.getRentStatus() == true){
                hasRent = true;
                break;
            }
        }
    }
    if(hasRent == true){
        cout << "Do you want to return the bike?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Please enter 1 or 2: ";
        int choice;
        int index = 0;
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            for(auto &m : members){
                if(m.getMemberID() == renterID){
                    m.setRentStatus(false);
                }
            }
            for(auto &rq : requests){
                if(rq.getOwnerID() == ownerID && rq.getRenterID() == renterID){
                    requests.erase(requests.begin() + index);
                    cout << "Returned Bike\n";
                }
                index++;
            }
        }
    }

    saveDataToDatabase();
}
// register guest to member
void RentalService::registerMember(){
    string memberID,fullName,username,password,idType,expiryDate;
    int phoneNumber,idNumber,licenceNumber;

    Member* newMember = new Member;
    int count = 1;
    string temp;
    bool idFound = false;

    while (!idFound) {
        temp = "MEM" + to_string(count);
        idFound = true;

        for (auto& m : members) {
            if (m.getMemberID() == temp) {
                idFound = false;
                break;
            }
        }

        if (idFound) {
            memberID = temp;
        } else {
            ++count;
        }
    }
    cout << "Your Member ID is: " << memberID << endl;
    cout << "Enter Fullname: ";
    getline(cin,fullName);
    cout << "Enter Username: ";
    getline(cin,username);
    cout << "Enter Password: ";
    getline(cin,password);
    cout << "Enter Phone Number: ";
    cin >> phoneNumber;
    cin.ignore();
    cout << "Enter ID type (Citizen ID or Passport): ";
    getline(cin,idType);
    cout << "Enter ID Number: ";
    cin >> idNumber;
    cin.ignore();
    cout << "Enter Licence Number: ";
    cin >> licenceNumber;
    cin.ignore();
    cout << "Enter expiry date: ";
    getline(cin,expiryDate);

    newMember->setMemberID(memberID);
    newMember->setFullName(fullName);
    newMember->setUsername(username);
    newMember->setPassword(password);
    newMember->setPhoneNumber(phoneNumber);
    newMember->setIdType(idType);
    newMember->setIdNumber(idNumber);
    newMember->setLicenceNumber(licenceNumber);
    newMember->setExpiryDate(expiryDate);
    newMember->setRentStatus(false);
    newMember->setRentScoreAverage(10);

    cout << "You will be charged $20 for 20points for initial fee" << endl;
    newMember->setPoints(20);

    members.push_back(*newMember);
    saveDataToDatabase();
    cout << "\nAccount Created!" << endl;
}

void RentalService::rentBike(string id){
    for(auto &member : members){
        if(member.getMemberID() == id){
            member.setRentStatus(true);
            cout <<"Motorbike Rented successfully!" << endl;
        }
    }
}
// view rented bike, can return bike as well
void RentalService::viewRentedBike(string renterID){
    string ownerID = "";
    bool bike = false;
    for(auto &member : members){
        if(member.getMemberID() == renterID){
            if(member.getRentStatus() == true){
                for(auto rq : requests){
                    if(rq.getRenterID() == renterID){
                        ownerID = rq.getOwnerID();
                        bike = true;
                    }
                }
            }
        }
    }

    for(auto &m : motorbikes){
        if(m.getOwnerID() == ownerID){
            m.showRentInfo();
        }
    }
    if(bike == false){
        cout << "You have not rented any motorbike!" << endl;
    }
    returnBike(renterID, ownerID);
}
void RentalService::viewMyBike(string ownerID){
    cout << "\nMy bike" << endl;
    bool isFounded = false;
    getAverageRatingForBike(ownerID);
    for(auto b : motorbikes){
        if(b.getOwnerID() == ownerID){
            b.showDetailedInfo();
            isFounded = true;
            break;
        }
    }
    if(isFounded = false){
        cout << "\nNo Registered Bike" << endl;
        cout << "Would you like to register one?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cout << "Please enter 1 or 2: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if(choice == 1){
            registerBike(ownerID);
        }
    }
};
void RentalService::registerBike(string ownerID){
    Motorbike* newBike = new Motorbike;
    string model,color,engineSize,mode,yearMade,description,city;
    int pointsPerDay;
    double minimumRenterScore;
    cout << "\nPlease enter bike information" << endl;
    cout << "Enter model: ";
    getline(cin,model);
    cout << "Enter color: ";
    getline(cin,color);
    cout << "Enter engine size: ";
    getline(cin,engineSize);
    cout << "Enter mode: ";
    getline(cin,mode);
    cout << "Enter year made: ";
    getline(cin,yearMade);
    cout << "Enter description: ";
    getline(cin,description);
    cout << "Enter city (Type Hanoi or Saigon): ";
    getline(cin,city);
    cout << "Enter Cost of rent per day: ";
    cin >> pointsPerDay;
    cin.ignore();
    cout << "Enter minimum renter score 1 to 10 (Renters with lower score cannot rent your bike): ";
    cin >> minimumRenterScore;
    cin.ignore();

    newBike->setOwnerID(ownerID);
    newBike->setModel(model);
    newBike->setColor(color);
    newBike->setEngineSize(engineSize);
    newBike->setMode(mode);
    newBike->setYearMade(yearMade);
    newBike->setDescription(description);
    newBike->setCity(city);
    newBike->setPointsPerDay(pointsPerDay);
    newBike->setMinimumRenter(minimumRenterScore);
    newBike->setRentStatus(false);
    newBike->setRatingAverage(10);

    motorbikes.push_back(*newBike);
    cout << "\nMotorbike Registered!!" << endl;
    saveDataToDatabase();
    
}
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
    saveDataToDatabase();
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
    saveDataToDatabase();
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
            cout << "\n\033[31m You already have an Existing request \033[0m" << endl;
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
                }
                if(m.getMemberID() == ownderID){
                    m.setPoints(m.getPoints() + credit);
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
    int choice;
    do
    {
        /* code */
        cin >> choice;
        cin.ignore(1);
        switch (choice)
        {
        case 1:
            menuGuest();
            break;
        case 2:
            menuMemberLogin();
            break;
        case 3:
            menuAdminLogin();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice < 1 || choice > 3);
    
}

// menu for guests
void RentalService::menuGuest(){

    int choice;
    do
    {
        cout << "---------------------------------------\n" << endl;
        cout << "|              GUEST MENU             |\n" << endl;
        cout << "|     1.View bike                     |\n" << endl;
        cout << "|     2.Register                      |\n" << endl;
        cout << "|     3.Back to main menu             |\n" << endl;
        cout <<"---------------------------------------\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(1);
        switch (choice)
        {
        case 1:
            viewAllBike();
            break;
        case 2:
            registerMember();
            break;
        case 3:
            menuMain();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 3);
    
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
void RentalService::menuAdmin(){
    int choice;
    do
    {
        cout << "---------------------------------------\n"<< endl;
        cout << "|              ADMIN MENU              |\n"<< endl;
        cout << "|     1.View Member List               |\n" <<endl;
        cout << "|     2.View Bike List                 |\n" <<endl;
        cout << "|     3.Back to main menu              |\n"<< endl;
        cout << "---------------------------------------\n"<< endl;
        cout << "Enter your choice (Type Number): ";
        cin >> choice;
        cin.ignore();
                switch (choice) {
            case 1:
                viewAllMember();
                break;
            case 2:
                viewAllBike();
                break;
            case 3:
                break;
        }
    } while (choice != 3);
    

}
// menu for member
void RentalService::menuMember(Member &member){

    int choice;
    do {
        cout << "---------------------------------------"<< endl;
        cout << "This is your Member Menu\n" << endl;
        cout << "0. Exit" << endl;
        cout << "1. View my Information" << endl;
        cout << "2. View rented bike" << endl;
        cout << "3. Search Bike for rent" << endl;
        cout << "4. My Bike" << endl;
        cout << "5. Check my request" << endl;
        cout << "6. View requests I received" << endl;
        cout << "7. Add credit" << endl;
        cout << "8. Write Review" << endl;
        cout << "9. Unlist Bikes" << endl;
        cout << "---------------------------------------\n"<< endl;
        cout << "\nEnter your choice (Please type number 0 to 9): ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "<          Your Information          >" << endl;
            member.showInfo();
            getAverageRatingForRenter(member.getMemberID());
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
            choice = 0;
            break;
        case 5:
            checkRequest(member.getMemberID());
            break;
        case 6:
            menuRequest(member);
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (choice != 0);
    
}

void RentalService::menuMemberLogin() {
    int choice;
    do
    {
        cout << "---------------------------------------\n"<< endl;
        cout << "|              MEMBER MENU             |\n"<< endl;
        cout << "|     1.Login As Member                |\n"<<endl;
        cout << "|     2.Back to main menu              |\n"<< endl;
        cout << "---------------------------------------\n"<< endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                loginMember();
                break;
            case 2:
                menuMain();
                break;
        }
    } while (choice != 2);
    



}

// menu for admin
void RentalService::menuAdminLogin(){
    int choice;
    do
    {
        cout << "---------------------------------------\n"<< endl;
        cout << "|              ADMIN MENU              |\n"<< endl;
        cout << "|     1.Login As Admin                 |\n"<<endl;
        cout << "|     2.Back to main menu              |\n"<< endl;
        cout << "---------------------------------------\n"<< endl;
        cout << "Enter your choice (1 or 2): ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                loginAdmin();
                break;
            case 2:
                menuMain();
                break;
        }
    } while (choice < 1 || choice > 2);
    
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
    cout << "\n0. Go back to menu" << endl;
    cout << "1. Approve Request" << endl;
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
        if(choice == 0){
            break;
        }
    } while (choice < 0 || choice > 2);
    

};

void RentalService::menuWriteReview(Member& member){

}

void RentalService::loginMember(){
    bool login = false;
    string username, password;
    Member curr;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);
    for(auto m : members){
        if (m.getUsername() == username && m.getPassword() == password) {
            cout << "\033[32m\nLog in successfully!!!\033[0m\n"<< endl;
            curr = m;
            menuMember(curr);
            break;
        } 
    }

    if(login == false) {
        cout <<"\nWrong username or password!!! \n"<< endl;
    } 
}

void RentalService::loginAdmin(){
    bool login = false;
    string username, password, dUsername, dPassword;
    cout << "Enter your username: ";
    getline(cin, username);
    cout << "Enter your password: ";
    getline(cin, password);

    ifstream inFile;
    inFile.open("Database/Admin.dat");
    if (inFile.is_open()) {
        while (inFile.peek()!=EOF) {
            string field;
            getline(inFile, field, ',');
            dUsername = field;
            getline(inFile, field, '\n');
            dPassword = field;
            if (dUsername == username && dPassword == password) {
                cout << "\033[32m \nLog in successfully!!!\033[0m\n"<< endl;
                login = true;
                break;
            }
        }
        inFile.close();
    } else {
        cout << "No file found" << endl;
    }

    if(login == true){
        menuAdmin();
    } else {
        cout << "\nWrong ID or PASSWORD" << endl;
    }
}