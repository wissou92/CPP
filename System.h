#ifndef SYSTEM_H
#define SYSTEM_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRect>
#include <QBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QProgressBar>
#include <QPalette>
#include <QColor>
#include<QPainter>
#include<QRect>
#include<QEvent>
#include <QRegion>
#include <QString>
#include <QDebug>
#include <QList>
#include <QTimer>
#include "Tank.h"
#include "Moteur.h"
#include "Line.h"
#include "Vanne.h"
#include "Pompe.h"
#include "VanneTM.h"
#include"VanneTT.h"


class System : public QWidget
{
    Q_OBJECT

private:
    Tank *t , *t1, *t2 ;

    QTimer *timer1 ,*timer2 , *timer3;

    QPushButton *V12 ,*V13 ,*V23 ,*VT12 ,*VT23 ,* P32 ,
                      *P12 ,*P22  ,*res1 ,*res2 ,*res3 ,
                      *tmp ,*PP11 ,*PP21 ,*PP31 ,*start;

    Moteur *M1 , *M2 , *M3;

    VanneTT  *vt12 , *vt23 ;

    VanneTM  *v12 , *v13 , *v23 ;

   QList <QPushButton*> mes_btns ;
   QList<Tank *> mes_tank ;
   QList<Moteur *> mes_moteur;
public:

     System(QWidget *parent = nullptr);
     QPushButton *Menu ;
     void tracer_lignes();
     void tracer_vannes();
     void creer_buttons();
     void creer_tanks();

     ~System();

public slots:
    void open_close();
    void mise_a_jour_tank();
    void alimentation();
    void vider_T();
    void accelerer_timer();
    void test_vidange();
    void arret_Pompe();
    void mouvement_reserv();
    void demarer_timer();

signals:
    void Panne_Tank();
    //siganl qui va permettre darreter
    //le timer pour le reservoir
    void Panne_P1();



};
#endif
