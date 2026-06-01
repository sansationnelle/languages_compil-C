#include <iostream>

float round(float var){
    float value = (int)(var * 100);
    return (float)value / 100;
}
int main(void){
    std::string prenom;
    int age;
    float note;
    std::cout << "donnez vos info pour le gouvernement\nPrenom: ";
    std::cin >> prenom;
    std::cout << "age: ";
    std::cin >> age;
    std::cout << "notes: ";
    std::cin >> note;
    std::cout << "--------\nprenom: " << prenom << "\nAge: "<< age << "\nnotes: " << round(note) << "\n--------\n";
    return 0;
}