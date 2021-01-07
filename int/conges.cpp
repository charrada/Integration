#include "conges.h"
#include<QDebug>
#include"employer.h"
#include"employe.h"
#include"gemp.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"



conges::conges()
{

}

conges::conges(const QString &id, const QString &unite, const QString &nom, const QString &prenom, const QString &njc, const QString &njcp, const QString &njcf, const QString &njcr,const QString &njcm)
        : id(id), unite (unite), nom(nom), prenom(prenom), njc(njc), njcp(njcp), njcf(njcf), njcr(njcr), njcm(njcm) {}
const QString &conges::getid() const {
    return id;
}

void conges::setid(const QString &id) {
    conges::id = id;
}



const QString &conges::getunite() const {
    return unite;
}

void conges::setunite(const QString &unite) {
    conges::unite = unite;
}
const QString &conges::getNom() const {
    return nom;
}

void conges::setNom(const QString &nom) {
    conges::nom = nom;
}

const QString &conges::getprenom() const {
    return prenom;
}
void conges::setprenom(const QString &prenom) {
    conges::prenom = prenom;
}
    const QString &conges::getnjc() const {
        return njc;}
    void conges::setnjc(const QString &njc) {
        conges::njc = njc;
}
        const QString &conges::getnjcp() const {
            return njcp;}
        void conges::setnjcp(const QString &njcp) {
            conges::njcp = njcp;
}
            const QString &conges::getnjcf() const {
                return njcf;}
            void conges::setnjcf(const QString &njcf) {
                conges::njcf = njcf;
}
                const QString &conges::getnjcr() const {
                    return njcr;}
                void conges::setnjcr(const QString &njcr) {
                    conges::njcr = njcr;
}
                    const QString &conges::getnjcm() const {
                        return njcm;}
                    void conges::setnjcm(const QString &njcm) {
                        conges::njcm = njcm;
}
bool conges::add()
{
    QSqlQuery query;

        query.prepare("INSERT INTO conge (ID, UNITE, NOM, PRENOM, NJC, NJCP, NJCF, NJCR, NJCM) "
                      "VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)");
        query.bindValue(0, this->id);
        query.bindValue(1, this->unite);
        query.bindValue(2, this->nom);
        query.bindValue(3, this->prenom);
        query.bindValue(4, this->njc);
        query.bindValue(5, this->njcp);
        query.bindValue(6, this->njcf);
        query.bindValue(7, this->njcr);
        query.bindValue(8, this->njcm);
        return query.exec();
}
QSqlQueryModel *conges::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from conge");


    return model;

}
bool conges::delet()

{
QSqlQuery query;
    query.prepare("delete from conge where id=:todelete");
            query.bindValue(":todelete",id);
            return query.exec();

}
QSqlQueryModel *conges::tri1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from conge order by NOM ");


    return model;

}
