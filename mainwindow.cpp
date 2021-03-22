#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include "carte_fidelite.h"
#include <ctime>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tableau_client->setModel(C.afficher_client());
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_ajouter_client_clicked()
{
    time_t actuel = time(0);
    tm *ltm = localtime((&actuel)) ;

    int id = rand() % 8888 + 1111 ; // doit etre generer automatiquement
    int telephone = (int) ui->lineEdit_telephoneclient->text().toInt() ;
    int num_CB = ui->lineEdit_numCB->text().toInt();
    int id_CF =  rand() % 8888 + 1111 ;
    int nbr_pnts = 100 ;
    int type = 0 ;
    date date_debut ;
    date_debut.jour =  ltm->tm_mday ;
    date_debut.mois = ltm->tm_mon ;
    date_debut.annee = ltm->tm_year ;
    date_debut.heure = ltm->tm_hour ;
    date_debut.minute = ltm->tm_min ;
    date_debut.second = ltm->tm_sec ;
    QString  nom = ui->lineEdit_nomclient->text();
    QString prenom = ui->lineEdit_prenomclient->text();
    QString adresse = ui->lineEdit_adresseclient->text();
    QString mail = ui->lineEdit_mailclient->text() ;
    carte_fidelite CF(id_CF, id , nbr_pnts , type , date_debut);
    client c(id , nom , prenom , adresse , mail , telephone , num_CB , id_CF ) ;
    bool test_client = c.ajouter_client() ;
    bool test_CF = CF.ajouter_CF();
    QMessageBox msgBoxClient ;
    QMessageBox msgBoxCF ;
    if(test_client )
    {
        msgBoxClient.setText("ajout confirmé ");
        ui->tableau_client->setModel(c.afficher_client());
    }
    else
        msgBoxClient.setText("ajout echouer ");
    msgBoxClient.exec();

    if(test_CF )
    {
        msgBoxCF.setText("ajout de la CF confirmé ");
        ui->tableau_client->setModel(CF.afficher_CF());
    }
    else
        msgBoxCF.setText("ajout de la CF echouer ");
    msgBoxCF.exec();

}

void MainWindow::on_pushButton_supprimerClient_clicked()
{

    client c ;
    carte_fidelite CF ;
    c.setID(ui->lineEdit_ID_client_supp->text().toInt());
    bool test = c.supprimer_client(c.getID());
    bool test1 = CF.supprimer_CF(c.getID());
    QMessageBox msgBoxC ;
    if(test)
    {
        msgBoxC.setText("suppression confirmé ");
        ui->tableau_client->setModel(c.afficher_client());
    }
    else
        msgBoxC.setText("suppression echouer ");
    msgBoxC.exec();

    QMessageBox msgBoxCF ;
    if(test1)
    {
        msgBoxCF.setText("suppression de la CF confirmé ");
        ui->tableau_client->setModel(c.afficher_client());
    }
    else
        msgBoxCF.setText("suppression de la CF echouer ");
    msgBoxCF.exec();


}
