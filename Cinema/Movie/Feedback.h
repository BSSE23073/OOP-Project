//
// Created by Dell on 05/05/2024.
//

#ifndef INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_FEEDBACK_H
#define INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_FEEDBACK_H
#include <iostream>
#include "../../nlohmann/json.hpp"

using json = nlohmann::json;
using namespace std;
class Feedback {
    int rating;
    string review;

public:
    Feedback(){
        rating = 0;
        review = " ";
    }
    Feedback( int rating, std::string review) {
        this->rating = rating;
        this->review = review;
    }
    void displayFeedback() {
        cout << "Rating: " << rating <<endl;
        cout << "Review:" <<endl;
        cout << review <<endl;
    }
    static Feedback readFeedbackFromJSON(json &feedbackData){
        Feedback feedback;
        feedback.review = feedbackData["Review"];
        feedback.rating = feedbackData["Rating"];
        return feedback;
    }
    json writeFeedbackToJson(){
        json feedbackData;
         feedbackData["Review"] = review;
         feedbackData["Rating"] = rating;
        return feedbackData;
    }
};


#endif //INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_FEEDBACK_H
