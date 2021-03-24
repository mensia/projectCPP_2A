#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
#include <QMainWindow>
#include"client.h"
#include"carte_fidelite.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_ajouter_client_clicked();

    void on_pushButton_supprimerClient_clicked();

    void on_pushButton_ajouterClient_clicked();

    void on_pushButton_modifierClient_clicked();

    void on_pushButton_modifier_client_clicked();

private:
    Ui::MainWindow *ui;
    client C ;
    carte_fidelite CF ;
};
#endif // MAINWINDOW_H
