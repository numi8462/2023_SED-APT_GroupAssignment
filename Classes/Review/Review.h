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
        double score;
        string comment;
    public:
        Review() { };
        Review(double score, string comment) : score(score), comment(comment) { };

        //getters
        double getScore();
        string getComment();
        
        void showReview();

        void setScore(double score);
        void setComment(string comment);

        friend class Member;
        friend class Motorbike;
};

#endif