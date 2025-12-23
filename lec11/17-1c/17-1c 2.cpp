#include <iostream>
#include <iomanip>
#include <fstream>
#include <set> // How I'll grab unique words
using namespace std;

int main()
{
    ifstream input_file;
    string word;
    set<string> unique_list;
    int i = 0; // iterator

    input_file.open("unique_words.txt", ios::in);

    // while(input_file.eof() != true)
    // {
    //     input_file >> word;
    //     unique_list.insert(word);
    // }

    while (input_file >> word)
    {
        // Strip the non-alphanumeric characters from end of word
        while (!word.empty() && !isalnum(static_cast<unsigned char>(word.back())))
         word.pop_back();

        // If word exists
        if (!word.empty())
            unique_list.insert(word);
    }

    for (auto& x : unique_list)
        cout << x << " ";
    cout << endl;

    return 0;
}