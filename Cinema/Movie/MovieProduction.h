#ifndef OOPS_PROJECT_MOVIEPRODUCTION_H
#define OOPS_PROJECT_MOVIEPRODUCTION_H

#include "iostream"
#include "./../../nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;
class MovieProduction {
    string producer;
    string director;
    string productionCompany;
    string DOP;
    string editor;
public:

    //Default Constructor
    MovieProduction() {}

    //Parameterized Constructor
    MovieProduction(const string &producer, const string &director, const string &productionCompany, const string &dop,
                    const string &editor);

    //getter
    string getProducer() const;

    //setter
    void setProducer(const string producer);

    //getter
    string getDirector() const;

    //setter
    void setDirector(const string director);

    //getter
    string getProductionCompany() const;

    //read Movie Production Data from Json
    void readMovieProductionFromJson(json &readMovieProduction);

    //setter
    void setProductionCompany(const string productionCompany);

    //getter
    string getDop() const;

    //setter
    void setDop(const string dop);

    //getter
    string getEditor() const;

    //write Movie Production Data to Json
    json getMovieProductionJson();

    //overload Output operator
    friend ostream &operator<<(ostream &os, const MovieProduction &production) {
        os << "Producer: " << production.producer << " Director: " << production.director << " ProductionCompany: "
           << production.productionCompany << " DOP: " << production.DOP << " Editor: " << production.editor<<endl;
        return os;
    }

    //setter
    void setEditor(const string editor);

    //display MovieProduction Function
    void displayMovieProducton();
};


#endif //OOPS_PROJECT_MOVIEPRODUCTION_H
