#include <iostream>
#include <string>

class Etudiant {
    private:
        std::string nom;
        int age;
        double moyenne;
    public:
        // Constructeur avec liste d'initialisation
        Etudiant(std::string n, int a, double m);
        // Methodes
        void ajouterNote(double note); // recalcule la moyenne
        bool estMajeur() const; // return age >= 18
        void afficher() const; // affiche nom, age, mo
        // Getters
        std::string getNom() const;
        double getMoyenne() const;
};

Etudiant::Etudiant(std::string n, int a, double m) : nom(n), age(a), moyenne(m) {}

std::string Etudiant::getNom() const { 
    return nom; 
}

double Etudiant::getMoyenne() const { 
    return moyenne; 
}

bool Etudiant::estMajeur() const {
    return age >= 18;
}

void Etudiant::ajouterNote(double note) {
    moyenne = (moyenne + note) / 2.0;
}

float round(float var){
    float value = (int)(var * 100);
    return (float)value / 100;
}

void afficher(Etudiant* *li){
    for(int i = 0; i < 5; i++){
        std::cout << "Etudiant " << i + 1 << "\nNom " << li[i]->getNom() << "\nMoyenne: " <<li[i]->getMoyenne() << "\n";
    }
}

void moyenneaff(Etudiant* *li){
    double somme = 0;
    for (int i = 0; i < 5; i++){
        somme += li[i]->getMoyenne();
    }
    std::cout << "Moyenne des étudiants: " << round(somme/5) << "\n";
}

void mostnote(Etudiant* *li){
    double max = li[0]->getMoyenne();
    int maxi = 0;
    for (int i = 1; i < 5; i++){
        if (li[i]->getMoyenne() > max){
            max = li[i]->getMoyenne();
            maxi = i;
        }
    }
    std::cout << "L'étudiant ayant la meilleur moyenne est " << li[maxi]->getNom() << " avec " << round(max) << " de moyenne\n";
}

int main(void){
    Etudiant* list[5]; 

    std::string nom;
    int age;
    double moyenne;

    for(int i = 0; i < 5; i++) {
        std::cout << "--- Etudiant " << i + 1 << " ---\n";
        std::cout << "inserez le nom : ";
        std::cin >> nom;
        std::cout << "inserez l'age : ";
        std::cin >> age;
        std::cout << "donner une moyenne : ";
        std::cin >> moyenne;

        list[i] = new Etudiant(nom, age, moyenne);
    }
    afficher(list);
    moyenneaff(list);
    mostnote(list);
    for(int i = 0; i < 5; i++) {
        delete list[i];
    }
    return 0;
}