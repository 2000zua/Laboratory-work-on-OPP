#include <iostream>
#include "Property2.h"

using namespace std;

class Apartment : Property
{

public:
    double square; // area do apartamento
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
