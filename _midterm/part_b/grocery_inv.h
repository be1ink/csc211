// Benjamin Link

#ifndef GROCERY_INV_H
#define GROCERY_INV_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class Groceryinv
{
    private:
        // Compile-time ready constant that every class instance can use
            // other option is to make this constant global. Need this to 
            // formalize item IDs as always four concatenated integers.
        static const int ID_SIZE = 4;
        
        // Structure that contains standard contents of inventory line item.
        // I decided to use a structure since a line item is incomplete without
        // all the data input or initialized in concert.
        struct Contents
        {
            // Initialize a 1D array of four 0's. Code for "not populated."
            int id[ID_SIZE] = {0}; 
            string item_name = "";
            int quant = 0;
            double price = 0.0;
        };

        // declare a vector to store Contents elements - will support dynamic
        // increases in size since we can't anticipate how many inventory items
        // will be input by each file or user.
        vector<Contents> inventory_items;

        // Known ID and fruit pairings. Uses parallel arrays to match the items
        // by their index. This is a hardcoded method, my preference would be to 
        // implment a dynamic solution that updates these lists with user input,
        // but ran out of time.
        const int KNOWN_IDS[5]  = {1011, 1012, 1013, 1014, 1015};
        const string KNOWN_NAMES[5] = {"Avocado", "Tomato", "Orange", "Mango", 
            "Grape"};

    public:

        // Default constructor
        Groceryinv()
        {
            // Initialize with sub-set Stock data from instructions
            // I'm directly linking the item names to the text file data
            // used for Order 1, hence why names are populated here to match
            // the ItemID and Name associations from that order.
            inventory_items.push_back({{1011}, "Avocado", 100, 1.22});
            inventory_items.push_back({{1012}, "Tomato", 150, 0.63});
            inventory_items.push_back({{1013}, "Orange", 200, 1.83});
            inventory_items.push_back({{1014}, "Mango", 80, 3.63});
            inventory_items.push_back({{1015}, "Grape", 155, 3.25});
        };

        // Constructor for grocery list
        Groceryinv(ifstream& input_file)
        {
            // Declare line string to hold getline contents
            string line;
            // Temporary structure to hold each record before adding to vector
            Contents temp;

            // Ensure input_file ifstream object linked properly, no errors.
            if (!input_file)
            {
                cout << "Invalid file stream.\n";
                return;
            }

            // Skip first line, which contains field names
            getline(input_file, line);

            // While the eof bit isn't tripped, grab all the lines in the file.
            while (!input_file.eof())
            {
                int id;
                int qty;
                double price;

                input_file >> id >> qty >> price;
                if (input_file.fail())
                    break;
                input_file.clear();

                Contents temp;
                for (int i = 0; i < ID_SIZE; i++) { temp.id[i] = 0; }
                temp.id[0] = id;
                temp.quant = qty;
                temp.price = price;

                // infer name from known lists (default Unknown)
                temp.item_name = "Unknown";
                for (int i = 0; i < 5; ++i)
                {
                    if (id == KNOWN_IDS[i])
                    {
                        temp.item_name = KNOWN_NAMES[i];
                        break;
                    }
                }

                // finally push the record
                inventory_items.push_back(temp);
            }
        }

        // If ID provided, and ID associated with known item, infer name
        Groceryinv(int id, int qty, double price)
        {
            // Copying Contents struct as temp to maintain constraints of struct
            // with temporary container
            Contents temp;
            for (int i = 0; i < ID_SIZE; ++i) {temp.id[i] = 0;}

            // Assign provided ID to the first position of the ID array.
            temp.id[0] = id;

            // Default item name in case ID is not recognized in known list.
            temp.item_name = "Unknown";

            // Loop through known IDs; if a match is found, update name to match
            // the known name tied to that ID.
            for (int i = 0; i < 5; ++i)
            {
                if (id == KNOWN_IDS[i])
                {
                    // When a known ID is matched, assign its paired name to
                    // the temporary structure’s item_name field.
                    temp.item_name = KNOWN_NAMES[i];
                    break;
                }
            }

            // Assign parameter values to corresponding structure elements. Name
            // has already been assigned.
            temp.quant = qty;
            temp.price = price;

            // Add the complete line item to the inventory_items vector.
            inventory_items.push_back(temp);
        }

        // If name provided, and name associated with known item, infer ID
        Groceryinv(const string& name, int qty, double price)
        {
            // Copying Contents struct as temp to maintain constraints of struct
            // with temporary container
            Contents temp;
            for (int i = 0; i < ID_SIZE; ++i) {temp.id[i] = 0;}

            temp.id[0] = -1; // default unknown

            for (int i = 0; i < 5; ++i)
            {
                // If name is in known, update corresponding ID field to inherit
                // known value.
                if (name == KNOWN_NAMES[i])
                {
                    // Fix temp.id to index 0 since it's just meant to hold our
                    // four digit integer ID, but we want it to be assigned the
                    // value of the matching known ID to the known name.
                    temp.id[0] = KNOWN_IDS[i];
                    break;
                }
            }

            // Assign parameter values to corresponding structure elements. ID
            // has already been assigned.
            temp.item_name = name;
            temp.quant = qty;
            temp.price = price;

            // Add the complete line item to the inventory_items vector.
            inventory_items.push_back(temp);
        }
        
        // Finds a matching inventory record by Item ID and returns a pointer.
            // Returns nullptr if not found.
        Contents* findById(int target)
        {
            for (auto& row : inventory_items)
            {
                if (row.id[0] == target) {return &row;}
            }
            return nullptr;
        }

        // Same as findById but only for checking values, not editing them.
        const Contents* findById(int target) const
        {
            for (const auto& row : inventory_items)
            {
                if (row.id[0] == target) {return &row;}
            }
            return nullptr;
        }

        // Reduces the quantity of an item if enough stock is available.
        // Returns false if not enough stock or item not found.
        bool reserve(int targetId, int qty)
        {
            for (int i = 0; i < inventory_items.size(); ++i)
            {
                if (inventory_items[i].id[0] == targetId)
                {
                    if (inventory_items[i].quant >= qty)
                    {
                        inventory_items[i].quant -= qty;
                        return true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return false;
        }

        // Calculates subtotal, tax, and grand total for all items in inventory.
        // Returns the grand total so other functions may reuse the value.
        double calculateTotals()
        {
            double subtotal = 0.0;
            double tax_rate = 0.08875; // NYC tax rate
            double tax = 0.0;
            double grand_total = 0.0;

            // Loop through each inventory item and sum each item's subtotal.
            for (const auto& item : inventory_items)
            {
                subtotal += (item.price * item.quant);
            }

            // Calculate tax and grand total.
            tax = subtotal * tax_rate;
            grand_total = subtotal + tax;

            // Display calculations to confirm accuracy.
            cout << fixed << setprecision(2); // Format to two decimal places
            cout << "\nInventory Cost Summary: \n\n";
            cout << "Subtotal:    $" << subtotal << endl;
            cout << "Tax (8.875%): $" << tax << endl;
            cout << "Grand Total: $" << grand_total << endl;

            return grand_total;
        }

        // Writes inventory data and calculated totals to an output file.
        void writeToOutfile(const string& filename)
        {
            ofstream outfile(filename);

            if (!outfile)
            {
                cout << "Error, unable to write into file.\n";
                return;
            }

            // Write header line for clarity.
            outfile << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            outfile << "\\\\\\\\\\\\\\\\\\ INVENTORY ITEMS ///////////////\n";
            outfile << "Item ID    Item Name      Quantity     Price\n";
            outfile << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

            // Write each item line-by-line using setw to format the spacing.
            // Using a range loop (I never use these!). The reference operator
            // allows item to modify inventory_items, otherwise you are just
            // making copies (took me a while to find this bug). Auto interprets
            // the data type that item needs to be for operation.
            for (const auto& item : inventory_items)
            {
                outfile << left  << setw(8)  << item.id[0]
                        << left  << setw(14) << item.item_name
                        << right << setw(10) << item.quant
                        << right << setw(10) << fixed << setprecision(2) << item.price
                        << "\n";
            }

            // Calculate totals for the file report.
            double subtotal = 0.0;
            for (const auto& item : inventory_items)
            {
                subtotal += (item.price * item.quant);
            }

            double tax_rate = 0.08875;
            double tax = subtotal * tax_rate;
            double grand_total = subtotal + tax;

            outfile << "\nSubtotal: $" << subtotal;
            outfile << "\nTax (8.875%): $" << tax;
            outfile << "\nGrand Total: $" << grand_total;
            outfile << "\n--------------------------------------------------\n";

            outfile.close();
            cout << "Success! Data written to " << filename << ".\n";
        }

        // Writes a simple inventory list to an output file (no totals).
        void writeInventoryList(const string& filename)
        {
            ofstream outfile(filename);

            if (!outfile)
            {
                cout << "Error, unable to write into file.\n";
                return;
            }

            // Write header line for clarity.
            outfile << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            outfile << "\\\\\\\\\\\\\\\\\\ CURRENT INVENTORY /////////////////////\n";
            outfile << "Item ID    Item Name      Quantity     Price\n";
            outfile << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

            // Write each item line-by-line using setw to format the spacing.
            for (const auto& item : inventory_items)
            {
                outfile << left  << setw(8)  << item.id[0]
                        << left  << setw(14) << item.item_name
                        << right << setw(10) << item.quant
                        << right << setw(10) << fixed << setprecision(2) << item.price
                        << "\n";
            }

            outfile << "--------------------------------------------------\n";
            outfile.close();
            cout << "Success! Inventory list written to " << filename << ".\n";
        }

        // Prints the same inventory report and totals directly to the screen.
        void printToScreen()
        {
            // Write header lines to distinguish the printed report visually.
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            cout << "\\\\\\\\\\\\\\\\\\ INVENTORY ITEMS (SCREEN) ///////////////\n";
            cout << "Item ID    Item Name      Quantity     Price\n";
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

            // Write each item line-by-line using setw to format the spacing.
            // Using a range-based loop with const reference so the loop can read
            // inventory_items directly without creating copies (saves memory).
            // Auto determines the data type for each element in the container.
            for (const auto& item : inventory_items)
            {
                cout << left  << setw(8)  << item.id[0]
                     << left  << setw(14) << item.item_name
                     << right << setw(10) << item.quant
                     << right << setw(10) << fixed << setprecision(2) << item.price
                     << "\n";
            }

            // Calculate subtotal, tax, and grand total.
            double subtotal = 0.0;
            for (const auto& item : inventory_items)
            {
                subtotal += (item.price * item.quant);
            }

            double tax_rate = 0.08875;
            double tax = subtotal * tax_rate;
            double grand_total = subtotal + tax;

            // Display calculated totals below the itemized section.
            cout << "\nSubtotal:    $" << fixed << setprecision(2) << subtotal;
            cout << "\nTax (8.875%): $" << fixed << setprecision(2) << tax;
            cout << "\nGrand Total:  $" << fixed << setprecision(2) << grand_total;
            cout << "\n--------------------------------------------------\n";
        }
};
#endif