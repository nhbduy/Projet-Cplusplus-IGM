#include "fenclient.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FenClient w;
 //  w.setStyleSheet("background-image:url(:Alg2.jpg)");
    w.show();

    return a.exec();
}
