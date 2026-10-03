//
// Created by Dell on 08/04/2024.
//

#ifndef OOPS_PROJECT_MOVIEROASTER_H
#define OOPS_PROJECT_MOVIEROASTER_H

#include "Movie.h"
#include <vector>
#include <fstream>
#include "./../../nlohmann/json.hpp"

using json = nlohmann::json;

class MovieRoaster {
    static MovieRoaster *instance;
    vector<Movie> movie;

    //Default Constructor
    MovieRoaster() {}

public:

    //getter
    static MovieRoaster *getInstance();

    //read Movie Roaster Data from File
    void readDataFromFile();

    //write Movie Roaster Data to File
    void dataFromJsonToRoaster(json &readData);

    //add Movie to vector in roaster
    void addMovieToRoaster(Movie &movie1);

    //add feedback to movie
    void addFeedbackToMovie(string movieName);

    //display Feedback for movies
    void displayFeedbacksForMovie(string movieName);

    //remove Movie from vector in roaster
    void removeMovieFromRoaster(string movieName);

    //change Movie Cast of a specific Movie
    void updateMovieDetails(string movieName, Cast &cast);

    //change Movie pdRating of a specific Movie
    void updateMovieDetails(string movieName, int pgRating);

    //display all movies in Roaster
    void displayMovieList();

    //Menu of Roaster to run in Main
    void menuForRoaster();

    //get movie for Showtime
    Movie getMovieForShowtime(string movieName);

    //write Movie Data to Json
    void writeDataToJson() {
        json movies;
        for(auto i: movie) {
            movies.push_back(i.getMovieJson());
        }
        ofstream write("Cinema/Movie/MovieRoaster.json", ios::out);
        if (write.is_open()) {
            // function return json then store it nto file
            write << movies.dump(2);
        } else {
            cerr << "file is not open" << endl;
        }

    }

    //getter
    Movie getMovie(int num);

    //select a specific Movie
    Movie selectMovie();
};


#endif //OOPS_PROJECT_MOVIEROASTER_H
