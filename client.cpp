#include "client.h"

     // using namespace
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
QSqlQueryModel* client::afficher_clients()
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

 // model->setData(model->index(1, 0), QBrush(Qt.red), QtCore->Qt.BackgroundRole) ;
    //     model->setData(model->index(1, 0), QtGui.QBrush(QtCore.Qt.red), QtCore.Qt.BackgroundRole)


 return model ;
}
void client::trouver_client(int n )
{

 QSqlQuery query;
 //QString n1 = QString::number(n);

 query.exec("SELECT * FROM client where ID = " + QString::number(n) );
 //  query.addBindValue(n);

 while (query.next())
         {
         QString name = query.value(1).toString();
         setNom(name);
         QString surname = query.value(2).toString();
         setPrenom(surname);
         QString ad = query.value(3).toString();
         setAdresse(ad);
         QString mai = query.value(4).toString();
         setMail(mai);
         int salary = query.value(0).toInt();
         setID(salary);
         int tel = query.value(5).toInt();
         setTelephone(tel);
         int num = query.value(6).toInt();
         setNum_CB(num);
         int C = query.value(7).toInt();
         setCF(C);

         qDebug() << name << surname << ad << mai << salary << tel << num << C ;
         }

}
void client::modifier_client ( )
{
      QSqlQuery query ;

    QString telephone_string = QString::number(telephone);
        QString num_CB_string = QString::number(num_CB);
        query.prepare("UPDATE client set nom = :nom , prenom = :prenom , adresse = :adresse , mail = :mail , telephone = :telephone , num_CB = :num_CB "
                      " where ID = " + QString::number(id));
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":adresse", adresse);
        query.bindValue(":mail", mail);
        query.bindValue(":telephone", telephone_string);
        query.bindValue(":num_CB", num_CB_string);
    query.exec();

}
bool client::supprimer_client(int n )
{
    QSqlQuery query;
    client x ;
    x.trouver_client(n);
    if (x.getID()==0 && x.getNum_CB()==0) qWarning("id inexistant ");
    else
    {
    query.prepare("Delete FROM client where id = :id ");
    query.bindValue(":id", n);
    }
    return query.exec();
}
int client::generation_id()
{
    int a = rand() % 8888 + 1111 , b ;

    id = a ;
        QSqlQuery query ;
        query.exec("SELECT * FROM client");

         while (query.next())
         {
             b = query.value(0).toInt() ;
              qDebug() << b ;
              if (id == b ) id ++ ;
         }
         return id ;
}
         /*
          bool test ;
        QSqlQuery count ;
       count.exec( "select count(*) from client ") ;
       if (!count.exec()) qWarning("Incorrect query");
        int l = count.value(0).toInt() ;
        int tab[l];

           do {
        for (int i = 0 ; i=l ; i++ )
            if (id== tab[i])
                test = false ;
    } while (test = false) ;
    */
QSqlQueryModel* client::trier_client(QString n )
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM client ORDER BY "+ n );

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

QSqlQueryModel *client::rechercheClient(QString n )
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("select * from client where nom LIKE '"+n+"%'");


     model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
     model->setHeaderData(5, Qt::Horizontal, QObject::tr("telephone"));
     model->setHeaderData(6, Qt::Horizontal, QObject::tr("num_CB"));
     model->setHeaderData(7, Qt::Horizontal, QObject::tr("CF"));

 return model;
}
