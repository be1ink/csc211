#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <map>
using namespace std;

// Function prototypes
void avg_price_year(ifstream&);
void avg_price_month_1(ifstream&);
void avg_price_month_2(ifstream&);
void min_max_year(ifstream&);
void asc_sort(ifstream&);
void desc_sort_1(ifstream&);
void desc_sort_2(ifstream&);

int main()
{
    ifstream input_file;
    input_file.open("GasPrices.txt", ios::in);

    cout << "Average yearly gas prices: \n";
    avg_price_year(input_file);

    cout << "\nAverage monthly gas prices: \n";
    avg_price_month_2(input_file);

    cout << "Highest and Lowest Prices per Year: \n";
    min_max_year(input_file);

    cout << "Output list of dates and prices from lowest to highest prices\n";
    asc_sort(input_file);

    cout << "Output list of dates and prices from highest to lowest prices\n";
    desc_sort_1(input_file);

    return 0;
}

void avg_price_year(ifstream& in)
{
    // Declare variables
    string s;
    int year;
    int d = 1; // the denominator for calculating yearly averages
    double value;
    map<int, double> yap;

    while(getline(in, s))
    {
        // Get year
        year = stoi(s.substr(6, 4)); 

        // Get value by taking the last five elements from the end of the string
        value = stod(s.substr(s.size() - 5));

        // Adds if the key isn't there, ignores if it is there
        if(yap.count(year) == 0) {yap.emplace(year, value); d = 1;}
        else {d++; yap.at(year) = (yap.at(year)*(d-1)+value)/d;}
    }
    // Display data
    for (auto y : yap) 
        {cout << fixed << setprecision(3) << y.first << " " << y.second << endl;}

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);
}

void avg_price_month_1(ifstream& in)
{
    // Declare variables
    string s;
    string month;
    double value;
    map<string, double> apm;
    map<string, int> dmap;

    while(getline(in, s))
    {
        // Get month
        month = s.substr(0, 2);

        // Get value by taking the last five elements from the end of the string
        value = stod(s.substr(s.size() - 5));

        // Adds if the key isn't there, ignores if it is there
            // Adjust denominator iterator for cycling months 
            // (not just all in sequential ordering)
        if(apm.count(month) == 0) 
        {
            apm.emplace(month, value); 
            dmap.emplace(month, 1); // Track denominators in parallel map for same month key
        }
        else 
        {
            dmap.at(month) += 1; 
            apm.at(month) = (apm.at(month)*(dmap.at(month)-1)+value)/dmap.at(month);
        }
    }
    // Display data
    for (auto m : apm) 
        {cout << fixed << setprecision(3) << m.first << " " << m.second << endl;}

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);
}

void avg_price_month_2(ifstream& in)
{
    // Declare data types
    struct val_month
    {
        double price = 0.0;
        int d = 1;
    };

    // Declare variables
    string s;
    string month;
    val_month key_value;
    map<string, val_month> apm;

    while(getline(in, s))
    {
        // Get month
        month = s.substr(0, 2);

        // Get value by taking the last five elements from the end of the string
        key_value.price = stod(s.substr(s.size() - 5));

        // Adds if the key isn't there, ignores if it is there
            // Adjust denominator iterator for cycling months 
            // (not just all in sequential ordering)
        if(apm.count(month) == 0) {apm.emplace(month, key_value);}
        else 
        {
            apm.at(month).d++;
            apm.at(month).price = 
                (apm.at(month).price*(apm.at(month).d-1)+key_value.price)
                    / apm.at(month).d;
        }
    }
    // Display data
    for (auto m : apm) 
        {cout << fixed << setprecision(3) << m.first << " " << m.second.price << endl;}

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);
}

void min_max_year(ifstream& in)
{
    // Declare data types
    struct record
    {
        string date = "";
        double price = 0.0;
    };

    // Declare variables
    string s;
    record r;
    int year;
    map<int, record> highest;
    map<int, record> lowest;

    while(getline(in, s))
    {
        // Get year
        year = stoi(s.substr(6, 4));

        // Get value by taking the last five elements from the end of the string
        r.price = stod(s.substr(s.size() - 5));

        // Grab highest amount per year, regardless of its frequency
        if(highest.count(year) == 0) {highest.emplace(year, r);}
        else if(r.price > highest.at(year).price) {highest.at(year).price = r.price;}

        // Grab lowest amount per year, regardless of its frequency
        if(lowest.count(year) == 0) {lowest.emplace(year, r);}
        else {if(r.price < lowest.at(year).price) {lowest.at(year).price = r.price;}}
    }

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);

    // Loop again to find duplicate max's and mins
    while(getline(in, s))
    {
        // Get year
        year = stoi(s.substr(6, 4));

        // Get date
        r.date = s.substr(0, 10);

        // Get value by taking the last five elements from the end of the string
        r.price = stod(s.substr(s.size() - 5));

        // Grab dates for highest amount by year (grabs duplciates if any)
        if(highest.at(year).price == r.price)
        {
            if(highest.at(year).date == "") {highest.at(year).date.append(r.date);}
            else
            {
                highest.at(year).date.append(", ");
                highest.at(year).date.append(r.date);
            }
        } 

        // Grab dates for lowest amount by year (grabs duplciates if any)
        if(lowest.at(year).price == r.price)
        {
            if(lowest.at(year).date == "") {lowest.at(year).date.append(r.date);}
            else
            {
                lowest.at(year).date.append(", ");
                lowest.at(year).date.append(r.date);
            }
        } 
    }

    // Display data - highest and lowest have same size
    cout << endl;
    for(auto a : highest)
        {
            year = a.first;
            cout << fixed << setprecision(3); 
            cout << a.first << endl;
            cout << "Highest price: " << a.second.price;
                cout << " Corresponding date(s): " << a.second.date  << endl;
            cout << "Lowest price:  " << lowest.at(year).price; 
                cout << " Corresponding date(s): " << lowest.at(year).date << endl;
            cout << endl;
        }

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);
}

void asc_sort(ifstream& in)
{
    // Declare variables
    string s;
    string date = "";
    double price = 0.0;
    multimap<double, string> sorted_list; // use prices as key, automatic sorting
    ofstream out_file("asc_prices.txt", ios::out);

    while(getline(in, s))
    {
        // Get date
        date = s.substr(0, 10);

        // Get value by taking the last five elements from the end of the string
        price = stod(s.substr(s.size() - 5));

        sorted_list.emplace(price, date);
    }

    // Print to out_file
    for(auto x : sorted_list)
    {
        out_file << x.second << ": " << x.first << endl;
    }

    out_file.close();

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);
}

void desc_sort_1(ifstream& in)
{
    // Declare data types
    struct price_date
    {
        double price = 0.0;
        string date = "";
    };

    // Declare variables
    string s;
    string date = "";
    double price = 0.0;
    price_date pd;
    multimap<double, string> sorted_list; // use prices as key, automatic sorting
    vector<price_date> pd_vector; // reverse the sorting of map elements
    ofstream out_file("desc_prices.txt", ios::out);

    while(getline(in, s))
    {
        // Get date
        date = s.substr(0, 10);

        // Get value by taking the last five elements from the end of the string
        price = stod(s.substr(s.size() - 5));

        // Gather records in ascending order
        sorted_list.emplace(price, date);
    }

    for(auto x : sorted_list)
    {
        // Add map record to price_date object
        pd.price = x.first; pd.date = x.second;

        // Add sorted records to vector in reverse order from right to left
        pd_vector.emplace(pd_vector.begin(), pd);
    }

    // Print to out_file in reverse order
    for(auto x : pd_vector)
    {
        out_file << x.date << ": " << x.price << endl;
    }

    out_file.close();

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);
}

void desc_sort_2(ifstream& in)
{
    // Declare variables
    string s;
    string date = "";
    double price = 0.0;
    multimap<double, string> sorted_list; // use prices as key, automatic sorting
    ofstream out_file("desc_prices.txt", ios::out);

    while(getline(in, s))
    {
        // Get date
        date = s.substr(0, 10);

        // Get value by taking the last five elements from the end of the string
        price = stod(s.substr(s.size() - 5));

        sorted_list.emplace(price, date);
    }

    // Print to out_file
    for (auto it = sorted_list.rbegin(); it != sorted_list.rend(); ++it)
        out_file << it->second << ": " << it->first << '\n';

    out_file.close();

    // Clear error flag and reset file position pointer
    in.clear();
    in.seekg(0, ios::beg);
}