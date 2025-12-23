#ifndef INVENTORY_H
#define INVENTORY_H

class Inventory
{
    private:
    int itemNumber;
    int quantity;
    double cost;
    double totalCost;

    public:

    // Constructors

    Inventory()
    {
        itemNumber = 0;
        quantity = 0;
        cost = 0;
        totalCost = 0;
    }

    Inventory(int iNum, int q, double c)
    {
        itemNumber = iNum;
        quantity = q;
        cost = c;
        setTotalCost();
    }

    // Setters
    void setItemNumber(int iNum)
    {
        itemNumber = iNum;
    }

    void setQuantity(int q)
    {
        quantity = q;
    }

    void setCost(double c)
    {
        cost = c;
    }

    void setTotalCost()
    {
        totalCost = quantity * cost;
    }

    // Getters

    int getItemNumber()
    {
        return itemNumber;
    }

    int getQuantity()
    {
        return quantity;
    }

    double getCost()
    {
        return cost;
    }

    double getTotalCost()
    {
        return totalCost;
    }
};

#endif