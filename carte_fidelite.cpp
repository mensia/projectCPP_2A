#include "carte_fidelite.h"

carte_fidelite::carte_fidelite()
{
id_CF =0 ;
id_client =0 ;
nbr_pnts =0;
type=0;
date_modif.jour = 0  ;
date_modif.mois = 0 ;
date_modif.annee = 0 ;
date_modif.second = 0 ;
date_modif.minute = 0 ;
date_modif.second = 0 ;
date_string = "" ;
}


carte_fidelite::carte_fidelite(int id_CF, int id_client, int nbr_pnts, int type , date date_modif , QString date_string  )
{
    this->id_CF = id_CF ;
    this->id_client = id_client;
    this->nbr_pnts = nbr_pnts ;
    this->type = type ;
    this->date_modif = date_modif ;
}

void carte_fidelite::setID_CF(int n){id_CF =n ; }
void carte_fidelite::setIDClient (int n ){id_client =n ; }
void carte_fidelite::setNbrPnts (int n ){nbr_pnts =n ; }
void carte_fidelite::setType(int n ){type=n; }
void carte_fidelite::setDateModif(date n)  {date_modif =n; }
void carte_fidelite::setDateString(QString n){date_string=n;}

int carte_fidelite::getID_CF(){return id_CF ; }
int carte_fidelite::getIDClient(){return id_client; }
int carte_fidelite::getNbrPnts (){return nbr_pnts; }
int carte_fidelite::getType () {return type; }
date carte_fidelite::getDateModif () {return date_modif; }
QString carte_fidelite::getDateString(){return date_string; }

bool carte_fidelite::ajouter_CF()
{
    QSqlQuery query;
    QString id_CF_string = QString::number(id_CF);
    QString id_client_string = QString::number(id_client);
    QString nbr_pnts_string = QString::number(nbr_pnts);
    QString type_string = QString::number(type);
    // creation de la date
    QString date_debut_string_j = QString::number(date_modif.jour);
    QString date_debut_string_M = QString::number(date_modif.mois);
    QString date_debut_string_y = QString::number(date_modif.annee);
    QString date_debut_string_h = QString::number(date_modif.heure);
    QString date_debut_string_m = QString::number(date_modif.minute);
    QString date_debut_string_s = QString::number(date_modif.second);
    QString separateur1 = "/";
    QString separateur2 = ":";

    date_string = date_debut_string_j+ separateur1 + date_debut_string_M + separateur1 + date_debut_string_y + "   " + date_debut_string_h + separateur2 + date_debut_string_m + separateur2 + date_debut_string_s ;


    query.prepare("INSERT INTO carte_CF (id_CF, id_client, nbr_pnts, type, date_debut ) "
                  "VALUES (:id_CF, :id_client, :nbr_pnts, :type, :date_debut )");
    query.bindValue(":id_CF", id_CF_string);
    query.bindValue(":id_client", id_client_string);
    query.bindValue(":nbr_pnts", nbr_pnts_string);
    query.bindValue(":type", type_string);
    query.bindValue(":date_debut", date_string);


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
void  carte_fidelite::trouvr_CF (int n )
{
    QSqlQuery query ;
    query.exec("SELECT * FROM CARTE_CF where ID_CF = " + QString::number(n) );

     while (query.next())
     {
         int idCF = query.value(0).toInt();
         setID_CF(idCF);
          int idC = query.value(1).toInt();
          setIDClient(idC);
           int nbr = query.value(2).toInt();
           setNbrPnts(nbr);
            int TY = query.value(3).toInt();
            setType(TY);
         QString date_modiff = query.value(4).toString();
         setDateString(date_modiff) ;

         qDebug() << idCF << idC << nbr << TY << date_modiff ;
     }

}
void carte_fidelite::goldenCarte()
{
     QSqlQuery query ;
      QString typ = QString::number(1);
     query.prepare("UPDATE CARTE_CF set  TYPE = :type  "
                   "where NBR_PNTS >= 200 " );
     query.bindValue(":type", typ);
     query.exec();

}

void carte_fidelite::calcul_pnt (int id_acheteur , int nb_pnt_achat  )
{
    QSqlQuery query ;

    query.prepare("UPDATE CARTE_CF set  NBR_PNTS = NBR_PNTS + " + QString::number(nb_pnt_achat) +
                  "where  ID_CF = " + QString::number(id_acheteur) );

    query.exec();
}

void carte_fidelite::modifier_CF()
{
    QSqlQuery query ;

    time_t actuel = time(0);
    tm *ltm = localtime((&actuel)) ;
    date_modif.jour =  ltm->tm_mday ;
    date_modif.mois = ltm->tm_mon ;
    date_modif.annee = ltm->tm_year ;
    date_modif.heure = ltm->tm_hour ;
    date_modif.minute = ltm->tm_min ;
    date_modif.second = ltm->tm_sec ;

    // creation de la date
    QString date_debut_string_j = QString::number(date_modif.jour);
    QString date_debut_string_M = QString::number(date_modif.mois);
    QString date_debut_string_y = QString::number(date_modif.annee);
    QString date_debut_string_h = QString::number(date_modif.heure);
    QString date_debut_string_m = QString::number(date_modif.minute);
    QString date_debut_string_s = QString::number(date_modif.second);
    QString separateur1 = "/";
    QString separateur2 = ":";

    date_string = date_debut_string_j+ separateur1 + date_debut_string_M + separateur1 + date_debut_string_y + "   " + date_debut_string_h + separateur2 + date_debut_string_m + separateur2 + date_debut_string_s ;


    QString typ = QString::number(type);
    QString nb = QString::number(nbr_pnts);

    query.prepare("UPDATE CARTE_CF set NBR_PNTS = :nbr_pnts , TYPE = :type , DATE_DEBUT = :date "
                  "where ID_CF = " + QString::number(id_CF));
    query.bindValue(":nbr_pnts", nb);
    query.bindValue(":type", typ);
    query.bindValue(":date",date_string);
    query.exec();


}
bool carte_fidelite::supprimer_CF(int n )
{
     QSqlQuery query;
    carte_fidelite x ;
    x.trouvr_CF(n);
    if (x.getID_CF()== 0 && x.getNbrPnts()== 0 )  qWarning("id inexistant ");
    else
    {

    query.prepare("Delete FROM carte_CF where id_client = :id ");
    query.bindValue(":id", n);

    }
     return  query.exec();
}
QSqlQueryModel* carte_fidelite::trier_CF(QString n )
{
    QSqlQueryModel* model = new QSqlQueryModel();


    model->setQuery("SELECT * FROM carte_CF ORDER BY "+ n );


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_CF"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id_client"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nbr_pnts"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("date_debut"));

    return model ;
}
