#include <iostream>
#include "Property.h"
#include "tax_rates.h"

using namespace std;

class Apartment : public Property
{
protected:
    double square;
public:
    Apartment(double _worth, double _square): Property(_worth){
        this->square = _square;
    };

    double calculatePropertyTax() override{
        if (this->square< TAX_RATES::LIMIT_APPARTMENT_SQUARE){
            return Property::worth*TAX_RATES::APPARTMENT_TEX;
        }
        else{
            return Property::worth*TAX_RATES::APPARTMENT_LUXURY_TAX;
        }
    }


};



