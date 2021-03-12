#ifndef CLIENT_H
#define CLIENT_H

#include<QString>

class client
{
public:

    void setID(int n );
    void setNom(QString n );
    void setPrenom(QString n );
    void setAdresse(QString n );
    void setMail(QString n );
    void setTelephone(int  n );
    void setNum_CB(int n );

    int getID() ;
    QString getNom() ;
    QString getPrenom() ;
    QString getAdresse() ;
    QString getMail() ;
    int  getTelephone() ;
    int getNum_CB() ;

    client();

private:
    int id , telephone, num_CB ;
    QString  nom, prenom , adresse, mail ;

};

#endif // CLIENT_H
