#include "try.h"
#include "ui_try.h"

try::try(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::try)
{
    ui->setupUi(this);
}

try::~try()
{
delete ui;
}
