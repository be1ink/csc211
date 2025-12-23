// 9. File Encryption Filter
    // File encryption is the science of writing the contents of a file in a secret code. Your
    // encryption program should work like a filter, reading the contents of one file, modi-
    // fying the data into a code, then writing the coded contents out to a second file. The
    // second file will be a version of the first file, but written in a secret code.
    // Although there are complex encryption techniques, you should come up with a simple
    // one of your own. For example, you could read the first file one character at a time,
    // and add 10 to the ASCII code of each character before it is written to the second file.

// 10. File Decryption Filter
    // Write a program that decrypts the file produced by the program in Programming
    // Challenge 9. The decryption program should read the contents of the coded file, restore
    // the data to its original state, and write it to another file.

#include <iostream>
#include <fstream>
using namespace std;

// Function Prototypes
void encryptFile(ifstream &, ofstream &);
void decryptFile(ifstream &, ofstream &);

int main()
{
    // Declare variables
    ifstream input_file;
    ofstream output_file;
    string file_name;

    // Read in and modify values of file by simply adding 10 to ASCII code
    cout << "Please enter the name of the file: ";
    cin >> file_name;
    
    input_file.open(file_name, ios::in);
    output_file.open("encrypted_file.txt", ios::out);

    if(input_file)
    {
        // Encrypt files by adding 10 to each char's ASCII value
        encryptFile(input_file, output_file);

        input_file.close();
        output_file.close();

        input_file.open("encrypted_file.txt", ios::in);
        output_file.open("decrypted_file.txt", ios::out);

        // Decrypt files by subtracting 10 frome ach char's ASCII value
        decryptFile(input_file, output_file);
    }
    else {cout << file_name << " could not be opened. \n";}

    return 0;
}

// Functions
void encryptFile(ifstream &in, ofstream &out)
{
    char ch; //TODO: How should I initialize chars?

    while (in.get(ch)) 
    {
        cout << ch; // See the next character
        unsigned char b = static_cast<unsigned char>(ch);
        b = static_cast<unsigned char>(b + 10);
        out.put(static_cast<char>(b));
        cout << b << endl; // See the encrypted character
    }  

    // Close files
    in.close();
    out.close();
}

void decryptFile(ifstream &in, ofstream &out)
{
    char ch; //TODO: How should I initialize chars?

    while (in.get(ch)) 
    {
        cout << ch; // See the next character
        unsigned char b = static_cast<unsigned char>(ch);
        b = static_cast<unsigned char>(b - 10);
        out.put(static_cast<char>(b));
        cout << b << endl; // See the decrypted character
    }

    // Close files
    in.close();
    out.close();
}