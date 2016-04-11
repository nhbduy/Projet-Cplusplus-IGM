/********************************************************************************
** Form generated from reading UI file 'fenserveur.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENSERVEUR_H
#define UI_FENSERVEUR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FenServeur
{
public:

    void setupUi(QWidget *FenServeur)
    {
        if (FenServeur->objectName().isEmpty())
            FenServeur->setObjectName(QStringLiteral("FenServeur"));
        FenServeur->resize(398, 165);

        retranslateUi(FenServeur);

        QMetaObject::connectSlotsByName(FenServeur);
    } // setupUi

    void retranslateUi(QWidget *FenServeur)
    {
        FenServeur->setWindowTitle(QApplication::translate("FenServeur", "FenServeur", 0));
    } // retranslateUi

};

namespace Ui {
    class FenServeur: public Ui_FenServeur {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENSERVEUR_H
