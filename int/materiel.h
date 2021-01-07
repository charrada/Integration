#ifndef MATERIEL_H
#define MATERIEL_H
#include <QPrinter>
#include <QDialog>
#include "machine.h"
#include "piece.h"
/*#include <QSortFilterProxyModel>
#include <QTextTableFormat>
#include <QStandardItemModel>
#include<QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QFileDialog>
#include <QTextTableFormat>
#include <QStandardItemModel>*/
#include <QDialog>
#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QByteArray>
#include <QSortFilterProxyModel>
#include"dialog.h"
#include <QTextTableFormat>
#include <QStandardItemModel>

#include <QPropertyAnimation>

#include <QFileDialog>
#include <QMessageBox>
#include <QPushButton>
//#include <QtMultimedia/QSound>
#include <QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextStream>


namespace Ui {
class materiel;
}

class materiel : public QDialog
{
    Q_OBJECT

public:
    explicit materiel(QWidget *parent = nullptr);
    ~materiel();

    QSortFilterProxyModel *proxy_machine,*proxy_piece;

    void afficher();
private slots:




    void on_ajout_mach_clicked();

    void on_modifier_mach_clicked();

    void on_supp_mach_clicked();

    void on_ajout_p_clicked();

    void on_modifier_p_clicked();

    void on_supp_p_clicked();



    void on_comboBox_piece_currentIndexChanged(int index);

    void on_lineEdit_machine_textChanged(const QString &arg1);

    void on_lineEdit_piece_textChanged(const QString &arg1);

    void on_comboBox_machine_currentIndexChanged(int index);

    void on_lineEdit_piece_cursorPositionChanged(int arg1, int arg2);

    void on_pushButton_clicked();

    void on_imprimer_clicked();

    void on_pushButton_pdf_clicked();

    void on_imprimer1_clicked();

    void on_pdf_clicked();

    void on_pdf1_clicked();

private:
    Ui::materiel *ui;

   machine  tmp;
   piece   emp;
   int selected_machine=0;
       int selected_piece=0;
         QStringList files;
};

#endif // MATERIEL_H
