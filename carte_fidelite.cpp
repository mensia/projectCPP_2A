#include "carte_fidelite.h"

carte_fidelite::carte_fidelite()
{
id_CF =0 ;
id_client =0 ;
nbr_pnts =0;
type=0;
date_debut ;
}


carte_fidelite::carte_fidelite(int id_CF, int id_client, int nbr_pnts, int type , date date_debut )
{
    this->id_CF = id_CF ;
    this->id_client = id_client;
    this->nbr_pnts = nbr_pnts ;
    this->type = type ;
    this->date_debut = date_debut ;
}

void carte_fidelite::setID_CF(int n){id_CF =n ; }
void carte_fidelite::setIDClient (int n ){id_client =n ; }
void carte_fidelite::setNbrPnts (int n ){nbr_pnts =n ; }
void carte_fidelite::setType(int n ){type=n; }
void carte_fidelite::setDateDebut (date n) {date_debut =n; }

int carte_fidelite::getID_CF(){return id_CF ; }
int carte_fidelite::getIDClient(){return id_client; }
int carte_fidelite::getNbrPnts (){return nbr_pnts; }
int carte_fidelite::getType () {return type; }
date carte_fidelite::getDateDebut () {return date_debut; }

bool carte_fidelite::ajouter_CF()
{
    QSqlQuery query;
    QString id_CF_string = QString::number(id_CF);
    QString id_client_string = QString::number(id_client);
    QString nbr_pnts_string = QString::number(nbr_pnts);
    QString type_string = QString::number(type);
    // creation de la date
    QString date_debut_string_j = QString::number(date_debut.jour);
    QString date_debut_string_M = QString::number(date_debut.mois);
    QString date_debut_string_y = QString::number(date_debut.annee);
    QString date_debut_string_h = QString::number(date_debut.heure);
    QString date_debut_string_m = QString::number(date_debut.minute);
    QString date_debut_string_s = QString::number(date_debut.second);
    QString separateur1 = "/";
    QString separateur2 = ":";

    QString date_debut_string = date_debut_string_j+ separateur1 + date_debut_string_M + separateur1 + date_debut_string_y + "   " + date_debut_string_h + separateur2 + date_debut_string_m + separateur2 + date_debut_string_s ;


    query.prepare("INSERT INTO carte_CF (id_CF, id_client, nbr_pnts, type, date_debut ) "
                  "VALUES (:id_CF, :id_client, :nbr_pnts, :type, :date_debut )");
    query.bindValue(":id_CF", id_CF_string);
    query.bindValue(":id_client", id_client_string);
    query.bindValue(":nbr_pnts", nbr_pnts_string);
    query.bindValue(":type", type_string);
    query.bindValue(":date_debut", date_debut_string);


    return query.exec();

}
QSqlQueryModel* carte_fidelite::afficher_CF()
{
    QSqlQueryModel* model = new QSqlQueryModel();


    model->setQuery("SELECT id_CF, id_client, nbr_pnts, type, date_debut FROM carte_CF ");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_CF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbr_pnts"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_debut"));

    return model ;
}
bool carte_fidelite::supprimer_CF(int n )
{

    QSqlQuery query;

    query.prepare("Delete FROM carte_CF where id_client = :id ");
    query.bindValue(":id", n);

    return  query.exec();

}
