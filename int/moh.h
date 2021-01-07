#ifndef MOH_H
#define MOH_H

#include <QDialog>

namespace Ui {
class moh;
}

class moh : public QDialog
{
    Q_OBJECT

public:
    explicit moh(QWidget *parent = nullptr);
    ~moh();

private:
    Ui::moh *ui;
};

#endif // MOH_H
