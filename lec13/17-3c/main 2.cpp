#include <iostream>
#include <iomanip>
#include <map>
#include <iterator>
#include <string>
using namespace std;

const map<string, string> state_capital = {
    {"Alabama","Montgomery"}, {"Alaska","Juneau"}, {"Arizona","Phoenix"}, {"Arkansas","Little Rock"},
    {"California","Sacramento"}, {"Colorado","Denver"}, {"Connecticut","Hartford"}, {"Delaware","Dover"},
    {"Florida","Tallahassee"}, {"Georgia","Atlanta"}, {"Hawaii","Honolulu"}, {"Idaho","Boise"},
    {"Illinois","Springfield"}, {"Indiana","Indianapolis"}, {"Iowa","Des Moines"}, {"Kansas","Topeka"},
    {"Kentucky","Frankfort"}, {"Louisiana","Baton Rouge"}, {"Maine","Augusta"}, {"Maryland","Annapolis"},
    {"Massachusetts","Boston"}, {"Michigan","Lansing"}, {"Minnesota","St. Paul"}, {"Mississippi","Jackson"},
    {"Missouri","Jefferson City"}, {"Montana","Helena"}, {"Nebraska","Lincoln"}, {"Nevada","Carson City"},
    {"New Hampshire","Concord"}, {"New Jersey","Trenton"}, {"New Mexico","Santa Fe"}, {"New York","Albany"},
    {"North Carolina","Raleigh"}, {"North Dakota","Bismarck"}, {"Ohio","Columbus"}, {"Oklahoma","Oklahoma City"},
    {"Oregon","Salem"}, {"Pennsylvania","Harrisburg"}, {"Rhode Island","Providence"}, {"South Carolina","Columbia"},
    {"South Dakota","Pierre"}, {"Tennessee","Nashville"}, {"Texas","Austin"}, {"Utah","Salt Lake City"},
    {"Vermont","Montpelier"}, {"Virginia","Richmond"}, {"Washington","Olympia"}, {"West Virginia","Charleston"},
    {"Wisconsin","Madison"}, {"Wyoming","Cheyenne"}
};

// Function prototypes
int get_choice();
string get_answer();
bool eval_answer(string, string);

int main()
{
    // Declare variables
    int point_counter = 0;
    int questions_asked = 0;
    int cont_game = 0;
    bool correct;
    string user_answer;
    double per_correct = 0.0;

    // Implement random seed
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Hello, welcome to the Capitals of the U.S. quiz. You may continue\n";
    cout << "as long as you wish, points will be tracked and totalled at the end\n";
    cout << "Capitals must be spelled correctly and written in standard case to \n";
    cout << "be awarded points. You must also remember any official punctuation\n";
    cout << "in the title or no credit will be awarded\n\n";
    do
    {
        int idx = rand() % state_capital.size();          
        auto it = state_capital.begin();
        advance(it, idx);

        cout << "What is the capital of " << it->first << "?" << endl;
        questions_asked++;
        getline(cin >> ws, user_answer);

        correct = eval_answer(user_answer, it->second);

        if(correct == true)
        {
            point_counter++;
            cout << "Correct!\n";
        }

        else {cout << "\nIncorrect, the answer is " << it->second;}

        cout << "\nDo you wish to continue the game?\n";
        cout << "[1] Continue\n";
        cout << "[2] Quit\n";
        cont_game = get_choice();

    }while(cont_game != 2);

    // Final results
    per_correct = (static_cast<double>(point_counter) / questions_asked) * 100.0;
    cout << "\nFinal results:\n";
    cout << "Questions asked: " << questions_asked << endl;
    cout << "Questions answered correctly: " << point_counter << endl;
    cout << fixed << setprecision(2);
    cout << "Percent correct: " << per_correct << "%\n";

    return 0;
}

// Function definitions
int get_choice()
{
    int choice = 0;

    while(true)
    {
        if(cin >> choice && cin.peek() == '\n' && choice >= 1 && choice <= 2)
            {return choice;}
        else
        {
            cout << "Invalid input, try again: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

bool eval_answer(string input, string answer)
{
    if(input == answer) {return true;}
    else {return false;}
}