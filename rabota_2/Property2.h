#include <iostream>
#include "tax_rates2.h"

using namespace std;

class Property
{

public:
    double worth;
    Property(double worth):worth(worth){}
    
    virtual double calculatePropertyTax() const = 0;

    double calculateIncomeTax() const {
        return 0.13 * this->worth;
    }

    void setWorth(double worth){
        if (worth > 0)
        {
            this->worth = worth;
        }
        // send the erro sms   
    }
    double getWorth(){
        return this->worth;
    }

    
};