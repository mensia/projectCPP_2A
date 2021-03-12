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
}

void client::setID(int n){id = n;}
void client::setNom(QString n ){nom = n; }
void client::setPrenom(QString n){prenom = n; }
void client::setAdresse(QString n) {adresse = n; }
void client::setMail(QString n) {mail = n; }
void client::setTelephone(int n ){telephone = n; }
void client::setNum_CB(int n){num_CB = n; }

int client::getID(){return id;}
QString client::getNom (){return nom ;}
QString client::getPrenom (){return prenom ;}
QString client::getAdresse (){return adresse;}
QString client::getMail (){return mail ;}
int client::getTelephone (){return telephone ;}
int client::getNum_CB (){return num_CB ;}
