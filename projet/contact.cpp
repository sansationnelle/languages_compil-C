#include "contact.h"
#include <string>

Contact::Contact(std::string n, std::string pre, std::string numb, std::string e){
    nom = n;
    prenom = pre;
    num = numb;
    email = e;
};
// équivalent du set
void Contact::Change_All(std::string n, std::string pre, std::string numb, std::string e){nom = n; prenom = pre; num = numb; email = e;};
void Contact::Change_Name(std::string n){nom = n;};
void Contact::Change_Prenom(std::string pre){prenom = pre;};
void Contact::Change_Number(std::string numb){num = numb;};
void Contact::Change_Email(std::string e){email = e;};
//get chaque valeurs (bonne manière)
std::string Contact::getName(){return nom;};
std::string Contact::getPrenom(){return prenom;};
std::string Contact::getNumber(){return num;};
std::string Contact::getEmail(){return email;};
