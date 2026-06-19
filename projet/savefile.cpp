#include "contact.h"
#include "savefile.h"
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>

saveContacts::saveContacts(){}

void saveContacts::UpdateFile(std::map<std::string, Contact> contacts){
    std::ofstream file("data/contacts.csv"); //crée un fichier csv
    if (!file.is_open()) { //fail safe si le fichier est en read only
        std::cout << "Erreur : impossible d'ouvrir le fichier pour la sauvegarde.\n";
        return;
    }
    for (auto contact: contacts){ //met dans tout les contacts stocké dans le code dans le fichier csv
        file << contact.second.getName() << "," << contact.second.getPrenom() << "," << contact.second.getNumber() << "," << contact.second.getEmail() << "\n";
    }
    file.close();
}

void saveContacts::RestoreData(std::map<std::string, Contact>& contacts){
    std::ifstream file("data/contacts.csv");
    if (!file.is_open()) {
        std::cout << "Erreur : impossible d'ouvrir le fichier pour la restoration des données.\n";
        return;
    }
    std::string line, name, prenom, number, email;
    while (std::getline(file, line)) {
        std::stringstream ss(line); //initie le "curseur"
        std::getline(ss, name, ','); //lit justqu'à attendre une virgule
        std::getline(ss, prenom, ',');
        std::getline(ss, number, ',');
        std::getline(ss, email, ',');
        std::string minnom = name; //clé pour la map
        std::transform(name.begin(), name.end(), minnom.begin(), ::tolower);
        contacts.emplace(minnom, Contact(name, prenom, number, email));
    }
    file.close();
}