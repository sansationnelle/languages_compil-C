#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
    private:
        std::string nom;
        std::string prenom;
        std::string num;
        std::string email;
    public:
        Contact(std::string n, std::string pre, std::string numb, std::string e);
        void Change_All(std::string n, std::string pre, std::string numb, std::string e);
        void Change_Name(std::string n);
        void Change_Prenom(std::string pre);
        void Change_Number(std::string numb);
        void Change_Email(std::string email);
        std::string getName();
        std::string getPrenom();
        std::string getNumber();
        std::string getEmail();
};

#endif