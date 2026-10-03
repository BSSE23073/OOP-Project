#include "MovieRoaster.h"
MovieRoaster* MovieRoaster::instance= nullptr;

//getter
MovieRoaster *MovieRoaster::getInstance() {
    if (!instance){
        instance=new MovieRoaster;
    }
    return instance;
}

//add Movie to vector in roaster
void MovieRoaster::addMovieToRoaster(Movie &movie1) {
    movie.push_back(movie1);
}

//remove Movie from vector in roaster
void MovieRoaster::removeMovieFromRoaster(string movieName) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i].getName()==movieName){
            movie.erase(movie.begin()+i);
            return;
        }
    }
}

//change Movie Cast of a specific Movie
void MovieRoaster::updateMovieDetails(std::string movieName, Cast &cast) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i].getName()==movieName){
            movie[i].addCast(cast);
            return;
        }
    }
}

//change Movie pdRating of a specific Movie
void MovieRoaster::updateMovieDetails(std::string movieName, int pgRating) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i].getName()==movieName){
            movie[i].setPgRating(pgRating);
            return;
        }
    }
}

//display all movies in Roaster
void MovieRoaster::displayMovieList() {
    cout<<"Movies in Roaster: \n";
    for (int i = 0; i < movie.size(); ++i) {
        cout<<i+1<<". ";
        movie[i].displayMovieDetails();
    }
}

//Menu of Roaster to run in Main
void MovieRoaster::menuForRoaster() {
//    readDataFromFile();
    int x = 0;
    while (x != 4) {
        cout
                << "Movies Management: \n1. Add Movie To Cinema\n2. Remove Movie From Cinema\n3. Display Movie Roaster\n4. Exit\n";
        cin >> x;
        if (x == 1) {
            string name, description;
            int duration, pgRating;

            cout << "Enter movie name: ";
            cin.ignore();
            getline(cin, name);

            cout << "Enter movie description: ";
            getline(cin, description);

            cout << "Enter movie duration (in minutes): ";
            cin >> duration;

            cout << "Enter movie PG rating: ";
            cin >> pgRating;

            cin.ignore(); // Clear the input buffer

            // Create a new Movie object
            Movie newMovie(name, description, duration, pgRating);

            // Add genres
            char addMoreGenres;
            do {
                string genreName;
                cout << "Enter genre name: ";
                getline(cin, genreName);
                Genre genre(genreName);
                newMovie.addGenre(genre);
                cout << "Add another genre? (y/n): ";
                cin >> addMoreGenres;
                cin.ignore(); // Clear the input buffer
            } while (addMoreGenres == 'y' || addMoreGenres == 'Y');

            // Add casts
            char addMoreCasts;
            do {
                string actorName, gender, role, nationality;
                int age;

                cout << "Enter actor name: ";
                getline(cin, actorName);
                cout << "Enter gender: ";
                cin >> gender;
                cout << "Enter age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter role in movie: ";
                getline(cin, role);
                cout << "Enter nationality: ";
                cin >> nationality;
                Cast cast(actorName, gender, age, role, nationality);
                newMovie.addCast(cast);
                cout << "Add another actor? (y/n): ";
                cin >> addMoreCasts;
                cin.ignore(); // Clear the input buffer
            } while (addMoreCasts == 'y' || addMoreCasts == 'Y');

            // Add movie production details
            string producer, director, productionCompany, DOP, editor;
            cout << "Enter producer name: ";

            getline(cin, producer);
            cout << "Enter director name: ";

            getline(cin, director);
            cout << "Enter Production Company: ";

            getline(cin, productionCompany);
            cout << "Enter DOP name: ";

            getline(cin, DOP);
            cout << "Enter editor name: ";
            getline(cin, producer);
            MovieProduction movieProduction(producer, director, productionCompany, DOP, editor);
            newMovie.addMovieProduction(movieProduction);

            // Add the new movie to the vector
            MovieRoaster::getInstance()->addMovieToRoaster(newMovie);

            cout << "Movie added successfully!" << endl;
//            Movie movie1("MI : 7", "A Mission Which the world awaits to watch!!", 120, 16);
//    Genre genre("Action");
//    movie1.addGenre(genre);
//    MovieProduction movieProduction("Dumbo", "Nauraiz", "Paramount", "Tom Cruise", "RDJ");
//    movie1.addMovieProduction(movieProduction);
//    Cast cast("Robert Downey Jr.", "Male", 55, "Hero", "British");
//    movie1.addCast(cast);
//            MovieRoaster::getInstance()->addMovieToRoaster(movie1);
        }
        if (x == 2) {
            string name;
            cout << "Enter Movie name: ";
            cin.ignore();
            getline(cin, name);
            MovieRoaster::getInstance()->removeMovieFromRoaster(name);
        }
        if (x == 3) {
            MovieRoaster::getInstance()->displayMovieList();
        }
        if (x == 4) {
            cout << "Exit....\n";
            writeDataToJson();
        }

    }
}

//getter
Movie MovieRoaster::getMovie(int num) {
    return movie[num-1];
}

Movie MovieRoaster::selectMovie() {
    int x = 0;
    movieLoop:
    cout << "Select Movie From Roaster: " << endl;
    MovieRoaster::getInstance()->displayMovieList();
    cin >> x;
    if (x - 1 >= movie.size()) {
        cout << "Index Not Found" << endl;
        goto movieLoop;
    } else {
        return getMovie(x);
    }
}

//write Movie Roaster Data to File
void MovieRoaster::dataFromJsonToRoaster(json &readData) {
    for(auto &i : readData){
        movie.push_back(Movie::readFromJson(i));
    }
}

//read Movie Roaster Data from File
void MovieRoaster::readDataFromFile() {
ifstream read("Cinema/Movie/MovieRoaster.json",ios::in);
    if (!read.is_open()) {
        cerr << "Failed to open JSON file." << endl;
        return;
    }
    json movieData;
    read >> movieData;
    read.close();
    dataFromJsonToRoaster(movieData);
}

//get movie for Showtime
Movie MovieRoaster::getMovieForShowtime(string movieName) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i].getName()==movieName){
            return movie[i];
        }
    }
    cout<<"Error!!\n";
}

void MovieRoaster::addFeedbackToMovie(string movieName) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i].getName()==movieName){
            string feedback;
            int rating;
            cout<<"Enter Your Opinion about "<<movieName;
            cin>>feedback;
            cout<<"Enter Your Rating for movie (1-5)";
            cin>>rating;
            Feedback feedback1(rating,feedback);
            movie[i].addFeedback(feedback1);
            return;
        }
    }
}

void MovieRoaster :: displayFeedbacksForMovie(string movieName) {
    for (int i = 0; i < movie.size(); ++i) {
        if (movie[i].getName()==movieName){
            movie[i].displayFeedbacks();
            return;
        }
    }
}
