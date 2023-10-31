
#ifndef PROPERTY_H
#define PROPERTY_H
#include <iostream>
#include "tax_rates.h"

using namespace std;

class Property : public IJsonIO
{
protected:
    double worth; // valor da propriedade
public:
    Property(double _worth);
    
    virtual double calculatePropertyTax() = 0;

    double calculateIncomeTax();

    void setWorth(double _worth);
    
    double getWorth();

        virtual void fromJson(const json& jsonObject) {
        worth = jsonObject["worth"];
    }

    virtual json toJson() const {
        return {
            {"worth", worth},
            {"property_tax", calculatePropertyTax()},
            {"income_tax", calculateIncomeTax()}
        };
    }
    
};

void Property::setWorth(double _worth){
    if(_worth > 0){
        this->worth = _worth;
    }
};

double Property::getWorth(){
    return this->worth;
};

double Property::calculateIncomeTax() {
    return 0.13 * this->worth;
};

Property::Property(double _worth){
    this->worth = _worth;
};

#endif
