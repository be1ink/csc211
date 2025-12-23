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