#include "contact.h"
#include "savefile.h"
#include <string>
#include <map>

class Principal {
    private:
        std::map<std::string, Contact> contacts;
        saveContacts save;
    public: 
        Principal();
        void menu();
        int add_new_contact(std::string str);
        void show_contact();
        void searchByName();
        void Modify();
        void del_contact();     
};