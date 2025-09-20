// Specifications
#ifndef CONTACTINFO_H
#define CONTACTINFO_H
#include <cstring> // includes strlen and strcpy
class ContactInfo {
    private:
        char* name;
        char* phone;

        // Constructors
        void initName(const char* n) 
        {
            name = new char[std::strlen(n) + 1];
            std::strcpy(name, n);
        }

        void initPhone(const char* p) 
        {
            phone = new char[std::strlen(p) + 1];
            std::strcpy(phone, p);
        }

    public:
        // Setter
        ContactInfo(const char* n, const char* p) 
        {
            initName(n);
            initPhone(p);
        }

        ~ContactInfo() 
        {
            delete [] name;
            delete [] phone;
        }

        // Getters
        const char* getName() const 
        { 
            return name; 
        }

        const char* getPhoneNumber() const 
        { 
            return phone; 
        }
};
#endif