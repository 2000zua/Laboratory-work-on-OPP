#include <iostream>

using namespace std;

class Car :public Property
{
protected:
    double horsepower; 
public:
    Car(double _worth, double _horsepower);

    double calculatePropertyTax() override{
        if (this->horsepower < TAX_RATES::LOW_HORSEPOWER)
        {
            return Property::worth*TAX_RATES::CAR_TAX;
        }
        else{
           if (this->horsepower > TAX_RATES::HIGHT_HORSEPOWER)
           {
                return Property::worth*TAX_RATES::CAR_LUXURY_TAX;
           }
           else
           {
                return Property::worth*TAX_RATES::CAR_TRUCK_TAX;
           }
        }
    }

    void fromJson(const json& jsonObject) override {
        Property::fromJson(jsonObject);
        horsepower = jsonObject["horsepower"];
    }

    json toJson() const override {
        json propertyJson = Property::toJson();
        propertyJson["horsepower"] = horsepower;
        return propertyJson;
    }

    double getHorsepower();
    void setHorsepower(double _horsepower);


};

Car::Car(double _worth, double _horsepower):Property(_worth){
    setHorsepower(_horsepower);
};

double Car::getHorsepower(){
    return this->horsepower;
};

void Car::setHorsepower(double _horsepower){
    this->horsepower = _horsepower;
};
