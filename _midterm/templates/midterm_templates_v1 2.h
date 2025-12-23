#ifndef TEMPLATE_CODE_H
#define TEMPLATE_CODE_H

// Main include packages
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <memory>      // unique_ptr (optional)
#include <string>

// Optional
#include <algorithm>   // sort, min/max_element
#include <cctype>
#include <cstdlib>     // rand, srand
#include <ctime>       // paired with cstdlib to create random num generator
#include <numeric>     // accumulate

using namespace std;

/* =========================
   QUICK I/O + VALIDATION
   ========================= */
int readInt(const string& prompt="Enter an integer: ") {
    int x;
    for (;;) {
        cout << prompt;
        if (cin >> x) return x;
        cout << "Invalid. Try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

double readDouble(const string& prompt="Enter a number: ") {
    double x;
    for (;;) {
        cout << prompt;
        if (cin >> x) return x;
        cout << "Invalid. Try again.\n";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void useFixed(int places=2) { cout << fixed << setprecision(places); }

/* =========================
   CH6: MENU-DRIVEN
   ========================= */
 do
    {
        // Display menu and validate selections
        displayMenu();
        cin >> choice;
        while (toupper(choice) < 'A' || toupper(choice) > 'G')
        {
            cout << "Please make a choice in the range "
                << "of A through G:";
            cin >> choice;
        }

    // Process menu selections
        switch(choice)
        {
        case 'a':
        case 'A': cout << "The current balance is $";
            cout << savings.getBalance() << endl;
            break;
        case 'b':
        case 'B': cout << "There have been ";
                cout << savings.getTransactions()
                    << " transactions.\n";
                break;
        case 'c':
        case 'C': cout << "Interest earned for this period: $";
            cout << savings.getInterest() << endl;
                break;
        case 'd':
        case 'D': makeDeposit(savings);
                break;
        case 'e':
        case 'E': withdraw(savings);
                break;
        case 'f':
        case 'F': savings.calcInterest();
                cout << "Interest added.\n";
        }
    } while (toupper(choice) != 'G');

     return 0;
}

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


/* =========================
   CH7: ARRAYS / VECTORS (ints)
   ========================= */
void fillVectorInts(vector<int>& v, int n) {
    v.clear(); v.reserve(n);
    for (int i = 0; i < n; ++i)
        v.push_back(readInt("value[" + to_string(i) + "]: "));
}

void printVector(const vector<int>& v, const string& label="") {
    if (!label.empty()) cout << label << ": ";
    for (int x : v) cout << x << ' ';
    cout << '\n';
}

int sumVector(const vector<int>& v) { return accumulate(v.begin(), v.end(), 0); }

double avgVector(const vector<int>& v) {
    return v.empty() ? 0.0 : double(sumVector(v)) / v.size();
}

int indexOfMax(const vector<int>& v) {
    if (v.empty()) return -1;
    return int(distance(v.begin(), max_element(v.begin(), v.end())));
}

int indexOfMin(const vector<int>& v) {
    if (v.empty()) return -1;
    return int(distance(v.begin(), min_element(v.begin(), v.end())));
}

vector<int> indicesEqualTo(const vector<int>& v, int value) {
    vector<int> idx;
    for (int i = 0; i < (int)v.size(); ++i)
        if (v[i] == value) idx.push_back(i);
    return idx;
}

/* =========================
   CH9: POINTERS (classic patterns)
   ========================= */
int* makeIntArray(int n) { return (n>0) ? new int[n]{} : nullptr; }
void freeIntArray(int* p) { delete[] p; }

void fillArray(int* a, int n) {
    for (int i=0;i<n;++i)
        a[i] = readInt("a[" + to_string(i) + "]: ");
}

void maxMinArray(const int* a, int n, int& maxv, int& minv) {
    if (n<=0) { maxv=minv=0; return; }
    maxv=minv=a[0];
    for (int i=1;i<n;++i) {
        if (a[i]>maxv) maxv=a[i];
        if (a[i]<minv) minv=a[i];
    }
}

void swapInts(int* a, int* b) {
    int t=*a;
    *a=*b;
    *b=t;
}

// Declare unique pointer dynamically
unique_ptr<int> ptr(new int);
*ptr = 99;


unique_ptr<int[]> makeIntArrayUPtr(int n) 
{
    return unique_ptr<int[]>( n>0 ? new int[n]{} : nullptr );
}

/* =========================
   CH12: FILE I/O (text + simple binary POD)
   ========================= */
/* ========== TEXT I/O ========== */

bool printAllLines(const string &fileName)
{
    ifstream in(fileName);
    if (!in) { return false; }

    string line;
    while (getline(in, line))
    {
        cout << line << '\n';
    }
    return true;
}

bool printTokensWithDelimiter(const string &fileName, char delimiter)
{
    ifstream in(fileName);
    if (!in) { return false; }

    string item;
    while (getline(in, item, delimiter))
    {
        cout << item << '\n';
    }
    return true;
}

bool uppercaseFilter(const string &inName, const string &outName)
{
    ifstream in(inName);
    ofstream out(outName);
    if (!in || !out) { return false; }

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

bool copyTextFile(const string &inName, const string &outName)
{
    ifstream in(inName);
    ofstream out(outName);
    if (!in || !out) { return false; }

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

/* ========== OPEN MODES / FLAGS ========== */

bool appendLine(const string &fileName, const string &line)
{
    ofstream out;
    out.open(fileName, ios::app);
    if (!out) { return false; }

    out << line << '\n';
    return true;
}

bool writeNearEnd(const string &fileName, const string &text, streamoff backUpBytes)
{
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::ate);
    if (!file) { return false; }

    file.seekp(-backUpBytes, ios::end);
    if (file.fail()) { return false; }

    file << text;
    return true;
}

/* ========== STATUS BITS ========== */

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

    if (in.eof())  cout << "EOF reached\n";
    if (in.fail()) cout << "failbit set\n";
    if (in.bad())  cout << "badbit set\n";

    in.clear();
    in.seekg(0, ios::beg);
    if (in.good()) cout << "Stream good after clear+seek\n";
}

/* ========== RANDOM ACCESS ========== */

streamoff fileSize(const string &fileName)
{
    ifstream in(fileName, ios::binary);
    if (!in) { return -1; }

    in.seekg(0, ios::end);
    streamoff sz = in.tellg();
    in.seekg(0, ios::beg);
    return sz;
}

bool patchByte(const string &fileName, streamoff pos, char byte)
{
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::binary);
    if (!file) { return false; }

    file.seekp(pos, ios::beg);
    if (file.fail()) { return false; }

    file.put(byte);
    return file.good();
}

/* ========== BINARY I/O ========== */

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
    if (!out) { return false; }

    out.write(reinterpret_cast<const char*>(data), static_cast<streamsize>(count));
    return out.good();
}

int readCharsBinary(const string &fileName, char *buffer, int maxCount)
{
    ifstream in(fileName, ios::binary);
    if (!in) { return 0; }

    in.read(reinterpret_cast<char*>(buffer), static_cast<streamsize>(maxCount));
    return static_cast<int>(in.gcount());
}

bool writeIntRaw(const string &fileName, int value)
{
    ofstream out(fileName, ios::binary | ios::trunc);
    if (!out) { return false; }

    out.write(reinterpret_cast<const char*>(&value), sizeof(value));
    return out.good();
}

bool readIntRaw(const string &fileName, int &outValue)
{
    ifstream in(fileName, ios::binary);
    if (!in) { return false; }

    in.read(reinterpret_cast<char*>(&outValue), sizeof(outValue));
    return in.good();
}

bool writePeople(const string &fileName, const PodPerson *people, int count, bool append)
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
    if (!out) { return false; }

    for (int i = 0; i < count; i++)
    {
        out.write(reinterpret_cast<const char*>(&people[i]), sizeof(PodPerson));
        if (!out) { return false; }
    }
    return true;
}

int readPeople(const string &fileName, PodPerson *buffer, int maxCount)
{
    ifstream in(fileName, ios::binary);
    if (!in) { return 0; }

    int readCount = 0;
    while (readCount < maxCount &&
           in.read(reinterpret_cast<char*>(&buffer[readCount]), sizeof(PodPerson)))
    {
        readCount++;
    }
    return readCount;
}

/* ========== C-STRING LINES (optional) ========== */

int readLinesToCArray(const string &fileName, char (*lines)[256], int maxLines)
{
    ifstream in(fileName);
    if (!in) { return 0; }

    int n = 0;
    while (n < maxLines && in.getline(lines[n], 256))
    {
        n++;
    }
    return n;
}

void printFileHead(const string &fileName, int maxLines = 10)
{
    ifstream inFile(fileName);
    if (!inFile)
    {
        cout << "Cannot open " << fileName << endl;
        return;
    }

    string line;
    int count = 0;

    while (getline(inFile, line) && count < maxLines)
    {
        cout << line << endl;
        count++;
    }

    inFile.close();

    if (count < maxLines)
    {
        cout << "\nFile has fewer than " << maxLines
             << " lines — all lines displayed.\n";
    }
}

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

    in.close();
    out.close();
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

    in.close();
    out.close();
}

// Converts to upper/lower case
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
        // tolower(ch) if opposite desired
        outFile.put(static_cast<char>(toupper(ch)));
    }

    inFile.close();
    outFile.close();
    cout << "File conversion done.\n";
}

struct InventoryItem
{
    char desc[31];
    int qty;
    double price;
};

// Reads and displays binary file
void readInventoryRecords(const string &fileName)
{
    fstream inventory(fileName, ios::in | ios::binary);

    if (!inventory)
    {
        cout << "Cannot open " << fileName << endl;
        return;
    }

    InventoryItem record;
    while (inventory.read(reinterpret_cast<char*>(&record), sizeof(record)))
    {
        cout << "Description: " << record.desc << endl;
        cout << "Quantity: " << record.qty << endl;
        cout << "Price: " << record.price << "\n\n";
    }

    inventory.close();
}

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
        cout << word << endl;
    }
}

// Struct with binary file output
struct InventoryItem
{
    char desc[31];
    int qty;
    double price;
};

// Creates a binary file pre-filled with blank records
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
        cout << "Writing blank record " << count + 1 << endl;
        inventory.write(reinterpret_cast<char*>(&record), sizeof(record));
    }

    inventory.close();
    cout << "File initialized successfully.\n";
}

// Reads and prints every line of a text file
void printAllLines(ifstream &in)
{
    string line;
    while (getline(in, line))
        cout << line << '\n';
}

// Prints only the final line of a text file
void printLastLine(ifstream &in)
{
    if (!in)
    {
        cout << "Invalid file stream.\n";
        return;
    }

    char ch;
    string line;

    // Jump to last character
    in.seekg(-1, ios::end);

    // Move backward until start or newline found
    while (in.tellg() > 0)
    {
        in.get(ch);
        if (ch == '\n')
            break;
        in.seekg(-2, ios::cur);  // step back twice
    }

    getline(in, line);
    cout << line << '\n';
}

/* =========================
   CH13: CLASSES (skeletons/patterns)
   ========================= */
class Rectangle {
private:
    double length, width;
public:
    Rectangle() : length(0.0), width(0.0) {}
    Rectangle(double l, double w) : length(l), width(w) {}

    void setLength(double l){ length = l; }
    void setWidth(double w){ width = w; }
    double getLength() const { return length; }
    double getWidth() const  { return width; }
    double area() const      { return length * width; }
};

class Contact {
private:
    string name, email, phone;
public:
    Contact() : Contact("", "", "") {}
    Contact(string n, string e, string p) : name(n), email(e), phone(p) {}
};

void sortByArea(vector<Rectangle>& rs) {
    sort(rs.begin(), rs.end(),
         [](const Rectangle& a, const Rectangle& b){ return a.area() < b.area(); });
}

/* =========================
   GENERAL - NOTABLE CODE IMPLEMENTATIONS
   ========================= */

// 1. Both evaluating a boolean method function and executing its contents
// in one line (if statement):

// account.h:
bool withdraw(double amount)
{
    if (balance < amount)
        return false; // insufficient funds
    else
    {
        balance -= amount;
        transactions++;
        return true;
    }  
}

// account.cpp:
void withdraw(Account &acnt)
{
    double dollars;

    cout << "Enter the amount of the withdrawal: ";
    cin >> dollars;
    cin.ignore();
    if (!acnt.withdraw(dollars)) // ****LINE OF INTEREST****
    cout << "ERROR: Withdrawal amount too large.\n\n";
}

//------------------------------------------------------------------------------
// 2. Implementing a random number generator
// Seed the random number generator ONCE at program start
unsigned seed = time(0);
srand(seed); // seed rand() with the current time

cout << "Seed used: " << seed << "\n\n";

// Generate some random numbers
for (int i = 0; i < 5; ++i) {
    int randomNum = rand() % 6 + 1; // random 1–6
    cout << "Roll " << (i+1) << ": " << randomNum << endl;
}

//------------------------------------------------------------------------------
// 3. Formatting floating point numbers
cout << setprecision(2) << fixed << showpoint;

//--------------------------------------------------------------------------
// 4. Validations
int readIntInRange(int minVal, int maxVal, const string &prompt="Enter a number: ") 
{
    int num;
    while (true) 
    {
        cout << prompt;
        if (!(cin >> num)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Try again.\n";
        } else if (num < minVal || num > maxVal) {
            cout << "Number must be between " << minVal << " and " << maxVal << ".\n";
        } else return num;
    }
}

//------------------------------------------------------------------------------
// 5. Print 2-D array
const int COLS = 3;

void print2DArray(int arr[][COLS], int rows) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < COLS; ++j)
            cout << arr[i][j] << ' ';
        cout << '\n';
    }
}

//------------------------------------------------------------------------------
// 6. Summary statistics (min, max, average, median, mode)
// Min
vector<int> findMinValues(const vector<int>& v) 
{
    vector<int> mins;
    if (v.empty()) return mins;
    int minVal = *min_element(v.begin(), v.end());
    for (int x : v)
        if (x == minVal) mins.push_back(x);
    return mins;
}

// Max
vector<int> findMaxValues(const vector<int>& v) 
{
    vector<int> maxs;
    if (v.empty()) return maxs;
    int maxVal = *max_element(v.begin(), v.end());
    for (int x : v)
        if (x == maxVal) maxs.push_back(x);
    return maxs;
}

// Return indices where value == max or min
vector<int> findIndicesOf(const vector<int>& v, int value) 
{
    vector<int> idx;
    for (int i = 0; i < (int)v.size(); ++i)
        if (v[i] == value) idx.push_back(i);
    return idx;
}

// Average (mean)
double findAverage(const vector<int>& v) {
    if (v.empty()) return 0.0;
    int total = 0;
    for (int x : v) total += x;
    return static_cast<double>(total) / v.size();
}

// Median
double findMedian(vector<int> v) 
{  // pass by value so we can sort safely
    if (v.empty()) return 0.0;
    sort(v.begin(), v.end());
    int n = v.size();
    if (n % 2 == 1)
        return v[n / 2];  // odd count → middle element
    else
        return (v[n / 2 - 1] + v[n / 2]) / 2.0;  // even count → avg of two middles
}

// Mode v1
vector<int> findModes(const vector<int>& v) 
{
    vector<int> modes;
    if (v.empty()) return modes;

    map<int, int> freq;
    for (int x : v) freq[x]++;

    int maxFreq = 0;
    for (auto& p : freq)
        if (p.second > maxFreq) maxFreq = p.second;

    // if all values appear once, no mode
    if (maxFreq == 1) return modes;

    for (auto& p : freq)
        if (p.second == maxFreq) modes.push_back(p.first);

    return modes;
}

// Mode v2
vector<int> findModes(int* arr, int length)
{
    vector<int> mode;
    if (length <= 0) return mode;

    // Sort the array first
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
            // End of current frequency run
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

            // Start a new frequency run
            value = arr[i];
            freq = 1;
        }
    }

    // Finalize last frequency run
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

    // Optional: if every value occurs once, no mode
    if (maxFreq == 1)
        mode.clear();

    return mode;
}
//------------------------------------------------------------------------------
// 7. Sorting algorithms (ascending, descending, reverse array)

// Sort ascending
void sortAscending(vector<int>& v) {
    sort(v.begin(), v.end());
}

// Sort descending
void sortDescending(vector<int>& v) {
    sort(v.begin(), v.end(), greater<int>());
}

int* reverseArray(int* array, int size)
{
    int* reversed = new int[size];

    for (int i = 0; i < size; i++)
    {
        reversed[i] = array[size - 1 - i];
    }

    return reversed;
}

#endif