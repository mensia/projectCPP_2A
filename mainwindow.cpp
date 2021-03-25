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

ui->tableau_client->setModel(C.afficher_clients());
ui->tableau_CF->setModel(CF.afficher_CF());
carte_fidelite CF ;
client c ;
 c.trouver_client(7445);
 CF.trouvr_CF(3522);




QString m = QString::number(c.getID()) ;
ui->ID->setText( QString::number(CF.getID_CF()) );
ui->nom->setText(CF.getDateString());
ui->prenom->setText(c.getPrenom());
ui->adresse->setText(c.getAdresse());
ui->mail->setText(c.getMail());
ui->telephone->setText( QString::number(CF.getIDClient()));
ui->CB->setText( QString::number(CF.getNbrPnts()));
ui->CF->setText( QString::number(CF.getType()));

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
    int id_CF =  id ;
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
    QString dateString ;
    carte_fidelite CF(id_CF, id , nbr_pnts , type , date_debut, dateString );
    client c(id , nom , prenom , adresse , mail , telephone , num_CB , id_CF ) ;
    bool test_client = c.ajouter_client() ;
    bool test_CF = CF.ajouter_CF();
    QMessageBox msgBoxClient ;
    QMessageBox msgBoxCF ;
    if(test_client )
    {
        msgBoxClient.setText("ajout confirmé ");
        ui->tableau_client->setModel(c.afficher_clients());

    }
    else
        msgBoxClient.setText("ajout echouer ");
    msgBoxClient.exec();

    if(test_CF )
    {
        msgBoxCF.setText("ajout de la CF confirmé ");

        ui->tableau_CF->setModel(CF.afficher_CF());

    }
    else
        msgBoxCF.setText("ajout de la CF echouer ");
    msgBoxCF.exec();

}

void MainWindow::on_pushButton_supprimerClient_clicked()
{

    client c ;
    carte_fidelite CF ;
    c.setID(ui->lineEdit_ID_client_supp_mod->text().toInt());
    bool test = c.supprimer_client(c.getID());
    bool test1 = CF.supprimer_CF(c.getID());
    QMessageBox msgBoxC ;
    if(test)
    {
        msgBoxC.setText("suppression confirmé ");
        ui->tableau_client->setModel(c.afficher_clients());
    }
    else
        msgBoxC.setText("suppression echouer ");
    msgBoxC.exec();

    QMessageBox msgBoxCF ;
    if(test1)
    {
        msgBoxCF.setText("suppression de la CF confirmé ");

        ui->tableau_CF->setModel(CF.afficher_CF());

    }
    else
        msgBoxCF.setText("suppression de la CF echouer ");
    msgBoxCF.exec();

}

void MainWindow::on_pushButton_modifierClient_clicked()
{
    // aller au tab modifier
    client c ;     carte_fidelite CF ;
    c.setID(ui->lineEdit_ID_client_supp_mod->text().toInt());
    CF.setID_CF(ui->lineEdit_ID_client_supp_mod->text().toInt());
    c.trouver_client(c.getID());
    CF.trouvr_CF(c.getID());

    ui->lineEdit_id_a_modifier->setText( QString::number(c.getID()));
    ui->lineEdit_nom_a_modifier->setText(c.getNom());
    ui->lineEdit__prenom_a_modifier->setText(c.getPrenom());
    ui->lineEdit_adresse_a_modifier->setText(c.getAdresse());
    ui->lineEdit_mail_a_modofier->setText(c.getMail());
    ui->lineEdit_telephone_a_modifier->setText(QString::number(c.getTelephone()));
    ui->lineEdit_num_CB_a_modifier->setText(QString::number(c.getNum_CB()));

    ui->lineEdit_id_CF_a_modifier->setText(QString::number(CF.getID_CF()));
    ui->lineEdit_date_debut_a_modifier->setText(CF.getDateString());
    ui->spinBox_type_a_modifier->setValue(CF.getType());
    ui->spinBox_nbr_pnts_a_modifier->setValue(CF.getNbrPnts());

}

void MainWindow::on_pushButton_modifier_client_clicked()
{
    client c ; carte_fidelite CF ;

        c.setID(ui->lineEdit_id_a_modifier->text().toInt());
        c.setTelephone( ui->lineEdit_telephone_a_modifier->text().toInt());
        c.setCF( ui->lineEdit_id_CF_a_modifier->text().toInt());
        c.setNum_CB( ui->lineEdit_num_CB_a_modifier->text().toInt());
        c.setNom(ui->lineEdit_nom_a_modifier->text());
        c.setPrenom(ui->lineEdit__prenom_a_modifier->text());
        c.setAdresse(ui->lineEdit_adresse_a_modifier->text());
        c.setMail(ui->lineEdit_mail_a_modofier->text());
        CF.setID_CF(c.getID());
        CF.setType( ui->spinBox_type_a_modifier->value() ) ;
        CF.setNbrPnts(ui->spinBox_nbr_pnts_a_modifier->value());

        CF.modifier_CF();
        c.modifier_client();
        ui->tableau_client->setModel(c.afficher_clients());
        ui->tableau_CF->setModel(CF.afficher_CF());
}
