#include "Movie.h"

//Parameterized Constructor
Movie::Movie(const string &name, const string &description, int duration, int pgRating) : name(name),
                                                                                          description(description),
                                                                                          duration(duration),
                                                                                          pgRating(pgRating) {}

//getter
string Movie::getName() const {
    return name;
}

//setter
void Movie::setName(const string name) {
    this->name = name;
}

//getter
string Movie::getDescription() const {
    return description;
}

//setter
void Movie::setDescription(const string description) {
    this->description = description;
}

//getter
int Movie::getDuration() const {
    return duration;
}

//setter
void Movie::setDuration(int duration) {
    this->duration = duration;
}

//getter
int Movie::getPgRating() const {
    return pgRating;
}

//setter
void Movie::setPgRating(int pgRating) {
    this->pgRating = pgRating;
}

//getter
vector<Cast> Movie::getCast() const {
    return cast;
}

//setter
void Movie::setCast(const vector<Cast> cast) {
    this->cast = cast;
}

//getter
MovieProduction Movie::getMovieProduction() const {
    return movieProduction;
}

//setter
void Movie::setMovieProduction(const MovieProduction movieProduction) {
    this->movieProduction = movieProduction;
}

//add MovieProduction
void Movie::addMovieProduction(MovieProduction &movieProduction1) {
    movieProduction = movieProduction1;
}

//add cast to vector
void Movie::addCast(Cast &cast1) {
    cast.push_back(cast1);
}

//add Genre to Vector
void Movie::addGenre(Genre &genre1) {
    genre.push_back(genre1);
}

//display Movie Details
void Movie::displayMovieDetails() {
    cout << "Name: " << name << " Description: " << description << " Duration: " << duration
         << "minutes pgRating: " << pgRating << " Genre: ";
    for (int i = 0; i < genre.size(); ++i) {
        genre[i].displayGenre();
    }
    cout << " Cast: \n";
    for (int i = 0; i < cast.size(); ++i) {
        cast[i].displayCast();
    }
    cout << "\n Movie Production: " << movieProduction;
}

//Overloaded Output Operator
ostream &operator<<(ostream &os, const Movie &movie) {
    os << "Name: " << movie.name << " Description: " << movie.description << " Duration: " << movie.duration
       << " pgRating: " << movie.pgRating;
    return os;
}

//getter
vector<Genre> Movie::getGenre() const {
    return genre;
}

//setter
void Movie::setGenre(const vector<Genre> genre) {
    this->genre = genre;
}

//read Movie Data from Json
Movie Movie::readFromJson(json &readData) {
   Movie temp;
    temp.name = readData["Movie Name"];
    temp.description = readData["Movie Description"];
    temp.duration = readData["Movie Duration"];
    temp.pgRating = readData["Movie PgRating"];
    for (int i = 0; i < readData["Genre"].size(); i++) {
        temp.genre.push_back(Genre::readFromJson(readData["Genre"][i]));
    }
    for (int i = 0; i < readData["Feedbacks"].size(); i++) {
        temp.feedback.push_back(Feedback::readFeedbackFromJSON(readData["Feedbacks"][i]));
    }
    for (int i = 0; i < readData["Cast"].size(); ++i) {
        temp.cast.push_back(Cast::readCastfromJson(readData["Cast"][i]));
    }
    temp.movieProduction.readMovieProductionFromJson(readData["Movie Production"]);
    return temp;
}

//write Movie Data to Json
json Movie::getMovieJson() {
    json movieData;
    movieData["Movie Name"] = name;
    movieData["Movie Description"] = description;
    movieData["Movie Duration"] = duration;
    movieData["Movie PgRating"] = pgRating;
    json genreData;
    for (int i = 0; i < genre.size(); ++i) {
        genreData.push_back(genre[i].getGenreJson());
    }
    movieData["Genre"] = genreData;
    json castData;
    for (int i = 0; i < cast.size(); ++i) {
        castData.push_back(cast[i].getCastJson());
    }
    movieData["Cast"] = castData;

    json feedbackData;
    for (int i = 0; i < feedback.size(); ++i) {
        feedbackData.push_back(feedback[i].writeFeedbackToJson());
    }
    movieData["Feedbacks"] = feedbackData;

    json movieProductionData;
    movieProductionData = movieProduction.getMovieProductionJson();
    movieData["Movie Production"] = movieProductionData;
    return movieData;
}

//write Movie Data to Json for Showtime
json Movie::getMovieJsonForShowtime() {
    json movieData;
    movieData["Movie Name"] = name;

    return movieData;
}

//read Movie Data from Json for Showtime
Movie Movie :: readFromJsonForShowtime(json &readData) {
    Movie temp;
    temp.name = readData["Movie Name"];
    return temp;
}

void Movie::addFeedback(Feedback &feedback1) {
feedback.push_back(feedback1);
}

void Movie::displayFeedbacks() {
cout<<"Feedbacks For Movie: \n";
    for (int i = 0; i < feedback.size(); ++i) {
        feedback[i].displayFeedback();
    }
}
