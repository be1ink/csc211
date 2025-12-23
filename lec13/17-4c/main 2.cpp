#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

const map<char, char> codes =
{
    {'A','%'}, {'B','@'}, {'C','!'}, {'D','^'}, {'E','&'}, {'F','*'},
    {'G','('}, {'H',')'}, {'I','-'}, {'J','+'}, {'K','='}, {'L','{'},
    {'M','}'}, {'N','['}, {'O',']'}, {'P',':'}, {'Q',';'}, {'R','<'},
    {'S','>'}, {'T','?'}, {'U','/'}, {'V','~'}, {'W','`'}, {'X','|'},
    {'Y','_'}, {'Z','$'},
    {'a','9'}, {'b','#'}, {'c','2'}, {'d','3'}, {'e','4'}, {'f','5'},
    {'g','6'}, {'h','7'}, {'i','8'}, {'j','0'}, {'k','1'}, {'l','q'},
    {'m','w'}, {'n','e'}, {'o','r'}, {'p','t'}, {'q','y'}, {'r','u'},
    {'s','i'}, {'t','o'}, {'u','p'}, {'v','a'}, {'w','s'}, {'x','d'},
    {'y','f'}, {'z','g'}
};

int main()
{
    ifstream input_file1("input_file1.txt", ios::in);
    ofstream encrypted_file("encrypted_file.txt", ios::out);
    ifstream input_file2("input_file2.txt", ios::in);
    ofstream decrypted_file("decrypted_file.txt", ios::out);

    char c;

    // Encryption
    while (input_file1.get(c))
    {
        auto it = codes.find(c);
        encrypted_file << (it != codes.end() ? it->second : c); // deals if char not found
    }
    encrypted_file.close();

    // Build decode map
    map<char, char> decode;
    for (const auto &p : codes)
        // Create reversed key value pairs
        decode[p.second] = p.first;

    // Decryption
    while (input_file2.get(c))
    {
        auto it = decode.find(c);
        decrypted_file << (it != decode.end() ? it->second : c); // deals if char not found
    }
    decrypted_file.close();

    return 0;
}