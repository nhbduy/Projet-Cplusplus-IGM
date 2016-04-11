#ifndef FENSERVEUR_H
#define FENSERVEUR_H

#include <QWidget>
#include <QtNetwork>
#include <QLabel>
#include <QPushButton>
namespace Ui {
class FenServeur;
}

class FenServeur : public QWidget
{
    Q_OBJECT

public:
     FenServeur();
     void envoyerATous(const QString &message);
 private slots:
     void nouvelleConnexion();
         void donneesRecues();
         void deconnexionClient();

     private:
         QLabel *etatServeur;
         QPushButton *boutonQuitter;

         QTcpServer *serveur;
         QList<QTcpSocket *> clients;
         quint16 tailleMessage;


};

#endif // FENSERVEUR_H
