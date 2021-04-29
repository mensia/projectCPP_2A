#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // parti deseign
    QFile File("C://Users//Hana Mansia//Desktop//C++//gestion_client//Toolery.qss");
            File.open(QFile::ReadOnly);
            QString StyleSheet =QLatin1String(File.readAll());
            //setup stylesheet
            a.setStyleSheet(StyleSheet);
        connexion c;
        bool test=c.creatconnexion();
        MainWindow w;

        // parti conex

        if(test)
        {w.show();
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("connection successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);



        return a.exec();
}
