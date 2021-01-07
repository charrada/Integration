#include "test.h"
#include "machine.h"
#include"piece.h"
#include"materiel.h"
#include"employer.h"
#include"employe.h"
#include"employee.h"
#include"conge.h"
#include "ui_test.h"
#include<QDialog>
#include"dialog.h"
#include <QtSerialPort/QSerialPort>


test::test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::test)
{
    ui->setupUi(this);
}

test::~test()
{
    delete ui;
}

void test::on_pushButton_clicked()
{
    employer mach;
    mach.setModal(true);
    mach.exec();


}








void test::on_pushButton_2_clicked()
{
    materiel ma;
    ma.setModal(true);
    ma.exec();
}
