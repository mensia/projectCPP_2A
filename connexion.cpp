#include "connexion.h"

connexion::connexion()
{

}
bool  connexion::creatconnexion ()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A.");//inserer le nom de la source de données ODBC
db.setUserName("system");//inserer nom de l'utilisateur
db.setPassword("SYS");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}
