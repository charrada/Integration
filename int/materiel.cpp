
#include "materiel.h"
#include "ui_materiel.h"
#include "machine.h"
#include "piece.h"
#include "materiel.h"
#include"dialog.h"
#include<QDialog>

#include <QMessageBox>

materiel::materiel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::materiel)
{
    ui->setupUi(this);

    ui->code_mach->setValidator(new QRegExpValidator( QRegExp("[1-9]*"), this ));
    ui->type_mach->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));

    ui->code_m->setValidator(new QRegExpValidator( QRegExp("[1-9]*"), this ));
    ui->nom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));

    //ui->date_mach->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));
    //ui->lineEdit_type->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));

    //ui->lineEdit_modepaiement->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));
    //ui->lineEdit_nomcommerce->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));
   // ui->lineEdit_nomproprietaire->setValidator(new QRegExpValidator( QRegExp("[A-Za-z ]*"), this ));

    afficher();

}
void materiel::afficher()
{

//**************
    proxy_machine = new QSortFilterProxyModel();
    proxy_machine ->setSourceModel(tmp.afficher());
        proxy_machine ->setFilterCaseSensitivity(Qt::CaseInsensitive);
        proxy_machine ->setFilterKeyColumn(selected_machine);
      ui->tab_machine->setModel(proxy_machine );

            proxy_piece = new QSortFilterProxyModel();
            proxy_piece->setSourceModel(emp.afficher());
                proxy_piece->setFilterCaseSensitivity(Qt::CaseInsensitive);
                proxy_piece->setFilterKeyColumn(selected_piece);
            ui->tab_piece->setModel(proxy_piece);

}


materiel::~materiel()
{
    delete ui;
}




void materiel::on_ajout_mach_clicked()
{


    int code_mach =ui->code_mach->text().toInt();
        QString type_mach =ui->type_mach->text();
        QDate date_mach=ui->date_mach->date();

        machine m(code_mach,type_mach,date_mach);

        bool test=m.ajouter();

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("ajouter une machine"),
                        QObject::tr("machine ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("ajouter une machine"),
                        QObject::tr("machine non ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }


}

void materiel::on_modifier_mach_clicked()
{
    int code_mach =ui->code_mach->text().toInt();
        QString type_mach =ui->type_mach->text();
        QDate date_mach=ui->date_mach->date();

        machine m(code_mach,type_mach,date_mach);

        bool test=m.editer();

        if(test){
            afficher();

    QMessageBox::information(nullptr, QObject::tr("edité une machine"),
                        QObject::tr("machine edité.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("editer une machine"),
                        QObject::tr("machine non edité.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }



}

void materiel::on_supp_mach_clicked()
{
    int code_mach =ui->code_mach->text().toInt();




        bool test=tmp.supprimer(code_mach);

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("supprimer une machine"),
                        QObject::tr("machine supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("supprimer une machine"),
                        QObject::tr("machine non supprimée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }

}

void materiel::on_ajout_p_clicked()
{
    int code_m =ui->code_m->text().toInt();
    int code_p =ui->code_p->text().toInt();
        QString nom =ui->nom->text();
        QDate date_piece=ui->date_piece->date();

        piece p(code_m,code_p,nom,date_piece);

        bool test=p.ajouter();

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("ajouter une piece"),
                        QObject::tr("piece ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("ajouter une piece"),
                        QObject::tr("piece non ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }



}

void materiel::on_modifier_p_clicked()
{  int code_m =ui->code_m->text().toInt();
    int code_p =ui->code_p->text().toInt();
        QString nom =ui->nom->text();
        QDate date_piece=ui->date_piece->date();

        piece p(code_m,code_p,nom,date_piece);

        bool test=p.editer();

        if(test){
              afficher();

    QMessageBox::information(nullptr, QObject::tr("editer une piece"),
                        QObject::tr("piece éditée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



    }
        else{
            QMessageBox::critical(nullptr, QObject::tr("editer une piece"),
                        QObject::tr("piece non editée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


     }





}

void materiel::on_supp_p_clicked()
{
    int code_m =ui->code_m->text().toInt();




        bool test=emp.supprimer(code_m);

        if(test){
              afficher();
            QMessageBox::information(nullptr, QObject::tr("Supprimer une piece"),
                                QObject::tr("piece supprimer.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);



            }
                else{
                    QMessageBox::critical(nullptr, QObject::tr("Supprimer une piece"),
                                QObject::tr("piece non supprimer.\n"
                                            "Click Cancel to exit."), QMessageBox::Cancel);


             }

        }

//type
void materiel::on_comboBox_piece_currentIndexChanged(int index)
{
    selected_machine=ui->comboBox_piece->currentIndex();
            afficher();

}
//rech

void materiel::on_lineEdit_machine_textChanged(const QString &arg1)
{
     proxy_machine->setFilterFixedString(arg1);
}

void materiel::on_lineEdit_piece_textChanged(const QString &arg2)
{
     proxy_piece->setFilterFixedString(arg2);
}

void materiel::on_comboBox_machine_currentIndexChanged(int index)
{
    selected_machine=ui->comboBox_machine->currentIndex();
            afficher();
}

/*void materiel::on_pushButton_clicked()
{
    ui->tab_machine->setModel(machine.tri());
}*/










void materiel::on_imprimer_clicked()
{

        QPrinter printer;
                    QPrintDialog * printDialog = new QPrintDialog(&printer, this);
                    printDialog->setWindowTitle("Imprimer Document");
                    printDialog->exec();

}

void materiel::on_pushButton_pdf_clicked()

{

            QString strStream;
                              QTextStream out(&strStream); //eureur

                                const int rowCount = ui->tab_machine->model()->rowCount();
                                const int columnCount = ui->tab_machine->model()->columnCount();

                                out <<  "<html>\n"
                                    "<head>\n"
                                    "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                    <<  QString("<title>%1</title>\n").arg("strTitle")
                                    <<  "</head>\n"
                                    "<body bgcolor=#ffffff link=#5000A0>\n"

                                   //     "<align='right'> " << datefich << "</align>"
                                    "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                // headers
                                out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                for (int column = 0; column < columnCount; column++)
                                    if (!ui->tab_machine->isColumnHidden(column))
                                        out << QString("<th>%1</th>").arg(ui->tab_machine->model()->headerData(column, Qt::Horizontal).toString());
                                out << "</tr></thead>\n";

                                // data table
                                for (int row = 0; row < rowCount; row++) {
                                    out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                    for (int column = 0 ; column < columnCount; column++) {
                                        if (!ui->tab_machine->isColumnHidden(column)) {
                                            QString data = ui->tab_machine->model()->data(ui->tab_machine->model()->index(row, column)).toString().simplified();
                                            out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                        }
                                    }
                                    out << "</tr>\n";
                                }
                                out <<  "</table> </center>\n"
                                    "</body>\n"
                                    "</html>\n";

                          QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                            if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                           QPrinter printer (QPrinter::PrinterResolution);
                            printer.setOutputFormat(QPrinter::PdfFormat);
                           printer.setPaperSize(QPrinter::A4);
                          printer.setOutputFileName(fileName);

                           QTextDocument  doc;
                            doc.setHtml(strStream);
                            doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                            doc.print(&printer);
            }


//************************************************








void materiel::on_imprimer1_clicked()
{
    QPrinter printer;
                QPrintDialog * printDialog = new QPrintDialog(&printer, this);
                printDialog->setWindowTitle("Imprimer Document");
                printDialog->exec();

}



void materiel::on_pdf1_clicked()
{
    QString strStream;
                      QTextStream out(&strStream); //eureur

                        const int rowCount = ui->tab_machine->model()->rowCount();
                        const int columnCount = ui->tab_machine->model()->columnCount();

                        out <<  "<html>\n"
                            "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                            <<  QString("<title>%1</title>\n").arg("strTitle")
                            <<  "</head>\n"
                            "<body bgcolor=#ffffff link=#5000A0>\n"

                           //     "<align='right'> " << datefich << "</align>"
                            "<center> <H1>Liste des commandes </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                        // headers
                        out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                        for (int column = 0; column < columnCount; column++)
                            if (!ui->tab_machine->isColumnHidden(column))
                                out << QString("<th>%1</th>").arg(ui->tab_machine->model()->headerData(column, Qt::Horizontal).toString());
                        out << "</tr></thead>\n";

                        // data table
                        for (int row = 0; row < rowCount; row++) {
                            out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                            for (int column = 0 ; column < columnCount; column++) {
                                if (!ui->tab_machine->isColumnHidden(column)) {
                                    QString data = ui->tab_machine->model()->data(ui->tab_machine->model()->index(row, column)).toString().simplified();
                                    out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                }
                            }
                            out << "</tr>\n";
                        }
                        out <<  "</table> </center>\n"
                            "</body>\n"
                            "</html>\n";

                  QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                   QPrinter printer (QPrinter::PrinterResolution);
                    printer.setOutputFormat(QPrinter::PdfFormat);
                   printer.setPaperSize(QPrinter::A4);
                  printer.setOutputFileName(fileName);

                   QTextDocument  doc;
                    doc.setHtml(strStream);
                    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                    doc.print(&printer);

}



void materiel::on_pushButton_clicked()
{
    Dialog mach;
    mach.setModal(true);
    mach.exec();

}
