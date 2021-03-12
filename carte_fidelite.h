#ifndef CARTE_FIDELITE_H
#define CARTE_FIDELITE_H
#include<QString>

class carte_fidelite
{
public:
    void setID_CF(int n);
    void setIDClient (int n );
    void setNbrPnts (int n );
    void setType(int n );
    void setDateDebut (QString n);

    int getID_CF();
    int getIDClient();
    int getNbrPnts ();
    int getType () ;
    QString getDateDebut () ;

    carte_fidelite();
private :
    int id_CF , id_client, nbr_pnts, type ;
    QString date_debut ;
};

#endif // CARTE_FIDELITE_H
