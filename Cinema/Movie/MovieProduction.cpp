#include "MovieProduction.h"

//Parameterized Constructor
MovieProduction::MovieProduction(const string &producer, const string &director, const string &productionCompany,
                                 const string &dop, const string &editor) : producer(producer), director(director),
                                                                            productionCompany(productionCompany),
                                                                            DOP(dop), editor(editor) {}

//getter
string MovieProduction::getProducer() const {
    return producer;
}

//setter
void MovieProduction::setProducer(const string producer) {
    MovieProduction::producer = producer;
}

//getter
string MovieProduction::getDirector() const {
    return director;
}

//setter
void MovieProduction::setDirector(const string director) {
    MovieProduction::director = director;
}

//Getter
string MovieProduction::getProductionCompany() const {
    return productionCompany;
}

//setter
void MovieProduction::setProductionCompany(const string productionCompany) {
    MovieProduction::productionCompany = productionCompany;
}

//getter
string MovieProduction::getDop() const {
    return DOP;
}

//setter
void MovieProduction::setDop(const string dop) {
    DOP = dop;
}

//getter
string MovieProduction::getEditor() const {
    return editor;
}

//setter
void MovieProduction::setEditor(const string editor) {
    MovieProduction::editor = editor;
}

//display MovieProduction Function
void MovieProduction::displayMovieProducton() {
    cout << "Producer: " << this->producer << " Director: " << this->director << " ProductionCompany: "
         << this->productionCompany << " DOP: " << this->DOP << " Editor: " << this->editor << endl;
}

//read Movie Production Data from Json
void MovieProduction::readMovieProductionFromJson(json &readMovieProduction) {
    producer = readMovieProduction["Producer"];
    director = readMovieProduction["Director"];
    productionCompany = readMovieProduction["Production Company"];
    DOP = readMovieProduction["DOP"];
    editor = readMovieProduction["Editor"];
}

//write Movie Production Data to Json
json MovieProduction::getMovieProductionJson() {
    json write;
    write["Producer"] = producer;
    write["Director"] = director;
    write["Production Company"] = productionCompany;
    write["DOP"] = DOP;
    write["Editor"] = editor;
    return write;
}
