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
#include <algorithm>     // sort, min/max_element, distance
#include <cctype>        // toupper, tolower
#include <cstdlib>       // rand, srand
#include <ctime>         // time
#include <memory>        // unique_ptr
#include <map>

using namespace std;

// ============================================================
// QUICK I/O + VALIDATION (common helpers)
// ============================================================

// - validate integer input (short n' sweet) v1
int get_num()
{
    int num = 0;
    cin >> num;

    while(num < 0 || !cin >> num || cin.peek() != '\n')
    {
        std::cout << "\nInvalid input. Please enter number of jars: ";
    }

    return num;
}

// - valid integer v2
int get_num()
{
    int num = 0;
    cin >> num;

    while(true)
    {
        if (cin >> num && cin.peek() == '\n' && num >= 0)
            break;

        cout << "Invalid input. Try again: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

// -- integer input with prompt and validation v3
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

// -- double input with prompt and validation
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

// -- set fixed + precision for floating output
void useFixed(int places = 2)
{
    cout << fixed << setprecision(places);
}

// -- bounded integer input
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

// -- example menu printer
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

// -- fill vector<int> via prompt
void fillVectorInts(vector<int> &v, int n)
{
    v.clear();
    v.reserve(n);
    for (int i = 0; i < n; ++i)
    {
        v.push_back(readInt("value[" + to_string(i) + "]: "));
    }
}

// -- print vector<int>
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

// -- sum / avg / min idx / max idx / indicesEqualTo
int sumVector(const vector<int> &v)
{
    int total = 0;
    for (int x : v) total += x;
    return total;
}

double avgVector(const vector<int> &v)
{
    if (v.empty())
    {
        return 0.0;
    }
    return static_cast<double>(sumVector(v)) / v.size();
}

int indexOfMax(const vector<int> &v)
{
    if (v.empty())
    {
        return -1;
    }
    return static_cast<int>(distance(v.begin(), max_element(v.begin(), v.end())));
}

int indexOfMin(const vector<int> &v)
{
    if (v.empty())
    {
        return -1;
    }
    return static_cast<int>(distance(v.begin(), min_element(v.begin(), v.end())));
}

vector<int> indicesEqualTo(const vector<int> &v, int value)
{
    vector<int> idx;
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
    {
        if (v[i] == value)
        {
            idx.push_back(i);
        }
    }
    return idx;
}

// ============================================================
// CHAPTER 9 – POINTERS (classic patterns)
// ============================================================

// -- raw dynamic arrays
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
        if (a[i] > maxv) { maxv = a[i]; }
        if (a[i] < minv) { minv = a[i]; }
    }
}

void swapInts(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// -- modern owning array
unique_ptr<int[]> makeIntArrayUPtr(int n)
{
    return unique_ptr<int[]>(n > 0 ? new int[n]{} : nullptr);
}

// ============================================================
// CHAPTER 12 – FILE I/O (text + binary)
// ============================================================

// ------------------------------
// TEXT I/O
// ------------------------------

// -- print all lines (getline)
bool printAllLines(const string &fileName)
{
    ifstream in(fileName);
    if (!in)
    {
        return false;
    }

    string line;
    while (getline(in, line))
    {
        cout << line << '\n';
    }
    return true;
}

// -- print tokens using custom delimiter
bool printTokensWithDelimiter(const string &fileName, char delimiter)
{
    ifstream in(fileName);
    if (!in)
    {
        return false;
    }

    string item;
    while (getline(in, item, delimiter))
    {
        cout << item << '\n';
    }
    return true;
}

// -- uppercase filter (get/put)
bool uppercaseFilter(const string &inName, const string &outName)
{
    ifstream in(inName);
    ofstream out(outName);
    if (!in || !out)
    {
        return false;
    }

    int ch = in.get();
    while (in.good())
    {
        if (ch != EOF)
        {
            out.put(static_cast<char>(toupper(ch)));
        }
        ch = in.get();
    }
    return true;
}

// -- copy text file (get/put)
bool copyTextFile(const string &inName, const string &outName)
{
    ifstream in(inName);
    ofstream out(outName);
    if (!in || !out)
    {
        return false;
    }

    int ch = in.get();
    while (in.good())
    {
        if (ch != EOF)
        {
            out.put(static_cast<char>(ch));
        }
        ch = in.get();
    }
    return true;
}

// -- file head (first N lines)
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

// -- uppercase / lowercase converters
void convertFileToUpper(const string &inputName, const string &outputName)
{
    ifstream inFile(inputName);
    ofstream outFile(outputName);

    if (!inFile || !outFile)
    {
        cout << "Cannot open one of the files.\n";
        return;
    }

    char ch;
    while (inFile.get(ch))
    {
        outFile.put(static_cast<char>(toupper(ch)));
    }
}

void convertFileToLower(const string &inputName, const string &outputName)
{
    ifstream inFile(inputName);
    ofstream outFile(outputName);

    if (!inFile || !outFile)
    {
        cout << "Cannot open one of the files.\n";
        return;
    }

    char ch;
    while (inFile.get(ch))
    {
        outFile.put(static_cast<char>(tolower(ch)));
    }
}

// ------------------------------
// OPEN MODES / FLAGS
// ------------------------------
bool appendLine(const string &fileName, const string &line)
{
    ofstream out;
    out.open(fileName, ios::app);
    if (!out)
    {
        return false;
    }

    out << line << '\n';
    return true;
}

bool writeNearEnd(const string &fileName, const string &text, streamoff backUpBytes)
{
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::ate);
    if (!file)
    {
        return false;
    }

    file.seekp(-backUpBytes, ios::end);
    if (file.fail())
    {
        return false;
    }

    file << text;
    return true;
}

// ------------------------------
// STATUS BITS
// ------------------------------
void demoStatusBitsAndClear(const string &fileName)
{
    ifstream in(fileName);
    if (!in)
    {
        cout << "Open failed\n";
        return;
    }

    string s;
    while (getline(in, s)) { }

    if (in.eof())  { cout << "EOF reached\n"; }
    if (in.fail()) { cout << "failbit set\n"; }
    if (in.bad())  { cout << "badbit set\n"; }

    in.clear();
    in.seekg(0, ios::beg);
    if (in.good()) { cout << "Stream good after clear+seek\n"; }
}

// ------------------------------
// RANDOM ACCESS
// ------------------------------
streamoff fileSize(const string &fileName)
{
    ifstream in(fileName, ios::binary);
    if (!in)
    {
        return -1;
    }

    in.seekg(0, ios::end);
    streamoff sz = in.tellg();
    in.seekg(0, ios::beg);
    return sz;
}

bool patchByte(const string &fileName, streamoff pos, char byte)
{
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::binary);
    if (!file)
    {
        return false;
    }

    file.seekp(pos, ios::beg);
    if (file.fail())
    {
        return false;
    }

    file.put(byte);
    return file.good();
}

// -- print last line (seek backward from end)
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
        if (ch == '\n')
        {
            break;
        }
        in.seekg(-2, ios::cur);
    }

    getline(in, line);
    cout << line << '\n';
}

// ------------------------------
// BINARY I/O (PODs)
// ------------------------------
struct PodPerson
{
    char name[51];
    int  age;
    char phone[14];
};

bool writeCharsBinary(const string &fileName, const char *data, int count, bool append)
{
    ofstream out;
    if (append)
    {
        out.open(fileName, ios::binary | ios::app);
    }
    else
    {
        out.open(fileName, ios::binary | ios::trunc);
    }
    if (!out)
    {
        return false;
    }

    out.write(reinterpret_cast<const char*>(data), static_cast<streamsize>(count));
    return out.good();
}

int readCharsBinary(const string &fileName, char *buffer, int maxCount)
{
    ifstream in(fileName, ios::binary);
    if (!in)
    {
        return 0;
    }

    in.read(reinterpret_cast<char*>(buffer), static_cast<streamsize>(maxCount));
    return static_cast<int>(in.gcount());
}

bool writeIntRaw(const string &fileName, int value)
{
    ofstream out(fileName, ios::binary | ios::trunc);
    if (!out)
    {
        return false;
    }

    out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    return out.good();
}

bool readIntRaw(const string &fileName, int &outValue)
{
    ifstream in(fileName, ios::binary);
    if (!in)
    {
        return false;
    }

    in.read(reinterpret_cast<char*>(&outValue), sizeof(outValue));
    return in.good();
}

// -- inventory records (binary)
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

// -- open + show (word-wise) example
bool openFileIn(fstream &file, const string &fileName)
{
    file.open(fileName, ios::in);
    return !file.fail();
}

void showFileContents(fstream &file)
{
    string word;
    while (file >> word)
    {
        cout << word << '\n';
    }
}

// ------------------------------
// simple encryption filters
// ------------------------------
void encryptFile(const string &inputName, const string &outputName, int shift = 10)
{
    ifstream in(inputName, ios::in | ios::binary);
    ofstream out(outputName, ios::out | ios::binary);

    if (!in || !out)
    {
        cout << "Error opening files.\n";
        return;
    }

    char ch;
    while (in.get(ch))
    {
        unsigned char b = static_cast<unsigned char>(ch);
        b = static_cast<unsigned char>(b + shift);
        out.put(static_cast<char>(b));
    }
}

void decryptFile(const string &inputName, const string &outputName, int shift = 10)
{
    ifstream in(inputName, ios::in | ios::binary);
    ofstream out(outputName, ios::out | ios::binary);

    if (!in || !out)
    {
        cout << "Error opening files.\n";
        return;
    }

    char ch;
    while (in.get(ch))
    {
        unsigned char b = static_cast<unsigned char>(ch);
        b = static_cast<unsigned char>(b - shift);
        out.put(static_cast<char>(b));
    }
}

// ============================================================
// CHAPTER 13 – CLASSES (skeletons/patterns)
// ============================================================

// ------------------------------
// Rectangle example
// ------------------------------
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

// ------------------------------
// Contact example (delegating ctor)
// ------------------------------
class Contact
{
private:
    string name, email, phone;

public:
    Contact() : Contact("", "", "") {}
    Contact(string n, string e, string p) : name(n), email(e), phone(p) {}
};

// ------------------------------
// sort rectangles by area
// ------------------------------
void sortByArea(vector<Rectangle> &rs)
{
    sort(rs.begin(), rs.end(),
         [](const Rectangle &a, const Rectangle &b) { return a.area() < b.area(); });
}

// ============================================================
// GENERAL UTILITIES
// ============================================================

// ------------------------------
// RNG helpers (rand/srand)
// ------------------------------
void seedRngWithTime()
{
    unsigned seed = static_cast<unsigned>(time(0));
    srand(seed);
}

int rollDieInclusive(int minVal, int maxVal)
{
    // assumes srand() has been called once in program startup
    int span = (maxVal - minVal + 1);
    return (rand() % span) + minVal;
}

// ------------------------------
// 2D array printer (fixed COLS)
// ------------------------------
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

// find minimum values
vector<int> findMinValues(const vector<int> &v)
{
    vector<int> mins;
    if (v.empty())
    {
        return mins;
    }
    int minVal = *min_element(v.begin(), v.end());
    for (int x : v)
    {
        if (x == minVal) { mins.push_back(x); }
    }
    return mins;
}

// find maximum values
vector<int> findMaxValues(const vector<int> &v)
{
    vector<int> maxs;
    if (v.empty())
    {
        return maxs;
    }
    int maxVal = *max_element(v.begin(), v.end());
    for (int x : v)
    {
        if (x == maxVal) { maxs.push_back(x); }
    }
    return maxs;
}

// indices where value equals target
vector<int> findIndicesOf(const vector<int> &v, int value)
{
    vector<int> idx;
    for (int i = 0; i < static_cast<int>(v.size()); ++i)
    {
        if (v[i] == value)
        {
            idx.push_back(i);
        }
    }
    return idx;
}

// average (mean)
double findAverage(const vector<int> &v)
{
    if (v.empty())
    {
        return 0.0;
    }
    int total = 0;
    for (int x : v)
    {
        total += x;
    }
    return static_cast<double>(total) / v.size();
}

// median (makes copy to sort)
double findMedian(vector<int> v)
{
    if (v.empty())
    {
        return 0.0;
    }
    sort(v.begin(), v.end());
    int n = static_cast<int>(v.size());
    if (n % 2 == 1)
    {
        return v[n / 2];
    }
    else
    {
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;
    }
}

// mode (map-based)
vector<int> findModes(const vector<int> &v)
{
    vector<int> modes;
    if (v.empty())
    {
        return modes;
    }

    map<int, int> freq;
    for (int x : v)
    {
        freq[x]++;
    }

    int maxFreq = 0;
    for (auto &p : freq)
    {
        if (p.second > maxFreq) { maxFreq = p.second; }
    }

    if (maxFreq == 1)
    {
        return modes; // no mode
    }

    for (auto &p : freq)
    {
        if (p.second == maxFreq)
        {
            modes.push_back(p.first);
        }
    }

    return modes;
}

// mode (array-based, in-place sort)
vector<int> findModes(int *arr, int length)
{
    vector<int> mode;
    if (length <= 0)
    {
        return mode;
    }

    sort(arr, arr + length);

    int value = arr[0];
    int freq = 1;
    int maxFreq = 1;

    for (int i = 1; i < length; i++)
    {
        if (arr[i] == value)
        {
            freq++;
        }
        else
        {
            if (freq > maxFreq)
            {
                maxFreq = freq;
                mode.clear();
                mode.push_back(value);
            }
            else if (freq == maxFreq)
            {
                mode.push_back(value);
            }

            value = arr[i];
            freq = 1;
        }
    }

    if (freq > maxFreq)
    {
        maxFreq = freq;
        mode.clear();
        mode.push_back(value);
    }
    else if (freq == maxFreq)
    {
        mode.push_back(value);
    }

    if (maxFreq == 1)
    {
        mode.clear();
    }

    return mode;
}

// ------------------------------
// sorting + reverse
// ------------------------------
void sortAscending(vector<int> &v)
{
    sort(v.begin(), v.end());
}

void sortDescending(vector<int> &v)
{
    sort(v.begin(), v.end(), greater<int>());
}

int* reverseArray(int *array, int size)
{
    int *reversed = new int[size];
    for (int i = 0; i < size; i++)
    {
        reversed[i] = array[size - 1 - i];
    }
    return reversed;
}

#endif // TEMPLATE_CODE_H