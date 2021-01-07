#ifndef EMPLOYER_H
#define EMPLOYER_H
#include "conge.h"
#include "employe.h"
#include <QMainWindow>
#include<QDialog>
namespace Ui { class emp1; }


class employer: public QDialog
{
    Q_OBJECT

public:
    emp1(QWidget *parent = nullptr);
   // ~employer();

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
    Ui::emp1 *ui;
    conge conge ;
    emp1 employe ;

};
#endif // MAINWINDOW_H
