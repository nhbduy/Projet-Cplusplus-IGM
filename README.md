# Projet-Cplusplus-IGM
Projet C++ IGM 2016. Sujet : Tuteur Algèbre (mode client-serveur)

On utilise la compilateur g++ avec des options pthread (pour le serveur multi-threads) et std=c++11 (pour la nouvelle librairie C++11) :
  #make all : compiler pour toutes les parties (main, tool, socket)
  #make main : compiler pour le test (main)
  #make tool : compiler pour l’outil (tool)
  #make socket : compiler pour le client-serveur via réseau TCP (socket)
  #make clean : supprimer les fichiers de sortie (*.o)
  #make txtclean : supprimer les fichiers de texte (*.txt)
  #make distclean : supprimer tous les fichiers compilés (*.o, *.txt, *.exe)

1/ Mode console
+ Test des expressions (main) => "make all"
+ Outil de création et évaluation des expressions (tool) => "make tool"
+ Client-serveur pour la connexion via TCP (socket) => "make socket"

2/ Mode graphique (en cours)
Qt framework (TCP socket)
