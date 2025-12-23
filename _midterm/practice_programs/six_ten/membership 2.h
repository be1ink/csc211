// Code for Membership class
#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H

class Membership
{
private:
    double rate;
    double cost;
    static constexpr double ADULT_RATE = 65.00;
    static constexpr double CHILD_RATE = 35.00;
    static constexpr double SENIOR_RATE = 45.00;
public:
    // Constructors    
    Membership() : rate(0.00) {}
    // Membership(double r) : rate(r < 0.00 ? 0.00 : r) {}

    // Setters
    void set_rate(int choice)
    {
        switch(choice)
        {
            case 1: // Standard Adult
                rate = ADULT_RATE;
                break;
            case 2: // Child
                rate = CHILD_RATE;
                break;
            case 3: // Senior Citizen
                rate = SENIOR_RATE;
                break;
            case 4: // Exit condition
                break;
        }
    }

    void set_cost(int months) {cost = get_rate() * months;}

    // Getters
    double get_rate() const {return rate;}
    double get_cost() const {return cost;}
};

#endif