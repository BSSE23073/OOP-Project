#ifndef OOPS_PROJECT_MOVIE_H
#define OOPS_PROJECT_MOVIE_H

#include "MovieProduction.h"
#include "Cast.h"
#include "Genre.h"
#include <vector>
#include <ostream>
#include "../../nlohmann/json.hpp"
#include "Feedback.h"
using json = nlohmann::json;
using namespace std;

class Movie {
    string name;
    string description;
    int duration;
    int pgRating;
    vector<Genre>genre;
    vector<Cast> cast;
    vector<Feedback> feedback;
    MovieProduction movieProduction;
public:

    //Default Constructor
    Movie() = default;

    //getter
    string getName() const;

    //setter
    void setName(const string name);

    //getter
    string getDescription() const;

    //setter
    void setDescription(const string description);

    //getter
    int getDuration() const;

    //setter
    void setDuration(int duration);

    //getter
    int getPgRating() const;

    //setter
    void setPgRating(int pgRating);

    //getter
    vector<Genre> getGenre() const;

    //setter
    void setGenre(const vector<Genre> genre);

    //getter
    vector<Cast> getCast() const;

    //setter
    void setCast(const vector<Cast> cast);

    //getter
    MovieProduction getMovieProduction() const;

    //setter
    void setMovieProduction(const MovieProduction movieProduction);

    //Parameterized Constructor
    Movie(const string &name, const string &description, int duration, int pgRating);

    //write Movie Data to Json
    json getMovieJson();

    //read Movie Data from Json
    static Movie readFromJson(json &readData);

    //add Genre to Vector
    void addGenre(Genre &genre1);

    //add Feedback to Vector
    void addFeedback(Feedback &feedback1);

    //display Feedbacks
void displayFeedbacks();

    //add MovieProduction
    void addMovieProduction(MovieProduction &movieProduction1);

    //add cast to vector
    void addCast(Cast &cast1);

    //display Movie Details
    void displayMovieDetails();

    //Overloaded Output Operator
    friend ostream &operator<<(ostream &os, const Movie &movie);

    //write Movie Data to Json for Showtime
    json getMovieJsonForShowtime();

    //read Movie Data from Json for Showtime
    static Movie readFromJsonForShowtime(json &readData);
};


#endif //OOPS_PROJECT_MOVIE_H
