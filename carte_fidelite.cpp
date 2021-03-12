#include "carte_fidelite.h"

carte_fidelite::carte_fidelite()
{
id_CF =0 ;
id_client =0 ;
nbr_pnts =0;
type=0;
date_debut ="";
}

void carte_fidelite::setID_CF(int n){id_CF =n ; }
void carte_fidelite::setIDClient (int n ){id_client =n ; }
void carte_fidelite::setNbrPnts (int n ){nbr_pnts =n ; }
void carte_fidelite::setType(int n ){type=n; }
void carte_fidelite::setDateDebut (QString n) {date_debut =n; }

int carte_fidelite::getID_CF(){return id_CF ; }
int carte_fidelite::getIDClient(){return id_client; }
int carte_fidelite::getNbrPnts (){return nbr_pnts; }
int carte_fidelite::getType () {return type; }
QString carte_fidelite::getDateDebut () {return date_debut; }
