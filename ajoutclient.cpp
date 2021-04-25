#include "ajoutclient.h"
#include "ui_ajoutclient.h"

ajoutClient::ajoutClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ajoutClient)
{
    ui->setupUi(this);
}

ajoutClient::~ajoutClient()
{
    delete ui;
}
