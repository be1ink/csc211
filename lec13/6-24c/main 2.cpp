#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <limits>
using namespace std;

// Function prototypes
int computer_move();
int get_choice();
bool tie_assess(int, int);
void report_victor(int, int);

int main()
{
    // Declare variables
    int player_choice = 0;
    int computer_choice = 0;
    bool victory = false;
    map<int, string> moves = 
    {
        {1, "rock"},
        {2, "paper"},
        {3, "scissors"}
    };

    // Implement random seed
    srand(static_cast<unsigned>(time(nullptr)));
    // Test random num generator
    cout << computer_move() << endl;

    cout << "Welcome to Rock, Paper, Scissors! You will play matches until you \n";
    cout << "or the AI wins. Good luck!" << endl;

    // Menu
    while(victory == false)
    {
        cout << "Please enter a move by inputting the corresponding integer:\n";
        cout << "[1] Rock\n";
        cout << "[2] Paper\n";
        cout << "[3] Scissors\n";

        player_choice = get_choice();

        computer_choice = computer_move();
         cout << "\nComputer chooses: " << moves.at(computer_choice) << endl << endl;

        victory = tie_assess(player_choice, computer_choice);
        // if(victory == false) {cout << "Tie! Go again. \n";}
    }

    // Report victor
    report_victor(player_choice, computer_choice);

    return 0;
}

// Function definitions
int computer_move()
{
    int num = rand() % 4;
    while(true)
    {
        if (num != 0)
            return num;
        else {num = rand() % 4;}
    }
}

int get_choice()
{
    int choice = 0;

    while(true)
    {
        if(cin >> choice && cin.peek() == '\n' && choice >= 1 && choice <= 3)
            {return choice;}
        else
        {
            cout << "Invalid input, try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool tie_assess(int p, int c)
{
    if(p == c) {cout << "Tie! Go again. \n\n"; return false; }
    else {return true;}
}

void report_victor(int p, int c)
{
    if(p == 1)
        {
            if(c == 2) {cout << "Computer wins! Paper beats rock!\n";}
            else if(c == 3) {cout << "Player wins! Rock beats, scissors!\n";}
        }
    else if(p == 2)
        {
            if(c == 1) {cout << "Player wins! Paper beats rock!\n";}
            else if(c == 3) {cout << "Computer wins! Scissors beat, paper!\n";}
        }
    else if(p == 3)
        {
            if(c == 1) {cout << "Computer wins! Rock beats scissors!\n";}
            else if(c == 2) {cout << "Player wins! Scissors beat, paper!\n";}
        }
}