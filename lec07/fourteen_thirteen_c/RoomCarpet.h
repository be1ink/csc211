// Specification file for the RoomCarpet class
#ifndef ROOM_CARPET_H
#define ROOM_CARPET_H
#include "RoomDimension.h"

class RoomCarpet
{
private:
    RoomDimension dimensions;   // The room dimensions
    double cost;                // Cost per square foot

public:
    // Constructor
    RoomCarpet(RoomDimension rd, double c)
    {
        dimensions = rd;
        cost = c;
    }

    // getTotalCost function
    double getTotalCost()
    {
        double area = dimensions.getAreaInFeet();
        return area * cost;
    }
};

#endif