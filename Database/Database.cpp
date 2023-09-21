/*
  RMIT University Vietnam
  Course: EEET2482/COSC2082
  Semester: 2023-2
  Group Assignment
  Group: 25
  Compiler used: Compiler version g++ 9.2.0
  Created  date: 14/09/2023
  Acknowledgement: https://www.daniweb.com/programming/software-development/threads/37710/reading-dat-file-data-into-an-array

*/

#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

// getters for vectors
vector<Member> Database::getMembersVector(){return members;}
vector<Motorbike> Database::getMotorbikesVector(){return motorbikes;}
vector<Review> Database::getRenterReviewsVector(){return renterReviews;}
vector<Review> Database::getBikeReviewsVector(){return bikeReviews;}
vector<Request> Database::getRequestsVector(){return requests;}


// void Database::displayData(){
//     for(int i = 0; i < members.size(); i++){
//         members[i]->showInfo();
//     }
//     for(int i = 0; i < motorbikes.size(); i++){
//         motorbikes[i].showInfo();
//     }
// };

//writes member data to Members.dat file
void Database::writeMemberData(Member &member){
    ofstream outFile("Database/Members.dat",ios::app);
    outFile << member.getMemberID() << "," << member.getFullName() << "," << member.getUsername() << "," << member.getPassword() << "," << member.getPhoneNumber() << "," << member.getIdType() << "," << member.getIdNumber() << "," << member.getLicenceNumber() << "," << member.getExpiryDate() << "," << member.getPoints() << "," << member.getRentScoreAverage() << "\n";
    outFile.close();
    cout << "File saved" << endl;
}

// write bike data
void Database::writeMotorbikeData(Motorbike &motorbike){
    ofstream outFile("Database/Motorbikes.dat",ios::app);
    outFile << motorbike.getOwnerID() << "," << motorbike.getModel() << "," << motorbike.getColor() << "," << motorbike.getEngineSize() << "," << motorbike.getMode() << "," << motorbike.getYearMade() << "," << motorbike.getDescription() << "," << motorbike.getRent() << "," << motorbike.getRatingAverage() << "," << motorbike.getCity() << "," << motorbike.getPointsPerDay() << "," << motorbike.getMinimumRenterScore() << "\n";
    outFile.close();
    cout << "File saved" << endl; 
}

//writes review data
void Database::writeReviewData(Review &review) {
    ofstream outFile("Database/Reviews.dat",ios::app);
    outFile << review.getReviewType() << "," << review.getID() << "," << review.getScore() << "," << review.getComment() << "\n";
    outFile.close();
    cout << "File saved" << endl;
}
// writes request data
void Database::writeRequestData(Request &request) {
    ofstream outFile("Database/Requests.dat",ios::app);
    outFile << request.getRenterID() << "," << request.getOwnerID() << "," << request.getCredit() << "," << request.getStatus() << "," << request.getDecline() << "\n";
    outFile.close();
    cout << "File saved" << endl;
}

//reads the current member data
Member Database::readMemberData(string currID){
    ifstream inFile;
    inFile.open("Database/Members.dat");

    Member curr;
    string line;

    string memberID;
    string fullName;
    string username;
    string password;
    int phoneNumber;
    string idType;
    int idNumber;
    int licenceNumber;
    string expiryDate;
    int points;
    double rentScoreAverage;

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        memberID = field;
        getline(inFile,field,',');
        fullName = field;
        getline(inFile,field,',');
        username = field;
        getline(inFile,field,',');
        password = field;
        getline(inFile,field,',');
        phoneNumber = stoi(field);
        getline(inFile,field,',');
        idType = field;
        getline(inFile,field,',');
        idNumber = stoi(field);
        getline(inFile,field,',');
        licenceNumber = stoi(field);
        getline(inFile,field,',');
        expiryDate = field;
        getline(inFile,field,',');
        points = stoi(field);
        getline(inFile,field,'\n');
        rentScoreAverage = stod(field);
        if(memberID == currID){
            Member member(memberID,fullName,username,password,phoneNumber,idType,idNumber,licenceNumber,expiryDate,points,rentScoreAverage);
            curr = member;
            break;
        }
    }
    inFile.close();
    return curr;
}

//reads current bike data
Motorbike Database::readBikeData(string id){
    ifstream inFile;
    inFile.open("Database/Motorbikes.dat");

    Motorbike currBike;
    string line;

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

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        ownerID = field;
        getline(inFile,field,',');
        model = field;
        getline(inFile,field,',');
        color = field;
        getline(inFile,field,',');
        engineSize = field;
        getline(inFile,field,',');
        mode = field;
        getline(inFile,field,',');
        yearMade = field;
        getline(inFile,field,',');
        description = field;
        getline(inFile,field,',');
        rent = (field == "1");
        getline(inFile,field,',');
        ratingAverage = stod(field);
        getline(inFile,field,',');
        city = field;
        getline(inFile,field,',');
        pointsPerDay = stoi(field);
        getline(inFile,field,'\n');
        minimumRenterScore = stod(field);
        if(ownerID == id){
            Motorbike bike(ownerID, model, color, engineSize, mode, yearMade, description, rent, ratingAverage, city, pointsPerDay, minimumRenterScore);
            currBike = bike;
            break;
        }
    }  
    inFile.close();
    return currBike;
}

//reads review data
Review Database::readRenterReviewData(string memberID){
    ifstream inFile;
    inFile.open("Database/Reviews.dat");

    Review currRev;
    string line;

    string reviewType;
    string id;
    double score;
    string comment;

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        reviewType = field;
        getline(inFile,field,',');
        id = field;
        getline(inFile,field,',');
        score = stod(field);
        getline(inFile,field,'\n');
        comment = field;

        if(id == memberID){
            Review review(reviewType,id,score,comment);
            currRev = review;
            break;
        }
    }  
    inFile.close();
    return currRev;

}

// replaces data if string id matches the Member class
void Database::replaceMemberData(string currID, Member& newMember){
    ifstream inFile;
    inFile.open("Database/Members.dat");

    ofstream tempFile;
    tempFile.open("Database/temp.dat");

    string line;

    while(getline(inFile, line)){
        istringstream ss(line);
        string field;
        getline(ss,field,',');
        string memberID = field;

        // If memberID matches currID, write newMember data to the temporary file
        if(memberID == currID){
            tempFile << newMember.memberID << "," << newMember.fullName << "," << newMember.username << "," << newMember.password << "," << newMember.phoneNumber << "," << newMember.idType << "," << newMember.idNumber << "," << newMember.licenceNumber << "," << newMember.expiryDate << "," << newMember.points << "," << newMember.rentScoreAverage << "\n";
        } else {
            // Otherwise, write the original line to the temporary file
            tempFile << line << '\n';
        }
    }
    
    inFile.close();
    tempFile.close();

    // Delete the original file and rename the temporary file
    remove("Database/Members.dat");
    rename("Database/temp.dat", "Database/Members.dat");
}
// replaces data if string id matches the motorbike class


// returns all members
void Database::getAllMembers(){
    members.clear();

    ifstream inFile;
    inFile.open("Database/Members.dat");

    Member curr;
    string line;

    string memberID;
    string fullName;
    string username;
    string password;
    int phoneNumber;
    string idType;
    int idNumber;
    int licenceNumber;
    string expiryDate;
    int points;
    double rentScoreAverage;

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        memberID = field;
        getline(inFile,field,',');
        fullName = field;
        getline(inFile,field,',');
        username = field;
        getline(inFile,field,',');
        password = field;
        getline(inFile,field,',');
        phoneNumber = stoi(field);
        getline(inFile,field,',');
        idType = field;
        getline(inFile,field,',');
        idNumber = stoi(field);
        getline(inFile,field,',');
        licenceNumber = stoi(field);
        getline(inFile,field,',');
        expiryDate = field;
        getline(inFile,field,',');
        points = stoi(field);
        getline(inFile,field,'\n');
        rentScoreAverage = stod(field);

        Member member(memberID,fullName,username,password,phoneNumber,idType,idNumber,licenceNumber,expiryDate,points,rentScoreAverage);
        curr = member;
        members.push_back(curr);
    }
    inFile.close();

    for(auto m : members){
        m.showInfo();
        cout << "\n";
    }
}
// returns all bikes
void Database::getAllMotorbikes(){
    ifstream inFile;
    inFile.open("Database/Motorbikes.dat");

    Motorbike currBike;
    string line;

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

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        ownerID = field;
        getline(inFile,field,',');
        model = field;
        getline(inFile,field,',');
        color = field;
        getline(inFile,field,',');
        engineSize = field;
        getline(inFile,field,',');
        mode = field;
        getline(inFile,field,',');
        yearMade = field;
        getline(inFile,field,',');
        description = field;
        getline(inFile,field,',');
        rent = (field == "1");
        getline(inFile,field,',');
        ratingAverage = stod(field);
        getline(inFile,field,',');
        city = field;
        getline(inFile,field,',');
        pointsPerDay = stoi(field);
        getline(inFile,field,'\n');
        minimumRenterScore = stod(field);

        Motorbike bike(ownerID, model, color, engineSize, mode, yearMade, description, rent, ratingAverage, city, pointsPerDay, minimumRenterScore);
        currBike = bike;
        motorbikes.push_back(bike);

    }  
    inFile.close();

    for(auto b : motorbikes){
        b.showDetailedInfo();
        cout << "\n";
    }
}

//return all reviews for renter and bike
void Database::getAllReviews(){
    ifstream inFile;
    inFile.open("Database/Reviews.dat");

    Review currRev;
    string line;

    string reviewType;
    string id;
    double score;
    string comment;

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        reviewType = field;
        getline(inFile,field,',');
        id = field;
        getline(inFile,field,',');
        score = stod(field);
        getline(inFile,field,'\n');
        comment = field;


        Review review(reviewType,id,score,comment);
        currRev = review;

        if(reviewType == "renter"){
            renterReviews.push_back(currRev);
        } else {
            bikeReviews.push_back(currRev);
        }

    }  
    inFile.close();

}

// return all requests
void Database::getAllRequests(){
    ifstream inFile;
    inFile.open("Database/Requests.dat");

    Request currReq;
    string line;

    string renterID;
    string ownerID;
    int credit;
    bool status;
    bool decline;

    while(inFile.peek()!=EOF){

        string field;
        getline(inFile,field,',');
        renterID = field;
        getline(inFile,field,',');
        ownerID = field;
        getline(inFile,field,',');
        credit = stod(field);
        getline(inFile,field,'\n');
        status = (field == "1");
        getline(inFile,field,',');
        decline = (field == "1");


        Request request(renterID,ownerID,credit,status,decline);
        currReq = request;

        requests.push_back(currReq);

    }  
    inFile.close();
}