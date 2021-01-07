#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<test.h>
#include "materiel.h"
#include "employe.h"
#include"employer.h"
#include "ui_materiel.h"
//#include "ui_materiel1.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   test m;
    Connection c;
    bool test=c.ouvrirConnection();
    if(test)
    {m.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
