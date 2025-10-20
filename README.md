# 🎮 Cub3D

## 🌟 Présentation

**Cub3D** est un projet du cursus 42 visant à créer un moteur graphique en **3D** utilisant la technique de **raycasting**. Inspiré des premiers jeux de tir à la première personne comme *Wolfenstein 3D* (1992), ce projet te permet d’appréhender les bases du rendu 3D en C avec la bibliothèque graphique **minilibx**.

---

## 🚀 Objectifs du projet

- Implémenter un moteur 3D basique avec raycasting en langage C  
- Utiliser la bibliothèque **MiniLibX** pour afficher graphiquement une scène 3D  
- Gérer les textures des murs avec orientation (Nord, Sud, Est, Ouest)  
- Programmer un déplacement fluide dans un environnement 3D  
- Valider et parser un fichier de carte `.cub` décrivant la scène  
- Implémenter la gestion des collisions avec les murs  
- Ajouter une **minimap** affichant la position et l’orientation du joueur  
- Gérer les événements clavier pour navigation et fermetures de fenêtre

---

## 🗂️ Structure du projet

- **Langages utilisés** :  
  - C (88.3%)  
  - Roff (documentation)  
  - Makefile  
  - Shell, Perl (scripts divers)  

- **Fichiers principaux** :  
  - Code source C (.c & .h)  
  - Makefile pour la compilation  
  - Fichiers `.cub` pour les maps

---

## 📋 Fonctionnalités

| Fonctionnalité                     | Statut                                       |
|----------------------------------|----------------------------------------------|
| Utilisation de MiniLibX           | ✔️ Oui                                      |
| Rendu 3D avec raycasting          | ✔️ Oui                                      |
| Textures différenciées par face   | ✔️ Oui (Nord, Sud, Est, Ouest)              |
| Map validation et parsing .cub    | ✔️ Oui (fichier strictement formaté)        |
| Gestion collisions murs           | ✔️ Oui (bonus)                              |
| Minimap                          | ✔️ Oui (bonus)                              |
| Mouvements avec touches WSAD      | ✔️ Oui                                      |
| Rotation vue avec flèches gauche/droite | ✔️ Oui                             |
| Fermeture propre du programme     | ✔️ Oui (touche ESC ou croix fenêtre)        |

---

## 📦 Installation

1. Clone le dépôt :
    git clone https://github.com/acanavat/Cub3D.git

   cd Cub3D

3. Compile le programme (avec MinilibX installée et configurée) :
   make

4. Lance le projet avec une map au format `.cub` :  
   ./cub3D path/to/map.cub

---

## 🗺️ Format `.cub`

Le fichier de carte `.cub` doit contenir :

- Les chemins vers les textures des murs (NO, SO, WE, EA)  
- Les couleurs du sol (`F`) et du plafond (`C`) au format RGB  
- Une carte fermée entourée de murs (`1`) et des espaces libres (`0`)  
- La position de départ du joueur (`N`, `S`, `E`, ou `W`)

Exemple minimal :

NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm
F 220,100,0
C 225,30,0

111111
100001
1000N1
100001
111111

---

## 🔧 Normes du projet

- Respect strict de la **Norminette** (règles de codage 42)  
- Pas de boucles `for`, `do while`, `switch`  
- Fonctions < 25 lignes max  
- Lignes < 80 caractères  
- Max 4 paramètres par fonction  
- Pas plus de 5 variables par fonction

---

## 📚 Ressources utiles

- Sujet officiel du projet 42 Cub3D  
- Documentation MiniLibX  
- Tutoriels raycasting (ex : tutoriels "lodev")

---

## 🌏 Meta

isibio : isibio@student.42nice.fr

acanavat : acanavat@student.42nice.fr
