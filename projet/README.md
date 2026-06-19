# Projet Store-Contacts
Ce projet fait en **C++** permet de gérer une liste de contacts,
Il y as 5 champs, Nom, Prenom, le numéro de téléphone et l'email.
Voici ce qu'on peut faire dans ce projet:
- Ajouter des contacts
- Suprimmer des contacts
- Rechercher par nom, ou avoir tous les contacts
- Modifier un contact, tous les champs peuvent être changé ou 1 seul au cas par cas
Le tout se fait sur le terminal, les données sont automatiquement **sauvegardé** dans un fichier csv
# Instalation/compilation
pour lancer le projet il faut le télécharger puis lancer le makefile avec la commande make pour compiler le projet et enfin ./principal pour lancer le projet
si vous modifiez le projet n'oubliez pas de faire make clean pour enlever les anciennes compilations
# Structure
5 fichiers:
- Principal.cpp qui a les fonctions principales du projet, il stoque les contacts, et peut les modifier de toutes sorte, toutes les opérations de contacts ainsi que le menu principal se fait ici
- savefile.cpp contient 2 fonctions en lien avec le stokage et la restauration de la sauvegarde au lancement du code, UpdateFile() met à jour le fichier csv et restaureData() qui remet les données du fichier csv dans une valeur map utilisé par principal pour stoquer les contacts
- Contacts.cpp C'est la classe contact qui contient les valeurs, nom, prenom, numéro, email pour 1 contact
- contacts.csv C'est là ou les contacts sont stoqué sur la machine
- main.cpp lance le projet et initialise la classe principal
# Crédit
Sansationnelle: codeur
# technicité
Le codes à beacoups de fail safe, il empêche l'utilisateur de mettre un champs vide, ou mettre un nom déjà pris pour ajout d'un nouveau contact ou la modification du nom
aussi pour les options du menu avec un int qui a un fail safe si un int n'est pas inséré
Ce projet utilise getline à la place de cin car j'ai préféré qu'il prenne toute une ligne et qu'on puisse ajouter des espaces dans les noms plutôt que le code bugge à cause des espaces insérés
