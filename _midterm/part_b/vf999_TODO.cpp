// Armand Link
// TODO.cpp
// 11/7/21

#include <iostream>
#include <iomanip>
#include <ctime>                        // Permits Use of Time
#include <cctype>                       // Permits use of toupper()
#include <string>                       // C-Strings and Strings
#include <limits>                       // Stream Limits
#include <fstream>                      // For File I/O

using namespace std;

/* 
    Create a TODO list program.
    I. Prompt your character/symbol they enter will be the command. 
       (Follow with a space character)
    II. Enter the todo list item (e.g. "Study for Final")
        (This will add Study for Final to the list with the date.)
    III. Fields
        a. TODO item
        b. Date Added
        c. TODO ID #
        Future Fields in Version 2.0:
            1. Add Due Date
            2. Incomplete vs Complete
*/

/*******************************************************************************
                        Date Class Declaration
*******************************************************************************/
class Date
{
    private:
        int month;                              // Name of the Month
        int day_month;                          // Date of the Month
        int year;                               // Annual Year
    public:
    // Default Date Constructor - Uses System Date
    Date()
    {
        time_t unix_time = time(NULL);
        const tm* now = localtime(&unix_time);

        // Assigning the Memory Location of Private Variables to Current Time
        month = now->tm_mon + 1;
        day_month = now->tm_mday;
        year = now->tm_year + 1900;
    }
    // Parameterized Date Constructor
    Date (int mm, int dd, int yy)             
    {
        month = mm;
        day_month = dd;
        year = yy;
    }

     // Member Function Prototypes
    void set_month(int mm){ month = mm;}        // Setter for Month
    void set_day(int dd) {day_month = dd;}      // Setter for Day
    void set_year(int yy) {year = yy;}          // Setter for Year

    // Displays the Date in 99/99/99 Format
    string PrintDate()
    {
        string s = to_string(month) + "/" + to_string(day_month) + "/"
                   + to_string(year).substr(2);
        return s;
    }
    void TestDate();                            // Class Component Test
};

    void Date::TestDate()
    {
       int mm = 99;
       int dd = 99;
       int yy = 99;

        // Test #1 for System Time
        if (mm != this->month && dd != this->day_month && yy != this->year)
            cout << "\n\t\tSystem Time: " << right << setw(11) 
                 << "\t\033[0;92mPassed\033[0m\n";
        else
            cout << "\n\t\tSystem Time: " << right << setw(11) 
                 << "\t\033[1;31mFailed\033[0m\n";


        // Test #2 for Overridden Due Date
        if (month >= 1 && month <= 12){

            cout <<"\n\t\tMonth Status: " << right << setw(10) 
                 << "\t\033[0;92mPassed\033[0m\n";
        }
        else
            cout<< "\n\t\tMonth Status: " << right << setw(10) << "Failed";

        if (day_month >= 1 && day_month <= 31)
            cout << "\n\t\tDay Status: " << right << setw(12)
                 << "\t\033[0;92mPassed\033[0m\n";
        else
            cout << "\n\t\tDay Status: " << right << setw(12) << "Failed";

        if (year >= 1900 && year <= 2021)
            cout << "\n\t\tYear Status: " << right << setw(11) 
                 << "\t\033[0;92mPassed\033[0m\n";
        else
            cout << "\n\t\tYear Status: " << right << setw(11) << "Failed";
    }

/*******************************************************************************
                        TODO Task Class Declaration
                        (Contains TODO List Fields)
*******************************************************************************/
class Task
{
    private:
        int task_id;                    // Task ID #
        static int task_count;          // Counter for # of Tasks
        string task_info;               // Task Description
        Date task_date;                 // Date Task Added
    public:
        // Default Task Constructor - Initialized to Dummy Data
        Task()
        {
            Date start;
            start = Date(99, 99, 9999);
            task_id = 99999;
            task_info = "Lorem ipsum dolor sit amet, " 
                        "consectetuer adipiscing elit.";
            task_date = start;   

           // cout << "\n\n\tDefault Task Constructor is running.\n";
        }
        // Parameterized Constructor
        Task(int id, string info, Date today)
        {
            task_id = id;
            task_info = info;
            task_date = today;  

           // cout << "\n\n\tTask Parameterized Constructor is running.";
        } 
        
        // Shared Getter Method : Returns Task ID Entry
        int get_item_record_num() { return task_id;}

        // Getter for Item ID
        int get_task_id() {return task_id;}
        // Setter for Item ID - Changed Task ID to Counter ****
        void set_task_id(int id) 
        { 
          task_id = task_count++; 
          //task_count = id;
         }

        // Getter for Task Counter
        static int get_count() {return task_count;}

        // Getter for Task Info
        string get_task_info() {return task_info;}
        // Setter for Task Info
        void set_task_info(string info) {task_info = info;}

        // Getter for Task Date
        Date get_task_date() {return task_date;}
        
        // Specification A3 - System Date
        // System Date Uses Date Constructor
        void set_date(Date today) {task_date = Date();}           

        // Component Test
        void TaskTest();
        // Assignment Operator Overload for Tasks
        Task& operator=(const Task& other);
        // Overloading for Dynamic User Task Input
        friend istream& operator>> (istream& in, Task& x);
        //Overloading Ostream to Display Tasks
        friend ostream& operator<< (ostream& out, const Task& x);
};
    // Initializing Counter for Task IDs
    int Task::task_count = 0;

    // Specification A2 - Overload Assignment Operator
    Task& Task::operator=(const Task& other)
    {
        if(this == &other)      // Only Copy if Obj Passed is This One
            return *this;       // Return New Memory Location w/ This Data
        
        // If Not This Task, Copy Values to Other Task
        else 
        {
            task_id = other.task_id;
            task_info = other.task_info;
            task_date = other.task_date;
        }  
       
            return *this;
    } 
    
    void Task::TaskTest()
    {
       Task t;
       Date today;
       bool success = false;
        
        // Test Case #1: Dummy Task Data
       (task_id == 99999) ? success = true : success = false;
       (task_info == "Lorem ipsum dolor sit amet, consectetuer adipiscing elit.") ?
            success = true : success = false;
     
        if (success == true)
            cout << "\n\t\tDummy Data: " << right << setw(11) 
                 << "\t\033[0;92mPassed\033[0m\n"; 
        else 
            cout << "\n\t\tDummy Data: " << right << setw(11)
                 << "\t\033[1;31mFailed\033[0m\n";

        // Test Case # 2: Parameters from Setters/Getters
        t.set_task_id(task_count);   // 99999
        t.set_task_info("This is a test.");
        t.set_date(today);  
    
        if (t.get_task_id() != 99999)
            cout << "\n\t\tTask ID: " << right << setw(11) 
                 << "\t\033[0;92mPassed\033[0m\n";
        else
        {
            cout << "\n\t\tTask ID: " << right << setw(11) 
                 << "\t\033[1;31mFailed\033[0m\n";
            cout << "\n\t\tWrong ID: " << t.get_task_id();
        }  

        if (t.get_task_info() == "This is a test.")
            cout << "\n\t\tTask Info: " << right << setw(11) 
                 << "\t\033[0;92mPassed\033[0m\n";
        else
            cout << "\n\t\tTask Info: " << right << setw(11) 
                 << "\t\033[1;31mFailed\033[0m\n";
    }

    // Specification C2 - Overload »
    istream& operator>> (istream& in, Task& x)
    {
        int id;
        static int task_count;
        string info;
        
        Date dum_date; 
        Date now = Date();  

            // Setting Default Constructor for Dummy Data
            x.set_task_info(info);
            x.set_task_id(id);
            x.set_date(dum_date);

        return in;
    }

    // Specification C1 - Overload «
    ostream& operator<< (ostream& out, Task& x)
    {
        // Formatted Output for Tasks
        out << "| " << left << setw(5) << x.get_task_id() << "|";
        out << left << setw(58) << x.get_task_info() << "|";
        out << left << setw(12) << x.get_task_date().PrintDate() << "|";
        // New Line for Chart
        out << "\n ------------------------------------------------------------------------------\n";

        return out;
    }

/*******************************************************************************
                        List Class Declaration
                (Dynamically Creates Space for Task(s))
*******************************************************************************/

class List
{
    private:
        int list_size;                  // Current List Size
        int max_list_size;              // Max List Size
        Task *arr_tasks;                // Pointer to Array of Tasks in List
        void build_list_space();        // Dynamically Adds Task Storage
        // Returns Task ID of Entry
        int find_item_record_num(int anID) const;
    public:
    // Default Constructor 
    List()
    {
        max_list_size = 5;
        list_size = 0;
        arr_tasks = new Task[max_list_size];
        // cout << "\n\tDefault List Constructor is running.\n";
    }
    // List Copy Constructor
    List(const List& l)
    {
        max_list_size = l.max_list_size;
        list_size = l.list_size;
        arr_tasks = new Task[l.max_list_size];

        // Copying Dynamic Todos
        for (int i = 0; i < list_size; i++)
            arr_tasks[i] = l.arr_tasks[i];
        // cout << "\n\n\tList Copy Constructor is running.\n";
    } 
    // List Destructor
    ~List()
    {
        delete [] arr_tasks;
        // cout << "\n\n\tList Destructor is running.\n";
    }

    /* 
        Member Function Prototypes
    */ 
    // Adds New Todo to List
    void add_todo(string &part_line);
    // Adds New Dummy Todo Record
    void add_dummy_todo(Task& info);
    // Removes Todo from List        
    void remove_todo();
    // Displays Full Todo List
    void display_todo_list() const;

    // Dumps List to Disk at EOF
    void dump_todo_list() const;

    // List Components Test
    void ListTest();
    // Overloading for Dynamic User TODO List Input
    friend istream& operator>> (istream& in, Task& x);
    //Overloading Ostream for Dynamic TODO List Output
    friend ostream& operator<< (ostream& out, const Task& x);
};

void List::build_list_space()
{
     max_list_size = list_size + 5;
     
     //Specification C4 - TODO array
     Task* new_items = new Task[max_list_size];

       for (int i = 0; i < list_size; i++)
            new_items[i] = arr_tasks[i];

        delete [] arr_tasks;
        arr_tasks = new_items;
        new_items = nullptr;
}

// Specification B1 - + Symbol
void List::add_todo(string &part_line)
{
    if(max_list_size == list_size)
        build_list_space();
    
    // Default Constructor Invoked
    Task t1;
    static int task_count;
    Date today;

    // Specification A4 - Overload Constructor
    // Constructor Overloaded w/ Index, Partial Line, & System Date
    Task t(0, part_line, today);

    t1 = t;

    // Setting Index for Output
    t1.set_task_id(task_count);

        cout << "\n\n\t*******************************************";
        cout << "\n\t\t  ✅ - Todo Item Added.";
        cout << "\n\t*******************************************\n";
    
    // Specification A1 - Overload Copy Constructor
    Task copy_t(t1); 

    // Assigning the contents of Copy Constructor to Dynamic Array Object
    arr_tasks[list_size++] = copy_t;

}

void List::add_dummy_todo(Task& info)
{
    if(max_list_size == list_size)
        build_list_space();
    
    // Default Task Data Assigned to Task Array
    arr_tasks[list_size++] = info;
}

// Helper Function for ID Record Number
int List::find_item_record_num(int anID) const
{
    for (int i = 0; i < list_size; i++)
    // Compare Task Index with Task ID Records
	if (arr_tasks[i].get_item_record_num() == anID)
		return i;

    // Return if Not Found
    return -1;
}

void List::remove_todo()
{
    int anID;                       // Method Member Variable for Comparison
    char rmv_response;              // User Response

    if (list_size == 0)
    {
        cout << "\nNOTHING TO SEE HERE. Press <+> to add a todo, or <Q> to quit.";
        return;
    } 

    cout << "\nThe most recent entry will be deleted. Are you sure?";
    cout << "\n\n * Press <N> for NO to Search for a Task by ID";
    cout << "\n * Press <Y> for YES or <X> to EXIT to Task Menu: ";
    cout << "\n\n>";
    cin.get(rmv_response); 
    rmv_response = toupper(rmv_response);

    switch (rmv_response)
    {
        case 'Y':
        {
            Task *temp = new Task[list_size - 1];
            for (int i = 0; i < list_size - 1; i++)
                temp[i] = arr_tasks[i];

            delete [] arr_tasks;
            arr_tasks = temp;
            temp = nullptr;
            list_size--;
        
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\n\t*******************************************";
            cout << "\n\t   ❌ - Todo Item Deleted from the List";
            cout << "\n\t*******************************************";
        /* cout << "\nPlease Type a Symbol and a Todo Task to Add or Delete ('+', '-')"
             << "\nor Choose Another Option ('?' to Display or 'Q' to Quit): "; */
        // cout << "\n>";
        break;
        }
        case 'N':
        {
         cout << "\nPlease type the ID of entry to be removed, and press <Enter>: ";
         cout << "\n>";
         cin >> anID;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');

         int curr_entry = find_item_record_num(anID);

         if (curr_entry == -1)
         {
             cout << "\n-----------------------------------------------------------";
             cout << "\nHMM...ID # " << anID << " was not found. "; 
             cout << "Please check it, and Try Again.\n";
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             break;
         }
         else
         {
            for (int j = curr_entry + 1; j < list_size; j++)
                arr_tasks[j-1] = arr_tasks[j];
                 
            list_size--;

            cout << "\n\t*******************************************";
            cout << "\n\t  ❌ -  Todo Item Deleted from the List";
            cout << "\n\t*******************************************";

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            /* cout << "\nPlease Type a Symbol and a Todo Task to Add or Delete ('+', '-')"
                 << "\nor Choose Another Option ('?' to Display or 'Q' to Quit):\n\n"; */
            break; 
         }
        }
        case 'X':
        {
            cout << "\nPlease Type a Symbol and a Todo Task to Add or Delete ('+', '-')"
                 << "\nor Choose Another Option ('?' to Display or 'Q' to Quit):\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
        default:
        if (list_size == 0)
        {
            cout << "\nNOTHING TO SEE HERE. Press <+> to add a todo, or <Q> to quit.";
            return;
        }
    }
} 

// Specification B2 - ? Symbol
//Allow the user to display all tasks with a ? symbol.
void List::display_todo_list() const
{
    if (list_size == 0)
    {
        cout << "\nNO CURRENT TODOS.";
        cout << "\nPlease Type a Symbol and a Todo Task to Add or Delete ('+', '-')"
                 << "\nor Choose Another Option ('?' to Display or 'Q' to Quit):\n\n";
        return;
    }

    // Header for Generated Stock
    cout << "\n ------------------------------------------------------------------------------";
    cout << "\n|  ID  |                        Tasks To-Do                       | Date Added |";
    cout << "\n ------------------------------------------------------------------------------\n";

    for (int i = 0; i < list_size; i++)
        cout << left << arr_tasks[i];
}

void List::dump_todo_list() const
{
    fstream file;

    // Opening File for I/O & Appending to Existing Contents
    file.open ("anewlist.txt", fstream::in | fstream::out | fstream::app);

    // Header for Generated Stock
    file << "\n ------------------------------------------------------------------------------";
    file << "\n|  ID  |                        Tasks To-Do                       | Date Added |";
    file << "\n ------------------------------------------------------------------------------\n";

    for (int i = 0; i < list_size; i++)
        file << left << arr_tasks[i];
    
}

// List Class Component Test
void List::ListTest()
{
   Date dd;
  // List tlist;

   fstream file;

   file.open ("anewlist.txt", fstream::in | fstream::out | fstream::app);

    // Specification C3 - Test TODO’s 
    // Saved to Same File as EOF Dump
    Task t1(111, "Test #1", dd);

    Task t2(222, "Test #2", dd);

    Task t3(333, "Test #3", dd);

    Task t4(444, "Test #4", dd);

    Task t5(555, "Test #5", dd);

   // display_todo_list();
    file << t1 << t2 << t3 << t4 << t5 << endl;

    // Closing for Now for Data Protection
    file.close(); 

   // Test for List Size (adding)
   // Test for Removing Data 
    if (arr_tasks != nullptr)
        cout <<"\n\t\tList Array: " << right << setw(10) 
             << "\t\033[0;92mPassed\033[0m\n";
    else
        cout <<"\n\t\tList Array: "<< right << setw(10) << "Failed" << endl;
    
    for (int i = 0; i < list_size; i++)
        cout << left << arr_tasks[i];
}

/*----------------------------------------------------------------------------*/

/******************************************************************************/

// Client Function Prototypes
void ProgramGreeting();
void UnitTest();                            // Calls Class Component Tests
void displayTaskMenu();                     // Program Menu Options for Input
void promptTaskMenu(char&, string&);        // Returns Char & Partial String from Menu 
bool validTaskInput(char);                  // Validates User Selected Option
char getValidTaskOption(char&, string&);    // Validate Menu Option & Pop Test Data

/* void file_handler();
string get_FileName();
bool open_File(fstream& file, string name); */
// void storeTaskList(const Task&);

int main () {

    // Fstream Object for R/W
    fstream file;                           
    // Local Variable for Todo Option
    char task_option;                     
    // Object for Dynamic Class
    List x;                                                    
    // Task Object for Task Fields
    Task info;                            
    // Local Variable Test for Empty Input 
    string mty_test;                     
    // Local Variable for Task Details
    string part_line;                    

    // Opening File for I/O & Appending to Existing Contents
    file.open ("anewlist.txt", fstream::in | fstream::out | fstream::app);

    ProgramGreeting();
    UnitTest();
    displayTaskMenu();

    do
    {
        getValidTaskOption(task_option, part_line); 
        
        switch (task_option)
        {
            // Specification B1 - + Symbol
            case '+':
                // Compares Partial Line to Empty Test Variable
                if (part_line == mty_test)
                {
                    cout << "\n\t\033[1;31mWARNING:\033[0m YOU ENTERED AN EMPTY TASK.";
                    Task item(info);
                    x.add_dummy_todo(item);
                    cout << "\n\tA record with Dummy Data has been added.\n";
                    break;
                } 
                // Add Record when Not Empty
                else if (part_line != mty_test)
                {
                    // cout << "\n\tAdding Entry to Record.\n";
                    // Partial Line Passed List CLass to Add Dynamically
                    x.add_todo(part_line);
                    break;
                }
            // Specification B3 - - symbol
            case '-':
                x.remove_todo();
                break;
            // Specification B2 - ? Symbol
            case '?':
                x.display_todo_list();
                break;
            // Specification B4 - Persistence
            // Saves Data If File is Open
            case 'Q': 
                // Check if File Exists & is Open
                if (file && file.is_open()) {
                    cout << "Saving Data...\n"; 
                    x.dump_todo_list();
                    break;
                }
                else
                    cout << "No File Open to Save...\n";
                    break;
        }
    } while (task_option != 'Q');

    // Farewell Message to User After Exiting Program
    if (task_option == 'Q')
        {
            cout << "\nThanks for using A-New-List (totally not \033[1;31mTodoist\033[0m)" << endl;
            cout << "Goodbye!";
        }

    file.close();
    
    return 0;
}
void ProgramGreeting()
{
    Date();
    Date set_date(11, 7, 2021);
    Date curr_date;                     

  cout << "\033[0;91m";
  cout << "@@@@@@@@@@@@@@@@@@                                                           \n";
  cout << "@@@@@@@@@/   /@@@@                                                           \n";
  cout << "@@@@@@/   /@@@@@@@   @      @@@@@@ @@@@❩ @        @    @.    ❐❐  @@@❩   @@  \n";
  cout << "/     @@     /@@@@  @ @     @@   @ @ _@  @.  @   .@    @.    @@  @.   ❨****❩\n";
  cout << "  /@@/   /@@@@@@@@ @_-_@ [] @@   @ @/      @, @. @  [] @@    @@    @.   @@  \n";
  cout << "@/    @@    /@@@@@ @   @    @@   @ @@@@❩    @@ @@      @@@@@ @@ ❨@@@@   @@  \n";
  cout << "  @@     /@@@@@@@@                                                           \n";
  cout << "@@/  /@@@@@@@@@@@@                                                           \n";
  cout << "\033[0m";

    cout <<"\n\n\t\033[1;31m Welcome to A-New-List™ (not Todoist)!\033[0m";
    cout << "\n **************";
    cout << "  Name: Armand Link  ";
    cout << "*************** " << "\n";
    cout << "\t******* " << "Due Date: ";

     // Date Object Prints Manual Due Date
    cout << set_date.PrintDate();
    cout <<" *******\n";

    // Displays Current Date
   cout << "\t******* " << "Current Date: "; 
   cout << curr_date.PrintDate() << " *******\n\n";
}

// Unit Test for Task & List Class Components
void UnitTest()
{
     Date d; List l; Task t;

    cout << "\t\n\\\\\\\\\\\\\\\\\\\\\\\\///////////////";
    cout << "\\\\\\\\\\\\\\\\\\\\\\\\///////////////" << endl;
    cout << "\n\t\tUnit Test is Running. . .\n";
    cout << "\n\t\tDate Components Status:\n";
    d.TestDate();
    cout << "\n\n\t\tList Components Status: \n";
    l.ListTest();
    cout << "\n\n\t\tTask Components Status: \n";
    t.TaskTest();
}
// Displays Initial Entry Options for Tasks
void displayTaskMenu()
{
    cout << "\b\n\t------------- ";
    cout << "Task Menu";
    cout << " ------------\n\n";
    cout << "\t\t<+> Add Todo Task\n";
    cout << "\t\t<-> Delete Todo Task\n";
    cout << "\t\t<?> Display All Todos\n";
    cout << "\t\t<Q> Quit Program\n";
    cout << "\b\n\t------------------------------------\n";
    cout << "\n\nPlease Type a Symbol and a Todo Task to Add or Delete ('+', '-')"
         << "\nor Choose Another Option ('?' to Display or 'Q' to Quit):";
}

// Task Control Menu
void promptTaskMenu(char &task_option, string &part_line)
{
    // cout << "\nNow Back in Prompt Menu: " << endl;
    cout << "\n\n>";

    part_line.clear();
    string full_line;

    // Input a Line
     getline(cin, full_line);
  
    // First Element of String Assigned to Menu Option
    task_option = full_line[0];

    if (task_option == 'q')
        // Converts to Upper Case
        task_option = toupper(task_option);  

    // When Task Elem #2 Isn't Empty while Adding a Task
    if (!(isspace(full_line[1])) && task_option == '+' && full_line.length() > 1)
    {
        cout << "\t\n\033[1;31mINVALID ENTRY:\033[0m PLACE A SPACE BETWEEN " 
             << "TASK OPTION AND TASK INFO";
        full_line.clear();
        getValidTaskOption(task_option, part_line);
    }
    // Size Limitations Due to Size of Formatted Todo List
    else if (full_line.length() > 1 && full_line.length() <= 60)
    {
        // cout << "\t\n*** PASSED VALID CHAR LENGTH CHECK. ***\n";
        part_line = full_line.substr(2); 
        // cout << "\t\nSubtracted lines of PART_LINE: " << part_line << "\n";
        // cout << "\t\nLength of PART_LINE: " << part_line.length() << "\n";

        // Line Limit to Fit Neatly in Field
        if (full_line.length() > 60)
        {
        cout << "\t\nINVALID LENGTH: TASK MUST BE 60 CHARACTERS OR LESS.";
        cout << "\n\tThis task is " << part_line.length() << " characters long.\n";
        promptTaskMenu(task_option, part_line);
        }
    }
}

// Returns Task Input Option when Valid
bool validTaskInput(char ch)
{
    return (ch == '+' || ch == '-' || ch == '?'|| ch == 'Q');
}

// Getter for Valid for Menu Option
char getValidTaskOption(char &task_option, string &part_line)
{
   promptTaskMenu(task_option, part_line);

    while (!validTaskInput(task_option))
    {
        cout << "\n\tINVALID TASK OPTION: PLEASE TRY AGAIN." << endl;
        displayTaskMenu();
        promptTaskMenu(task_option, part_line);
    }
    return task_option;
}