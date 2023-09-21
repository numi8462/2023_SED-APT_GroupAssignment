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

#include "Review.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


//getters
double Review::getScore() { return score; };
string Review::getComment() { return comment; };
string Review::getReviewType() { return reviewType; };
string Review::getID() { return id; };

void Review::showReview(){
    cout << "Score: " << score << ", Comment: " << comment << endl;
}

void Review::setScore(double score) { this->score = score; };
void Review::setComment(string comment) { this->comment = comment; };
void Review::setReviewType(string reviewType){this->reviewType = reviewType;}
void Review::setID(string id){this->id = id;}

