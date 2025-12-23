// Specification file for the RoomDimension class
#ifndef ROOM_DIMENSION_H
#define ROOM_DIMENSION_H
#include "FeetInches.h"

class RoomDimension
{
private:
    FeetInches length;   // The length of the room
    FeetInches width;    // The width of the room
    FeetInches area;     // The room's area

public:
    // Default constructor
    RoomDimension()
    {
    }

    // Constructor
    RoomDimension(FeetInches len, FeetInches w)
    {
        length = len;
        width = w;
        area = len.multiply(w);
    }

    // Copy constructor
    RoomDimension(const RoomDimension &obj)
    {
        length = obj.length;
        width = obj.width;
        area = obj.area;
    }

    // getArea function (returns FeetInches object)
    FeetInches getArea()
    {
        return area;
    }

    // getAreaInFeet function (returns numeric total feet)
    double getAreaInFeet()
    {
        double totalFeet = area.getFeet() + (area.getInches() / 12.0);
        return totalFeet;
    }
};
#endif