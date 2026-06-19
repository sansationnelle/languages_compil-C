#include <iostream>
#include <string>
#include <map>
#include <limits>
#include <algorithm>
#include <bits/stdc++.h>
#include "contact.h"
#include "principal.h"
#include "savefile.h"
//permet de comparez si 2 strings sont égal, ne prend pas la case en compte
bool compareStrings(std::string str1, std::string str2)
{
    if (str1.length() != str2.length()) //vérifie la longueur
        return false;

    for (long unsigned int i = 0; i < str1.length(); ++i) { //vérifie les charactères 1 par 1
        if (tolower(str1[i]) != tolower(str2[i]))
            return false;
    }

    return true;
}

//quand la classe est initié il restaure les contacts sauvegarder dans le csv
Principal::Principal(){
    save.RestoreData(contacts);
}

//menu principal du projet
void Principal::menu(){
    int option = -1;
    std::cout << "------------------------------\n";
    std::cout << "Que voulez vous faire?\n";
    std::cout << "1. Ajouter un contact\n2. Afficher tous les contacts\n3. Rechercher par nom\n4. Modifier un contact existant\n5. Suprimmer un contact\n6. Quitter\n";
    if (!(std::cin >> option)){ //selection de l'option avec un int, donc vérification que la données entré est un int sinin retourne un log et recommance le menu
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erreur: ceci n'est pas un nombre\n";
        return;
    }
    switch (option)
    {
    case 1:
        add_new_contact("");
        save.UpdateFile(contacts); //savegarde les données
        break;
    case 2:
        show_contact();
        break;
    case 3:
        searchByName();
        break;
    case 4:
        Modify();
        save.UpdateFile(contacts);
        break;
    case 5:
        del_contact();
        save.UpdateFile(contacts);
        break;
    case 6:
        std::cout << "Au revoir!\n";
        exit(0);
    default:
        std::cout << "Cet option n'existe pas!\nRéessayez\n";
        break;
    }
}

int Principal::add_new_contact(std::string str){ //ajout d'un contact entier sur la valeurs contacts
    int successcode = 0;
    std::string nom = "";
    std::string prenom;
    std::string numero;
    std::string email;
    std::cout << "\n------------------------------\n";
    std::cout << "Menu: Ajouter un contact\nVeuillez selectionner le nom: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //nettoie les résidus comme /n
    std::getline(std::cin, nom); //prend une ligne entière, ne s'arrête pas à l'espace
    if (nom.empty()){
        std::cout << "Le champ que vous avez inséré est vide\n";
        return 1;
    }
    std::string minnom = nom; //sera le nom en miniscule, sert pour les clés strings
    std::transform(nom.begin(), nom.end(), minnom.begin(), ::tolower);
    auto found = contacts.find(minnom); //essaye de trouvé le nom dans la map
    if (found != contacts.end()){ // vérifie si le contact existe déjà
        if (str.empty() || !compareStrings(minnom,str)){ //vérifie si le nom est le même qu'en argument
            std::cout << "\nLe contact existe déjà, veuillez le suprimmer ou le modifier ou changer le nom inséré\n";
            return 1;
        }
        successcode = 2;
    }
    std::cout << "\nVeuillez entrer un prenom: ";
    std::getline(std::cin, prenom);
    std::cout << "\nVeullez entrer un numéro de tel: ";
    std::getline(std::cin, numero);
    std::cout << "\nVeullez entrer l'email: ";
    std::getline(std::cin, email);
    if (email.empty() || prenom.empty() || numero.empty()){ //vérifie que les champs ne soit pas vide
        std::cout << "\nNe peut pas créer le contact, l'une des information est vide\n";
        return 1;
    }
    contacts.insert_or_assign(minnom, Contact(nom, prenom, numero, email)); //insert une clé et ses valeurs dans map (modifie la valeur si la clé existe déjà)
    std::cout << "\nSuccès: Le contact " << nom << " " << prenom << " avec le numéro " << numero << " et l'email " << email << " a été crée\n";
    return successcode; //retoune le success code selon si c'est le nom qui à été modifié ou non
}

void Principal::del_contact(){ //suprimme un contact
    std::cout << "\n------------------------------\n";
    std::cout << "Menu: Suprimmer un contact\nEntrez le nom du contact que vous voulez suprimmer: ";
    if (contacts.size() == 0){ //si il n'y as pas de contacts, erreur
        std::cout << "\nVous n'avez pas de contacts\n";
        return;
    }
    std::string nom;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nom); 
    if (nom.empty()){
        std::cout << "Le champ que vous avez inséré est vide\n";
        return;
    }
    std::transform(nom.begin(), nom.end(), nom.begin(), ::tolower);
    auto found = contacts.find(nom);
    if (found == contacts.end()){ //reguarde si le nom est dans la map
        std::cout << "\nLe nom que vous avez inséré n'existe pas\n";
        return;
    }
    contacts.erase(nom);
    std::cout << "\nLe nom à bien été suprimmé\n";
}

void Principal::show_contact(){ //montre tous les contacts
    std::cout << "\n------------------------------\n";
    std::cout << "Option: Montre les contacts\n";
    if (contacts.size() == 0){
        std::cout << "Vous n'avez pas de contacts\n";
        return;
    }
    for (auto guy : contacts){ //boucle tous les contacts dans la map
        std::cout << "\n------------------------------\n";
        std::cout << "Nom/prenom: " << guy.second.getName() << " " << guy.second.getPrenom() << "\nNuméro: " << guy.second.getNumber() << "\nEmail: " << guy.second.getEmail();
    }
    std::cout << "\n\nFin des contacts\n";
}

void Principal::searchByName(){ // recherche par le nom dans la map
    std::cout << "\n------------------------------\n";
    std::cout << "\nMenu: Recherche par nom\nVeuillez mettre le nom que vous voulez chercher: ";
    if (contacts.size() == 0){
        std::cout << "Vous n'avez pas de contacts\n";
        return;
    }
    std::string nom;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nom);
    if (nom.empty()){
        std::cout << "Le champ que vous avez inséré est vide\n";
        return;
    }
    std::transform(nom.begin(), nom.end(), nom.begin(), ::tolower);
    auto found = contacts.find(nom);
    if (found != contacts.end()){
        std::cout << "------------------------------\n";
        std::cout << "Nom/prenom: " << found->second.getName() << " " << found->second.getPrenom() << "\nNuméro: " << found->second.getNumber() << "\nEmail: " << found->second.getEmail() << "\n";
        return;
    }
    std::cout << "\nLe nom que vous avez inséré n'existe pas\n";

}

void Principal::Modify(){ //modifie les valeurs d'un clé dans un contacts
    std::cout << "\n------------------------------\n";
    std::cout << "Menu: Modifier un contact\nVeuillez mettre le nom du contact que vous voulez modifier: ";
    if (contacts.size() == 0){ //pas de contacts
        std::cout << "\nVous n'avez pas de contacts\n";
        return;
    }
    std::string nom;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, nom); 
    if (nom.empty()){ //si le champ est vide skip
        std::cout << "Le champ que vous avez inséré est vide\n";
        return;
    }
    std::transform(nom.begin(), nom.end(), nom.begin(), ::tolower);
    auto found = contacts.find(nom);
    if (found == contacts.end()){ //si le nom n'est pas dans contacts skip
        std::cout << "\nLe nom que vous avez inséré n'existe pas\n";
        return;
    }
    std::cout << "\nQue voulez vous modifier?\n1. Le nom\n2. Le prénom\n3. Le numéro\n4. L'email\n5. Tout\nTappez autre chose pour ne rien modifier\n";
    int option = -1;
    if (!(std::cin >> option)){ //si l'option n'est pas un nombre skip
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Erreur: ceci n'est pas un nombre\n";
        return;
    }
    Contact searched = contacts.at(nom); //stocke le contact du nom sélectionné, utilis
    std::string newval;
    switch (option){
    case 1: { //changer le nom, il faut changer la clé et crée une nouvelle clé plus récupérer les anciennes données
        std::cout << "Veuillez insérer le nouveau nom\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newval);
        if (newval.empty()){ //pas de nouveau nom skip
            std::cout << "Le champ que vous avez inséré est vide\n";
            return;
        }
        std::string minnewval = newval; //version miniscule du nom
        std::transform(newval.begin(), newval.end(), minnewval.begin(), ::tolower);
        auto found = contacts.find(minnewval);
        if (found != contacts.end() && !compareStrings(nom,newval)){ //vérifie si le nom est dans dans les contacts skip SAUF si le nom est égal au nom modifé
            std::cout << "Le contact existe déjà, veuillez le suprimmer ou le modifier ou changer le nom inséré\n";
            return;
        }
        contacts.erase(nom);
        contacts.insert_or_assign(minnewval,Contact(newval,searched.getPrenom(),searched.getNumber(),searched.getEmail())); //change le nom et prends les anciennes valeurs qui sont stocké dans searched
        break;
    }
    case 2: //change le prénom
        std::cout << "Veuillez insérer le nouveau prenom\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newval);
        if (newval.empty()){
            std::cout << "Le prénom ne peut pas être vide\n";
            return;
        }
        contacts.at(nom).Change_Prenom(newval); //change le nom avec la nouvelle valeur
        break;
    case 3: //change le numéro de tel
        std::cout << "Veuillez insérer le nouveau numéro de tel\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newval);
        if (newval.empty()){
            std::cout << "Le numéro ne peut pas être vide\n";
            return;
        }
        contacts.at(nom).Change_Number(newval);
        break;
    case 4: //change l'email
        std::cout << "Veuillez insérer le nouvelle email\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, newval);
        if (newval.empty()){
            std::cout << "L'email ne peut pas être vide\n";
            return;
        }
        contacts.at(nom).Change_Email(newval);
        break;
    case 5: { //change toutes les données pour faire plus simple j'ai juste mis add_new_contact
        bool end = false;
        int ending = 0;
        while (!end){
            ending = add_new_contact(nom);
            // si l'utilisateur insère le même nom il faut pas qu'il efface le nom
            if (ending == 0){ //le nom n'as pas été utilisé
                end = true;
                contacts.erase(nom);
            } else if (ending == 2){ //le nom à été utilisé
                end = true;
            } else { //en cas d'erreur de l'utilisateur il peut recommencer ou quitter
                std::cout << "voulez vous quitter?\noui/non: ";
                std::cin >> newval;
                if (compareStrings("oui", newval)){ //si oui skip
                    end = true;
                    break;
                }
            }
        }
        std::cout << "Le contact a bien été modifié\n";
        break;
    }
    default:
        std::cout << "ceci n'est pas une option valide\n";
        break;
    }
}