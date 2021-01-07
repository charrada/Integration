#include "employee.h"
#include "ui_employee.h"
#include "employe.h"
#include "conge.h"
#include"test.h"
#include <QMessageBox>
#include<QDialog>

employee::employee(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::employee)
{
    ui->setupUi(this);

    //afficher();

}void employee::on_pushButton_12_clicked()// ajouter conge
{
    QString id = ui->le_idd->text();
    QString unite = ui->le_unitee->text();
        QString NOM = ui->le_nomm->text();
        QString prenom = ui->le_prenomm->text();
        QString njc = ui->le_njcc->text();
        QString njcp = ui->le_njcpp->text();
            QString njcf = ui->le_njcff->text();
            QString njcr = ui->le_njcrr->text();
            QString njcm = ui->le_njcmm->text();



        conge.setid(id);
        conge.setunite(unite);
        conge.setNom(NOM);
        conge.setprenom(prenom);
        conge.setnjc(njc);
        conge.setnjcp(njcp);
        conge.setnjcf(njcf);
        conge.setnjcr(njcr);
        conge.setnjcm(njcm);


        if (conge.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }


}


void employee::on_pushButton_11_clicked()
{
    ui->tableView_2->setModel(conge.tri1());
}

void employee::on_pushButton_6_clicked() // supp conge
{
    QString id = ui->le_id_supp->text();
        conge.setid(id);
        if (conge.delet())
        {
            QMessageBox::information(this, "success ", "supprimÃ© avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}

void employee::on_pushButton_13_clicked()//modifier conge
{
            QString id = ui->lineEdit_35->text();
            QString unite = ui->lineEdit_25->text();
            QString NOM = ui->lineEdit_26->text();
            QString prenom = ui->lineEdit_27->text();
            QString njc = ui->lineEdit_28->text();
            QString njcp = ui->lineEdit_29->text();
            QString njcf = ui->lineEdit_30->text();
            QString njcr = ui->lineEdit_31->text();
            QString njcm = ui->lineEdit_32->text();



            conge.setunite(unite);
            conge.setNom(NOM);
            conge.setprenom(prenom);
            conge.setnjc(njc);
            conge.setnjc(njcp);
            conge.setnjc(njcf);
            conge.setnjc(njcr);
            conge.setnjc(njcm);
            QSqlQuery query;

            query.prepare("update conge set  UNITE:=unite,NOM=:nom,PRENOM=:prenom,NJC=:njc,NJCP=:njcp,NJCF=:njcf,NJCR=:njcr,NJCM=:njcm where ID=:id");

            query.bindValue(":id",id);

            query.bindValue(":unite",unite);
                query.bindValue(":NOM",NOM);
                query.bindValue(":prenom",prenom);
                query.bindValue(":njc",njc);
                query.bindValue(":njcp",njcp);
                query.bindValue(":njcf",njcf);
                query.bindValue(":njcr",njcr);
                query.bindValue(":njcm",njcm);

            query.exec();
            if(query.exec()){
                QMessageBox::information (this, "update", "conge updated");
                ui->lineEdit_35->setText("");
            }


            else {QMessageBox::critical (this, "Error", "unexpected error");}
    }


void employee::on_pushButton_14_clicked()// recherchefil modifier
{
    QString id = ui->lineEdit_35->text();
           QSqlQuery query;
           query.prepare("Select * from conge where id=:id");
           query.bindValue(":id", id);
           query.exec();
           if(query.next())
           {
               ui->lineEdit_36->setText(query.value(1).toString());
               ui->lineEdit_23->setText(query.value(2).toString());
               ui->lineEdit_24->setText(query.value(3).toString());
               ui->lineEdit_37->setText(query.value(4).toString());
               ui->lineEdit_38->setText(query.value(5).toString());
               ui->lineEdit_39->setText(query.value(6).toString());
               ui->lineEdit_40->setText(query.value(7).toString());
               ui->lineEdit_41->setText(query.value(8).toString());



           }
}



void employee::on_pushButton_8_clicked()// ajou empl
{

    QString id = ui->le_IDD->text();
    QString unite = ui->le_unitee_2->text();
        QString nom = ui->le_nom->text();
        QString prenom = ui->le_prenomm_2->text();
        QString datenai = ui->la_datt->text();



        employe.setid(id);
        employe.setunite(unite);
        employe.setnom(nom);
        employe.setprenom(prenom);
        employe.setdatenai(datenai);


        if (employe.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }


}

void employee::on_tabWidget_3_currentChanged(int index)// affich employe
{
    if ( index == 0){
    ui->tableView->setModel(employe.list());
    }
}


void employee::on_pushButton_9_clicked()// supp fil employe
{
    QString id = ui->lineEdit_10->text();
        employe.setid(id);
        if (employe.delet())
        {
            QMessageBox::information(this, "success ", "supprimÃ© avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }


}

void employee::on_pushButton_15_clicked()// recherch fil mod employe
{
    QString id = ui->lineEdit_14->text();
           QSqlQuery query;
           query.prepare("Select * from employe where id=:id");
           query.bindValue(":id", id);
           query.exec();
           if(query.next())
           {   ui->lineEdit_7->setText(query.value(0).toString());
               ui->lineEdit_8->setText(query.value(1).toString());
               ui->lineEdit_9->setText(query.value(2).toString());
               ui->lineEdit_21->setText(query.value(3).toString());
               ui->lineEdit_3->setText(query.value(4).toString());




           }
}

void employee::on_pushButton_10_clicked()
{
    QString id = ui->lineEdit_5->text();
    QString unite = ui->lineEdit_6->text();
    QString nom = ui->lineEdit_13->text();
    QString prenom = ui->lineEdit_11->text();
    QString datenai = ui->lineEdit_12->text();


    employe.setid(id);
    employe.setunite(unite);
    employe.setnom(nom);
    employe.setprenom(prenom);
    employe.setdatenai(datenai);
     QSqlQuery query;

    query.prepare("update conge set  ID:=id,UNITE:=unite,NOM=:nom,PRENOM=:prenom,DATENAI:=datenaiwhere ID=:id");

    query.bindValue(":id",id);

    query.bindValue(":unite",unite);
        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":datenai",datenai);

    query.exec();
    if(query.exec()){
        QMessageBox::information (this, "update", "employe updated");
        ui->lineEdit_5->setText("");
    }


    else {QMessageBox::critical (this, "Error", "unexpected error");}

}

void employee::on_tabWidget_2_currentChanged(int index)
{
    if ( index == 1){
    ui->tableView_2->setModel(conge.list());
    }
}

void employee::on_pushButton_7_clicked()
{

    ui->tableView->setModel(employe.tri());
    }


