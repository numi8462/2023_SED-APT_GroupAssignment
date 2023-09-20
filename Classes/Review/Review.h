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
#ifndef REVIEW_H
#define REVIEW_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Review {
    private:
        string reviewType;
        string id;
        double score;
        string comment;
    public:
        Review() { };
        Review(string reviewType,string id,double score, string comment) : reviewType(reviewType),id(id), score(score), comment(comment) { };

        //getters
        double getScore();
        string getComment();
        string getReviewType();
        string getID();
        
        void showReview();

        void setScore(double score);
        void setComment(string comment);
        void setReviewType(string reviewType);
        void setID(string id);

        friend class Member;
        friend class Motorbike;
};

#endif