#include "conge.h"
#include<QDebug>
#include"employer.h"
#include"employe.h"
#include"gemp.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"



conge::conge()
{

}

conge::conge(const QString &id, const QString &unite, const QString &nom, const QString &prenom, const QString &njc, const QString &njcp, const QString &njcf, const QString &njcr,const QString &njcm)
        : id(id), unite (unite), nom(nom), prenom(prenom), njc(njc), njcp(njcp), njcf(njcf), njcr(njcr), njcm(njcm) {}
const QString &conge::getid() const {
    return id;
}

void conge::setid(const QString &id) {
    conge::id = id;
}



const QString &conge::getunite() const {
    return unite;
}

void conge::setunite(const QString &unite) {
    conge::unite = unite;
}
const QString &conge::getNom() const {
    return nom;
}

void conge::setNom(const QString &nom) {
    conge::nom = nom;
}

const QString &conge::getprenom() const {
    return prenom;
}
void conge::setprenom(const QString &prenom) {
    conge::prenom = prenom;
}
    const QString &conge::getnjc() const {
        return njc;}
    void conge::setnjc(const QString &njc) {
        conge::njc = njc;
}
        const QString &conge::getnjcp() const {
            return njcp;}
        void conge::setnjcp(const QString &njcp) {
            conge::njcp = njcp;
}
            const QString &conge::getnjcf() const {
                return njcf;}
            void conge::setnjcf(const QString &njcf) {
                conge::njcf = njcf;
}
                const QString &conge::getnjcr() const {
                    return njcr;}
                void conge::setnjcr(const QString &njcr) {
                    conge::njcr = njcr;
}
                    const QString &conge::getnjcm() const {
                        return njcm;}
                    void conge::setnjcm(const QString &njcm) {
                        conge::njcm = njcm;
}
bool conge::add()
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
QSqlQueryModel *conge::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from conge");


    return model;

}
bool conge::delet()

{
QSqlQuery query;
    query.prepare("delete from conge where id=:todelete");
            query.bindValue(":todelete",id);
            return query.exec();

}
QSqlQueryModel *conge::tri1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from conge order by NOM ");


    return model;

}
