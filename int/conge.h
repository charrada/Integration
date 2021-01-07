#ifndef CONGE_H
#define CONGE_H
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include"gemp.h"
#include <QSqlQueryModel>


class conge
{
public:
    QString id;
        QString unite;
        QString nom;
        QString prenom;
         QString njc;
          QString njcp;
           QString njcf;
            QString njcr;
             QString njcm;

public:
    conge();
    conge(const QString &id, const QString &unite, const QString &nom, const QString &prenom, const QString &njc, const QString &njcpadresse, const QString &njcf, const QString &njcr, const QString &njcm);

    const QString &getid() const;
    void setid(const QString &id);

    const QString &getunite() const;
    void setunite(const QString &id);

    const QString &getNom() const;
    void setNom(const QString &nom);

    const QString &getprenom() const;
    void setprenom(const QString &prenom);

    const QString &getnjc() const;
    void setnjc(const QString &njc);

    const QString &getnjcp() const;
    void setnjcp(const QString &njcp);

    const QString &getnjcf() const;
    void setnjcf(const QString &njcf);

    const QString &getnjcr() const;
    void setnjcr(const QString &njcr);

    const QString &getnjcm() const;
    void setnjcm(const QString &njcm);


 bool add();
 QSqlQueryModel *list();
 bool delet();
QSqlQueryModel *tri1();
};

#endif
