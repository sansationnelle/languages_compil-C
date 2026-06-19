#include <map>
#include <string>
#include "contact.h"
#ifndef SAVEFILE_H
#define SAVEFILE_H

class saveContacts{
    public:
        saveContacts();
        void UpdateFile(std::map<std::string, Contact> contacts);
        void RestoreData(std::map<std::string, Contact>& contacts);
};

#endif