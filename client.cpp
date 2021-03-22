#include "client.h"

client::client()
{
id=0;
nom="";
prenom="";
adresse="";
mail="";
telephone=0;
num_CB=0;
CF=0;
}

client::client(int id , QString nom , QString prenom , QString adresse , QString mail , int telephone , int num_CB, int CF  )
{
    this->id = id ;
    this->nom = nom ;
    this->prenom = prenom ;
    this->adresse = adresse ;
    this->mail = mail ;
    this-> telephone = telephone ;
    this->num_CB = num_CB ;
    this->CF = CF ;
}

void client::setID(int n){id = n;}
void client::setNom(QString n ){nom = n; }
void client::setPrenom(QString n){prenom = n; }
void client::setAdresse(QString n) {adresse = n; }
void client::setMail(QString n) {mail = n; }
void client::setTelephone(int n ){telephone = n; }
void client::setNum_CB(int n){num_CB = n; }
void client::setCF(int n){CF = n ; }

int client::getID(){return id;}
QString client::getNom (){return nom ;}
QString client::getPrenom (){return prenom ;}
QString client::getAdresse (){return adresse;}
QString client::getMail (){return mail ;}
int client::getTelephone (){return telephone ;}
int client::getNum_CB (){return num_CB ;}
int client::getCF(){return CF ; }

bool client::ajouter_client()
{


    QSqlQuery query;
    QString id_string = QString::number(id);
    QString telephone_string = QString::number(telephone);
    QString num_CB_string = QString::number(num_CB);
    QString CF_string = QString::number(CF);
    query.prepare("INSERT INTO client (id, nom, prenom, adresse, mail, telephone, num_CB, CF ) "
                  "VALUES (:id, :nom, :prenom, :adresse, :mail, :telephone, :num_CB, :CF )");
    query.bindValue(":id", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":mail", mail);
    query.bindValue(":telephone", telephone_string);
    query.bindValue(":num_CB", num_CB_string);
    query.bindValue(":CF", CF_string);

    return query.exec();

}
QSqlQueryModel* client::afficher_client()
{
 QSqlQueryModel* model = new QSqlQueryModel();


 model->setQuery("SELECT id, nom, prenom, adresse, mail, telephone, num_CB, CF FROM client ");


 model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
 model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
 model->setHeaderData(6, Qt::Horizontal, QObject::tr("num_CB"));
 model->setHeaderData(7, Qt::Horizontal, QObject::tr("CF"));



 return model ;
}
bool client::supprimer_client(int n )
{
    QSqlQuery query;

    query.prepare("Delete FROM client where id = :id ");
    query.bindValue(":id", n);
    return query.exec();



}

