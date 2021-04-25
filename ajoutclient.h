#ifndef AJOUTCLIENT_H
#define AJOUTCLIENT_H

#include <QWidget>

namespace Ui {
class ajoutClient;
}

class ajoutClient : public QWidget
{
    Q_OBJECT

public:
    explicit ajoutClient(QWidget *parent = nullptr);
    ~ajoutClient();

private:
    Ui::ajoutClient *ui;
};

#endif // AJOUTCLIENT_H
