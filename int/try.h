#ifndef TRY_H
#define TRY_H

#include <QDialog>

namespace Ui {
class try;
}

class try : public QDialog
{
    Q_OBJECT

public:
    explicit try(QWidget *parent = nullptr);
    ~try();

private:
    Ui::try *ui;
};

#endif // TRY_H
