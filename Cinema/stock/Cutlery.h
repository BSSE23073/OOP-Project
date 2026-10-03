#include <iostream>
using namespace std;
#ifndef INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_CUTLERY_H
#define INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_CUTLERY_H
class Cutlery {
protected:
    string type;
    int quantity;
public:
    Cutlery();
    void display();
    Cutlery(string type,int quantity);
    void setType(string type);
    string getType();
    void setQuantity(int quantity);
    int getQuantity();
    void add(int quantity);
    void remove(int quantity);
};



#endif //INC_2024_SPRING_SE102TB_PROJECT_SE102B_G_CUTLERY_H
