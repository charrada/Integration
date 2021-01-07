#include "employe.h"
#include"employer.h"
#include<QDebug>




employe::employe()
{

}

employe::employe(const QString &id, const QString &unite, const QString &nom, const QString &prenom, const QString datenai )
        : id(id), unite (unite), nom(nom), prenom(prenom), datenai(datenai) {}
const QString &employe::getid() const {
    return id;
}

void employe::setid(const QString &id) {
    employe::id = id;
}



const QString &employe::getunite() const {
    return unite;
}

void employe::setunite(const QString &unite) {
    employe::unite = unite;
}
const QString &employe::getnom() const {
    return nom;
}

void employe::setnom(const QString &nom) {
    employe::nom = nom;
}

const QString &employe::getprenom() const {
    return prenom;
}
void employe::setprenom(const QString &prenom) {
    employe::prenom = prenom;
}
    const QString &employe::getdatenai() const {
        return datenai;}
    void employe::setdatenai(const QString &datenai) {
        employe::datenai = datenai;
}

bool employe::add()
{
    QSqlQuery query;

        query.prepare("INSERT INTO employe (ID, UNITE, NOM, PRENOM, DATENAI ) "
                      "VALUES (?, ?, ?, ?, ?)");
        query.bindValue(0, this->id);
        query.bindValue(1, this->unite);
        query.bindValue(2, this->nom);
        query.bindValue(3, this->prenom);
        query.bindValue(4, this->datenai);
        return query.exec();
}
QSqlQueryModel *employe::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");


    return model;

}
bool employe::delet()

{
QSqlQuery query;
    query.prepare("delete from employe where id=:todelete");
            query.bindValue(":todelete",id);
            return query.exec();

}
QSqlQueryModel *employe::tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe order by NOM ");


    return model;

}
