#include <iostream>
#include "Property2.h"

using namespace std;

class Car : Property
{

public:
    int horsepower; 
    Car(double worth, double horsepower) : Property(worth), horsepower(horsepower){}

    double calculatePropertyTax() const override{
        if (horsepower < TAX_RATES::LOW_HORSEPOWER)
        {
            return Property::worth*TAX_RATES::CAR_TAX;
        }
        else
        {
           if (horsepower > TAX_RATES::HIGHT_HORSEPOWER)
           {
                return Property::worth*TAX_RATES::CAR_LUXURY_TAX;
           }
           else
           {
                return Property::worth*TAX_RATES::CAR_TRUCK_TAX;
           }
           
        }
        
    }

};
