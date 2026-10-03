#ifndef INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_CHATBOT_H
#define INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_CHATBOT_H
#include <iostream>
#include <vector>
#include "./../../nlohmann/json.hpp"
#include <fstream>

using namespace std;
using json = nlohmann :: json;

class HelpBot {
    static HelpBot* instance;
    vector <string> questions;
    vector <string> answers;
    vector <string> suggestedQuestions;
    vector <string> complaints;
    HelpBot(){
    }
public:
    static HelpBot* getInstance();
    void displayQuestion();
    void addComplaints(string &complaint);
    void addSuggestionQuestions(string &question);
    void chooseQuestion();
    void addQuestionAndAnswer(string &question, string &answer);
    void writeToJSON();
    void readFileFromJSON();
    string readQuestions(json &questionData);
    string readAnswer(json &answerData);
    string readSuggestions(json &suggestionData);
    string readComplaints(json &complaintsData);
    void menuForHelpBot();
};

#endif //INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_CHATBOT_H
