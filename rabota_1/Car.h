#include <iostream>

using namespace std;

class Car : Property
{
private:
    int horsepower; // cavalo de forca do cavalo
public:
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
