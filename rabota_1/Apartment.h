#include <iostream>
#include "Property.h"

using namespace std;

class Apartment : Property
{
private:
    double square; // area do apartamento
public:
    Apartment(double worth, double square) : Property(worth), square(square){};

    double calculatePropertyTax() const override{
        if (square < TAX_RATES::LIMIT_APPARTMENT_SQUARE)
        {
            return Property::worth*TAX_RATES::APPARTMENT_TEX;
        }
        else
        {
            return Property::worth*TAX_RATES::APPARTMENT_LUXURY_TAX;
        }
    }

};
