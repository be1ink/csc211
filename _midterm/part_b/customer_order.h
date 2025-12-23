// Benjamin Link

#ifndef CUSTOMER_ORDER_H
#define CUSTOMER_ORDER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "grocery_inv.h"
#include <algorithm>
using namespace std;

class CustomerOrder
{
    private:
        // Compile-time ready constant that every class instance can use
        // Other option is to make this constant global. Need this to formalize
        // item IDs as always four concatenated integers.
        static const int ID_SIZE = 4;

        // Structure that contains standard contents of an order line.
        // I decided to use a structure since a line item is incomplete without
        // all the data input or initialized in concert.
        struct Line
        {
            int id[ID_SIZE] = {0};
            string name = "";
            int qty = 0;
            double price_each = 0.0;
            double line_total = 0.0;
            bool accepted = false;
            string reason = "";
        };

        // Declare a vector to store Line elements - will support dynamic
        // increases in size since we can't anticipate how many order items
        // will be input by each file or user.
        vector<Line> lines;

        // Known ID and fruit pairings. Uses parallel arrays to match the items
        // by their index. This is a hardcoded method, my preference would be to 
        // implement a dynamic solution that updates these lists with user input,
        // but ran out of time. 
        const int KNOWN_IDS[5]  = {1011, 1012, 1013, 1014, 1015};
        const string KNOWN_NAMES[5] = {"Avocado", "Tomato", "Orange", "Mango", 
                "Grape"};

        const double TAX_RATE = 0.08875;

    public:

        // Default constructor
        CustomerOrder() {}

        // Builds an order from a file with ItemID, Name, and Qty. The price will
        // later be assigned when cross-checking the inventory.
        CustomerOrder(ifstream& input_file)
        {
            // Declare line string to hold getline contents
            string line;

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
                string name;
                int qty;

                input_file >> id >> name >> qty;
                if (input_file.fail())
                    break;
                input_file.clear();

                Line temp;
                for (int i = 0; i < ID_SIZE; i++) { temp.id[i] = 0; }
                temp.id[0] = id;
                temp.name = name;
                temp.qty = qty;

                // Add the complete line item to the lines vector.
                lines.push_back(temp);
            }
        }

        // Clears the current order lines so we can reuse the same object.
        void clearOrder()
        {
            lines.clear();
        }

        // Loads an order from a file with ItemID, Name, Qty.
        // This mirrors the file-based constructor but works on the existing object.
        void loadFromFile(ifstream& input_file)
        {
            // Declare line string to hold getline contents
            string line;

            // Ensure input_file ifstream object linked properly, no errors.
            if (!input_file)
            {
                cout << "Invalid file stream.\n";
                return;
            }

            // Start fresh
            lines.clear();

            // Skip first line, which contains field names
            getline(input_file, line);

            // While the eof bit isn't tripped, grab all the lines in the file.
            while (!input_file.eof())
            {
                int id;
                string name;
                int qty;

                input_file >> id >> name >> qty;
                if (input_file.fail())
                    break;
                input_file.clear();

                Line temp;
                for (int i = 0; i < ID_SIZE; i++) { temp.id[i] = 0; }
                temp.id[0] = id;
                temp.name = name;
                temp.qty = qty;

                // Add the complete line item to the lines vector.
                lines.push_back(temp);
            }
        }

        // If ID provided, and ID associated with known item, infer name
        CustomerOrder(int id, int qty)
        {
            // Copying Line struct as temp to maintain constraints of struct
            // with temporary container
            Line temp;
            for (int i = 0; i < ID_SIZE; ++i) { temp.id[i] = 0; }

            // Assign provided ID to the first position of the ID array.
            temp.id[0] = id;

            // Default item name in case ID is not recognized in known list.
            temp.name = "Unknown";

            // Loop through known IDs; if a match is found, update name to match
            // the known name tied to that ID.
            for (int i = 0; i < 5; ++i)
            {
                if (id == KNOWN_IDS[i])
                {
                    // When a known ID is matched, assign its paired name to
                    // the temporary structure’s name field.
                    temp.name = KNOWN_NAMES[i];
                    break;
                }
            }

            // Assign parameter values to corresponding structure elements. Name
            // has already been assigned.
            temp.qty = qty;

            // Add the complete line item to the lines vector.
            lines.push_back(temp);
        }

        // If name provided, and name associated with known item, infer ID
        CustomerOrder(const string& name, int qty)
        {
            // Copying Line struct as temp to maintain constraints of struct
            // with temporary container
            Line temp;
            for (int i = 0; i < ID_SIZE; ++i) { temp.id[i] = 0; }

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
            temp.name = name;
            temp.qty = qty;

            // Add the complete line item to the lines vector.
            lines.push_back(temp);
        }

        // Checks each order item against the inventory and updates line totals.
        void checkInventory(Groceryinv& inv)
        {
            for (auto& item : lines)
            {
                item.accepted = false;
                item.reason = "";

                if (item.qty <= 0)
                {
                    item.reason = "Invalid quantity";
                    continue;
                }

                // Find a match for the item ID in the inventory
                bool found = false;
                for (int i = 0; i < 5; ++i)
                {
                    if (item.id[0] == KNOWN_IDS[i])
                    {
                        item.name = KNOWN_NAMES[i];
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    item.reason = "Unknown item";
                    continue;
                }

                // Find matching inventory record and validate stock
                const auto* inv_item = inv.findById(item.id[0]);
                if (inv_item == nullptr)
                {
                    item.reason = "Not found in inventory";
                    continue;
                }

                if (inv_item->quant < item.qty)
                {
                    item.reason = "Insufficient stock";
                    continue;
                }

                // Mark as valid and calculate line total
                item.accepted = true;
                item.price_each = inv_item->price;
                item.line_total = item.qty * item.price_each;
            }

            // Sort by Item ID for consistency
            sort(lines.begin(), lines.end(),
                 [](const Line& a, const Line& b) { return a.id[0] < b.id[0]; });
        }

        // Updates inventory after successful order validation
        void updateInventory(Groceryinv& inv)
        {
            for (auto& item : lines)
            {
                if (!item.accepted)
                    continue;
                bool success = inv.reserve(item.id[0], item.qty);
                if (!success)
                {
                    item.accepted = false;
                    item.reason = "Inventory update failed";
                }
            }
        }

        // Calculates subtotal for accepted lines only.
        double subtotal() const
        {
            double s = 0.0;
            for (const auto& item : lines)
            {
                if (item.accepted) {s += item.line_total;}
            }
            return s;
        }

        // Adds a single order line by ItemID and Qty (quick manual entry).
        void addLine(int id, int qty)
        {
            // Copying Line struct as temp to maintain constraints of struct
            // with temporary container
            Line temp;
            for (int i = 0; i < ID_SIZE; ++i) {temp.id[i] = 0;}

            // Assign provided ID to the first position of the ID array.
            temp.id[0] = id;

            // Default item name in case ID is not recognized in known list.
            temp.name = "Unknown";

            // Loop through known IDs; if a match is found, update name to match
            // the known name tied to that ID.
            for (int i = 0; i < 5; ++i)
            {
                if (id == KNOWN_IDS[i])
                {
                    // When a known ID is matched, assign its paired name to
                    // the temporary structure’s name field.
                    temp.name = KNOWN_NAMES[i];
                    break;
                }
            }

            // Assign parameter values to corresponding structure elements. Name
            // has already been assigned.
            temp.qty = qty;

            // Add the complete line item to the lines vector.
            lines.push_back(temp);
        }

        // Adds a single order line by Name and Qty (alternate manual entry).
        void addLine(const string& name, int qty)
        {
            // Copying Line struct as temp to maintain constraints of struct
            // with temporary container
            Line temp;
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
            temp.name = name;
            temp.qty = qty;

            // Add the complete line item to the lines vector.
            lines.push_back(temp);
        }

        // Calculates tax using the class tax rate.
        double tax() const
        {
            return subtotal() * TAX_RATE;
        }

        // Calculates grand total.
        double grandTotal() const
        {
            return subtotal() + tax();
        }

        // Prints receipt to screen (wrapper so main can call printReceipt()).
        void printReceipt()
        {
            printToScreen();
        }

        // Writes receipt to file (wrapper so main can call writeReceiptToFile()).
        void writeReceiptToFile(const string& filename)
        {
            writeToOutfile(filename);
        }

        // Displays the customer receipt and calculated totals on screen.
        void printToScreen()
        {
            cout << fixed << setprecision(2);
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            cout << "\\\\\\\\\\\\\\\\\\ CUSTOMER ORDER (SCREEN) ///////////////\n";
            cout << "Item ID    Item Name      Quantity     Price     Total\n";
            cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

            for (const auto& item : lines)
            {
                if (item.accepted)
                {
                    cout << left  << setw(8)  << item.id[0]
                         << left  << setw(14) << item.name
                         << right << setw(10) << item.qty
                         << right << setw(10) << item.price_each
                         << right << setw(10) << item.line_total
                         << "\n";
                }
            }

            double subtotal = 0.0;
            for (const auto& item : lines)
            {
                if (item.accepted)
                    subtotal += item.line_total;
            }

            double tax = subtotal * TAX_RATE;
            double grand_total = subtotal + tax;

            cout << "\nSubtotal:    $" << subtotal;
            cout << "\nTax (8.875%): $" << tax;
            cout << "\nGrand Total: $" << grand_total;
            cout << "\n--------------------------------------------------\n";
        }

        // Writes the customer order data and totals to an output file.
        void writeToOutfile(const string& filename)
        {
            ofstream outfile(filename);

            if (!outfile)
            {
                cout << "Error, unable to write into file.\n";
                return;
            }

            outfile << fixed << setprecision(2);
            outfile << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
            outfile << "\\\\\\\\\\\\\\\\\\ CUSTOMER ORDER (FILE) /////////////////\n";
            outfile << "Item ID    Item Name      Quantity     Price     Total\n";
            outfile << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

            for (const auto& item : lines)
            {
                if (item.accepted)
                {
                    outfile << left  << setw(8)  << item.id[0]
                            << left  << setw(14) << item.name
                            << right << setw(10) << item.qty
                            << right << setw(10) << item.price_each
                            << right << setw(10) << item.line_total
                            << "\n";
                }
            }

            double subtotal = 0.0;
            for (const auto& item : lines)
            {
                if (item.accepted)
                    subtotal += item.line_total;
            }

            double tax = subtotal * TAX_RATE;
            double grand_total = subtotal + tax;

            outfile << "\nSubtotal: $" << subtotal;
            outfile << "\nTax (8.875%): $" << tax;
            outfile << "\nGrand Total: $" << grand_total;
            outfile << "\n--------------------------------------------------\n";

            outfile.close();
            cout << "Success! Receipt written to " << filename << ".\n";
        }
};
#endif