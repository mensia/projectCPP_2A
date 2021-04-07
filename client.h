#ifndef CLIENT_H
#define CLIENT_H

#include "INCLUD.h"


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
QSqlQueryModel* afficher_clients();
bool supprimer_client(int );
void trouver_client(int n );
void modifier_client ( );
int generation_id();
QSqlQueryModel* trier_client(QString n );
QSqlQueryModel* rechercheClient (QString);

private:
    int id , telephone, num_CB, CF  ;
    QString  nom, prenom , adresse, mail ;

};

#endif // CLIENT_H
