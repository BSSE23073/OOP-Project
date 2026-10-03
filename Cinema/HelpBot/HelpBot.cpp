#include "HelpBot.h"

HelpBot *HelpBot::instance = nullptr;

void HelpBot::addQuestionAndAnswer(string &question, string &answer){
    questions.push_back(question);
    answers.push_back(answer);
}

void HelpBot::addComplaints(string &complaint){
    complaints.push_back(complaint);
}

void HelpBot::displayQuestion() {
    for (int i = 0; i < questions.size(); ++i) {
        cout << "Question " << i + 1 << ". " << questions[i]<<endl;
    }
}

void HelpBot::addSuggestionQuestions(string &question1) {
    suggestedQuestions.push_back(question1);
}

void HelpBot::chooseQuestion(){
    displayQuestion();
    int index;
    cout << "Enter Question Number: ";
    cin >> index;
    cout << answers[index - 1];
}

void HelpBot::writeToJSON(){
    json helpBot;
    json questionsData;
    for (int i = 0; i < questions.size(); ++i) {
        json question;
        question["Question"] = questions[i];
        questionsData.push_back(question);
    }
    helpBot["Questions"] = questionsData;
    json answersData;
    for (int i = 0; i < answers.size(); ++i) {
        json answer;
        answer["Answer"] = answers[i];
        answersData.push_back(answer);
    }
    helpBot["Answers"] = answersData;
    json suggestionData;
    for (int i = 0; i < suggestedQuestions.size(); ++i) {
        json suggestions;
        suggestions["Suggestion"] = suggestions[i];
        suggestionData.push_back(suggestions);
    }
    helpBot["Suggestions"] = suggestionData;
    json complainData;
    for (int i = 0; i < complaints.size(); ++i) {
        json complain;
        complain["Complain"] = complaints[i];
        complainData.push_back(complain);
    }
    helpBot["Complaints"] = complainData;
    ofstream writeData("Cinema/HelpBot/HelpBotData.json",ios::out);
    if (writeData.is_open()) {
        // function return json then store it into file
        writeData << helpBot.dump(2);
    } else {
        cerr << "file is not open" << endl;
    }
}

string HelpBot::readQuestions(json &questionData) {
    string question;
    question = questionData["Question"];
    return question;
}

string HelpBot::readAnswer(json &answerData) {
    string answer;
    answer = answerData["Answer"];
    return answer;
}

string HelpBot::readSuggestions(json &suggestionData) {
    string suggestion;
    suggestion = suggestionData["Suggestion"];
    return suggestion;
}

string HelpBot::readComplaints(json &complaintsData) {
    string complain;
    complain = complaintsData["Complain"];
    return complain;
}

void HelpBot::readFileFromJSON() {
    ifstream readData("Cinema/HelpBot/HelpBotData.json",ios::in);
    if(!readData.is_open()){
        cerr << "file is not open" << endl;
        return;
    }
    json read;
    readData >> read;
    for (int i = 0; i < read["Questions"].size(); ++i) {
        questions.push_back(readQuestions(read["Questions"][i]));
    }
    for (int i = 0; i < read["Answers"].size(); ++i) {
        answers.push_back(readAnswer(read["Answers"][i]));
    }
    for (int i = 0; i < read["Suggestions"].size(); ++i) {
        suggestedQuestions.push_back(readSuggestions(read["Suggestions"][i]));
    }
    for (int i = 0; i < read["Complaints"].size(); ++i) {
        complaints.push_back(readComplaints(read["Complaints"][i]));
    }
}

HelpBot *HelpBot::getInstance() {
    if(!instance){
        instance = new HelpBot;
    }
    return instance;
}

void HelpBot::menuForHelpBot() {
    int choice;

    do {
        cout << "HelpBot Menu\n";
        cout << "1. Display Questions\n";
        cout << "2. Add Complaint\n";
        cout << "3. Add Suggested Question\n";
        cout << "4. Choose Question\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayQuestion();
                break;
            case 2:{

                string complain1;
                cout<<"Enter the complain you want to give:";
                cin.ignore();
                getline(cin,complain1);
                addComplaints(complain1);
                break;
            }
            case 3: {
                string suggestion1;
                cout << "Enter the suggestion you want to give:";
                cin.ignore();
                getline(cin,suggestion1);
                addComplaints(suggestion1);
                break;
            }
            case 4:
                chooseQuestion();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice! Please enter a valid option.\n";
                break;
        }
    } while (choice != 5);

}
