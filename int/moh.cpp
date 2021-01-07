#include "moh.h"
#include "ui_moh.h"

moh::moh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::moh)
{
    ui->setupUi(this);
}

moh::~moh()
{
    delete ui;
}
