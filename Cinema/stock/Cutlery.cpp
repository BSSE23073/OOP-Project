//
// Created by APPLE on 06/05/2024.
//

#include "Cutlery.h"


//
// Created by APPLE on 06/05/2024.
//

#include "Cutlery.h"
Cutlery::Cutlery()
{
    type="";
}
Cutlery::Cutlery(std::string type,int quantity)
{
    this->type=type;
    this->quantity=quantity;
}
void Cutlery::display()
{
    cout<<"Type: "<<type<<"\tQuantity: "<<quantity<<endl;
}

void Cutlery::setType(std::string type)
{
    this->type=type;
}

string Cutlery::getType()
{
    return type;
}

void Cutlery::setQuantity(int quantity)
{
    this->quantity=quantity;
}

int Cutlery::getQuantity()
{
    return quantity;
}

void Cutlery::add(int quantity)
{
    this->quantity+=quantity;
    cout<<"Added "<<quantity<<"\t of "<<type<<" To inventory."<<endl;
}

void Cutlery::remove(int quantity) {
    if (this->quantity >= quantity) {
        this->quantity -= quantity;
        cout << "Removed " << quantity << " of " << type << " from inventory." << endl;
    } else {
        cout << "Insufficient Quantity of " << type << " in inventory." << endl;
    }
}