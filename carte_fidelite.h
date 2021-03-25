#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H

#include "INCLUD.h"

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
    void setDateModif (date n);
    void setDateString (QString n);

    int getID_CF();
    int getIDClient();
    int getNbrPnts ();
    int getType () ;
    date getDateModif ();
    QString getDateString();


    carte_fidelite();
    carte_fidelite(int, int, int, int, date, QString );

    bool ajouter_CF();
    QSqlQueryModel* afficher_CF();
    bool supprimer_CF(int n );
    void trouvr_CF (int n );
    void modifier_CF();
    QSqlQueryModel* trier_CF(QString n );
private :
    int id_CF , id_client, nbr_pnts, type ;
    QString date_string ;
    date date_modif ;
};

#endif // CARTE_FIDELITE_H


/*
cout << "Année" << 1900 + ltm->tm_year<<endl; // l'anne du systeme
cout << "Mois: "<< 1 + ltm->tm_mon<< endl; // le mois du systeme
cout << "Day: "<<  ltm->tm_mday << endl; // le jour du systeme
*/
