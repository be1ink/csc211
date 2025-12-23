#ifndef FINAL_TEMPLATE_H
#define FINAL_TEMPLATE_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <cstdlib> // abs(), rand(), srand(), EXIT_FAILURE
#include <ctime> // time
#include <fstream>
#include <new> // bad_alloc
using namespace std;

// =============================================================================
//  VALIDATION CODE
int a = 0;
int b = numeric_limits<int>::max(); // Basically the largest possible integer

int get_int()
{
    int num = 0;
    while(true)
    {
        if(cin >> num && cin.peek() == '\n' && num >= 0) {return num;}
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// same as get_int above, but accepts two parameters
int get_int(int a, int b)
{
    int num = 0;
    while(true)
    {
        if(cin >> num && cin.peek() == '\n' && num >= a && num <= b) {return num;}
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

// =============================================================================
//  CLASS COMPONENTS
// Basic example
class ParkedCar
{
private:
    string make;            // The car's make
    string model;           // The car's model
    string color;           // The car's color
    string licenseNumber;   // The car's license number
    int minutesParked;      // Minutes parked

public:
    // Default constructor
    ParkedCar()
    {
        make = "";
        model = "";
        color = "";
        licenseNumber = "";
        minutesParked = 0;
    }

    // Constructor
    ParkedCar(string mk, string md, string c, string lic, int m)
    {
        make = mk;
        model = md;
        color = c;
        licenseNumber = lic;
        minutesParked = m;
    }

    // Destructor
    ~ParkedCar();

    // Copy constructor
    ParkedCar(const ParkedCar &other)
    {
        make = other.make;
        model = other.model;
        color = other.color;
        licenseNumber = other.licenseNumber;
        minutesParked = other.minutesParked;
    }

    // Mutators
    void setMake(string m) {make = m;}

    // Accessors
    string getMake() const {return make;}

    // Overloaded Operators
    const 

    // Print function
    void print();
};

// FeetInches assignment with overload applications
    // FeetInches class and main implement overloads and conversions 
class FeetInches
{
    private:
        int feet;   // To hold a number of feet
        int inches; // To hold a number of inches
        void simplify(); // Defined in FeetInches.cpp

    public:
        // Constructor
        FeetInches(int f = 0, int i = 0)
        {
            feet = f;
            inches = i;
            simplify();
        }

        // Add a copy constructor to the FeetInches class. This constructor should accept 
        // a FeetInches object as an argument. The constructor should assign to the feet 
        // attribute the value in the argument’s feet attribute, and assign to the inches 
        // attribute the value in the argument’s inches attribute. As a result, the new 
        // object will be a copy of the argument object.
        // FeetInches(const FeetInches &obj); 
        
        FeetInches(const FeetInches &right)
        {
            feet = right.feet;
            inches = right.inches;
        }

        // Next, add a multiply member function to the FeetInches class. The multiply 
        // function should accept a FeetInches object as an argument. The argument 
        // object’s feet and inches attributes will be multiplied by the calling 
        // object’s feet and inches attributes, and a FeetInches object containing 
        // the result will be returned.
        FeetInches multiply(const FeetInches &obj)
        {
            FeetInches result;
            result.feet = feet * obj.feet;
            result.inches = inches * obj.inches;
            // result.simplify(); // optional per your assignment
            return result;
        }

        // Mutators
        void setFeet(int f) { feet = f; }
        void setInches(int i) { inches = i; simplify(); }

        // Accessors
        int getFeet() const { return feet; }
        int getInches() const { return inches; }

        // Overloaded operator functions
        FeetInches operator+(const FeetInches &right)
        {
            FeetInches temp;
            temp.inches = inches + right.inches;
            temp.feet = feet + right.feet;
            temp.simplify();
            return temp;
        }
        FeetInches operator-(const FeetInches &right)
        {
            FeetInches temp;
            temp.inches = inches - right.inches;
            temp.feet = feet - right.feet;
            temp.simplify();
            return temp;
        }
        FeetInches &operator++() {++inches; simplify(); return *this;}
        FeetInches operator++(int) 
        {
            FeetInches temp(feet, inches);
            inches++;
            simplify();
            return temp;
        }
        bool operator>(const FeetInches &right)
        {
            bool status;

            if (feet > right.feet)
                status = true;
            else if (feet == right.feet && inches > right.inches)
                status = true;
            else
                status = false;

            return status;
        }
        bool operator<(const FeetInches &right)
        {
            bool status;

            if (feet < right.feet)
                status = true;
            else if (feet == right.feet && inches < right.inches)
                status = true;
            else
                status = false;

            return status;
        }
        bool operator==(const FeetInches &right)
        {
            bool status;

            if (feet == right.feet && inches == right.inches)
                status = true;
            else
                status = false;

            return status;
        }
        // friend keyword needed as .cpp implementation accesses private
        // attributes and functions without getters
        friend ostream &operator<<(ostream &, const FeetInches &);
        friend istream &operator>>(istream &, FeetInches &);

        // Conversions
        operator double() const;
        operator int() const;
};
class RoomDimension
{
    private:
        FeetInches length;   // The length of the room
        FeetInches width;    // The width of the room
        FeetInches area;     // The room's area

    public:
        // Default constructor
        RoomDimension()
        {
        }

        // Constructor
        RoomDimension(FeetInches len, FeetInches w)
        {
            length = len;
            width = w;
            area = len.multiply(w);
        }

        // Copy constructor
        RoomDimension(const RoomDimension &obj)
        {
            length = obj.length;
            width = obj.width;
            area = obj.area;
        }

        // getArea function (returns FeetInches object)
        FeetInches getArea()
        {
            return area;
        }

        // getAreaInFeet function (returns numeric total feet)
        double getAreaInFeet()
        {
            double totalFeet = area.getFeet() + (area.getInches() / 12.0);
            return totalFeet;
        }
};
class RoomCarpet
{
    private:
        RoomDimension dimensions;   // The room dimensions
        double cost;                // Cost per square foot

    public:
        // Constructor
        RoomCarpet(RoomDimension rd, double c)
        {
            dimensions = rd;
            cost = c;
        }

        // getTotalCost function
        double getTotalCost()
        {
            double area = dimensions.getAreaInFeet();
            return area * cost;
        }
};
// Implementation
void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}
ostream &operator<<(ostream &out, const FeetInches &x)
{
    out << x.feet << " feet, " << x.inches << " inches";
    return out;
}
istream &operator>>(istream &in, FeetInches &x)
{
    // cout << "Enter feet: ";
    in >> x.feet;
    // cout << "Enter inches: ";
    in >> x.inches;
    x.simplify();
    return in;
}
FeetInches::operator double() const
{
    return feet + inches / 12.0;   // total feet as a double
}
FeetInches::operator int() const
{
    return feet * 12 + inches;     // total inches as an int (common choice)
}
int main()
{
    // Declare variables:
    FeetInches length, width;
    double costPerFoot;

    // Get the room's length.
    cout << "Enter the length in two integers separated by a space (feet inches): ";
    cin >> length;
    cout << length << endl;
   
    // The the room's width.
    cout << "Enter the width in two integers separated by a space (feet inches): ";
    cin >> width;
    cout << width << endl << endl;

    // Calculate cost for a room.
    cout << "What is the cost of the carpet per foot?: $";
    cin >> costPerFoot;
    cout << endl;
    RoomDimension room1(length, width);
    RoomCarpet carpet1(room1, costPerFoot);

    // Display cost
    cout << fixed << setprecision(2);
    cout << "The total cost of the carpet is: $" << carpet1.getTotalCost() << endl;
    
    // Show off copy constructor
    RoomDimension room2 = room1;

    return 0;
}

// Derived class constructor / destructor basics
class BaseClass
{
    public:
        // Constructor
        BaseClass()
        {
            cout << "This is the BaseClass constructor.\n";
        }

        // Destructor
        ~BaseClass()
        {
            cout << "This is the BaseClass destructor.\n";
        }
};
class DerivedClass : public BaseClass
{
    public:
        // Constructor
        DerivedClass()
        {
            cout << "This is the DerivedClass constructor.\n";
        }

        // Destructor
        ~DerivedClass()
        {
            cout << "This is the DerivedClass destructor.\n";
        }
};
int main()
{
    cout << "We will now define a DerivedClass object.\n";

    DerivedClass object;

    cout << "The program is now going to end.\n";

    return 0;
}

// Overloaded copy operator, destructor
class StudentTestScores
{
    const int DEFAULT_SCORE = 0;
    private:
        string studentName;  // The student's name
        double *testScores;  // Points to array of test scores
        int numTestScores;   // Number of test scores

        // Private member function to create an
        // array of test scores.
        void createTestScoresArray(int size)
        { 
            numTestScores = size;
            testScores = new double[size]; 
            for (int i = 0; i < size; i++)
                testScores[i] = DEFAULT_SCORE; 
        }
        
    public:
        // Constructor
        StudentTestScores(string name, int numScores)
        { 
            studentName = name;
            createTestScoresArray(numScores); 
        }
            
        // Copy constructor
        StudentTestScores(const StudentTestScores &obj)
        { studentName = obj.studentName;
            numTestScores = obj. numTestScores;
            testScores = new double[numTestScores];
            for (int i = 0; i < numTestScores; i++)
                testScores[i] = obj.testScores[i]; }

            // Destructor
        ~StudentTestScores()
        { delete [] testScores; }

            // The setTestScore function sets a specific
            // test score's value.
        void setTestScore(double score, int index)
        { testScores[index] = score; }

            // Set the student's name.
        void setStudentName(string name)
        { studentName = name; }

            // Get the student's name.
        string getStudentName() const
        { return studentName; }
        
        // Get the number of test scores.
        int getNumTestScores()
        { return numTestScores; }

            // Get a specific test score.
        double getTestScore(int index) const
        { return testScores[index]; }

        // Overloaded = operator
        StudentTestScores operator=(const StudentTestScores &right)
        {
            if (this != &right)
            {
                delete[] testScores;
                studentName = right.studentName;
                numTestScores = right.numTestScores;
                testScores = new double[numTestScores];
                for (int i = 0; i < numTestScores; i++)
                    testScores[i] = right.testScores[i];
            }
            return *this;
        }
};

// Using this pointer in constructor
class Person {
    private:
        std::string name;
        int age;

    public:
        Person(const std::string& name, int age) 
        {
            this->name = name;
            this->age = age;
        }

        void displayInfo() 
        {
            std::cout << "Name: " << this->name << std::endl;
            std::cout << "Age: " << this->age << std::endl;
        }

        void updateAge(int newAge) 
        {
            this->age = newAge;
        }
};

// Using class reference and this to modify class object
class Student2 
{
    private:
        string name;
        int age;

    public:

        // Constructor with parameters having the same name
        Student2(string name, int age) {
            
            // 'this' is used to distinguish between class members and constructor parameters
            this->name = name;
            this->age = age;
        }

        // Member function using 'this'
        void introduce() {
            cout << "Hi, I am " << this->name
                << " and I am " << this->age << " years old." << endl;
        }

        // Returning current object using 'this'
        Student2& olderBy(int years) {
            this->age += years;  
            return *this;        
        }
};
// Implementation
int student_implementation() 
{
    Student2 s("Alice", 20);

    // Display initial introduction
    s.introduce();

    // Increase age and reintroduce
    s.olderBy(2).introduce();

    return 0;
}

// Aggregatation
    // Making an instance of one class an attribute of another class is called 
    //object aggregation. 
class Instructor
{
private:
    string lastName;      // Last name
    string firstName;     // First name
    string officeNumber;  // Office number

public:
    // Default constructor
    Instructor()
    {
        set("", "", "");
    }

    // Constructor
    Instructor(string lname, string fname, string office)
    {
        set(lname, fname, office);
    }

    // Set function
    void set(string lname, string fname, string office)
    {
        lastName = lname;
        firstName = fname;
        officeNumber = office;
    }

    // Print function
    void print() const
    {
        cout << "Last name: " << lastName << endl;
        cout << "First name: " << firstName << endl;
        cout << "Office number: " << officeNumber << endl;
    }
};
class TextBook
{
private:
    string title;       // Book title
    string author;      // Author name
    string publisher;   // Publisher name

public:
    // Default constructor
    TextBook()
    {
        set("", "", "");
    }

    // Constructor
    TextBook(string textTitle, string auth, string pub)
    {
        set(textTitle, auth, pub);
    }

    // Set function
    void set(string textTitle, string auth, string pub)
    {
        title = textTitle;
        author = auth;
        publisher = pub;
    }

    // Print function
    void print() const
    {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Publisher: " << publisher << endl;
    }
};
class Course
{
private:
    string courseName;        // Course name
    Instructor instructor;   // Instructor
    TextBook textbook;       // Textbook

public:
    // Constructor
    Course(string course,
           string instrLastName,
           string instrFirstName,
           string instrOffice,
           string textTitle,
           string author,
           string publisher)
    {
        courseName = course;

        instructor.set(instrLastName, instrFirstName, instrOffice);
        textbook.set(textTitle, author, publisher);
    }

    // Print function
    void print() const
    {
        cout << "Course name: " << courseName << endl << endl;

        cout << "Instructor Information:\n";
        instructor.print();

        cout << "\nTextbook Information:\n";
        textbook.print();

        cout << endl;
    }
};
int main()
{
    Course myCourse(
        "Intro to Computer Science",   // Course name
        "Kramer", "Shawn", "RH3010",    // Instructor info
        "Starting Out with C++",        // Textbook title
        "Gaddis",                       // Author
        "Pearson"                      // Publisher
    );

    myCourse.print();

    return 0;
}

// Move constructor and operator
class Person {
    private:
        char* name;

    public:
        // Default / converting constructor
        Person(const char* n = "") : name(new char[strlen(n) + 1]) {
            strcpy(name, n);
        }

        // Destructor
        ~Person() { delete[] name; }

        // Copy constructor (deep copy)
        Person(const Person& other) : name(new char[strlen(other.name) + 1]) {
            strcpy(name, other.name);
        }

        // Move constructor (steal pointer)
        Person(Person&& other) : name(other.name) {
            other.name = nullptr;
        }

        // Copy assignment (deep copy; handle self-assign; free old)
        Person& operator=(const Person& right) {
            if (this != &right) {
                char* newMem = new char[strlen(right.name) + 1];
                strcpy(newMem, right.name);
                delete[] name;
                name = newMem;
            }
            return *this;
        }

        // Move assignment (steal pointer; free old; leave source safe)
        Person& operator=(Person&& right) {
            if (this != &right) {
                delete[] name;          // release current resource
                name = right.name;      // steal
                right.name = nullptr;   // make safe
            }
            return *this;
        }

        const char* getName() const { return (name ? name : ""); }
};
Person makePerson() {
    Person p("Will MacKenzie");
    return p; // may elide; otherwise move
}
int main() {
    Person a("Alice");
    Person b("Bob");

    Person c = a;          // copy constructor
    Person d = makePerson(); // move constructor

    b = a;                 // copy assignment
    b = makePerson();      // move assignment (RHS is temporary)

    cout << a.getName() << "\n";
    cout << b.getName() << "\n";
    cout << c.getName() << "\n";
    cout << d.getName() << "\n";
}

class MyBase
{
private:
    int ival{};
    double dval{};

public:
    MyBase(int i) : ival(i) {}
    MyBase(double d) : dval(d) {}

    void print() const
    {
        cout << "ival = " << ival << ", dval = " << dval << '\n';
    }
};

// Inheriting classes with USING keyword
class MyDerived : public MyBase
{
public:
    using MyBase::MyBase;  // inherit MyBase's constructors
};
int main()
{
    MyDerived d1(22);     // calls MyBase(int)
    MyDerived d2(3.14);   // calls MyBase(double)

    d1.print();
    d2.print();

    return 0;
}

// Using virtual functions & calling Base class constructors for Derived class 
    // constructors, Base class pointer
class GradedActivity
{
    protected:
        char letter;        // To hold the letter grade
        double score;       // To hold the numeric score
        void determineGrade()
        {
            if (score < 60) {letter = 'F';}
            else if (score >= 60 && score < 70) {letter = 'D';}
            else if (score >= 70 && score < 80) {letter = 'C';}
            else if (score >= 80 && score < 90) {letter = 'B';}
            else letter = 'A';
        }
    public:
        // Default constructor
        GradedActivity() : score(0.0) {}
        // GradedActivity() {score = 0.0;}

        // Constructor
        GradedActivity(double s) {score = s; determineGrade();}

        // Mutator functions
        void setScore(double s) {score = s; determineGrade();}

        // Accessor functions
        double getScore() const {return score;}

        //**** Declared as virtual now! ****//
        virtual char getLetterGrade() const {return letter;}
};
class PassFailActivity : public GradedActivity
{
protected:
    double minPassingScore;   // Minimum passing score
public:
    // Default constructor
    PassFailActivity() : GradedActivity()
    { minPassingScore = 0.0; }

    // Constructor
    PassFailActivity(double mps) : GradedActivity()
    { minPassingScore = mps; }

    // Mutator
    void setMinPassingScore(double mps)
    { minPassingScore = mps; }

    // Accessors
    double getMinPassingScore() const
    { return minPassingScore; }

    char getLetterGrade() const;
};
char PassFailActivity::getLetterGrade() const
{
    char letterGrade;

    if (score >= minPassingScore)
        letterGrade = 'P';
    else
        letterGrade = 'F';

    return letterGrade;
}
class PassFailExam : public PassFailActivity
{
private:
    int numQuestions;     // Number of questions
    double pointsEach;    // Points for each question
    int numMissed;        // Number of questions missed

public:
    // Default constructor
    PassFailExam() : PassFailActivity()
    { 
        numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0;
    }

    // Constructor
    PassFailExam(int questions, int missed, double mps) : PassFailActivity(mps)
    { 
        set(questions, missed); 
    }

    // Mutator function
    void set(int, int);    // Defined in PassFailExam.cpp

    // Accessor functions
    double getNumQuestions() const
    { return numQuestions; }

    double getPointsEach() const
    { return pointsEach; }

    int getNumMissed() const
    { return numMissed; }
};
void PassFailExam::set(int questions, int missed)
{
    double numericScore;  // To hold the numeric score

    // Set the number of questions and number missed.
    numQuestions = questions;
    numMissed = missed;

    // Calculate the points for each question.
    pointsEach = 100.0 / numQuestions;

    // Calculate the numeric score for this exam.
    numericScore = 100.0 - (missed * pointsEach);

    // Call the inherited setScore function to set the numeric score.
    setScore(numericScore);
}
void displayGrade(const GradedActivity &);
int main()
{
    // Create a GradedActivity object. The score is 88.
    GradedActivity test1(88.0);

    // Create a PassFailExam object. There are 100 questions,
    // the student missed 25 of them, and the minimum passing
    // score is 70.
    PassFailExam test2(100, 25, 70.0);

    // Display the grade data for both objects.
    cout << "Test 1:\n";
    displayGrade(test1);     // GradedActivity object
    cout << "\nTest 2:\n";
    displayGrade(test2);     // PassFailExam object

    return 0;
}
void displayGrade(const GradedActivity &activity)
{
    cout << setprecision(1) << fixed;
    cout << "The activity's numeric score is "
         << activity.getScore() << endl;
    cout << "The activity's letter grade is "
         << activity.getLetterGrade() << endl;
}

// Using classes from above
// Uses GradedActivity* pointer
int main()
{
    // Constant for the size of an array.
    const int NUM_TESTS = 4;

    // tests is an array of GradedActivity pointers.
    // Each element of tests is initialized with the
    // address of a dynamically allocated object.
    GradedActivity* tests[NUM_TESTS] =
    {
        new GradedActivity(88.0),
        new PassFailExam(100, 25, 70.0),
        new GradedActivity(67.0),
        new PassFailExam(50, 12, 60.0)
    };

    // Display the grade data for each element in the array.
    for (int count = 0; count < NUM_TESTS; count++)
    {
        cout << "Test #" << (count + 1) << ":\n";
        displayGrade(tests[count]);
        cout << endl;
    }

    return 0;
}
void displayGrade(const GradedActivity* activity)
{
    cout << setprecision(1) << fixed;
    cout << "The activity's numeric score is "
         << activity->getScore() << endl;
    cout << "The activity's letter grade is "
         << activity->getLetterGrade() << endl;
}

// Base class pointer array, virtual destructors, override keyword
class Ship
{
    protected:
        string name;
        int year;
    public:
        // Constructor - one for simplicity
        Ship() : name("Default"), year(9999) {};

        // Destructor
        virtual ~Ship() = default;

        // Mutators / Setters
        void set_name(string n) {name = n;} 
        void set_year(int y) {year = y;}

        // Accessors / Getters - const to ensure no changes to private members
        string get_name() const {return name;}
        int get_year() const {return year;}

        // Virtual print function
        virtual void display_ship() const
        {
            cout << "Ship Details" << endl;
            cout << "------------" << endl;
            cout << "Name: " << get_name() << endl;
            cout << "Year: " << get_year() << endl << endl;
        }
};
class Cruise_Ship : public Ship
{
    private:
        int max_pass;
    public:
        // Constructor - one for simplicity. 
            // Initialize with Ship constructor in part
        Cruise_Ship() : Ship(), max_pass(0) {};

        // Use this default constructor if above code fails "Contents of Box.h":
        // Cruise_Ship() : Ship() {max_pass = 0;};

        // Mutators / Setters
        void set_max_pass(int c) {max_pass = c;} 

        // Accessors / Getters - const to ensure no changes to private members
        int get_max_pass() const {return max_pass;}

        // Virtual print function
        void display_ship() const override final
        {
            cout << "Cruise Ship Details" << endl;
            cout << "-------------------" << endl;
            cout << "Name: " << Ship::get_name() << endl;
            cout << "Passengers Limit: " << get_max_pass() << endl << endl;
        }
};
class Cargo_Ship : public Ship
{
    private:
        double capacity;
    public:
        // Constructor - one for simplicity. 
            // Initialize with Ship constructor in part
        Cargo_Ship() : Ship(), capacity(0.0) {};

        // Use this default constructor if above code fails "Contents of Box.h":
        // Cargo_Ship() : Ship() {capacity = 0;};

        // Mutators / Setters
        void set_capacity(double c) {capacity = c;} 

        // Accessors / Getters - const to ensure no changes to private members
        double get_capacity() const {return capacity;}

        // Virtual print function
        void display_ship() const override final
        {
            cout << fixed << setprecision(2);
            cout << "Cargo Ship Details" << endl;
            cout << "------------------" << endl;
            cout << "Name: " << Ship::get_name() << endl;
            cout << "Cargo Capacity: " << get_capacity() << endl << endl;
        }
};
int main()
{
    const int NUM_SHIPS = 3;

    Ship* ships[NUM_SHIPS] = 
        {
            new Ship(),
            new Cruise_Ship(),
            new Cargo_Ship()
        };

    for(int i = 0; i < NUM_SHIPS; ++i)
    {
        // Method 1
        ships[i]->display_ship();
        // Method 2
        (*ships[i]).display_ship();
    }

    // Release dynamic memory
    for (int i = 0; i < NUM_SHIPS; ++i) {delete ships[i];}

    return 0;
}

class Student
{
protected:
    string name;        // Student name
    string idNumber;    // Student ID
    int yearAdmitted;   // Year student was admitted

public:
    // Default constructor
    Student()
    {
        name = "";
        idNumber = "";
        yearAdmitted = 0;
    }

    // Constructor
    Student(string n, string id, int year)
    {
        set(n, id, year);
    }

    // The set function sets the attribute data.
    void set(string n, string id, int year)
    {
        name = n;            // Assign the name
        idNumber = id;       // Assign the ID number
        yearAdmitted = year; // Assign the year admitted
    }

    // Accessor functions
    const string getName() const
    {
        return name;
    }

    const string getIdNum() const
    {
        return idNumber;
    }

    int getYearAdmitted() const
    {
        return yearAdmitted;
    }

    // Pure virtual function
    virtual int getRemainingHours() const = 0;
};
class CsStudent : public Student
{
// Constants for required hours
const int MATH_HOURS   = 20;  // Math hours
const int CS_HOURS     = 40;  // Computer science hours
const int GEN_ED_HOURS = 60;  // General Ed hours

private:
    int mathHours;   // Hours of math taken
    int csHours;     // Hours of Computer Science taken
    int genEdHours;  // Hours of general education taken

public:
    // Default constructor
    CsStudent() : Student()
    {
        mathHours = 0;
        csHours = 0;
        genEdHours = 0;
    }

    // Constructor
    CsStudent(string n, string id, int year) : Student(n, id, year)
    {
        mathHours = 0;
        csHours = 0;
        genEdHours = 0;
    }

    // Mutator functions
    void setMathHours(int mh)
    {
        mathHours = mh;
    }

    void setCsHours(int csh)
    {
        csHours = csh;
    }

    void setGenEdHours(int geh)
    {
        genEdHours = geh;
    }

    // Overridden getRemainingHours function
    virtual int getRemainingHours() const
    {
        int reqHours, remainingHours;

        // Calculate the required hours.
        reqHours = MATH_HOURS + CS_HOURS + GEN_ED_HOURS;

        // Calculate the remaining hours.
        remainingHours = reqHours - (mathHours + csHours + genEdHours);

        // Return the remaining hours.
        return remainingHours;
    }
};
int main()
{
    // Create a CsStudent object for a student.
    CsStudent student("Jennifer Haynes", "167W98337", 2006);

    // Store values for Math, Computer Science, and General Ed hours.
    student.setMathHours(12);     // Student has taken 12 Math hours
    student.setCsHours(20);       // Student has taken 20 CS hours
    student.setGenEdHours(40);    // Student has taken 40 Gen Ed hours

    // Display the number of remaining hours.
    cout << "The student " << student.getName()
         << "\nneeds to take " << student.getRemainingHours()
         << " more hours to graduate.\n";

    return 0;
}

// Template functions, operations in Derived class before Base function called 
class Bank_Account
{
    protected:
        double balance;
        double beg_bal;
        int num_dep;
        int num_with;
        double int_rate;
        double month_charge;
        double month_charge_cpy;
    public:
        // Relying on compiler to furnish default constructor
        // Decided to make default constructor to demonstrate passing arguments
            // to base constructor
        Bank_Account() : balance(0.0), beg_bal(0.0), num_dep(0), num_with(0), 
            int_rate(0.12), month_charge(0.0), month_charge_cpy(0.0) {;}

        // Overloaded constructor - allowing default initialization for other vars
        Bank_Account(double b) : balance(b), beg_bal(b), num_dep(0), num_with(0), 
            int_rate(0.12), month_charge(0.0), month_charge_cpy(0.0) {;}

        // Virtual destructor
        virtual ~Bank_Account() {};

        // Helper function
        // Display balance after withdraws and deposits
        void display_bal()
        {
            cout << fixed << setprecision(2);
            cout << "Current balance: $" << balance << endl;
        }

        virtual void deposit(double d)
        {
            balance += d;
            num_dep++;
            display_bal();
        }

        virtual void withdraw(double w)
        {
            balance -= w;
            num_with++;
            display_bal();
        }

        virtual void calcInt()
        {
            // Declare variables
            double month_rate;
            double month_int;

            // Monthly Interest Rate = (Annual Interest Rate / 12
            // Monthly Interest = Balance * Monthly Interest Rate
            // Balance = Balance + Monthly Interest
            balance += balance * (int_rate / 12);
        }

        virtual void monthlyProc()
        {
            balance -= month_charge;
            month_charge_cpy = month_charge;

            // Calculate interest accrued after service charges applied
            // Only do so if the account has money, don't want to compound 
            // negative money!
            if(balance >= 0) {calcInt();}

            // Reset vars to zero
            num_dep = 0;
            num_with = 0;
            month_charge = 0.0;
        }

        // Setters
        void set_beg_bal(double b) {beg_bal = b;}

        // Getters
        double get_balance() const {return balance;}
        double get_beg_bal() const {return beg_bal;}
        int get_num_dep() const {return num_dep;}
        int get_num_with() const {return num_with;}
        double get_month_charge_cpy() const {return month_charge_cpy;}
};
class Checking_Account : public Bank_Account
{
    public:
        // Default constructor
        Checking_Account() : Bank_Account() {;}

        // Overloaded constructor
        Checking_Account(double b) : Bank_Account(b) {;}
       
        // Helper function to check if amount goes below zero.
        bool check_sub_zero(double w)
        {
            double copy_bal = balance - w;

            if (copy_bal < 0) {return true;} // Withdrawal will knock balance below zero
            else {return false;} // Still more than $0.00 in account post withdrawal
        }

        // Before the base class function is called, this function will determine if a
        // withdrawal (a check written) will cause the balance to go below $O. If
        // the balance goes below $0, a service charge of $15 will be taken from
        // the account. (The withdrawal will not be made.) If there isn't enough
        // in the account to pay the service charge, the balance will become nega-
        // tive and the customer will owe the negative amount to the bank.
        void withdraw(double w)
        {
            if(check_sub_zero(w) == true) 
            {
                balance -= 15.00;

                cout << "Not enough funds for withdrawal. A $15.00 service ";
                cout << "charge has been processed and deducted from your account ";
                cout << "balance." << endl;

                cout << fixed << setprecision(2);
                cout << "Current balance: $" << balance;
            }
            else if(check_sub_zero(w) == false) // Could have said else, but felt this is more readable
            {
                Bank_Account::withdraw(w);
            }
        }

        // monthlyProc: Before the base class function is called, this function adds the monthly
        // fee of $5 plus $0.10 per withdrawal (check written) to the base class
        // variable that holds the monthly service charges.
        void monthlyProc()
        {
            Bank_Account::month_charge += 5+0.10*num_with;
            Bank_Account::monthlyProc();
        }

};
class Savings_Account : public Bank_Account
{
    private:
        bool status;
    public:
        // Default constructor
        Savings_Account() : Bank_Account(), status(false) {;}

        // Overloaded constructor
        Savings_Account(double b) : Bank_Account(b), status(false) {;}

        // Helper function to check balance
        bool check_status()
        {
            if (balance >= 25.00) {status = true;} // account active
            else {status = false;} // simple else, no validation

            return status;
        }

        void withdraw(double w)
        {
            if(status == false) 
            {
                cout << "Account inactive: Less than $25.00 in account. Please ";
                cout << "deposit more funds to meet or exceed this amount." << endl;
            }
            else if(status == true) // Could have said else, but felt this is more readable
            {
                Bank_Account::withdraw(w);
            }
        }

        void deposit(double d)
        {
            // Assign account status to var before deposit
            bool status_copy = status;

            Bank_Account::deposit(d);
            check_status();
            
            // Message regarding account status
            if(status_copy == true) {;} // Account was active before deposit
            else if(status_copy == false && status == false) // still deactivated
            {
                cout << "Account inactive: Less than $25.00 in account. Please ";
                cout << "deposit more funds to meet or exceed this amount." << endl;
            }
            else if((status_copy == false && status == false)) // reactivated
            {
                cout << "Account reactivated: $25.00 amount threshold met." << endl;
            }
        }

        void monthlyProc()
        {
            if(num_with > 4)
            {
                // Add additional charge if withdrawals exceed 4 in a month
                month_charge += num_with - 4;
            }
            // Run the monthlyProc() Base class function
            Bank_Account::monthlyProc();
            // See if additional charge knocked balance below $25.00.
            check_status();
        }
};
    // Function prototypes
template <class T> 
T get_num(T, T); // for both menu options and dollar amounts
void display_menu_1();
void display_menu_2();
void account_trans(Bank_Account*);
void display_summary(int*, bool*, bool*, Bank_Account*, Bank_Account*);
int main()
{
    // Declare variables
    Savings_Account sa; // Will initialize later
    Checking_Account ca; // Will initialize later
    int menu_choice_1 = 0;
    bool savings_init = false;
    bool checking_init = false;
    int month = 1;
    double bal = 0.0;
    double bal_init = 0.0;

    // Initial message:
    cout << "Welcome to BLinK Bank. Please enter the corresponding number to select ";
    cout << "an option.\nPlease see an agent or call the bank if you have technical ";
    cout << "difficulties." << endl;

    // Menu logic: Initialize Accounts
    do
    {
        display_menu_1();
        cout << "Menu selection: ";
        menu_choice_1 = get_num(1, 6);

        // Initialize savings account
        if(menu_choice_1 == 1 && savings_init == false)
        {
            cout << "Please enter balance to be transferred to Savings Account: $";
            bal_init = get_num(0.0, numeric_limits<double>::max());
            sa = Savings_Account(bal_init);
            savings_init = true;
        }
        else if(menu_choice_1 == 1 && savings_init == true)
        {
            cout << "Savings Account already created, please select other options.";
            cout << endl;
        }

         // Initialize checking account
        else if(menu_choice_1 == 2 && checking_init == false)
        {
            cout << "Please enter balance to be transferred to Checking Account: $";
            bal_init = get_num(0.0, numeric_limits<double>::max());
            ca = Checking_Account(bal_init);
            checking_init = true;
        }
        else if(menu_choice_1 == 2 && checking_init == true)
        {
            cout << "Checking Account already created, please select other options.";
            cout << endl;
        }

        // If options 3 or 4 picked, execute a transaction:
        else if(menu_choice_1 == 3 && savings_init == true) {account_trans(&sa);}
        else if(menu_choice_1 == 3 && savings_init == false) 
        {
            cout << "No Savings Account found." << endl;
        }

        else if(menu_choice_1 == 4 && checking_init == true) {account_trans(&ca);}
        else if(menu_choice_1 == 4 && checking_init == false) 
        {
            cout << "No Checking Account found." << endl;
        }

        else if(menu_choice_1 == 5)
        {
            display_summary(&month, &savings_init, &checking_init, &sa, &ca);
        }

    }while(menu_choice_1 != 6);

    cout << "Thank you for using our online services. Have a nice day!" << endl;

    return 0;
}
template <class T>
T get_num(T a, T b)
{
    T choice;

    while (true)
    {
        // Multiple error checks:
            // If input stream doesn't error out (accept input each time)
            // If the next character in the input buffer is the newline char
                // after the number is read
            // If the menu choice is in the correct range
        if (cin >> choice && cin.peek() == '\n' && (choice >= a && choice <= b))
        {
            return choice;
        }
        cout << "Invalid menu selection. Try again: ";
        cin.clear();
        // Ignore all unanticipated input for the maximum stream size or until
        // the new line char is enountered
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
void display_menu_1()
{
    cout << endl;
    cout << "[1] Open Savings Account" << endl;
    cout << "[2] Open Checking Account" << endl;
    cout << "[3] Make a transaction with Savings Account" << endl;
    cout << "[4] Make a transaction with Checking Account" << endl;
    cout << "[5] Retrieve current monthly statement of accounts" << endl;
    cout << "[6] Exit";
    cout << endl;
}
void display_menu_2()
{
    cout << endl;
    cout << "Transaction Menu:" << endl;
    cout << "[1] Deposit funds" << endl;
    cout << "[2] Withdraw funds" << endl;
    cout << "[3] Exit" << endl;
}
void account_trans(Bank_Account* ba)
{
    int menu_choice_2 = 0;
    double money = 0.0;
    do
    {
        display_menu_2();
        cout << "Menu selection: ";
        menu_choice_2 = get_num(1, 3);

        if(menu_choice_2 == 1) 
        {
            cout << "Please enter dollar amount to be deposited: $";
            money = get_num(0.0, numeric_limits<double>::max());
            ba->deposit(money);
            cout << endl;
        }
        else if(menu_choice_2 == 2) 
        {
            cout << "Please enter dollar amount to be withdrawn: $";
            money = get_num(0.0, numeric_limits<double>::max());
            ba->withdraw(money);
            cout << endl;
        }

    }while(menu_choice_2 != 3);
}
void display_summary(int* m, bool* s, bool* c, Bank_Account* sa, Bank_Account* ca)
{
    cout << "\nMonth " << *m << " Account(s) Summary:" << endl;

    if(*s == true)
    {
        cout << "----------------------------------\n";
        cout << "SAVINGS ACCOUNT" << endl;
        cout << "----------------------------------\n";
        cout << "Beginning balance: $" << sa->get_beg_bal() << endl;
        cout << "Total Deposits: " << sa->get_num_dep() << endl;
        cout << "Total Withdrawals: " << sa->get_num_with() << endl;

        // Process service charges and compute final balance
        sa->monthlyProc();

        cout << "Service Charges: $" << sa->get_month_charge_cpy() << endl;
        cout << "Final Balance: $" << sa->get_balance() << endl;

        sa->set_beg_bal(sa->get_balance());
    }

    if(*c == true)
    {
        cout << "----------------------------------\n";
        cout << "CHECKING ACCOUNT" << endl;
        cout << "----------------------------------\n";
        cout << "Beginning balance: $" << ca->get_beg_bal() << endl;
        cout << "Total Deposits: " << ca->get_num_dep() << endl;
        cout << "Total Withdrawals: " << ca->get_num_with() << endl;

        // Process service charges and compute final balance
        ca->monthlyProc();

        cout << "Service Charges: $" << ca->get_month_charge_cpy() << endl;
        cout << "Final Balance: $" << ca->get_balance() << endl;

        ca->set_beg_bal(ca->get_balance());
    }

    *m += 1;
}

// Template class with error checking, overloaded [] operator
template <class T>
class SimpleVector
{
private:
    T* aptr;
    int arraySize;

    void memError()
    {
        cout << "ERROR: Cannot allocate memory.\n";
        exit(EXIT_FAILURE);
    }

    void subError()
    {
        cout << "ERROR: Subscript out of range.\n";
        exit(EXIT_FAILURE);
    }

public:
    // Default constructor
    SimpleVector() : aptr(nullptr), arraySize(0) {}

    // Constructor
    SimpleVector(int s) : aptr(nullptr), arraySize(s)
    {
        try
        {
            aptr = new T[arraySize];
        }
        catch (bad_alloc)
        {
            memError();
        }

        // Initialize the array (assumes T can be assigned 0, as in the book example)
        for (int count = 0; count < arraySize; ++count)
            aptr[count] = 0;
    }

    // Copy constructor
    SimpleVector(const SimpleVector& obj) : aptr(nullptr), arraySize(obj.arraySize)
    {
        try
        {
            aptr = new T[arraySize];
        }
        catch (bad_alloc)
        {
            memError();
        }

        for (int count = 0; count < arraySize; ++count)
            aptr[count] = obj.aptr[count];
    }

    // Destructor
    ~SimpleVector()
    {
        delete[] aptr; // delete[] is safe on nullptr
    }

    // Accessor to return the array size
    int size() const { return arraySize; }

    // Accessor to return a specific element (by value)
    T getElementAt(int sub)
    {
        if (sub < 0 || sub >= arraySize)
            subError();
        return aptr[sub];
    }

    // Overloaded [] operator (returns reference so you can assign/increment)
    T& operator[](const int& sub)
    {
        if (sub < 0 || sub >= arraySize)
            subError();
        return aptr[sub];
    }
};
int main()
{
    const int SIZE = 10;   // Number of elements
    int count;             // Loop counter

    // Create a SimpleVector of ints.
    SimpleVector<int> intTable(SIZE);

    // Create a SimpleVector of doubles.
    SimpleVector<double> doubleTable(SIZE);

    // Store values in the two SimpleVectors.
    for (count = 0; count < SIZE; count++)
    {
        intTable[count] = (count * 2);
        doubleTable[count] = (count * 2.14);
    }

    // Display the values in the SimpleVectors.
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;

    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    // Use the standard + operator on the elements.
    cout << "\nAdding 5 to each element of intTable and doubleTable.\n";
    for (count = 0; count < SIZE; count++)
    {
        intTable[count] = intTable[count] + 5;
        doubleTable[count] = doubleTable[count] + 5.0;
    }

    // Display the values in the SimpleVectors.
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;

    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    // Use the standard ++ operator on the elements.
    cout << "\nIncrementing each element of intTable and doubleTable.\n";
    for (count = 0; count < SIZE; count++)
    {
        intTable[count]++;
        doubleTable[count]++;
    }

    // Display the values in the SimpleVectors.
    cout << "These values are in intTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << intTable[count] << " ";
    cout << endl;

    cout << "These values are in doubleTable:\n";
    for (count = 0; count < SIZE; count++)
        cout << doubleTable[count] << " ";
    cout << endl;

    return 0;
}

// Throwing exception classes without catch
class Date
{
    private:
        int month = 0;
        int day = 0;
        int year = 0;
    public:
        // Exception classes to be called when error thrown.
        class InvalidDay {};
        class InvalidMonth {};

        // Setters
        void set_month(int m) 
        {
            if (m < 1 || m > 12) throw InvalidMonth();
            month = m;
        }

        void set_day(int d) 
        {
            if (d < 1 || d > 31) throw InvalidDay();
            day = d;
        }

        void set_year(int y) { year = y; }

        // Getters

        int get_day() const {return day;}
        int get_month() const {return month;}
        int get_year() const {return year;}
};
int main()
{
    Date date;
    int day = 0;
    int month = 0;
    int year = 0;

    cout << "Please enter the day: ";
    cin >> day;
    date.set_day(day);

    cout << "Please enter the month: ";
    cin >> month;
    date.set_month(month); 

    cout << "Please enter the year: ";
    cin >> year;
    date.set_year(year);

    // Final Date
    cout << date.get_month() << "/" << date.get_day() << "/" << date.get_year() << endl;

    return 0;
}

// Throwing exception with catch
int main()
{
    int num1, num2;      // To hold two numbers
    double quotient;    // To hold the quotient of the numbers

    // Get two numbers.
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Divide num1 by num2 and catch any
    // potential exceptions.
    try
    {
        quotient = divide(num1, num2);
        cout << "The quotient is " << quotient << endl;
    }
    catch (string exceptionString)
    {
        cout << exceptionString;
    }

    cout << "End of the program.\n";
    return 0;
}
double divide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        string exceptionString = "ERROR: Cannot divide by zero.\n";
        throw exceptionString;
    }

    return static_cast<double>(numerator) / denominator;
}

// Exception classes, exception class objects (simple)
class Rectangle
{
    private:
        double width;   // The rectangle's width
        double length;  // The rectangle's length

    public:
        // Exception class for a negative width
        class NegativeWidth
        {
        private:
            double value;
        public:
            NegativeWidth(double val) : value(val) {}
            double getValue() const { return value; }
        };

        // Exception class for a negative length
        class NegativeLength
        {
        private:
            double value;
        public:
            NegativeLength(double val) : value(val) {}
            double getValue() const { return value; }
        };

        // Default constructor
        Rectangle() : width(0.0), length(0.0) {}

        // Mutator functions (were in Rectangle.cpp)
        void setWidth(double w)
        {
            if (w >= 0)
                width = w;
            else
                throw NegativeWidth(w);
        }

        void setLength(double len)
        {
            if (len >= 0)
                length = len;
            else
                throw NegativeLength(len);
        }

        // Accessor functions
        double getWidth() const { return width; }
        double getLength() const { return length; }
        double getArea() const { return width * length; }
};
int main()
{
    double width;
    double length;

    // Create a Rectangle object.
    Rectangle myRectangle;

    // Get the width and length.
    cout << "Enter the rectangle's width: ";
    cin >> width;
    cout << "Enter the rectangle's length: ";
    cin >> length;

    // Store these values in the Rectangle object.
    try
    {
        myRectangle.setWidth(width);
        myRectangle.setLength(length);
        cout << "The area of the rectangle is "
             << myRectangle.getArea() << endl;
    }
    catch (Rectangle::NegativeWidth e)
    {
        cout << "Error: " << e.getValue()
             << " is an invalid value for the rectangle's width.\n";
    }
    catch (Rectangle::NegativeLength e)
    {
        cout << "Error: " << e.getValue()
             << " is an invalid value for the rectangle's length.\n";
    }

    cout << "End of the program.\n";
    return 0;
}

// Exception classes and main exception handling (complex)
class Date2
{
    private:
        int month;
        int day;
        int year;

        static bool isLeapYear(int y)
        {
            return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
        }

        static int daysInMonth(int m, int y)
        {
            switch (m)
            {
                case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
                case 4: case 6: case 9: case 11: return 30;
                case 2: return isLeapYear(y) ? 29 : 28;
                default: return 0;
            }
        }

    public:
        class InvalidMonth
        {
        public:
            int value;
            InvalidMonth(int m) : value(m) {}
            std::string what() const { return "Month must be 1-12."; }
        };

        class InvalidDay
        {
        public:
            int value, month, year;
            InvalidDay(int d, int m, int y) : value(d), month(m), year(y) {}
            std::string what() const { return "Day is out of range for that month/year."; }
        };

        Date2(int m = 1, int d = 1, int y = 2000) : month(1), day(1), year(2000)
        {
            setYear(y);
            setMonth(m);
            setDay(d);
        }

        void setYear(int y) { year = y; }

        void setMonth(int m)
        {
            if (m < 1 || m > 12)
                throw InvalidMonth(m);

            month = m;

            int dim = daysInMonth(month, year);
            if (day > dim)
                throw InvalidDay(day, month, year);
        }

        void setDay(int d)
        {
            int dim = daysInMonth(month, year);
            if (d < 1 || d > dim)
                throw InvalidDay(d, month, year);

            day = d;
        }

        int getYear()  const { return year; }
        int getMonth() const { return month; }
        int getDay()   const { return day; }
};
int main()
{
    Date2 dt; // default

    while (true)
    {
        try
        {
            int m, d, y;

            cout << "Enter date (MM DD YYYY): ";
            if (!(cin >> m >> d >> y))
                throw runtime_error("Input must be three integers.");

            dt.setYear(y);
            dt.setMonth(m);
            dt.setDay(d);

            cout << "Valid date: " << dt.getMonth() << "/"
                               << dt.getDay() << "/"
                               << dt.getYear() << "\n";
            break;
        }
        catch (const Date2::InvalidMonth &e)
        {
            cout << "Invalid month (" << e.value << "). " << e.what() << "\n";
        }
        catch (const Date2::InvalidDay &e)
        {
            cout << "Invalid day (" << e.value << ") for "
                 << e.month << "/" << e.year << ". " << e.what() << "\n";
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << "\n";
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Try again.\n\n";
    }

    return 0;
}

// Vector of class objects
class Product
{
    private:
        string name;
        int units;

    public:
        Product(string n, int u)
        {
            name = n;
            units = u;
        }

        void setName(string n)
        {
            name = n;
        }

        void setUnits(int u)
        {
            units = u;
        }

        string getName() const
        {
            return name;
        }

        int getUnits() const
        {
            return units;
        }
};
int main()
{
    // Create a vector of Product objects.
    vector<Product> products =
    {
        Product("T-Shirt", 20),
        Product("Calendar", 25),
        Product("Coffee Mug", 30)
    };

    // Display the vector elements.
    for (auto element : products)
    {
        cout << "Product: " << element.getName() << endl
             << "Units: " << element.getUnits() << endl;
    }

    return 0;
}

// Searching for key in map
class Contact
{
private:
    string name;
    string email;

public:
    Contact()
    {
        name = "";
        email = "";
    }

    Contact(string n, string em)
    {
        name = n;
        email = em;
    }

    void setName(string n)
    {
        name = n;
    }

    void setEmail(string em)
    {
        email = em;
    }

    string getName() const
    {
        return name;
    }

    string getEmail() const
    {
        return email;
    }
};
int main()
{
    string searchName; // The name to search for

    // Create some Contact objects
    Contact contact1("Ashley Miller", "amiller@faber.edu");
    Contact contact2("Jacob Brown", "jbrown@gotham.edu");
    Contact contact3("Emily Ramirez", "eramirez@coolidge.edu");

    // Create a map to hold the Contact objects.
    map<string, Contact> contacts;

    // Create an iterator for the map.
    map<string, Contact>::iterator iter;

    // Add the contact objects to the map.
    contacts[contact1.getName()] = contact1;
    contacts[contact2.getName()] = contact2;
    contacts[contact3.getName()] = contact3;

    // Get the name to search for.
    cout << "Enter a name: ";
    getline(cin, searchName);

    // Search for the name.
    iter = contacts.find(searchName);

    // Display the results.
    if (iter != contacts.end())
    {
        cout << "Name: " << iter->second.getName() << endl;
        cout << "Email: " << iter->second.getEmail() << endl;
    }
    else
    {
        cout << "Contact not found.\n";
    }

    return 0;
}

// Searching for value in set, overloading < operator (necessary)
class Customer
{
    private:
        int custNumber;
        string name;

    public:
        Customer(int cn, string n)
        {
            custNumber = cn;
            name = n;
        }

        void setCustNumber(int cn)
        {
            custNumber = cn;
        }

        void setName(string n)
        {
            name = n;
        }

        int getCustNumber() const
        {
            return custNumber;
        }

        string getName() const
        {
            return name;
        }

        bool operator < (const Customer &right) const
        {
            bool status = false;

            if (custNumber < right.custNumber)
                status = true;

            return status;
        }
};
int main()
{
    // Create a set of Customer objects.
    set<Customer> customerset =
    {
        Customer(1003, "Megan Cruz"),
        Customer(1002, "Austin Hill"),
        Customer(1001, "Sarah Scott")
    };

    // Try to insert a duplicate customer number.
    customerset.emplace(1001, "Evan Smith");

    // Display the set elements.
    cout << "List of customers:\n";
    for (auto element : customerset)
    {
        cout << element.getCustNumber() << " "
             << element.getName() << endl;
    }

    // Search for customer number 1002.
    cout << "\nSearching for Customer Number 1002:\n";
    auto it = customerset.find(Customer(1002, ""));

    if (it != customerset.end())
        cout << "Found: " << it->getName() << endl;
    else
        cout << "Not found.\n";

    return 0;
}

// =============================================================================
// FUNCTIONS

// Pointer function
    // use when object may not be found or if dynamic object outlives function call
 ParkedCar *patrol(int minutesParked, int minutesPurchased)
 {
    // If not over time, no ticket scenario (nothing to “patrol”)
    if (minutesParked <= minutesPurchased) return nullptr;

    // Create a sample parked car record (dynamic so it outlives this function)
    // Replace these literals with your real data sources as needed.
    ParkedCar* car = new ParkedCar("Toyota", "Corolla", "Blue", "ABC-123", minutesParked);

    return car;
}

// Dynamic memory & Pointers
void createTestScoresArray(int size = 5)
   { 
      int const DEFAULT_SCORE = 0;
      int numTestScores = size;
      double* testScores = new double[size]; 
      for (int i = 0; i < size; i++)
        testScores[i] = DEFAULT_SCORE; 
   }

// Multiple template values
template <class T1, class T2>
int largest(const T1 &var1, T2 &var2)
{
    if (sizeof(var1) > sizeof(var2))
        return sizeof(var1);
    else
        return sizeof(var2);
}
int main()
{
    int i = 0;
    char c = ' ';
    float f = 0.0;
    double d = 0.0;

    cout << "Comparing an int and a double, the largest\n"
         << "of the two is " << largest(i, d) << " bytes.\n";

    cout << "Comparing a char and a float, the largest\n"
         << "of the two is " << largest(c, f) << " bytes.\n";

    return 0;
}

// Overloading template function
template <class T>
T sum(T val1, T val2)
{
    return val1 + val2;
}
template <class T>
T sum(T val1, T val2, T val3)
{
    return val1 + val2 + val3;
}
int main()
{
    double num1, num2, num3;

    // Get two values and display their sum.
    cout << "Enter two values: ";
    cin >> num1 >> num2;
    cout << "Their sum is " << sum(num1, num2) << endl;

    // Get three values and display their sum.
    cout << "Enter three values: ";
    cin >> num1 >> num2 >> num3;
    cout << "Their sum is " << sum(num1, num2, num3) << endl;

    return 0;
}

// Iterating char by char from file
void transform_char()
{
    ifstream input_file;
    ofstream output_file;
    char c;

    // Pretend I opened both files

    // Grabs everything, including whitespace and newlines
    while(input_file.get(c))
    {
        c = 'a'; // Change all chars to the letter a
        output_file << c;
    }

    // Skips whitespaces
    while(input_file >> c)
    {
        c = 'a'; // Change all chars to the letter a
        output_file << c;
    }
}

// Basic iterator use
int main()
{
    const int SIZE = 3;

    // Store some names in an array object.
    array<string, SIZE> names = {"Sarah", "William", "Alfredo"};

    // Create an iterator for the array object.
    array<string, SIZE>::iterator it;

    // Display the names.
    cout << "Here are the names:\n";
    for (it = names.begin(); it != names.end(); it++)
        cout << *it << endl;

    return 0;

     // Create an iterator for the array object.
    array<string, SIZE>::reverse_iterator it;

    // Display the names.
    cout << "Here are the names:\n";
    for (it = names.begin(); it != names.end(); it++)
        cout << *it << endl;

    const int SIZE = 3;
    array<string, SIZE> names = {"Sarah", "William", "Alfredo"};

    cout << "Forward:\n";
    for (auto it = names.begin(); it != names.end(); ++it)
        cout << *it << '\n';

    cout << "\nReverse:\n";
    for (auto rit = names.rbegin(); rit != names.rend(); ++rit)
        cout << *rit << '\n';

    return 0;
}

// Swap map key and value elements
map<string, int> reverse_map()
{
    map<int, string> student_list;
    student_list[1] = "Riv Charden";
    student_list[2] = "Liz Bourden";
    student_list[3] = "Xylophone";

    map<string, int> r_student_list;
    for (auto &x : student_list)
    {
        r_student_list[x.second] = x.first;
    }

    for (auto &x : r_student_list)
    {
        cout << x.first << ": " << x.second << endl;
    }

    return r_student_list;
}

// map & file functions, average, min, max, descending & ascending sorts
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

// Array class object and iterator
int main()
{
    const int SIZE = 3;

    // Store some names in an array object.
    array<string, SIZE> names = {"Sarah", "William", "Alfredo"};

    // Create an iterator for the array object.
    array<string, SIZE>::iterator it;

    // Display the names.
    cout << "Here are the names:\n";
    for (it = names.begin(); it != names.end(); it++)
        cout << *it << endl;

    return 0;
}

// Grab unique words from file, strip off non-alphanum chars
    // static_cast used
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

// Towers of Hanoi
int main()
{
    // const int NUM_DISCS = 3;   
    // const int FROM_PEG = 1;    
    // const int TO_PEG = 3;      
    // const int TEMP_PEG = 2;    

    int NUM_DISCS = 3;   
    int FROM_PEG = 1;    
    int TO_PEG = 3;      
    int TEMP_PEG = 2; 

    cout << "Please enter number of discs: ";
    cin >> NUM_DISCS;

    cout << "Please enter the leave peg: ";
    cin >> FROM_PEG;

    cout << "Please enter the target or goal peg: ";
    cin >> TO_PEG;

    cout << "Please enter the temporary peg: ";
    cin >> TEMP_PEG;

    moveDiscs(NUM_DISCS, FROM_PEG, TO_PEG, TEMP_PEG);
    cout << "All the pegs are moved!\n";
    return 0;
}
    // Number of discs, leave peg, goal peg, temp peg
void moveDiscs(int num, int A, int B, int C)
{
    if (num > 0)
    {
        moveDiscs(num - 1, A, C, B);
        cout << "Move a disc from peg " << A << " to peg " << B << endl;
        moveDiscs(num - 1, C, B, A);
    }
}

// Lambda function
int main()
{
    // Create a vector of ints.
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    // Use a lambda expression to create a function object.
    auto isEven = [](int x) { return x % 2 == 0; };

    // Get the number of elements that are even.
    int evenNums = count_if(v.begin(), v.end(), isEven);

    // Display the results.
    cout << "The vector contains " << evenNums << " even numbers.\n";

    return 0;
}

// Recursion (Basic 1)
void sign(int n)
{
    if(n <= 0) {}
    else 
    {
        cout << "No Parking\n";
        sign(n - 1);
    }
}

// Recursion (Basic 2)
int main()
{
    int count_start = 0;
    cout << "Enter count timer start: ";
    cin >> count_start;

    countDown(count_start);

    return 0;
}
void countDown(int c)
{
    if(c == 0)
    {
        cout << "Blastoff!" << endl;
    }
    else if(c >= 1)
    {
        cout << c << "..." << endl;
        countDown(c-1);
    }
}

// **Recursion Project
int main()
{
    // Declare / initialize variables
    int choice = 0;
    int fib_range = 0;
    int prime_candidate = 0;
    int gcd_num1 = 0;
    int gcd_num2 = 0;
    int gcd_result = 0;
    int factorial_num = 0;
    int factorial_result = 0;
    int out_file_counter = 0;
    bool prime_status;
    bool choice2 = false;
    bool choice3 = false;
    bool choice4 = false;
    string file_name;
    ofstream out_file;

    // I interpreted that a vector counts as an array. I use this because my
    // interpretation of the implementation is to have the user request how
    // many Fibonacci numbers to generate. Since a vector can dynamically increase
    // in size, I thought it would be the best STL container to use here.
    vector<int> fib_series;

    cout << "Welcome to NumGen 17, please consult the menu below for the latest \n";
    cout << "in 20th century numerical operations for the home computer!\n";

    // Menu
    do
    {
        cout << "\nPlease select from the below menu options:\n";
        cout << "==========================================\n";
        cout << "[1] Generate a Fibonacci Series\n";
        cout << "[2] Check if number is prime\n";
        cout << "[3] Identify the Greatest Common Divisor (GCD) between two numbers\n";
        cout << "[4] Calculate the factorial of a number\n";
        cout << "[5] Output operations to a file.\n";
        cout << "[6] Exit\n";

        choice = get_choice();
        
        if(choice == 1)
        {
            // Menu Item 1
            cout << "\n1. Fibonacci Series Generation: \n";
            cout << "---------------------------\n";
            cout << "Please enter the number of fibonacci values you'd like generated \n";
            cout << "starting from the first member of the series, 0: ";

            fib_range = get_num();

            // Clear if already called previously
            fib_series.clear();

            // Hardcode iterator - starts at 0
            fibonacci(0, fib_range, fib_series);

            display_fib(fib_series);
        }
        else if(choice == 2)
        {
            // Menu Item 2
            choice2 = true;

            cout << "\n2. Prime Number Identifier: \n";
            cout << "------------------------------\n";
            cout << "Please enter a whole number to test whether it is prime:  \n";

            prime_candidate = get_num();

            // Hardcode starting divisor at 2
            prime_status = prime_check(prime_candidate, 2);

            if(prime_status) {cout << prime_candidate << " is a prime number!" << endl;}
            else {cout << prime_candidate << " is NOT a prime number!" << endl;}
        }
        else if(choice == 3)
        {
            // Menu Item 3
            choice3 = true;

            cout << "\n3. Greatest Common Divisor: \n";
            cout << "==============================\n";
            cout << "Please enter two whole numbers to identify the greatest common \n";
            cout << "divisor between them: \n\n";

            cout << "First number: ";
            gcd_num1 = get_num();

            cout << "Second number: ";
            gcd_num2 = get_num();
            cout << endl;

            gcd_result = gcd(gcd_num1, gcd_num2);

            cout << "The greatest common divisor of " << gcd_num1 << " and " << gcd_num2;
            cout << " is: " << gcd_result << "!" << endl;
        }
        else if(choice == 4)
        {
            // Menu Item 4
            choice4 = true;

            cout << "\n4. Factorial calculator: \n";
            cout << "==============================\n";
            cout << "Please enter a whole number to apply the factorial operation to: ";

            factorial_num = get_num();

            factorial_result = factorial(factorial_num);

            cout << factorial_num << "! = " << factorial_result << endl;
        }
        else if(choice == 5)
        {
            // Menu Item 5
            if(fib_series.empty() && !choice2 && !choice3 && !choice4)
            {
                cout << "No results to output, returning to menu.\n";
                continue;
            }
            else
            {
                out_file_counter++;

                // Create a new output file each time this is selected.
                file_name = "NumGen17_output_" + to_string(out_file_counter) + ".txt";

                cout << "\n5. Output your operation results to a file! \n";
                cout << "============================================\n";

                cout << "Any operations you have performed can now be found in: ";
                cout << file_name << endl;

                out_file.open(file_name, ios::out);

                // Student Info:
                out_file << "Program Author: Benjamin Link" << endl;
                out_file << "Author EMPLID: 21009239" << endl;
                out_file << "Program Sponsor: CSC 211 — 1300" << endl << endl;

                // Data:
                out_file << "NumGen 17 Output File " + to_string(out_file_counter) << endl;
                out_file << "=======================\n";

                // Choice 1 output
                if(fib_series.empty())
                    {out_file << "No Fibonacci series generated." << endl;}
                else
                {
                    out_file << "Fibonacci series: ";
                    for(auto x : fib_series)
                    {
                        out_file << x << " ";
                    }
                    out_file << endl;
                }

                // Choice 2 output
                if(!choice2) {out_file << "2. No prime number operation performed." << endl;}
                else if(prime_status)
                    {out_file << prime_candidate << " is a prime number." << endl;}
                else
                    {out_file << prime_candidate << " is NOT a prime number." << endl;}

                // Choice 3 output
                if(!choice3) {out_file << "No GCD operation performed." << endl;}
                else 
                {
                    out_file << "The GCD of " << gcd_num1 << " and " << gcd_num2;
                    out_file << " is " << gcd_result << "." << endl;
                }

                // Choice 4 output
                if(!choice4) {out_file << "No factorial operation performed." << endl;}
                else {out_file << factorial_num << "! = " << factorial_result << endl;}
            }
            // Close out_file so that new files can be generated:
            out_file.close();
        }
    }while(choice != 6);

    cout << "Thank you for using NumGen 17! Closing program..." << endl;
        
    return 0;
}
int get_choice()
{
    int num = 0;

    while (true)
    {
        // If:
            // i. the input stream operator worked correctly 
                //(also acts to receive user input)
           // ii. The character at the end of the input is a newline character
          // iii. The integer is non-negative.
        if (cin >> num && cin.peek() == '\n' && num >=1 && num <= 6)
            {return num;}
        cout << "Invalid input. Try again: ";

        // Clears any tripped error flags in the input stream if present
        cin.clear();

        // This allows the input stream to skip over all characters in the buffer
        // up to the theoretical maximum size of the input stream buffer until a
        // newline character is reached. This is particularly useful in dealing
        // with unanticipated non-numerical inputs that can lead to infinite looping.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}
int get_num()
{
    int num = 0;

    while (true)
    {
        // If:
            // i. the input stream operator worked correctly 
                //(also acts to receive user input)
           // ii. The character at the end of the input is a newline character
          // iii. The integer is non-negative.
        if (cin >> num && cin.peek() == '\n' && num >= 0)
            {return num;}
        cout << "Invalid input. Try again: ";

        // Clears any tripped error flags in the input stream if present
        cin.clear();

        // This allows the input stream to skip over all characters in the buffer
        // up to the theoretical maximum size of the input stream buffer until a
        // newline character is reached. This is particularly useful in dealing
        // with unanticipated non-numerical inputs that can lead to infinite looping.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}
void fibonacci(int n, int fib_range, vector<int>& fib_series)
{

    // Base case: 
    // The iterator matches or exceeds the requested Fibonacci series range exit 
    // the function.
    if (n >= fib_range) return;

    // Fill in the first two values of the fib series, assuming the base case
    // isn't already tripped.
    if (n == 0) {fib_series.push_back(0);} 
    else if (n == 1) {fib_series.push_back(1);} 

    // Recursive case: 
    // If the fib_range is greater than 2, compute the next Fibonacci numbers
    // in sequence.
    else 
    {
        // Create temp next var to hold next fib number to be computed
        int next = fib_series[n - 1] + fib_series[n - 2];
        fib_series.push_back(next);
    }
    // Continue processing cases
    fibonacci(n + 1, fib_range, fib_series);
}
void display_fib(vector<int> fib_series)
{
    // Use a for range loop to display contents of fib_series
    for(auto x : fib_series)
    {
        cout << x << " ";
    }
    cout << endl;
}
bool prime_check(int num, int i)
{
    // Base cases
    // Below ternary line:
        // If num is less than or equal to 2 return true if num is equal to 2 
        // and false if not
    if (num <= 2) return (num == 2) ? true : false;

    // Keep checking divisors incrementally from 2 onward to see if num can be
    // divided cleanly, with no remainder, from any of them. If so, then it's
    // not a prime number.
    if (num % i == 0) return false;

    // Stop iterating the divisor if it multiplied by itself exceeds the value
    // of the candidate number being assessed. This means that there are are no
    // whole number divisors beyond num and 1 that can divide num, thus it's prime.
    if (i * i > num) return true;

    // Recursive case
    // Increment the divisor and run the prior two if statements again
    return prime_check(num, i + 1);
}
int gcd(int x, int y)
{
    // If the user inputs 0 for y:
    if (y == 0) {return x;}

    // If x's remainder after dividing by 2 is y, then y is the GCD
    if(x % y == 0) {return y;}

    // Replace y with the remainder of x after being divided by y to advance
    // the recursive search for the GCD
    else {return gcd(y, x % y);}
}
int factorial(int n)
{
    // Base case
    if(n == 0) {return 1;}
    // Recursive case
        // Applies the formula n * n-1 * n-2 * n-3... with two terms per call
    else {return(n * factorial(n-1));}
}

// Padding numerical data with leading 0's
int main()
{
    int id_num;
    string id;

    id_num = get_id();
    id = to_string(id_num);

    cout << "Method 1: ";
    if(id.length() < 6)
    {
        // From 0 to wherever the string has a digit, insert 0's
        id.insert(0, 6 - id.length(), '0');
    }
    cout << id << endl;

    cout << "Method 2: ";
    cout << setw(6) << setfill('0') << id_num << endl;

    return 0;
}
int get_id()
{
    int id = 0;

    cout << "Please input ID number: ";
    while(true)
    {
        if(cin >> id && cin.peek() == '\n' && id > 0 && id < 999999)
            {return id;}
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please try again: ";
        }
    }
}

// Ternary Operators
bool parity_ternary()
{
    int a = 10;
    return a % 2 == 0 ? true : false;
}

// Random number generator - between 1 and 3
int rand_num()
{
    int num = 0;
    srand(static_cast<unsigned>(time(nullptr)));
    num = (rand() % 3) + 1;
    return num;
}


// =============================================================================
//  STL ALGORITHMS

// Vector sort and binary search
int main()
{
    int searchValue;   // Value to search for

    // Create a vector of unsorted integers.
    vector<int> numbers = {10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    // Sort the vector.
    sort(numbers.begin(), numbers.end());

    // Display the vector.
    cout << "Here are the sorted values:\n";
    for (auto element : numbers)
        cout << element << " ";
    cout << endl << endl;

    // Get the value to search for.
    cout << "Enter a value to search for: ";
    cin >> searchValue;

    // Search for the value.
    if (binary_search(numbers.begin(), numbers.end(), searchValue))
        cout << "That value is in the vector.\n";
    else
        cout << "That value is not in the vector.\n";

    return 0;
}

// Ascending and DESCENDING sort of vector with lambda STLs
int main()
{
    // Create an unsorted vector of ints.
    vector<int> v = {8, 1, 7, 2, 6, 3, 5, 4};

    // Display the vector contents.
    cout << "Original order:\n";
    for (auto element : v)
        cout << element << " ";
    cout << endl;

    // Sort the vector in ascending order.
    sort(v.begin(), v.end());

    // Display the vector contents again.
    cout << "\nAscending order:\n";
    for (auto element : v)
        cout << element << " ";
    cout << endl;

    // Sort the vector in descending order.
    sort(v.begin(), v.end(), greater<int>());

    // Display the vector contents again.
    cout << "\nDescending order:\n";
    for (auto element : v)
        cout << element << " ";
    cout << endl;

    return 0;
}

// Permutations
    // checks whether two ranges contain the same elements with the same 
    // frequencies, regardless of order. 
int main()
{
    const int MAX = 5;                 // Numbers in 1 lottery ticket
    vector<int> winning(MAX);          // The winning numbers
    vector<int> player(MAX);           // Numbers on a ticket

    // Get the winning numbers.
    cout << "Enter the " << MAX << " winning numbers:\n";
    for (auto &element : winning)
    {
        cout << "> ";
        cin >> element;
    }

    // Get the numbers purchased on a lottery ticket.
    cout << "\nEnter your " << MAX << " lottery numbers:\n";
    for (auto &element : player)
    {
        cout << "> ";
        cin >> element;
    }

    // Check for a winner.
    if (is_permutation(winning.begin(), winning.end(), player.begin()))
        cout << "You won the lottery!\n";
    else
        cout << "Sorry, you did not win.\n";

    return 0;
}

// for_each
int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Display the numbers before doubling.
    for (auto element : numbers)
        cout << element << " ";
    cout << endl;

    // Double the value of each vector element.
    for_each(numbers.begin(), numbers.end(), doubleNumber);

    // Display the numbers after doubling.
    for (auto element : numbers)
        cout << element << " ";
    cout << endl;

    return 0;
}
void doubleNumber(int &n)
{
    n = n * 2;
}

// count_if
int main()
{
    // Create a vector of ints.
    vector<int> numbers = {0, 99, 120, -33, 10, 8, -1, 101};

    // Get the number of elements that are < 0 or > 100.
    int invalid = count_if(numbers.begin(), numbers.end(), outOfRange);

    // Display the results.
    cout << "There are " << invalid << " elements out of range.\n";

    return 0;
}
bool outOfRange(int n)
{
    // Constants for min and max values
    const int MIN = 0, MAX = 100;

    // Determine whether n is out of range.
    if (n < MIN || n > MAX)
        return true;
    else
        return false;
}

// set union
    // same idea for set intersections, differences, and symmetric differences
int main()
{
    // Create two sets.
    set<int> set1 = {1, 2, 3, 4};
    set<int> set2 = {3, 4, 5, 6};

    // Create a vector to hold the union.
    // The vector must be large enough to hold both sets.
    vector<int> result(set1.size() + set2.size());

    // Get the union of the sets.
    // iter will point one past the last inserted element.
    auto iter = set_union(
        set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        result.begin()
    );

    // Resize the result vector to remove unused elements.
    result.resize(iter - result.begin());

    // Display the result vector's elements.
    cout << "The union of the sets is:\n";
    for (auto element : result)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}

// subsets
int main()
{
    // Create two sets.
    set<int> set1 = {1, 2, 3, 4};
    set<int> set2 = {2, 3};

    // Determine whether set1 includes the elements of set2.
    if (includes(set1.begin(), set1.end(),
                 set2.begin(), set2.end()))
    {
        cout << "set2 is a subset of set1.\n";
    }
    else
    {
        cout << "set2 is NOT a subset of set1.\n";
    }

    return 0;
}

// TODO
// Conversion code / recasting

// =============================================================================
// CONCEPTS

// Rule of Three (triggered when pointer attributes used)
    // Destructor
    // Copy constructor
    // Copy assignment

// Friend vs virtual vs static

// function override vs function redefine vs function overloads
    // override keyword

// type casting differences: static_cast, dynamic_cast, etc.

// Compile time, runtime, etc.

// Stack vs heap vs buffer

#endif