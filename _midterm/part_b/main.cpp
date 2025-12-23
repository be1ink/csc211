// Benjamin Link
//
// Notes:
//  * Uses header files grocery_inv.h and customer_order.h
//  * Menu mirrors my Chapter 6 pattern skeleton

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <limits>      // For numeric_limits in input validation
#include "grocery_inv.h"
#include "customer_order.h"
using namespace std;

// ============================================================
// MAIN MENU (pattern skeleton adapted for this program)
// ============================================================

// -- Simple integer validator (line must contain exactly one non-negative int)
int getNum()
{
    int num = 0;

    while (true)
    {
        if (cin >> num && cin.peek() == '\n' && num >= 0)
        {
            return num;
        }
        cout << "Invalid input. Try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// -- Same as getNum but forces a range [low, high]
int getIntInRange(int low, int high)
{
    int v;
    while (true)
    {
        v = getNum();
        if (v >= low && v <= high) return v;
        cout << "Please enter a value between " << low << " and " << high << ": ";
    }
}

void showMenu()
{
    cout << "\n\t\tGrocery — Inventory & Orders\n\n"
         << "[1] View Inventory\n"
         << "[2] Add New Order\n"
         << "[3] View Order Receipt (also writes file)\n"
         << "[4] Exit\n\n"
         << "Enter your choice: ";
}

// Displays inventory to screen and writes a simple list file (no finances)
void viewInventory(Groceryinv &inv)
{
    inv.printToScreen(); // Screen view can show totals; that’s fine.

    string invFile = "inventory_list.txt";
    inv.writeInventoryList(invFile); // New plain inventory file
    cout << "(Inventory list also written to " << invFile << ")\n";
}

// Helper to add/load an order, then validate and apply to inventory
void addNewOrder(CustomerOrder &order, Groceryinv &inv)
{
    cout << "\nNew order: choose input method.\n"
         << "[1] Load from file (ItemID Name Qty)\n"
         << "[2] Enter one line manually by ID and Qty\n"
         << "Enter: ";

    int sub = getIntInRange(1, 2);

    if (sub == 1)
    {
        string ofile;
        cout << "Enter order filename (ID Name Qty): ";
        cin >> ofile;

        ifstream fin(ofile);
        if (!fin)
        {
            cout << "Error, cannot open " << ofile << " for reading.\n";
            return;
        }

        order.clearOrder();
        order.loadFromFile(fin);
    }
    else // sub == 2
    {
        cout << "Enter ItemID (four digits): ";
        int id = getNum();

        cout << "Enter Qty (non-negative): ";
        int qty = getNum();

        order.clearOrder();
        order.addLine(id, qty);
    }

    // Validate against inventory and then update inventory
    order.checkInventory(inv);
    order.updateInventory(inv);

    cout << "Order processed against inventory.\n";
}

// Shows the order receipt to screen and writes to a file
void viewOrderReceipt(CustomerOrder &order)
{
    // Print to screen
    order.printReceipt();

    // Write to file
    string rfile = "receipt_output.txt";
    order.writeReceiptToFile(rfile);
    cout << "(Receipt also written to " << rfile << ")\n";
}

// Runs the simplified menu loop
void runProgramMenu()
{
    // Choice constants
    const int VIEW_INV      = 1;
    const int ADD_ORDER     = 2;
    const int VIEW_RECEIPT  = 3;
    const int QUIT          = 4;

    // Start with default stock via default constructor as required
    Groceryinv *inv = new Groceryinv();

    // Empty order object — will be filled when user creates/loads
    CustomerOrder currentOrder;

    int choice;

    do
    {
        showMenu();
        choice = getIntInRange(VIEW_INV, QUIT);

        if (choice == VIEW_INV)
        {
            viewInventory(*inv);
        }
        else if (choice == ADD_ORDER)
        {
            addNewOrder(currentOrder, *inv);
        }
        else if (choice == VIEW_RECEIPT)
        {
            viewOrderReceipt(currentOrder);
        }

    } while (choice != QUIT);

    cout << "\nThank you for using this program!\n";

    // Deallocate memory
    delete inv;
}

int main()
{
    runProgramMenu();
    return 0;
}