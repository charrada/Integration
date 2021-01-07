#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>


class employe
{
public:
        QString id;
        QString unite;
        QString nom;
        QString prenom;
        QString datenai;
    employe();
    employe(const QString &id, const QString &unite, const QString &nom, const QString &prenom, const QString datenai );

    const QString &getid() const;
    void setid(const QString &id);

    const QString &getunite() const;
    void setunite(const QString &unite);

    const QString &getnom() const;
    void setnom(const QString &nom);

    const QString &getprenom() const;
    void setprenom(const QString &prenom);

    const QString &getdatenai() const;
    void setdatenai(const QString &datenai);

 bool add();
 QSqlQueryModel *list();
 bool delet();
QSqlQueryModel *tri();
};

#endif
