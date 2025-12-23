#ifndef INVENTORYITEM_H
#define INVENTORYITEM_H
#include <string>
using namespace std;

class InventoryItem
{
    private:
        string description;
        double cost;
        int units;
    public:
        // Constructor #1 (default constructor)
        InventoryItem()
            { // Initialize description, cost, and units.
                description = "";
                cost = 0.0;
                units = 0;
            }
            
        // Constructor #2
        InventoryItem(string desc)
            { // Assign the value to description.
                description = desc;
                
             // Initialize cost and units
                cost = 0.0;
                units = 0;
            }
        
        // Constructor #3
        InventoryItem(string desc, double c, int u)
            {
                description = desc;
                cost = c;
                units = u;
            }
        
        // Constructor #4
        InventoryItem(double c)
            {
                description = "";
                cost = c;
                units = 0;
            }    

        // Constructor #5
        InventoryItem(string desc, double c)
            {
                description = desc;
                cost = c;
                units = 1;
            }
            
        // Constructor #6
        InventoryItem(double c, int u)
        {
            description = "";
            cost = c;
            units = u;
        }
            
        // Mutator functions
        void setDescription(string d)
            { description = d; }
            
        void setCost(double c)
            { cost = c; }
            
        void setUnits(int u)
            { units = u; }
            
        // Accessor functions
        string getDescription() const 
            { return description; }
            
        double getCost() const
            { return cost; }
        
        int getUnits() const
            { return units; }
};
#endif