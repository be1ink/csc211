#ifndef DIE_H
#define DIE_H

class Die
{
    private:
        int sides;
        int value;

    public:
        // Constructor
        Die(int = 6);

        // Setter?
        void roll();

        // Getters
        int getSides();
        int getValue();
};
#endif