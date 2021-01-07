#include "emp1.h"
#include "ui_emp1.h"

emp1::emp1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::emp1)
{
    ui->setupUi(this);
}

emp1::~emp1()
{
    delete ui;
}
