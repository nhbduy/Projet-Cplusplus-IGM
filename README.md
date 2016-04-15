# Projet C++ IGM 2016.
Sujet : Tuteur Algèbre
(mode console, graphique et client-serveur)

Le travail réalisé dans le cadre d’une formation en Master 2 Informatique SSIO avec le langage de programmation C++. Ce projet a été réalisé par le trinôme.
-----------------------------------------------------------------------------------------
#Enoncé
L'objectif est de créer un programme fonctionnel en C++ utilisant les concepts de la P.O.O.
L'application devra simuler un face à face pédagogique entre un ou plusieurs élèves et un professeur en mode client-serveur. Un gestion de la concurrence devra être mis en place côté serveur.
L'élève, le client, traite un exercice fourni par son professeur, le serveur, et lui remet sa copie.
Le professeur corrige la copie, fournit des annotations, et la retourne à l'élève accompagnée du corrigé de l'exercice.
-----------------------------------------------------------------------------------------
#Fonctionnalités
L’application “Tuteur Algèbre” simule un face à face pédagogique entre un ou plusieurs élèves et un professeur en mode client-serveur.
L’élève (le client) traite un exercice fourni par son professeur (le serveur) et lui remet sa copie.
Le professeur corrige la copie, fournit des annotations, et la retourne à l’élève accompagnée du corrigé de l’exercice.
Il existe deux version pour les interactions entre élèves et professeur : mode console et mode graphique (réalisée avec Qt).
Il y a aussi une gestion de la concurrence qui est mis en place côté serveur.
-----------------------------------------------------------------------------------------
#Répertoire 
Le repertoire de cette application contient principalement des fichiers .ccp, des fichiers .h, un Makefile, un manuel d’utilisation, un README et une batterie de test version.
Nous avons nommé cette version V1.0 nous espérons qu’elle soit améliorer dans le futur. 
-----------------------------------------------------------------------------------------
#Licence 
Cette application a été conçue pour un but pédagogique non lucratif en open source.
-----------------------------------------------------------------------------------------

#Comment utiliser le Makefile ?
On utilise la compilateur g++ avec des options pthread (pour le serveur multi-threads) et std=c++11 (pour la nouvelle librairie C++11). 
  + make all : compiler pour toutes les parties (main, tool, socket)
  + make main : compiler pour le test (main)
  + make tool : compiler pour l’outil (tool)
  + make socket : compiler pour le client-serveur via réseau TCP (socket)
  + make clean : supprimer les fichiers de sortie (*.o)
  + make txtclean : supprimer les fichiers de texte (*.txt)
  + make distclean : supprimer tous les fichiers compilés (*.o, *.txt, *.exe)

1/ Mode console
+ Test des expressions (main) => "make all"
+ Outil de création et évaluation des expressions (tool) => "make tool"
+ Client-serveur pour la connexion via TCP (socket) => "make socket"

2/ Mode graphique (en cours)
Qt framework (TCP socket)
