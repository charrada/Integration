#ifndef TEST_H
#define TEST_H
#include"employer.h"
#include <QDialog>

namespace Ui {
class test;
}

class test : public QDialog
{
    Q_OBJECT

public:
    explicit test(QWidget *parent = nullptr);
    ~test();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::test *ui;
};

#endif // TEST_H
