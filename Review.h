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
        double getScore() { return score; };
        string getComment() { return comment; };
        
        void showReview(){
            cout << "Score: " << score << ", Comment: " << comment << endl;
        }

        void setScore(double score) { this->score = score; };
        void setComment(string comment) { this->comment = comment; };

        friend class Member;
        friend class Motorbike;
};