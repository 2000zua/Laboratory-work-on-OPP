#ifndef OWNER_H
#define OWNER_
#include <iostream>
#include <string>
#include <vector>
#include "Property.h"

using namespace std;

class Owner : public IJsonIO
{
protected:
    string fullName;
    int INN;
    vector<Property*> properties;

public:
    Owner(string _fullname, int _inn);

    // getter and setter
    string getFullName();
    void setFullName(string _fullName);

    void setINN(int _inn);
    int getINN();

    // add uma propriedade
    void addProperty(Property* _property);

    // metodo para apagar
    int removeProperty(Property* _property);

    // metodo para calcular o imposto total
    double calculateTotalPropertyTax();

    //mostrar todas as propriedades do proprietario
    void showAllProperties();

    void fromJson(const json& jsonObject) override {
        fullName = jsonObject["fullName"];
        inn = jsonObject["inn"];
        properties.clear();

        const json& propertiesArray = jsonObject["properties"];
        for (const json& propertyJson : propertiesArray) {
            std::string propertyType = propertyJson["type"];
            if (propertyType == "Apartment") {
                Apartment* apartment = new Apartment(0, 0);
                apartment->fromJson(propertyJson);
                properties.push_back(apartment);
            } else if (propertyType == "Car") {
                Car* car = new Car(0, 0);
                car->fromJson(propertyJson);
                properties.push_back(car);
            } else if (propertyType == "CountryHouse") {
                CountryHouse* countryHouse = new CountryHouse(0, 0);
                countryHouse->fromJson(propertyJson);
                properties.push_back(countryHouse);
            }
        }
    }

    json toJson() const override {
        json ownerJson = {
            {"fullName", fullName},
            {"inn", inn},
            {"total_property_tax", calculateTotalPropertyTax()},
            {"properties", json::array()}
        };

        json& propertiesArray = ownerJson["properties"];
        for (const Property* property : properties) {
            propertiesArray.push_back(property->toJson());
        }
        return ownerJson;
    }

    ~Owner();

};

Owner::Owner(string _fullname, int _inn){
    setFullName(_fullname);
    setINN(_inn);
};

Owner::~Owner(){
    for (Property* property:properties){
        delete property;
    }        
};

string Owner::getFullName(){
    return this->fullName;
};

void Owner::setFullName(string _fullName){
    this->fullName = _fullName;
};

int Owner::getINN(){
    return this->INN;
};

void Owner::setINN(int _inn){
    this->INN = _inn;
};

void Owner::addProperty(Property* _property){
    properties.push_back(_property);
};


int Owner::removeProperty(Property* _property){
    // usando um interador para achar a propriedade a ser removida
    for (auto i = properties.begin(); i != properties.end(); ++i){
        if (*i == _property){
            try{
                delete *i; 
                properties.erase(i);
                break;
                return 0;
            }
            catch(const std::exception& e)
            {
                return -1;
            }
        }else{
            return -1;
        }
    }
    return -1;
};

double Owner::calculateTotalPropertyTax()  {
    double totalTax = 0.0;
    for (Property* property : properties){
        totalTax += property->calculatePropertyTax();
    }
    return totalTax;
};

void Owner::showAllProperties(){
    cout << "Properties of "<< getFullName() <<"[INN{"<<getINN()<<"}]: " <<endl;
    for (Property* property : properties){
        cout << "- Worth: $" << property->getWorth() << endl;
    } 
};

#endif