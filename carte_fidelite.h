#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H

#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlQueryModel>
#include<QObject>

class date
{
public:
    int jour ;
    int mois ;
    int annee ;
    int heure ;
    int minute ;
    int second ;

};

class carte_fidelite
{
public:
    void setID_CF(int n);
    void setIDClient (int n );
    void setNbrPnts (int n );
    void setType(int n );
    void setDateDebut (date n);

    int getID_CF();
    int getIDClient();
    int getNbrPnts ();
    int getType () ;
    date getDateDebut ();


    carte_fidelite();
    carte_fidelite(int, int, int, int, date);

    bool ajouter_CF();
    QSqlQueryModel* afficher_CF();
    bool supprimer_CF(int n );

private :
    int id_CF , id_client, nbr_pnts, type ;
    date date_debut ;
};

#endif // CARTE_FIDELITE_H


/*
cout << "Année" << 1900 + ltm->tm_year<<endl; // l'anne du systeme
cout << "Mois: "<< 1 + ltm->tm_mon<< endl; // le mois du systeme
cout << "Day: "<<  ltm->tm_mday << endl; // le jour du systeme
*/
