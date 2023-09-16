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
        string name;
        double score;
        string comment;
    public:
        Review(string name,double score, string comment) : name(name), score(score), comment(comment) { };

        void showReview(){
            cout << "Name: " << name << endl;
            cout << "Score: " << score << endl;
            cout << "Comment: " << comment << endl;
        }
};