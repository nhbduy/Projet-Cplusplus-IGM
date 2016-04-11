/********************************************************************************
** Form generated from reading UI file 'fenclient.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENCLIENT_H
#define UI_FENCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenClient
{
public:
    QTextEdit *listeMessages;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *boutonEnvoyer;
    QLineEdit *message;
    QLineEdit *pseudo;
    QLabel *label_2;
    QPushButton *boutonConnexion;
    QSpinBox *serveurPort;
    QLabel *label;
    QLineEdit *serveurIP;

    void setupUi(QWidget *FenClient)
    {
        if (FenClient->objectName().isEmpty())
            FenClient->setObjectName(QStringLiteral("FenClient"));
        FenClient->resize(734, 480);
        QIcon icon;
        icon.addFile(QStringLiteral("../Desktop/icon.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FenClient->setWindowIcon(icon);
        listeMessages = new QTextEdit(FenClient);
        listeMessages->setObjectName(QStringLiteral("listeMessages"));
        listeMessages->setGeometry(QRect(20, 130, 681, 161));
        listeMessages->setReadOnly(true);
        label_5 = new QLabel(FenClient);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 741, 481));
        label_5->setStyleSheet(QLatin1String("#label_5{\n"
"background-color:transparent;\n"
"border-image:url(:Alg6);\n"
"background:none;\n"
"background-repeart:none;\n"
"}"));
        label_5->setWordWrap(true);
        label_3 = new QLabel(FenClient);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 360, 94, 17));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_3->setFont(font);
        label_3->setStyleSheet(QLatin1String("#label_3{\n"
"color: black;\n"
"background-color:white;\n"
"\n"
"}"));
        label_4 = new QLabel(FenClient);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(290, 360, 156, 17));
        label_4->setFont(font);
        label_4->setStyleSheet(QLatin1String("#label_4{\n"
"color: black;\n"
"background-color:white;\n"
"\n"
"}"));
        boutonEnvoyer = new QPushButton(FenClient);
        boutonEnvoyer->setObjectName(QStringLiteral("boutonEnvoyer"));
        boutonEnvoyer->setGeometry(QRect(620, 410, 110, 32));
        QIcon icon1;
        icon1.addFile(QStringLiteral("chat.png"), QSize(), QIcon::Normal, QIcon::Off);
        boutonEnvoyer->setIcon(icon1);
        message = new QLineEdit(FenClient);
        message->setObjectName(QStringLiteral("message"));
        message->setGeometry(QRect(470, 360, 231, 21));
        pseudo = new QLineEdit(FenClient);
        pseudo->setObjectName(QStringLiteral("pseudo"));
        pseudo->setGeometry(QRect(140, 360, 100, 21));
        pseudo->setMaximumSize(QSize(100, 16777215));
        label_2 = new QLabel(FenClient);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 39, 115, 17));
        label_2->setFont(font);
        label_2->setStyleSheet(QLatin1String("#label_2{\n"
"color: black;\n"
"background-color:white;\n"
"\n"
"}"));
        boutonConnexion = new QPushButton(FenClient);
        boutonConnexion->setObjectName(QStringLiteral("boutonConnexion"));
        boutonConnexion->setGeometry(QRect(610, 100, 106, 32));
        serveurPort = new QSpinBox(FenClient);
        serveurPort->setObjectName(QStringLiteral("serveurPort"));
        serveurPort->setGeometry(QRect(480, 40, 72, 24));
        serveurPort->setMinimumSize(QSize(60, 0));
        serveurPort->setMinimum(1024);
        serveurPort->setMaximum(65535);
        serveurPort->setValue(50885);
        label = new QLabel(FenClient);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 40, 99, 17));
        label->setFont(font);
        label->setStyleSheet(QLatin1String("#label{\n"
"color: black;\n"
"background-color:white;\n"
"\n"
"}"));
        serveurIP = new QLineEdit(FenClient);
        serveurIP->setObjectName(QStringLiteral("serveurIP"));
        serveurIP->setGeometry(QRect(160, 40, 125, 21));
        serveurIP->setMaximumSize(QSize(150, 16777215));
        label_5->raise();
        label_3->raise();
        label_4->raise();
        boutonEnvoyer->raise();
        message->raise();
        pseudo->raise();
        label_2->raise();
        boutonConnexion->raise();
        serveurPort->raise();
        label->raise();
        serveurIP->raise();
        listeMessages->raise();

        retranslateUi(FenClient);

        QMetaObject::connectSlotsByName(FenClient);
    } // setupUi

    void retranslateUi(QWidget *FenClient)
    {
        FenClient->setWindowTitle(QApplication::translate("FenClient", "PlateformeAlgebrique- Client", 0));
        label_5->setText(QString());
        label_3->setText(QApplication::translate("FenClient", "Nom Etudiant", 0));
        label_4->setText(QApplication::translate("FenClient", "Expression Algebrique", 0));
        boutonEnvoyer->setText(QApplication::translate("FenClient", "Envoyer", 0));
        label_2->setText(QApplication::translate("FenClient", "Port du serveur :", 0));
        boutonConnexion->setText(QApplication::translate("FenClient", "Connexion", 0));
        label->setText(QApplication::translate("FenClient", "IP du serveur :", 0));
        serveurIP->setText(QApplication::translate("FenClient", "127.0.0.1", 0));
    } // retranslateUi

};

namespace Ui {
    class FenClient: public Ui_FenClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENCLIENT_H
