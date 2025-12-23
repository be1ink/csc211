#ifndef TEMPLATE_CODE_H
#define TEMPLATE_CODE_H

// ==========================
// includes (used by content)
// ==========================
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>   // sort, min/max_element, distance
#include <cctype>      // toupper, tolower
#include <cstdlib>     // rand, srand
#include <ctime>       // time
#include <limits>      // numeric_limits
#include <map>         // map (mode)

using namespace std;

// ============================================================
// QUICK I/O + VALIDATION (common helpers)
// ============================================================

int readInt(const string &prompt = "Enter an integer: ")
{
    int x;
    for (;;)
    {
        cout << prompt;
        if (cin >> x)
        {
            return x;
        }
        cout << "Invalid. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double readDouble(const string &prompt = "Enter a number: ")
{
    double x;
    for (;;)
    {
        cout << prompt;
        if (cin >> x)
        {
            return x;
        }
        cout << "Invalid. Try again.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void useFixed(int places = 2)
{
    cout << fixed << setprecision(places);
}

int readIntInRange(int minVal, int maxVal, const string &prompt = "Enter a number: ")
{
    int num;
    for (;;)
    {
        cout << prompt;
        if (!(cin >> num))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
        }
        else if (num < minVal || num > maxVal)
        {
            cout << "Number must be between " << minVal << " and " << maxVal << ".\n";
        }
        else
        {
            return num;
        }
    }
}

// ============================================================
// CHAPTER 6 – MENU (pattern skeleton)
// ============================================================

void displayMenu()
{
    cout << "\n MENU\n";
    cout << "-----------------------------------------\n";
    cout << "A) Display the account balance\n";
    cout << "B) Display the number of transactions\n";
    cout << "C) Display interest earned for this period\n";
    cout << "D) Make a deposit\n";
    cout << "E) Make a withdrawal\n";
    cout << "F) Add interest for this period\n";
    cout << "G) Exit the program\n\n";
    cout << "Enter your choice: ";
}

// ============================================================
// CHAPTER 7 – ARRAYS / VECTORS (ints)
// ============================================================

void fillVectorInts(vector<int> &v, int n)
{
    v.clear();
    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        v.push_back(readInt("value[" + to_string(i) + "]: "));
    }
}

void printVector(const vector<int> &v, const string &label = "")
{
    if (!label.empty())
    {
        cout << label << ": ";
    }
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << '\n';
}

int sumVector(const vector<int> &v)
{
    int total = 0;
    for (int x : v) total += x;
    return total;
}

double avgVector(const vector<int> &v)
{
    if (v.empty()) return 0.0;
    return static_cast<double>(sumVector(v)) / v.size();
}

int indexOfMax(const vector<int> &v)
{
    if (v.empty()) return -1;
    return static_cast<int>(distance(v.begin(), max_element(v.begin(), v.end())));
}

int indexOfMin(const vector<int> &v)
{
    if (v.empty()) return -1;
    return static_cast<int>(distance(v.begin(), min_element(v.begin(), v.end())));
}

// ============================================================
// CHAPTER 9 – POINTERS (classic patterns)
// ============================================================

int* makeIntArray(int n)
{
    return (n > 0) ? new int[n]{} : nullptr;
}

void freeIntArray(int *p)
{
    delete[] p;
}

void fillArray(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = readInt("a[" + to_string(i) + "]: ");
    }
}

void maxMinArray(const int *a, int n, int &maxv, int &minv)
{
    if (n <= 0)
    {
        maxv = 0;
        minv = 0;
        return;
    }
    maxv = a[0];
    minv = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > maxv) maxv = a[i];
        if (a[i] < minv) minv = a[i];
    }
}

// ============================================================
// CHAPTER 12 – FILE I/O (text + binary)
// ============================================================
//
// ------------------------------
// TEXT I/O
// ------------------------------

bool printAllLines(const string &fileName)
{
    ifstream in(fileName);
    if (!in) return false;

    string line;
    while (getline(in, line))
    {
        cout << line << '\n';
    }
    return true;
}

void printFileHead(const string &fileName, int maxLines = 10)
{
    ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "Cannot open " << fileName << '\n';
        return;
    }

    string line;
    int count = 0;
    while (getline(inFile, line) && count < maxLines)
    {
        cout << line << '\n';
        count++;
    }

    if (count < maxLines)
    {
        cout << "\nFile has fewer than " << maxLines
             << " lines — all lines displayed.\n";
    }
}

bool uppercaseFilter(const string &inName, const string &outName)
{
    ifstream in(inName);
    ofstream out(outName);
    if (!in || !out) return false;

    int ch = in.get();
    while (in.good())
    {
        if (ch != EOF) out.put(static_cast<char>(toupper(ch)));
        ch = in.get();
    }
    return true;
}

bool appendLine(const string &fileName, const string &line)
{
    ofstream out;
    out.open(fileName, ios::app);
    if (!out) return false;

    out << line << '\n';
    return true;
}

// random access: print only the last line of a text file
void printLastLine(ifstream &in)
{
    if (!in)
    {
        cout << "Invalid file stream.\n";
        return;
    }

    char ch;
    string line;

    in.seekg(-1, ios::end);
    while (in.tellg() > 0)
    {
        in.get(ch);
        if (ch == '\n') break;
        in.seekg(-2, ios::cur);
    }

    getline(in, line);
    cout << line << '\n';
}

// status bits demo (+ clear + seek reset)
void demoStatusBitsAndClear(const string &fileName)
{
    ifstream in(fileName);
    if (!in)
    {
        cout << "Open failed\n";
        return;
    }

    string s;
    while (getline(in, s)) { /* read to EOF */ }

    if (in.eof())  cout << "EOF reached\n";
    if (in.fail()) cout << "failbit set\n";
    if (in.bad())  cout << "badbit set\n";

    in.clear();
    in.seekg(0, ios::beg);
    if (in.good()) cout << "Stream good after clear+seek\n";
}

// ------------------------------
// BINARY I/O (PODs)
// ------------------------------

bool writeIntRaw(const string &fileName, int value)
{
    ofstream out(fileName, ios::binary | ios::trunc);
    if (!out) return false;

    out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    return out.good();
}

bool readIntRaw(const string &fileName, int &outValue)
{
    ifstream in(fileName, ios::binary);
    if (!in) return false;

    in.read(reinterpret_cast<char*>(&outValue), sizeof(outValue));
    return in.good();
}

struct InventoryItem
{
    char desc[31];
    int qty;
    double price;
};

void createBlankInventoryFile(const string &fileName, int numRecords = 5)
{
    InventoryItem record = { "", 0, 0.0 };

    fstream inventory(fileName, ios::out | ios::binary);
    if (!inventory)
    {
        cout << "Error opening " << fileName << " for writing.\n";
        return;
    }

    for (int count = 0; count < numRecords; count++)
    {
        inventory.write(reinterpret_cast<char*>(&record), sizeof(record));
    }
}

void readInventoryRecords(const string &fileName)
{
    fstream inventory(fileName, ios::in | ios::binary);
    if (!inventory)
    {
        cout << "Cannot open " << fileName << '\n';
        return;
    }

    InventoryItem record;
    while (inventory.read(reinterpret_cast<char*>(&record), sizeof(record)))
    {
        cout << "Description: " << record.desc << '\n';
        cout << "Quantity: " << record.qty << '\n';
        cout << "Price: " << record.price << "\n\n";
    }
}

// ============================================================
// CHAPTER 13 – CLASSES (skeletons/patterns)
// ============================================================

class Rectangle
{
private:
    double length, width;

public:
    Rectangle() : length(0.0), width(0.0) {}
    Rectangle(double l, double w) : length(l), width(w) {}

    void setLength(double l) { length = l; }
    void setWidth(double w)  { width = w; }
    double getLength() const { return length; }
    double getWidth() const  { return width; }
    double area() const      { return length * width; }
};

void sortByArea(vector<Rectangle> &rs)
{
    sort(rs.begin(), rs.end(),
         [](const Rectangle &a, const Rectangle &b) { return a.area() < b.area(); });
}

// ============================================================
// GENERAL UTILITIES
// ============================================================

void seedRngWithTime()
{
    unsigned seed = static_cast<unsigned>(time(0));
    srand(seed);
}

int rollDieInclusive(int minVal, int maxVal)
{
    int span = (maxVal - minVal + 1);
    return (rand() % span) + minVal; // assumes srand() was called once
}

const int COLS = 3;
void print2DArray(int arr[][COLS], int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < COLS; ++j)
        {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
}

// ------------------------------
// summary statistics (vectors)
// ------------------------------

double findMedian(vector<int> v)
{
    if (v.empty()) return 0.0;
    sort(v.begin(), v.end());
    int n = static_cast<int>(v.size());
    if (n % 2 == 1) return v[n / 2];
    return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

vector<int> findModes(const vector<int> &v)
{
    vector<int> modes;
    if (v.empty()) return modes;

    map<int, int> freq;
    for (int x : v) freq[x]++;

    int maxFreq = 0;
    for (auto &p : freq)
    {
        if (p.second > maxFreq) maxFreq = p.second;
    }

    if (maxFreq == 1) return modes; // no mode

    for (auto &p : freq)
    {
        if (p.second == maxFreq) modes.push_back(p.first);
    }
    return modes;
}

// ------------------------------
// sorting helpers
// ------------------------------

void sortAscending(vector<int> &v)
{
    sort(v.begin(), v.end());
}

void sortDescending(vector<int> &v)
{
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
}

#endif // TEMPLATE_CODE_H