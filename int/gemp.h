#ifndef GEMP_H
#define GEMP_H

#include <QDialog>
#include "conge.h"
#include"conges.h"
#include "employe.h"
#include <QMainWindow>
namespace Ui {
class gemp;
}

class gemp : public QDialog
{
    Q_OBJECT

public:
    explicit gemp(QWidget *parent = nullptr);
   // ~gemp();
private slots:
    void on_pushButton_12_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_6_clicked();

    void on_label_58_linkActivated(const QString &link);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_tabWidget_2_currentChanged(int index);

    void on_pushButton_8_clicked();

    void on_tabWidget_3_currentChanged(int index);

    void on_pushButton_7_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_10_clicked();
private:
    Ui::gemp *ui;
    employe employe;
};

#endif // GEMP_H
