#ifndef CONNEXION_H
#define CONNEXION_H
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QDebug>
class Connexion : public QWidget{
  Q_OBJECT
private:
    QLineEdit * prenom , *nom;


public:
    Connexion(QWidget * parent = 0 );
    QPushButton * se_Connecter;
    QPushButton * btn;
    bool user = false;
    QString valeur   , unom , uprenom ;
    void Decoration();

public slots:
    void stocker_nom_prenom();

};

#endif // CONNEXION_H
