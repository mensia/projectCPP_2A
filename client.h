#ifndef CLIENT_H
#define CLIENT_H

#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QObject>
class client
{
public:
    client () ;
    client(int, QString, QString, QString, QString, int, int, int );

    void setID(int n );
    void setNom(QString n );
    void setPrenom(QString n );
    void setAdresse(QString n );
    void setMail(QString n );
    void setTelephone(int  n );
    void setNum_CB(int n );
    void setCF (int n);

    int getID() ;
    QString getNom() ;
    QString getPrenom() ;
    QString getAdresse() ;
    QString getMail() ;
    int  getTelephone() ;
    int getNum_CB() ;
    int getCF();

bool ajouter_client();
QSqlQueryModel* afficher_client();
bool supprimer_client(int );
// int generation_id();

private:
    int id , telephone, num_CB, CF  ;
    QString  nom, prenom , adresse, mail ;

};

#endif // CLIENT_H
